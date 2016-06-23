#include "Model.h"
#include <iostream>

void* processaAutomatico(void *data)
{	if(data == NULL)
		return NULL;

	Model *model = (Model*) data;

	int contador = 0;

	while( model->getProcessamento() ) // automatico
	{	gdk_threads_enter();
		model->processador();
		gdk_threads_leave();

		contador++;
//*
		if(contador > 500)
		{	model->delay();
			contador = 0;
		}
//*/
	}
	gdk_threads_enter();
	model->updateAll();
	gdk_threads_leave();

	return NULL;
}

void Model::updateAll()
{	Ins->updateInstrucoes(auxpc, pc2, N_LINHAS);		// termina imprimindo o resultado
	Reg->updateRegistradores();	// e atualizando os registradores
	Reg->updateFR();
	Reg->updatePC();
	Reg->updateIR();
	Reg->updateSP();
	Reg->updateC0();
	Reg->updateIRQ();
}


// -- Construtor e destrutor ---
Model::Model(char *cpuram)
{	FILE *pf;
	if( (pf = fopen(cpuram, "r")) == NULL)
	{	printf("Erro ao tentar abrir: %s\n", cpuram);
		exit(1);
	}

	char linha[128];
	fgets(linha, 128, pf);
	if( strcmp("-- Codigo gerado pelo montador\n", linha) && strcmp("-- Codigo gerado pelo montador\r\n", linha) )
	{	fclose(pf);
		printf("Erro no arquivo .mif");
		exit(1);
	}
	fclose(pf);

	GravaArquivo(cpuram);

	sprintf(this->cpuram, "CPURAM: %s", cpuram);

	varDelay = MEDIA;
	automatico = false;
	count = 0;

	resetVideo();
}



void Model::setController(ControllerInterface *controller)
{	this->controller = controller; }

void Model::reset()
{	pc = 0;
	ir = 0;
 	sp = 0x5FFC;
	auxpc = 0;
	pc2 = 0;

	int i, tmp;
	int vetor[] = {0, 0, 0, 0, 0 , 0, 0, 0};
	setRegistrador(vetor);

	for(i = 16; i-- ; )
		FR[i] = 0;

	processador();

	tmp = auxpc;

	setPC(0);
	setIR(0);
	setSP(0x5FFC);

	setRegistrador(vetor);

	for(i = 16; i-- ; )
		setFR(i, 0);


	for(i = 16; i-- ; )
		setC0(i, 0);


	for(i = 16; i-- ; )
		setIRQ(i, 0);

	Ins->updateInstrucoes(0, tmp, N_LINHAS);		// termina imprimindo o resultado
}


// ------ Registradores ----------------
void Model::registraRegistrador(Registradores *r)
{	Reg = r;	}

void Model::removeRegistrador()
{	Reg = NULL;	}


// --- registradores gerais ---
int Model::getRegistrador(int regN)
{	return reg[regN];	}

void Model::setRegistrador(int *vetor)
{	if(vetor != NULL)
	{	for(int i=8; i--; )
		{	if(vetor[i] >= 0)
				reg[i] = vetor[i];
		}
	}
	Reg->updateRegistradores();
}


// -------- PC -----------
int Model::getPC()
{	return pc; }

void Model::setPC(int valor)
{	if(valor >= 0)
		pc = valor;
	Reg->updatePC();
}


// -------- IR -----------
int Model::getIR()
{	return ir;	}

void Model::setIR(int valor)
{	if(valor >= 0)
		ir = valor;
	Reg->updateIR();
}


// -------- SP -----------
int Model::getSP()
{	return sp;	}

void Model::setSP(int valor)
{	if(valor >= 0)
		sp = valor;
	Reg->updateSP();
}


// -------- FR -----------
bool Model::getFR(int N)
{	return FR[N];	}

void Model::setFR(int N, bool valor)
{	if(valor >= 0)
		FR[N] = valor;
	Reg->updateFR();
}

// -------- C0 -----------
bool Model::getC0(int N)
{	return c0[N];	}

void Model::setC0(int N, bool valor)
{	if(valor >= 0)
		c0[N] = valor;
	Reg->updateC0();
}

// -------- IRQ -----------
bool Model::getIRQ(int N)
{	return IRQ[N];	}

void Model::setIRQ(int N, bool valor)
{	if(valor >= 0)
		IRQ[N] = valor;
	Reg->updateIRQ();
}


// ------ Instrucoes -------------------
void Model::registraInstrucoes(Instrucoes *i)
{	Ins = i;	}

