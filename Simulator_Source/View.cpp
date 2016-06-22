#include "View.h"
#include <iostream>

ControllerInterface* View::controller = NULL;
GtkWidget** View::TextEntryRegs = new GtkWidget*[8];

GtkWidget* View::labelR = NULL;

int line2_instruction[TAM] = { STORE, LOAD, LOADIMED, JMP, CALL };

using namespace std;

View::View(Model *model, ControllerInterface *controller)
{	this->model = model;
	View::controller = controller;

	// adiciona o view como observador
	model->registraRegistrador(this);
	model->registraInstrucoes(this);

	cpuram = model->getCpuram();

	// cria a GUI
	criaJanela("Simulador");
	GtkWidget *menubar = gtk_menu_bar_new();
	GtkWidget *vbox = gtk_vbox_new(0, 0);//gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	GtkWidget *hbox = gtk_hbox_new(0, 0);//gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

	criaFile(menubar);
	criaEditar(menubar);

	gtk_container_add(GTK_CONTAINER(vbox), menubar);

	criarLabelsSuperior(vbox);
	criarAreaTexto(hbox);
	criarAreaVisualizacao(hbox);
	gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);
	criarLabelsInferior(vbox);

  	gtk_container_add(GTK_CONTAINER(window), vbox);

	gtk_widget_show_all(window);

}


View::~View()
{ delete View::TextEntryRegs;
}


// ----- Registradores -----
void View::updatePC()
{	pc = model->getPC();

	sprintf(textoLabelPC, "PC: %05d", pc);
	gtk_label_set_text(GTK_LABEL (labelPc), textoLabelPC);
}

void View::updateIR()
{	ir = model->getIR();

	sprintf(textoLabelIR, "IR: %05d", ir);
	gtk_label_set_text(GTK_LABEL (labelIr), textoLabelIR);
}

void View::updateSP()
{	sp = model->getSP();

	sprintf(textoLabelSP, "SP: %05d", sp);
	gtk_label_set_text(GTK_LABEL (labelSp), textoLabelSP);
}

void View::updateFR()
{	for(int i=16; i--; )
		FR[i] = model->getFR(i);

	char texto[32];

	sprintf(texto, "FR: %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", FR[15], FR[14], FR[13], FR[12], FR[11], FR[10], FR[9], FR[8], FR[7], FR[6], FR[5], FR[4], FR[3], FR[2], FR[1], FR[0]);
	gtk_label_set_text(GTK_LABEL (labelFR), texto);
}

void View::updateC0()
{	for(int i=16; i--; )
		c0[i] = model->getC0(i);

	char texto[32];

	sprintf(texto, "C0: %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", c0[15], c0[14], c0[13], c0[12], c0[11], c0[10], c0[9], c0[8], c0[7], c0[6], c0[5], c0[4], c0[3], c0[2], c0[1], c0[0]);
	gtk_label_set_text(GTK_LABEL (labelC0), texto);
}

void View::updateIRQ()
{	for(int i=16; i--; )
		IRQ[i] = model->getIRQ(i);

	char texto[32];

	sprintf(texto, "IRQ: %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", IRQ[15], IRQ[14], IRQ[13], IRQ[12], IRQ[11], IRQ[10], IRQ[9], IRQ[8], IRQ[7], IRQ[6], IRQ[5], IRQ[4], IRQ[3], IRQ[2], IRQ[1], IRQ[0]);
	gtk_label_set_text(GTK_LABEL (labelIRQ), texto);
}
void View::updateRegistradores()
{	char texto[6];
	char opt[5];

	if(controller->getHex())
		strcpy(opt, "%05X");
	else
		strcpy(opt, "%05d");

	for(int i=8; i--; )
	{	reg[i] = model->getRegistrador(i);	// atualiza o valor dos registradores

		sprintf(texto, opt, reg[i]);				// formata o valor para decimal ou hexadecimal

		gtk_entry_set_text(GTK_ENTRY(TextEntryRegs[i]), texto);	// atualiza o display dos registradores
	}
}


// -------- Video --------
void View::updateVideo(int pos)
{	//gtk_widget_queue_draw(outputarea);
	static int r = 0;
	gtk_widget_queue_draw_area(outputarea, 0,0,640,480);
	r=(r+1)%30;
}