void Model::removeInstrucoes()
{	Ins = NULL;	}

void Model::setProcessamento(bool automatico)
{	this->automatico = automatico; }

bool Model::getProcessamento()
{	return automatico; }

void Model::processa()
{ if(automatico)
	{
		GError *error = NULL;

//*
		if(!g_thread_new("proc", processaAutomatico, this))
		{	g_printerr ("Failed to create YES thread: %s\n", error->message);
			return;
		}
//*/
		updateAll();
		return;
	}
	//pthread_join(out, NULL);
	processador(); // executa soh uma vez
	updateAll();
}


// Funcao que separa somente o pedaco de interesse do IR;
 int Model::pega_pedaco(int ir, int a, int b)
{ return (int)((ir & (int)  ( (int)((1 << (a+1)) - 1) )  ) >> b); }

void Model::resetVideo()
{
	Vid.reset();
}


// -------- arquivos.mif -----------
int Model::processa_linha(char *linha)
{ unsigned int i = 0, j = 0, valor = 0;

	//procura o inicio do numero
	while(linha[i] != ':')
	{	if(!linha[i])
		 return -1;
		i++;
	}

	for(; j<16; j++)  					 	 //le a palavra toda
	{ valor <<= 1; 								 //shifta pra esquerda entrando 0
		valor += linha[i+j+1] - '0'; //converte char pra numero 0 ou 1 o bit 15-k da palavra
	}

	return valor;
}

void Model::GravaArquivo(char *nome)
{	FILE *stream;   // Declara ponteiro para o arquivo

	//  Processa dados do Arquivo CPU.MIF
	if( (stream = fopen(nome,"r")) == NULL)  // Abre o arquivo para leitura
	{ printf("Error: File not OPEN!\n");
		return;
	}

	char linha[128];
	unsigned int i, j, processando = 0;

	while(!feof(stream))   				 // Le linha por linha ate' o final do arquivo: eof = end of file !!
	{ fscanf(stream,"%s", linha);  // Le uma linha inteira ate' o \n
		char letra[3] = "00";

		if(!processando)
		{ i = 0;
		  do						// Busca por sequencias de caracteres para catar inicio do codigo
			{ letra[0] = letra[1];
		    letra[1] = linha[i];

		    if((letra[1]==':') && (letra[0]=='0') )  // Cata primeira linha de codigo comecando com "0: "
		    { // Le programa e guarda no vetor mem[32768]
		      processando = 1;
		      j = 0;
		    }
		    i++;
		  } while (linha[i] != '\0');
		}

		if(processando && (j < TAMANHO_MEMORIA))
		{ mem[j] = processa_linha(linha);

		  if(mem[j] == -1)
			 printf("Linha invalida (%d): '%s'", j, linha);
		  j++;
		}
	} // Fim do while (!feof(stream))

	fclose(stream);  // Nunca esqueca um arquivo aberto!!
}

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}


char* Model::getCpuram()
{ return cpuram; }


// Memoria
int Model::getMem(int pos)
{	return mem[pos]; }


// Processamento
unsigned int Model::_rotl(const unsigned int value, int shift)
{ if(shift >= 16)									 				 // evita rotacoes completas
		shift = shift - (shift/16)*16; 				 // shift = shift mod 16

	unsigned int aux = value << shift;			 // shifta para a esquerda
	aux += pega_pedaco(value, 15, 16-shift); // pega os bits finais que serao deslocados para o inicio

	return aux &= 65535;										 // retorna somente os 16 primeiros bits do numero
}

unsigned int Model::_rotr(const unsigned int value, int shift)
{ if(shift >= 16)									 					// evita rotacoes completas
		shift = shift - (shift/16)*16; 					// shift = shift mod 16

	unsigned int aux = value >> shift;				// shifta para a direita
	aux += ( pega_pedaco(value, shift, 0) << (16 - shift) );  // pega os bits iniciais que serao deslocados para o final

	return aux &= 65535;											// retorna somente os 16 primeiros bits do numero
}

void Model::delay()
{
/*
	void Model::delay(clock_t wait)

	clock_t goal = ( wait + clock() );
	while( goal > clock() );
//*/

	//g_print("Delay: %d\n", varDelay);

	//clock_t goal = ( varDelay + clock() );
	//while( goal > clock() );
}

int Model::getDelay()
{	return varDelay; }

void Model::setDelay(int valor)
{
	/*
	// se igual nao faz nada
		if(varDelay == valor)
			return;

		// senao, mata a thread e cria uma nova com o novo valor do delay
	*/

	varDelay = valor;
}

void Model::processador()
{
	unsigned int la;
	unsigned int i;
	unsigned int temp;
	unsigned int opcode;

	unsigned int letra;

	// -- Video --
	if(count == 49999){
		controller->updateVideo();
		count = 0;
	}
	count ++;

if(opcode != RTS){
	    bool irq = false;
	    /* Ciclo de interrupcao */
	    for(i=0;i<16;i++ ){
	    	if(IRQ[i]){
	    		irq = true;
	    		break;
	    	}
	    }
	  if(irq && !c0[1] && c0[0]){
	  	c0[1] = 1;
	    mem[sp] = pc;
	    sp--;

	    /* Executa interrupcao */
		  if(IRQ[0]){
		  		pc = mem[0x7ff0];
		  		IRQ[0] = 0;
		  }
		  else if(IRQ[1]){
		  		pc = mem[0x7ff1];
		  		IRQ[1] = 0;
		  }
		  else if(IRQ[2]){
		  		pc = mem[0x7ff2];
		  		IRQ[2] = 0;
		  }
		  else if(IRQ[3]){
		  		pc = mem[0x7ff3];
		  		IRQ[3] = 0;
		  }
		  else if(IRQ[4]){
		  		pc = mem[0x7ff4];
		  		IRQ[4] = 0;
		  }
		  else if(IRQ[5]){
		  		pc = mem[0x7ff5];
		  		IRQ[5] = 0;
		  }
		  else if(IRQ[6]){
		  		pc = mem[0x7ff6];
		  		IRQ[6] = 0;
		  }
		  else if(IRQ[7]){
		  		pc = mem[0x7ff7];
		  		IRQ[7] = 0;
		  }
		  else if(IRQ[8]){
		  		pc = mem[0x7ff8];
		  		IRQ[8] = 0;
		  }
		  else if(IRQ[9]){
		  		pc = mem[0x7ff9];
		  		IRQ[9] = 0;
		  }
		  else if(IRQ[10]){
		  		pc = mem[0x7ffa];
		  		IRQ[10] = 0;
		  }
		  else if(IRQ[11]){
		  		pc = mem[0x7ffb];
		  		IRQ[11] = 0;
		  }
		  else if(IRQ[12]){
		  		pc = mem[0x7ffc];
		  		IRQ[12] = 0;
		  }
		  else if(IRQ[13]){
		  		pc = mem[0x7ffd];
		  		IRQ[13] = 0;
		  }
		  else if(IRQ[14]){
		  		pc = mem[0x7ffe];
		  		IRQ[14] = 0;
		  }
		  else if(IRQ[15]){
		  		pc = mem[0x7fff];
		  		IRQ[15] = 0;
		  }
	  }
	}
  // ----- Ciclo de Busca: --------
	ir = mem[pc];
	if(pc > 32767)
	{ printf("Ultrapassou limite da memoria, coloque um jmp no fim do código\n");
		exit(1);
	}
	pc++;
	// ----------- -- ---------------

  // ------ Ciclo de Executa: ------
  rx = pega_pedaco(ir,9,7);
  ry = pega_pedaco(ir,6,4);
  rz = pega_pedaco(ir,3,1);
	// ------------- -- --------------*

  // Case das instrucoes
  opcode = pega_pedaco(ir,15,10);

  switch(opcode)
	{ case INCHAR:
			if(reg[ry] == 0x900){//Keyboard
		        key = controller->getKey();//getch();
		        reg[rx] = pega_pedaco(key,7,0);
		    }else if(reg[ry] >= 0x990 && reg[ry] <= 0x994){//PIT

		    }else{
				cout << "Erro: Voce tentou usar uma porta nao implementada " << reg[ry] << endl;
			}
		break;

    case OUTCHAR:
			if(reg[ry] == 0) //Video ADDR BG
			{
				Vid.setAddrBG(reg[rx]);
			}else if(reg[ry] == 1) //Video BG
			{
				Vid.addBG(reg[rx]);
			}else if(reg[ry] == 2) //Video ADDR OAM
			{
				Vid.setAddrOAM(reg[rx]);
			}else if(reg[ry] == 3) //Vdeo OAM
			{
				Vid.addObject(reg[rx]);
			}else if(reg[ry] == 4) //Video ADDR SPRITE
			{
				Vid.setAddrSprite(reg[rx]);
			}else if(reg[ry] == 5) //Video SPRITE
			{
				Vid.addSprite(reg[rx]);
			}else if(reg[ry] == 6) //Video ADDR PALETTE
			{
				Vid.setAddrPalette(reg[rx]);
			}else if(reg[ry] == 7) //Video PALETTE
			{
				Vid.addPalette(reg[rx]);
			}else if(reg[ry] >= 0x901 && reg[ry] <= 0x902){ //com1

			}else if(reg[ry] >= 0x990 && reg[ry] <= 0x994){//PIT

			}else{
				cout << "Erro: Voce tentou usar uma porta nao implementada " << reg[ry] << endl;
			}

			break;

		case EI:
			switch(pega_pedaco(ir,0,0)){
				case 0:
					c0[0] = 0;
					break;
				default:
					c0[0] = 1;
					break;
			}
			break;

		case MOV:
			switch(pega_pedaco(ir,1,0))
			{ case 0:
					reg[rx] = reg[ry];
					break;
				case 1:
					reg[rx] = sp;
					break;
				default:
					sp = reg[rx];
				break;
			}
      break;

    case STORE:
      mem[mem[pc]] = reg[rx];
      pc++;
      break;

    case STOREINDEX:
      mem[reg[rx]] = reg[ry];
      break;

    case LOAD:
      reg[rx] = mem[mem[pc]];
      pc++;
      break;

    case LOADIMED:
      reg[rx] = mem[pc];
      pc++;
      break;

    case LOADINDEX:
      reg[rx] = mem[reg[ry]];
      break;

    case LAND:
      reg[rx] = reg[ry] & reg[rz];
			FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>
      if(reg[rx] == 0)
				FR[3] = 1;
      break;

    case LOR:
      reg[rx] = reg[ry] | reg[rz];
			FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>
      if(reg[rx] == 0)
				FR[3] = 1;
      break;

    case LXOR:
      reg[rx] = reg[ry] ^ reg[rz];
			FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>
      if(reg[rx] == 0)
				FR[3] = 1;
      break;

    case LNOT:
      reg[rx] =  ~(reg[ry]);
			FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>
      if(reg[rx] == 0)
				FR[3] = 1;
      break;

    case CMP:
			//if(rx == 1200)
			//	printf("valor de ry: %d\n", ry);

      if (reg[rx] > reg[ry])
			{	FR[2] = 0; // FR = <...|zero|equal|lesser|greater>
				FR[1] = 0;
				FR[0] = 1;
			}
      else if (reg[rx] < reg[ry])
			{	FR[2] = 0; // FR = <...|zero|equal|lesser|greater>
				FR[1] = 1;
				FR[0] = 0;
			}
      else // reg[rx] == reg[ry]
			{	FR[2] = 1; // FR = <...|zero|equal|lesser|greater>
				FR[1] = 0;
				FR[0] = 0;
				//printf("rx == ry\n");
			}
      break;

    case JMP:
			la = pega_pedaco(ir,9,6);

			if((la == 0) // NO COND
                || (FR[0]==1 && (la==7)) 							// GREATER
                || ((FR[2]==1 || FR[0]==1) && (la==9))  // GREATER EQUAL
                || (FR[1]==1 && (la==8)) 							// LESSER
                || ((FR[2]==1 || FR[1]==1) && (la==10)) // LESSER EQUAL
                || (FR[2]==1 && (la==1)) 							// EQUAL
                || (FR[2]==0 && (la==2)) 							// NOT EQUAL
                || (FR[3]==1 && (la==3)) 							// ZERO
                || (FR[3]==0 && (la==4)) 							// NOT ZERO
                || (FR[4]==1 && (la==5)) 							// CARRY
                || (FR[4]==0 && (la==6)) 							// NOT CARRY
                || (FR[5]==1 && (la==11)) 						// OVERFLOW
                || (FR[5]==0 && (la==12)) 						// NOT OVERFLOW
                || (FR[6]==1 && (la==14)) 						// NEGATIVO
                || (FR[9]==1 && (la==13))) 						// DIVBYZERO
                 { pc = mem[pc];
								}
                else
                    pc++;
        break;

    case PUSH:
      if(!pega_pedaco(ir,6,6)) // Registrador
				mem[sp] = reg[rx];
      else  // FR
			{	temp = 0;
        for(i=16; i--; ) 		// Converte o vetor FR para int
					temp = temp + (int) (FR[i] * (pow(2.0,i)));
        mem[sp] = temp;
      }
      sp--;
      break;

    case POP:
      sp++;
      if(!pega_pedaco(ir,6,6))  // Registrador
				reg[rx] = mem[sp];
      else // FR
			{ for(i=16; i--; )				// Converte o int mem[sp] para o vetor FR
					FR[i] = pega_pedaco(mem[sp],i,i);
      }
      break;

    case CALL:
			la = pega_pedaco(ir,9,6);

			if( (la == 0) // NO COND
               || (FR[0]==1 && (la==7)) 							// GREATER
                || ((FR[2]==1 || FR[0]==1) && (la==9))  // GREATER EQUAL
                || (FR[1]==1 && (la==8)) 							// LESSER
                || ((FR[2]==1 || FR[1]==1) && (la==10)) // LESSER EQUAL
                || (FR[2]==1 && (la==1)) 							// EQUAL
                || (FR[2]==0 && (la==2)) // NOT EQUAL
                || (FR[3]==1 && (la==3)) // ZERO
                || (FR[3]==0 && (la==4)) // NOT ZERO
                || (FR[4]==1 && (la==5)) // CARRY
                || (FR[4]==0 && (la==6)) // NOT CARRY
                || (FR[5]==1 && (la==11)) // OVERFLOW
                || (FR[5]==0 && (la==12)) // NOT OVERFLOW
                || (FR[6]==1 && (la==14)) // NEGATIVO
                || (FR[9]==1 && (la==13))) { // DIVBYZERO
                    mem[sp] = pc;
                    sp--;
                    pc = mem[pc];
                    }
                else
                    pc++;
            break;

      case RTS:
      	sp++;
        pc = mem[sp];
        if(!pega_pedaco(ir,0,0)){
      		pc++;
        }
        else{
        	c0[1] = 0;
        }
        break;


      case ADD:
        reg[rx] = reg[ry] + reg[rz]; // Soma sem Carry

        if(pega_pedaco(ir,0,0))   // Soma com Carry
        	reg[rx] += FR[4];

				FR[3] = 0; 									// -- FR = <...|zero|equal|lesser|greater>
				FR[4] = 0;

        if(!reg[rx]) // Se resultado = 0, seta o Flag de Zero
					FR[3] = 1;
				else
        	if(reg[rx] > 0xffff)
					{ FR[4] = 1;  // Deu Carry
          	reg[rx] = reg[rx] - 0xffff;
        	}
        break;

      case SUB:
        reg[rx] = reg[ry] - reg[rz]; // Subtracao sem Carry

        if(pega_pedaco(ir,0,0)==1)  // Subtracao com Carry
      	  reg[rx] += FR[4];

				FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>
				FR[9] = 0;

        if(!reg[rx]) // Se resultado = 0, seta o Flag de Zero
					FR[3] = 1;
        else
        	if(reg[rx] < 0x0000)
					{ FR[9] = 1;  // Resultado e' Negativo
         	  reg[rx] = 0;
        	}
        break;

      case MULT:
        reg[rx] = reg[ry] * reg[rz]; // MULT sem Carry

        if(pega_pedaco(ir,0,0)==1)  // MULT com Carry
          reg[rx] += FR[4];

				FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>
				FR[5] = 0;

        if(!reg[rx])
					FR[3] = 1;  // Se resultado = 0, seta o Flag de Zero
        else
        	if(reg[rx] > 0xffff)
						FR[5] = 1;  // Arithmetic Overflow
        break;

      case DIV:
        if(!reg[rz])
				{ FR[6] = 1;  // Arithmetic Overflow
          reg[rx] = 0;
					FR[3] = 1;  // Se resultado = 0, seta o Flag de Zero
        }
        else
				{ FR[6] = 0;

          reg[rx] = reg[ry] / reg[rz]; // DIV sem Carry
          if(pega_pedaco(ir,0,0)==1)  // DIV com Carry
          	reg[rx] += FR[4];

					FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>
        	if(!reg[rx])
						FR[3] = 1;  // Se resultado = 0, seta o Flag de Zero
				}
        break;

      case LMOD:
        reg[rx] = reg[ry] % reg[rz];

				FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>

        if(!reg[rx])
					FR[3] = 1;  // Se resultado = 0, seta o Flag de Zero
				break;

      case INC:
				reg[rx]++;									// Inc Rx
        if(pega_pedaco(ir,6,6)!=0) // Dec Rx
          reg[rx] = reg[rx] - 2;

				FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>

        if(!reg[rx])
					FR[3] = 1;  // Se resultado = 0, seta o Flag de Zero
				break;

      case SHIFT:
				FR[3] = 0; // -- FR = <...|zero|equal|lesser|greater>

        if(!reg[rx])
					FR[3] = 1;  // Se resultado = 0, seta o Flag de Zero

				switch(pega_pedaco(ir,6,4))
        { case 0: reg[rx] = reg[rx] << pega_pedaco(ir,3,0);					break;
        	case 1: reg[rx] = ~((~(reg[rx]) << pega_pedaco(ir,3,0)));	break;
        	case 2: reg[rx] = reg[rx] >> pega_pedaco(ir,3,0);					break;
        	case 3: reg[rx] = ~((~(reg[rx]) >> pega_pedaco(ir,3,0)));	break;
					default:
        		if(pega_pedaco(ir,6,5)==2) // ROTATE LEFT
        		{  reg[rx] = _rotl(reg[rx],pega_pedaco(ir,3,0)); break; }
        	  reg[rx] = _rotr(reg[rx],pega_pedaco(ir,3,0)); break;
				}
        break;

      case SETC:
        FR[4] = pega_pedaco(ir,9,9);
        break;

      case HALT:		break;
      case NOP:			break;
      case BREAKP:	break;

			default:
				//printf("Default\n");
				//printf("Rx: %d	Ry: %d	Rz: %d\nPC: %d	IR: %d	opcode: %d\n\n", rx, ry, rz, pc, ir, opcode);
				break;
    }



	auxpc = pc;

	int ir2;

	// ----- Ciclo de Busca: --------
    ir2 = mem[pc];
	pc2 = pc + 1;

	// Case das instrucoes
	opcode = pega_pedaco(ir2,15,10);

	switch(opcode)
	{	case JMP:
			la = pega_pedaco(ir2,9,6);

			if((la == 0) // NO COND
                || (FR[0]==1 && (la==7)) 							// GREATER
                || (FR[2]==1 && FR[0]==1 && (la==9))  // GREATER EQUAL
                || (FR[1]==1 && (la==8)) 							// LESSER
                || (FR[2]==1 && FR[1]==1 && (la==10)) // LESSER EQUAL
                || (FR[2]==1 && (la==1)) 							// EQUAL
                || (FR[2]==0 && (la==2)) 							// NOT EQUAL
                || (FR[3]==1 && (la==3)) 							// ZERO
                || (FR[3]==0 && (la==4)) 							// NOT ZERO
                || (FR[4]==1 && (la==5)) 							// CARRY
                || (FR[4]==0 && (la==6)) 							// NOT CARRY
                || (FR[5]==1 && (la==11)) 						// OVERFLOW
                || (FR[5]==0 && (la==12)) 						// NOT OVERFLOW
                || (FR[6]==1 && (la==14)) 						// NEGATIVO
                || (FR[9]==1 && (la==13))) 						// DIVBYZERO
                    pc2 = mem[pc2];
                else
                    pc2++;
        break;

    case CALL:
			la = pega_pedaco(ir2,9,6);

			if( (la == 0) // NO COND
                || (FR[0]==1 && (la==7)) // GREATER
                || (FR[2]==1 && FR[0]==1 && (la==9)) // GREATER EQUAL
                || (FR[1]==1 && (la==8)) // LESSER
                || (FR[2]==1 && FR[1]==1 && (la==10)) // LESSER EQUAL
                || (FR[2]==1 && (la==1)) // EQUAL
                || (FR[2]==0 && (la==2)) // NOT EQUAL
                || (FR[3]==1 && (la==3)) // ZERO
                || (FR[3]==0 && (la==4)) // NOT ZERO
                || (FR[4]==1 && (la==5)) // CARRY
                || (FR[4]==0 && (la==6)) // NOT CARRY
                || (FR[5]==1 && (la==11)) // OVERFLOW
                || (FR[5]==0 && (la==12)) // NOT OVERFLOW
                || (FR[6]==1 && (la==14)) // NEGATIVO
                || (FR[9]==1 && (la==13))) { // DIVBYZERO
                    pc2 = mem[pc2];
                    }
                else
                    pc2++;
            break;

    	case RTS:
			pc2 = mem[sp+1];

        	if(!pega_pedaco(ir,0,0)){
				pc2++;
			}
			break;

		case STORE:
		case LOAD:
		case LOADIMED:
			pc2++;
			break;

		case BREAKP:
			controller->notifyProcessamento();
			controller->updateVideo();
			break;

		case HALT:
			controller->notifyProcessamento();
			controller->updateVideo();
			break;

		default: break;
   }
}