void View::_setColor(cairo_t *cr, int color, int palette){
	double R = 0.0, G = 0.0, B = 0.0;
	auto p = model->Vid.getPalette();
	auto c = p[palette << 2 | color];
	B = c.blue/(double)32;
	G = c.green/(double)32;
	R = c.red/(double)32;
	cairo_set_source_rgb(cr, R, G, B);
}

void View::_draw_pixmap(cairo_t *cr, int sprite, int palette, int x, int y, int v, int h)
{
	int i, j;
	auto sprites = model->Vid.getSprites();

	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			int cor = ((sprites[sprite].p[i])>>j&1)*2 + ((sprites[sprite].p[i]>>(j+8))&1);
			int indexX = (8-j+x)*2;
			int indexY = (i+y)*2;
			if(v && !h){
				indexX = (j+x)*2;
			}else if(h && !v){
				indexY = (8-i+y)*2;

			}else if(v && h){
				indexX = (j+x)*2;
				indexY = (8-i+y)*2;
			}
			if(cor){
				_setColor(cr, cor, palette);
		  		cairo_rectangle(cr, indexX, indexY, 2, 2);
	      		cairo_fill(cr);
			}
  	}
	}
}


// ----- Instrucoes -------
void View::updateInstrucoes(unsigned int atual, unsigned int proxima, unsigned int linhas)
{ Imprime(atual, proxima, linhas); }

void View::escrever_na_tela(const char *string, int linha, int size)
{ if(gtk_text_buffer_get_line_count(buffer) < linha)
	{	g_print("Erro tentou escrever na linha %d e o maximo é %d\n", linha, gtk_text_buffer_get_line_count(buffer));
		return;
	}

	GtkTextIter iterInicio, iterFim;

	gtk_text_buffer_get_iter_at_line(buffer, &iterInicio, linha);
	gtk_text_buffer_get_iter_at_line(buffer, &iterFim, linha);
	gtk_text_iter_forward_to_line_end (&iterFim);

	gtk_text_buffer_delete(buffer, &iterInicio, &iterFim);

  gtk_text_buffer_insert (buffer, &iterInicio, string, strlen(string));

	gtk_text_buffer_get_iter_at_line(buffer, &iterInicio, linha);
	gtk_text_buffer_get_iter_at_line(buffer, &iterFim, linha);
	gtk_text_iter_forward_to_line_end (&iterFim);

	if(size)
  {	gtk_text_buffer_apply_tag_by_name (buffer, "Fonte", &iterInicio, &iterFim);
		return;
	}
	gtk_text_buffer_apply_tag_by_name (buffer, "Fonte2", &iterInicio, &iterFim);
}

void View::Imprime(unsigned int atual, unsigned int proxima, unsigned int linhas)
{	unsigned int i, k;
	unsigned int temp;

	show_program(1, atual, sp);
	show_program(3, proxima, sp);
	for(i=0; i<linhas; i++)
	{ temp = 1;
		 for(k=0; k<TAM; k++)
		 { if(model->pega_pedaco(model->getMem(proxima),15,10) == line2_instruction[k])
		   	temp = 2;
		 }
		 proxima = proxima + temp;
		 show_program(i+4,proxima,sp);
	}
}

void View::show_program(int linha, int pc, int sp)
{ unsigned int ir = model->getMem(pc),
							_rx = model->pega_pedaco(ir,9,7),
							_ry = model->pega_pedaco(ir,6,4),
							_rz = model->pega_pedaco(ir,3,1);

	char texto[128];

  switch(model->pega_pedaco(ir,15,10))
	{ case INCHAR: 	sprintf(texto, "PC: %05d\t|	IN  R%d, R%d	|	R%d      <- bus[R%d]", 			pc, _rx,_ry, _rx,_ry);		 			 break;
	  case OUTCHAR:	sprintf(texto, "PC: %05d\t|	OUT R%d, R%d	|	bus[R%d] <- R%d", pc, _rx, _ry, _ry, _rx); break;
	  case EI:
	  	switch(model->pega_pedaco(ir,0,0)){
	  		case 1:
	  			sprintf(texto, "PC: %05d\t|	EI			|	C0[0] <= 1", pc); break;
	  		default:
	  			sprintf(texto, "PC: %05d\t|	DI			|	C0[0] <= 0", pc); break;
	  	}
	  	break;
    case MOV:
			switch(model->pega_pedaco(ir,1,0))
			{	case 0:  sprintf(texto,"PC: %05d\t|	MOV R%d, R%d			|	R%d <- R%d", 	pc, _rx, _ry, _rx, _ry); break;
				case 1:  sprintf(texto,"PC: %05d\t|	MOV R%d, SP				|	R%d <- SP", 	pc, _rx, _rx); 				   break;
				default: sprintf(texto,"PC: %05d\t|	MOV SP, R%d				|	SP  <- R%d", 	pc, _rx, _rx);					 break;
			}
			break;

    case STORE:				sprintf(texto,"PC: %05d\t|	STORE %05d, R%d	|	MEM[%d] <- R%d", 		pc, model->getMem(pc+1), _rx, model->getMem(pc+1), _rx); break;
    case STOREINDEX: 	sprintf(texto,"PC: %05d\t|	STOREI R%d, R%d		|	MEM[R%d] <- R%d", pc, _rx, _ry, _rx, _ry); 						 break;

    case LOAD: 			sprintf(texto,"PC: %05d\t|	LOAD R%d, %05d		|	R%d <- MEM[%d]", 	pc, _rx, model->getMem(pc+1), _rx, model->getMem(pc+1)); 	break;
    case LOADIMED: 	sprintf(texto,"PC: %05d\t|	LOADN R%d, #%05d	|	R%d <- #%d", 			pc, _rx, model->getMem(pc+1), _rx, model->getMem(pc+1)); 	break;
    case LOADINDEX:	sprintf(texto,"PC: %05d\t|	LOADI R%d, R%d		|	R%d <- MEM[R%d]", pc, _rx, _ry, _rx, _ry); 							break;

    case LAND: sprintf(texto,"PC: %05d\t|	AND R%d, R%d, R%d		|	R%d <- R%d and R%d", 	pc, _rx, _ry, _rz, _rx, _ry, _rz);	break;
    case LOR:	 sprintf(texto,"PC: %05d\t|	OR R%d, R%d, R%d		|	R%d <- R%d or R%d", 	pc, _rx, _ry, _rz, _rx, _ry, _rz); 	break;
    case LXOR: sprintf(texto,"PC: %05d\t|	XOR R%d, R%d, R%d		|	R%d <- R%d xor R%d", 	pc, _rx, _ry, _rz, _rx, _ry, _rz);  break;
    case LNOT: sprintf(texto,"PC: %05d\t|	NOT R%d, R%d			|	R%d <- R%d", 						pc, _rx, _ry, _rx, _ry); 						break;

    case CMP:	sprintf(texto,"PC: %05d\t|	CMP R%d, R%d			|	FR <- <eq|le|gr>", 			pc, _rx, _ry); break;

    case JMP:
			switch(model->pega_pedaco(ir,9,6))
			{ case 0:	 sprintf(texto, "PC: %05d\t|	JMP #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 1:	 sprintf(texto, "PC: %05d\t|	JEQ #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 2:	 sprintf(texto, "PC: %05d\t|	JNE #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 3:  sprintf(texto, "PC: %05d\t|	JZ  #%05d			|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 4:  sprintf(texto, "PC: %05d\t|	JNZ #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 5:  sprintf(texto, "PC: %05d\t|	JC  #%05d			|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 6:  sprintf(texto, "PC: %05d\t|	JNC #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 7:  sprintf(texto, "PC: %05d\t|	JGR #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 8:  sprintf(texto, "PC: %05d\t|	JLE #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 9:  sprintf(texto, "PC: %05d\t|	JEG #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 10: sprintf(texto, "PC: %05d\t|	JEL #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 11: sprintf(texto, "PC: %05d\t|	JOV #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 12: sprintf(texto, "PC: %05d\t|	JNO #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 13: sprintf(texto, "PC: %05d\t|	JDZ #%05d 		|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				case 14: sprintf(texto, "PC: %05d\t|	JN  #%05d			|	PC <- #%05d", pc, model->getMem(pc+1), model->getMem(pc+1)); break;
				default: printf("Erro. Instrucao inesperada em show_program"); break;
			}
			break;

    case PUSH:
    	if(!model->pega_pedaco(ir,6,6)) // Registrador
			{ sprintf(texto, "PC: %05d\t|	PUSH R%d			|	MEM[%d] <- R%d]", pc, _rx, sp, _rx);
				break;
			}
			sprintf(texto, "PC: %05d\t|	PUSH FR			|	MEM[%d] <- FR]", pc, sp); // FR
      break;

    case POP:
    	if(!model->pega_pedaco(ir,6,6))  // Registrador
			{ sprintf(texto, "PC: %05d\t|	POP R%d				|	R%d <- MEM[%d]", pc, _rx, _rx, sp);
				break;
			}
			sprintf(texto, "PC: %05d\t|	POP FR			|	FR <- MEM[%d]", pc, sp); // FR
      break;

    case CALL:
			switch(model->pega_pedaco(ir,9,6))
			{ case 0:  sprintf(texto, "PC: %05d\t|	CALL #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 1:  sprintf(texto, "PC: %05d\t|	CEQ #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 2:  sprintf(texto, "PC: %05d\t|	CNE #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 3:  sprintf(texto, "PC: %05d\t|	CZ #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 4:  sprintf(texto, "PC: %05d\t|	CNZ #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 5:  sprintf(texto, "PC: %05d\t|	CC #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 6:  sprintf(texto, "PC: %05d\t|	CNC #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 7:  sprintf(texto, "PC: %05d\t|	CGR #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 8:  sprintf(texto, "PC: %05d\t|	CLE #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 9:  sprintf(texto, "PC: %05d\t|	CEG #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1)); break;
				case 10: sprintf(texto, "PC: %05d\t|	CEL #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1));	break;
				case 11: sprintf(texto, "PC: %05d\t|	COV #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1));	break;
				case 12: sprintf(texto, "PC: %05d\t|	CNO #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1));	break;
				case 13: sprintf(texto, "PC: %05d\t|	CDZ #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1));	break;
				case 14: sprintf(texto, "PC: %05d\t|	CN #%05d\t\t|	M[%d]<-PC; SP--; PC<-#%05d", pc, model->getMem(pc+1), sp, model->getMem(pc+1));	break;
				default: printf("Erro. Linha inesperada show_program"); break;
			}
			break;

    case RTS:  sprintf(texto, "PC: %05d\t|	RTS				|	SP++; PC <- MEM[%d]; PC++", pc, sp); break;

    case ADD:	 sprintf(texto, "PC: %05d\t|	ADD R%d, R%d, R%d		|	R%d <- R%d + R%d", 		pc, _rx, _ry, _rz, _rx, _ry, _rz); break;
    case SUB:  sprintf(texto, "PC: %05d\t|	SUB R%d, R%d, R%d		|	R%d <- R%d - R%d", 		pc, _rx, _ry, _rz, _rx, _ry, _rz); break;
    case MULT: sprintf(texto, "PC: %05d\t|	MULT R%d, R%d, R%d		|	R%d <- R%d * R%d", 	pc, _rx, _ry, _rz, _rx, _ry, _rz); break;
    case DIV:	 sprintf(texto, "PC: %05d\t|	DIV R%d, R%d, R%d		|	R%d <- R%d / R%d", 		pc, _rx, _ry, _rz, _rx, _ry, _rz); break;
    case LMOD: sprintf(texto, "PC: %05d\t|	MOD R%d, R%d, R%d		|	R%d <- R%d %% R%d", 	pc, _rx, _ry, _rz, _rx, _ry, _rz); break;
    case INC:
    	if(!model->pega_pedaco(ir,6,6))  // Inc Rx
			{ sprintf(texto, "PC: %05d\t|	INC R%d				|	R%d <- R%d + 1", pc, _rx, _rx, _rx);
				break;
			}
			sprintf(texto, "PC: %05d\t|	DEC R%d				|	R%d <- R%d - 1", pc, _rx, _rx, _rx);// Dec Rx
      break;

    case SHIFT:     // Nao tive paciencia de fazer diferente para cada SHIFT/ROT
			switch(model->pega_pedaco(ir,6,4))
			{ case 0: sprintf(texto, "PC: %05d\t|	SHIFTL0 R%d, #%02d		|	R%d <-'0'  << %d", pc, _rx, model->pega_pedaco(ir,3,0), _rx, model->pega_pedaco(ir,3,0)); break;
				case 1: sprintf(texto, "PC: %05d\t|	SHIFTL1 R%d, #%02d		|	R%d <-'1'  << %d", pc, _rx, model->pega_pedaco(ir,3,0), _rx, model->pega_pedaco(ir,3,0));	break;
				case 2: sprintf(texto, "PC: %05d\t|	SHIFTR0 R%d, #%02d		|	'0'-> R%d   >> %d", pc, _rx, model->pega_pedaco(ir,3,0), _rx, model->pega_pedaco(ir,3,0));break;
				case 3: sprintf(texto, "PC: %05d\t|	SHIFTR1 R%d, #%02d		|	'1'-> R%d   >> %d", pc, _rx, model->pega_pedaco(ir,3,0), _rx, model->pega_pedaco(ir,3,0));break;
				default:
        	if(model->pega_pedaco(ir,6,5) == 2) // ROTATE LEFT
          { sprintf(texto, "PC: %05d\t|	ROTL R%d, #%02d	|	R%d <- R%d   << %d", pc, _rx, model->pega_pedaco(ir,3,0), _rx,_rx, model->pega_pedaco(ir,3,0));
						break;
					}
					sprintf(texto, "PC: %05d\t|	ROTR R%d, #%02d	|	R%d -> R%d   >> %d", pc, _rx, model->pega_pedaco(ir,3,0), _rx,_rx, model->pega_pedaco(ir,3,0)); break;
			}
			break;

    case SETC: sprintf(texto, "PC: %05d\t|	SETC				|	C <- %d", pc, model->pega_pedaco(ir,9,9)); break;

    case HALT: sprintf(texto, "PC: %05d\t|	HALT				|	Pausa a execucao", pc); break;

    case NOP:	sprintf(texto, "PC: %05d\t|	NOOP %x				|	Do nothing", pc, model->getMem(pc)); break;

    case BREAKP: sprintf(texto, "PC: %05d\t|	BREAKP #%05d		|	Break Point", pc, model->pega_pedaco(ir,9,0)); break;

		default:
			cout << "ERRO - show program linha: " << linha << " pc " << pc << endl;
			break;
  }

	escrever_na_tela(texto, linha, 1);
}

// interface grafica

void View::criaJanela(const char *nome)
{ if(nome == NULL) return;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_widget_set_size_request(window, 1024, -1);
	gtk_window_set_resizable(GTK_WINDOW(window), true);

	gtk_window_set_decorated(GTK_WINDOW(window), TRUE);

	gtk_window_set_title(GTK_WINDOW(window), nome);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK(destroy), NULL);
	g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK(teclado), NULL);
}

GtkWidget* View::criaMenu()
{ GtkWidget *menubar = gtk_menu_bar_new();
	return menubar;
}

void View::criaFile(GtkWidget *menubar)
{ GtkWidget *filemenu = gtk_menu_new(),
						*file 		= gtk_menu_item_new_with_label("Arquivo"),
						*quit 		= gtk_menu_item_new_with_label("Sair");

	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);

	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);

	g_signal_connect(quit, "activate", G_CALLBACK(destroy), NULL);
}

void View::criaEditar(GtkWidget *menubar)
{	// Botao da barra de ferramentas
	GtkWidget *edit = gtk_menu_item_new_with_label("Editar"),
						*editMenu = gtk_menu_new();

	gtk_menu_shell_append (GTK_MENU_SHELL (menubar), 	edit);
	gtk_menu_item_set_submenu (GTK_MENU_ITEM (edit), editMenu);

	// Botoes do scroll do editar:

	// ------ Botao decimal para hexa ------
	GtkWidget *registradores = gtk_menu_item_new_with_label("Registradores"),
						*registradoresMenu = gtk_menu_new();

	GtkWidget *registradorDec = gtk_radio_menu_item_new_with_label(NULL, "Decimal"),
						*registradorHex = gtk_radio_menu_item_new_with_label_from_widget(GTK_RADIO_MENU_ITEM (registradorDec), "Hexadecimal");

	gtk_menu_shell_append(GTK_MENU_SHELL (editMenu), registradores);

	gtk_menu_item_set_submenu (GTK_MENU_ITEM (registradores), registradoresMenu);

	gtk_menu_shell_append (GTK_MENU_SHELL (registradoresMenu), registradorDec);
	gtk_menu_shell_append (GTK_MENU_SHELL (registradoresMenu), registradorHex);

	g_signal_connect(registradorDec, "activate", G_CALLBACK(PressionaBotaoRegistradorDec), NULL);
	g_signal_connect(registradorHex, "activate", G_CALLBACK(PressionaBotaoRegistradorHex), NULL);

	// ------- Botao reset -------------
	GtkWidget *resetVideo = gtk_menu_item_new_with_label("Reset Vídeo"),
						*resetMenu = gtk_menu_new();

	GtkWidget *resetComTela = gtk_radio_menu_item_new_with_label(NULL, "Sim"),
						*resetSemTela = gtk_radio_menu_item_new_with_label_from_widget(GTK_RADIO_MENU_ITEM (resetComTela), "Não");


	gtk_menu_shell_append(GTK_MENU_SHELL (editMenu), resetVideo);

	gtk_menu_item_set_submenu (GTK_MENU_ITEM (resetVideo), resetMenu);

	gtk_menu_shell_append (GTK_MENU_SHELL (resetMenu), resetSemTela);
	gtk_menu_shell_append (GTK_MENU_SHELL (resetMenu), resetComTela);

	g_signal_connect(resetSemTela, "activate", G_CALLBACK(PressionaBotaoResetVideoNao), labelR);
	g_signal_connect(resetComTela, "activate", G_CALLBACK(PressionaBotaoResetVideoSim), labelR);


	// ------ Botao Velocidade ---------
	GtkWidget	*velocidade = gtk_menu_item_new_with_label("Velocidade"),
						*velocidadeMenu = gtk_menu_new();

	GtkWidget	*velocidadeMedia 					= gtk_radio_menu_item_new_with_label(NULL, "Média"),
						*velocidadeMuitoRapida 		= gtk_radio_menu_item_new_with_label_from_widget(GTK_RADIO_MENU_ITEM (velocidadeMedia), "Muito Rápida"),
						*velocidadeRapida 				= gtk_radio_menu_item_new_with_label_from_widget(GTK_RADIO_MENU_ITEM (velocidadeMedia), "Rápida"),
						*velocidadeLenta 					= gtk_radio_menu_item_new_with_label_from_widget(GTK_RADIO_MENU_ITEM (velocidadeMedia), "Lenta"),
						*velocidadeMuitoLenta 		= gtk_radio_menu_item_new_with_label_from_widget(GTK_RADIO_MENU_ITEM (velocidadeMedia), "Muito Lenta");

	gtk_menu_shell_append (GTK_MENU_SHELL (editMenu), velocidade);

	gtk_menu_item_set_submenu (GTK_MENU_ITEM (velocidade), velocidadeMenu);

	gtk_menu_shell_append (GTK_MENU_SHELL (velocidadeMenu), velocidadeMuitoRapida);
	gtk_menu_shell_append (GTK_MENU_SHELL (velocidadeMenu), velocidadeRapida);
	gtk_menu_shell_append (GTK_MENU_SHELL (velocidadeMenu), velocidadeMedia);
	gtk_menu_shell_append (GTK_MENU_SHELL (velocidadeMenu), velocidadeLenta);
	gtk_menu_shell_append (GTK_MENU_SHELL (velocidadeMenu), velocidadeMuitoLenta);

	g_signal_connect(velocidadeMuitoRapida, "activate", G_CALLBACK(PressionaVelocidadeMuitoRapida), NULL);
	g_signal_connect(velocidadeRapida, 			"activate", G_CALLBACK(PressionaVelocidadeRapida)			, NULL);
	g_signal_connect(velocidadeMedia, 			"activate", G_CALLBACK(PressionaVelocidadeMedia)			, NULL);
	g_signal_connect(velocidadeLenta, 			"activate", G_CALLBACK(PressionaVelocidadeLenta)			, NULL);
	g_signal_connect(velocidadeMuitoLenta, 	"activate", G_CALLBACK(PressionaVelocidadeMuitoLenta)	, NULL);
}

void View::criarLabelsSuperior(GtkWidget *vbox)
{ GtkWidget *fixed = gtk_fixed_new ();

	unsigned int i;
	char linha[128];

	for(i=8; i--; )
	{ sprintf(linha, "R%d:", i);
		labelReg[i] = gtk_label_new(linha);
		TextEntryRegs[i] = gtk_entry_new();
		gtk_entry_set_width_chars( GTK_ENTRY(TextEntryRegs[i]) , 5);
		gtk_fixed_put (GTK_FIXED (fixed), labelReg[i], 10+i*80, 10);
		gtk_fixed_put (GTK_FIXED (fixed), TextEntryRegs[i], 30+i*80, 5);
		gtk_entry_set_max_length(GTK_ENTRY(TextEntryRegs[i]), 5);
		gtk_editable_set_editable(GTK_EDITABLE(TextEntryRegs[i]), TRUE);
	}

	labelIr = gtk_label_new ("IR: 00000");
	gtk_fixed_put (GTK_FIXED (fixed), labelIr, 650, 10);

	labelSp = gtk_label_new ("SP: 00000");
	gtk_fixed_put (GTK_FIXED (fixed), labelSp, 720, 10);

	labelPc = gtk_label_new ("PC: 00000");
	gtk_fixed_put (GTK_FIXED (fixed), labelPc, 790, 10);

	labelFR = gtk_label_new ("FR: 0000000000000000");
	gtk_fixed_put (GTK_FIXED (fixed), labelFR, 10, 40);

	labelC0 = gtk_label_new ("C0: 0000000000000000");
	gtk_fixed_put (GTK_FIXED (fixed), labelC0, 160, 40);


	labelIRQ = gtk_label_new ("IRQ: 0000000000000000");
	gtk_fixed_put (GTK_FIXED (fixed), labelIRQ, 310, 40);

	gtk_box_pack_start (GTK_BOX (vbox), fixed, false, TRUE, 0);
}

void View::criarLabelsInferior(GtkWidget *vbox)
{ GtkWidget *fixed = gtk_fixed_new();

	labelCPURAM 	= gtk_label_new (cpuram);
	gtk_fixed_put(GTK_FIXED (fixed), labelCPURAM, 40, 0);		// 40

	labelP 		= gtk_label_new("Pressione Home para modo Automático");
	labelEnd 	= gtk_label_new("Pressione End para passo a passo");
	labelR		= gtk_label_new("Pressione Insert para resetar o simulador (com vídeo)");

	gtk_fixed_put(GTK_FIXED (fixed), labelP, 430, 0);
	gtk_fixed_put(GTK_FIXED (fixed), labelEnd, 710, 0);
	gtk_fixed_put(GTK_FIXED (fixed), labelR, 430, 20);

	gtk_box_pack_start (GTK_BOX (vbox), fixed, false, TRUE, 0);
}

void View::criarAreaVisualizacao(GtkWidget *hbox)
{ GtkWidget *outputframe = gtk_frame_new("Viewport");

	outputarea = gtk_drawing_area_new();
	gtk_widget_set_size_request(outputarea , 640, 480);

	gtk_container_add(GTK_CONTAINER(outputframe), outputarea);
	gtk_box_pack_start (GTK_BOX (hbox), outputframe, false, TRUE, 0);

	g_signal_connect (G_OBJECT (outputarea), "expose_event", G_CALLBACK(ViewerExpose), this);
}

void View::criarAreaTexto(GtkWidget *hbox)
{ GtkWidget *textview = gtk_text_view_new();

	GtkTextIter iter;
	GtkTextMark *mark;

	gtk_widget_set_size_request(textview, 374, 487);
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));

	for(int i = N_LINHAS + 3; i--; )
	{	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (textview));
		mark = gtk_text_buffer_get_insert(buffer);
		gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
		gtk_text_buffer_insert(buffer, &iter, "\n \0", -1);
	}
  gtk_text_buffer_create_tag(buffer, "Fonte", "scale", PANGO_SCALE_SMALL, NULL );
  gtk_text_buffer_create_tag(buffer, "Fonte2", "scale", PANGO_SCALE_MEDIUM, NULL );
	escrever_na_tela("Linha		|	Instrução			|	Ação", 0, 1);

	GtkWidget *frameMemoria = gtk_frame_new("Memória");

  gtk_container_add(GTK_CONTAINER(frameMemoria), textview);
	gtk_box_pack_start(GTK_BOX (hbox), frameMemoria, false, TRUE, 0);

	gtk_text_view_set_editable(GTK_TEXT_VIEW(textview), FALSE);
}

gboolean View::teclado(GtkWidget *widget, GdkEventKey *event, gpointer data)
{	char tecla[32];
	guint keyval;

	keyval = event->keyval;

	strcpy(tecla, gdk_keyval_name (event->keyval) );

	if (keyval <= 127)
	{
		tecla[0] = ((char*)&keyval)[0];
		tecla[1] = 0;
	}
	controller->userInput(tecla);
	return FALSE;
}

void View::destroy (GtkWidget *window, gpointer data)
{ gtk_main_quit(); }

GtkWidget** View::getRegistradores()
{	return TextEntryRegs;	}

void View::PressionaBotaoRegistradorDec(GtkWidget *widget)
{	controller->setRegistradorHex(false);	}

void View::PressionaBotaoRegistradorHex(GtkWidget *widget)
{	controller->setRegistradorHex(true);	}

void View::PressionaBotaoResetVideoSim(GtkWidget *widget)
{ controller->setResetVideo(true);

	gtk_label_set_text(GTK_LABEL(labelR), "Pressione Insert para resetar o simulador (com vídeo)"); // <--------
}

void View::PressionaBotaoResetVideoNao(GtkWidget *widget)
{ controller->setResetVideo(false);

	gtk_label_set_text(GTK_LABEL(labelR), "Pressione Insert para resetar o simulador (sem vídeo)"); // <--------
}

void View::PressionaVelocidadeMuitoRapida()	{ controller->setDelay(MUITO_RAPIDA); }
void View::PressionaVelocidadeRapida()			{ controller->setDelay(RAPIDA); }
void View::PressionaVelocidadeMedia()				{ controller->setDelay(MEDIA); }
void View::PressionaVelocidadeLenta()				{ controller->setDelay(LENTA); }
void View::PressionaVelocidadeMuitoLenta()	{ controller->setDelay(MUITO_LENTA); }

void View::TravaRegs()
{	gtk_label_set_text(GTK_LABEL(labelEnd), " "); // <--------
	gtk_label_set_text(GTK_LABEL(labelP), "Pressione Home para modo Manual"); // <--------

	for(int i=8; i--; )
		gtk_editable_set_editable(GTK_EDITABLE(TextEntryRegs[i]), FALSE);
}

void View::DestravaRegs()
{	gtk_label_set_text(GTK_LABEL(labelEnd), "Pressione End para passo a passo"); // <--------
	gtk_label_set_text(GTK_LABEL(labelP), "Pressione Home para modo Automático"); // <--------

	for(int i=8; i--; )
		gtk_editable_set_editable(GTK_EDITABLE(TextEntryRegs[i]), TRUE);
}

gboolean View::ViewerExpose(GtkWidget *widget, GdkEventExpose *event, gpointer data)
{	View *vi = (View*) data;

	cairo_t *cr = gdk_cairo_create(vi->outputarea->window);

  	cairo_set_source_rgb(cr, 0, 0, 0);
  	cairo_paint(cr);

  	auto bg = vi->model->Vid.getBG();

  	for(int i=1200; i--;)
	{
		vi->_draw_pixmap(cr, bg[i].c, bg[i].p, 8*(i%40), 8*(i/40), bg[i].v, bg[i].h);
	}

	auto oam = vi->model->Vid.getOAM();
//
	for(int i=128; i--; )
	{
		vi->_draw_pixmap(cr, oam[i].c, oam[i].p, oam[i].x, oam[i].y, oam[i].v, oam[i].h);
	}

  	cairo_destroy(cr);

	return FALSE;
}
