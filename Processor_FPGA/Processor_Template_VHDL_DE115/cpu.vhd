-- Processador Versao 3: 23/05/2013
-- Jeg e Ceg  concertado!!
-- Video com 16 cores e tela de 40 colunas por 30 linhas

libraRY ieee;
use ieee.std_LOGIC_1164.all;
use ieee.std_LOGIC_ARITH.all;
use ieee.std_LOGIC_unsigned.all;

entity cpu is
	port( clk			: in	std_LOGIC;
			reset			: in	std_LOGIC;

			Mem			: in	STD_LOGIC_VECTOR(15 downto 0);
			M5				: out STD_LOGIC_VECTOR(15 downto 0);
			M1				: out STD_LOGIC_VECTOR(15 downto 0);
			RW				: out std_LOGIC;
			
			bus_data		: inout STD_LOGIC_VECTOR(15 downto 0);
			bus_addr		: out	std_LOGIC_VECTOR(15 downto 0);
			bus_rw		: out std_LOGIC;
			bus_req		: out std_LOGIC;
			bus_ack		: in std_LOGIC;
			irq			: in std_LOGIC_VECTOR(15 downto 0);
			
			Ponto			: out STD_LOGIC_VECTOR(3 downto 0);
			
			halt_ack		: out	std_LOGIC;
			halt_req		: in	std_LOGIC;
			
			PC_data		: out STD_LOGIC_VECTOR(15 downto 0);
			break 		: out STD_LOGIC;
			
			boot_mem		: in std_logic_vector(15 downto 0)
		);
end cpu;

ARCHITECTURE main of cpu is

	TYPE STATES				is (fetch, decode, exec, int, intExec, halted);		-- Estados da Maquina de Controle do Processador
	TYPE Registers			is array(0 to 7) of STD_LOGIC_VECTOR(15 downto 0); -- Banco de Registradores
	TYPE LoadRegisters	is array(0 to 7) of std_LOGIC;							-- Sinais de LOAD dos Registradores do Banco

	-- INSTRUCTION SET: 29 INSTRUCTIONS
	-- Data Manipulation Instructions:												-- Usage		    -- Action     	-- Format	
	CONSTANT LOAD			: STD_LOGIC_VECTOR(5 downto 0) := "110000";		-- LOAD RX END  -- RX <- M[END]  Format: < inst(6) | RX(3) | xxxxxxx >  + 16bit END
	CONSTANT STORE			: STD_LOGIC_VECTOR(5 downto 0) := "110001";		-- STORE END RX -- M[END] <- RX  Format: < inst(6) | RX(3) | xxxxxxx >  + 16bit END
	CONSTANT LOADIMED		: STD_LOGIC_VECTOR(5 downto 0) := "111000";		-- LOADN RX Nr   -- RX <- Nr    	Format: < inst(6) | RX(3) | xxxxxxb0 >  + 16bit Numero
	CONSTANT LOADINDEX	: STD_LOGIC_VECTOR(5 downto 0) := "111100";		-- LOADI RX RY   -- RX <- M[RY]	Format: < inst(6) | RX(3) | RY(3) | xxxx >
	CONSTANT STOREINDEX	: STD_LOGIC_VECTOR(5 downto 0) := "111101";		-- STOREI RX RY  -- M[RX] <- RY	Format: < inst(6) | RX(3) | RY(3) | xxxx >
	CONSTANT MOV			: STD_LOGIC_VECTOR(5 downto 0) := "110011";		-- MOV RX RY    -- RX <- RY	  	Format: < inst(6) | RX(3) | RY(3) | xx | x0 >
																								-- MOV RX SP    RX <- SP         Format: < inst(6) | RX(3) | xxx | xx | 01 >
																								-- MOV SP RX    SP <- RX         Format: < inst(6) | RX(3) | xxx | xx | 11 >
	
	-- I/O Instructions:
	CONSTANT OUTWORD		: STD_LOGIC_VECTOR(5 downto 0) := "110010";		-- OUT RX RY -- bus[RY] <- RX		Format: < inst(6) | RX(3) | RY(3) | xxxx > 																						
	CONSTANT INWORD		: STD_LOGIC_VECTOR(5 downto 0) := "110101";		-- IN RX RY  -- RY <- bus[RX]	RX[15..6] <- 0's  	Format: < inst(6) | RX(3) | RY(3) | xxxx >
	CONSTANT EI				: STD_logic_vector(5 downto 0) := "110111";		-- EI			 -- CR0(10) <- 1;		Format: < inst(6) xxxxxxxxx | 1>
--	CONSTANT DI				: STD_logic_vector(5 downto 0) := "110111";		-- DI			 -- CR0(10) <- 0;		Format: < inst(6) xxxxxxxxx | 0>
	
	CONSTANT ARITH			: STD_LOGIC_VECTOR(1 downto 0) := "10";
	-- Aritmethic Instructions(All should begin wiht "10"):	
	CONSTANT ADD 			: STD_LOGIC_VECTOR(3 downto 0) := "0000";			-- ADD RX RY RZ / ADDC RX RY RZ  	-- RX <- RY + RZ / RX <- RY + RZ + C  	-- b0=CarRY	  			Format: < inst(6) | RX(3) | RY(3) | RZ(3)| C >
	CONSTANT SUB 			: STD_LOGIC_VECTOR(3 downto 0) := "0001";			-- SUB RX RY RZ / SUBC RX RY RZ  	-- RX <- RY - RZ / RX <- RY - RZ + C  	-- b0=CarRY	  			Format: < inst(6) | RX(3) | RY(3) | RZ(3)| C >
	CONSTANT MULT 			: STD_LOGIC_VECTOR(3 downto 0) := "0010";			-- MUL RX RY RZ  / MUL RX RY RZ		-- RX <- RY * RZ / RX <- RY * RZ + C  	-- b0=CarRY				Format: < inst(6) | RX(3) | RY(3) | RZ(3)| C >
	CONSTANT DIV 			: STD_LOGIC_VECTOR(3 downto 0) := "0011";			-- DIV RX RY RZ 							-- RX <- RY / RZ / RX <- RY / RZ + C  	-- b0=CarRY				Format: < inst(6) | RX(3) | RY(3) | RZ(3)| C >
	CONSTANT INC 			: STD_LOGIC_VECTOR(3 downto 0) := "0100";			-- INC RX / DEC RX						-- RX <- RX + 1 / RX <- RX - 1  			-- b6= INC/DEC : 0/1	Format: < inst(6) | RX(3) | b6 | xxxxxx >
	CONSTANT LMOD 			: STD_LOGIC_VECTOR(3 downto 0) := "0101";			-- MOD RX RY RZ 							-- RX <- RY MOD RZ														Format: < inst(6) | RX(3) | RY(3) | RZ(3)| x >	

	CONSTANT LOGIC			: STD_LOGIC_VECTOR(1 downto 0) := "01";
	-- LOGIC Instructions (All should begin wiht "01"):	
	CONSTANT LAND			: STD_LOGIC_VECTOR(3 downto 0) := "0010"; 	-- AND RX RY RZ  	-- RZ <- RX AND RY	Format: < inst(6) | RX(3) | RY(3) | RZ(3)| x >
	CONSTANT LOR			: STD_LOGIC_VECTOR(3 downto 0) := "0011";		-- OR RX RY RZ   	-- RZ <- RX OR RY		Format: < inst(6) | RX(3) | RY(3) | RZ(3)| x >
	CONSTANT LXOR			: STD_LOGIC_VECTOR(3 downto 0) := "0100"; 	-- XOR RX RY RZ  	-- RZ <- RX XOR RY	Format: < inst(6) | RX(3) | RY(3) | RZ(3)| x >
	CONSTANT LNOT			: STD_LOGIC_VECTOR(3 downto 0) := "0101";		-- NOT RX RY       	-- RX <- NOT(RY)		Format: < inst(6) | RX(3) | RY(3) | xxxx >
	CONSTANT SHIFT			: STD_LOGIC_VECTOR(3 downto 0) := "0000";		-- SHIFTL0 RX,n / SHIFTL1 RX,n / SHIFTR0 RX,n / SHIFTR1 RX,n / ROTL RX,n / ROTR RX,n
																							-- SHIFT/Rotate RX	-- b6=shif/rotate: 0/1  b5=left/right: 0/1; b4=fill; 	
																							-- Format: < inst(6) | RX(3) |  b6 b5 b4 | nnnn >
												
	CONSTANT CMP 			: STD_LOGIC_VECTOR(3 downto 0) := "0110";		-- CMP RX RY  		-- Compare RX and RY and set FR :   Format: < inst(6) | RX(3) | RY(3) | xxxx >   Flag Register: <...DIVbyZero|StackUnderflow|StackOverflow|DIVByZero|ARITHmeticOverflow|carRY|zero|equal|lesser|greater>
																							-- JMP Condition: (UNconditional, EQual, Not Equal, Zero, Not Zero, CarRY, Not CarRY, GReater, LEsser, Equal or Greater, Equal or Lesser, OVerflow, Not OVerflow, Negative, DIVbyZero, NOT USED)	

	-- FLOW CONTROL Instructions:	
	CONSTANT JMP			: STD_LOGIC_VECTOR(5 downto 0) := "000010";	-- JMP END    -- PC <- 16bit END 							  : b9-b6 = COND		Format: < inst(6) | COND(4) | xxxxxx >   + 16bit END
	CONSTANT CALL			: STD_LOGIC_VECTOR(5 downto 0) := "000011";	-- CALL END   -- M[SP] <- PC | SP-- | PC <- 16bit END   : b9-b6 = COND	  	Format: < inst(6) | COND(4) | xxxxxx >   + 16bit END
	CONSTANT RTS			: STD_LOGIC_VECTOR(5 downto 0) := "000100";	-- RTS        -- SP++ | PC <- M[SP] | b6=RX/FR: 1/0	  							Format: < inst(6) | xxxxxxxxxx >
	CONSTANT PUSH			: STD_LOGIC_VECTOR(5 downto 0) := "000101";	-- PUSH RX / PUSH FR  -- M[SP] <- RX / M[SP] <- FR | SP-- 	 : b6=RX/FR: 0/1		Format: < inst(6) | RX(3) | b6 | xxxxxx >
	CONSTANT POP			: STD_LOGIC_VECTOR(5 downto 0) := "000110";	-- POP RX  / POP FR   -- SP++ | RX <- M[SP]  / FR <- M[SP]	 : b6=RX/FR: 0/1		Format: < inst(6) | RX(3) | b6 | xxxxxx >	

	
	-- Control Instructions:		
	CONSTANT NOP			: STD_LOGIC_VECTOR(5 downto 0) := "000000";	-- NOP            -- Do Nothing	 									Format: < inst(6) | xxxxxxxxxx >
	CONSTANT HALT			: STD_LOGIC_VECTOR(5 downto 0) := "001111";	-- HALT           -- StOP Here										Format: < inst(6) | xxxxxxxxxx >
	CONSTANT SETC			: STD_LOGIC_VECTOR(5 downto 0) := "001000";	-- CLEARC / SETC  -- Set/Clear CarRY: b9 = 1-set; 0-clear	Format: < inst(6) | b9 | xxxxxxxxx >
	CONSTANT BREAKP		: STD_LOGIC_VECTOR(5 downto 0) := "001110"; 	-- BREAK POINT    -- Switch to manual clock						Format: < inst(6) | xxxxxxxxxx >	
	
	
	-- CONSTANTes para controle do Mux2: Estes sinais selecionam as respectivas entradas para o Mux2
	CONSTANT sULA		: STD_LOGIC_VECTOR (2 downto 0) := "000";
	CONSTANT sMem		: STD_LOGIC_VECTOR (2 downto 0) := "001";
	CONSTANT sM4		: STD_LOGIC_VECTOR (2 downto 0) := "010";
	CONSTANT sBUS		: STD_LOGIC_VECTOR (2 downto 0) := "011"; -- nao tinha
	CONSTANT sSP		: STD_LOGIC_VECTOR (2 downto 0) := "100";	
	
	
	CONSTANT boot			: STD_LOGIC := '0';
	CONSTANT mainmem		: STD_LOGIC :='1';	

	
	-- Sinais para o Processo da ULA	
	signal OP				: STD_LOGIC_VECTOR(6 downto 0);	-- OP(6) deve ser setado para OPeracoes com carRY
	signal x, y, result	: STD_LOGIC_VECTOR(15 downto 0) := x"0000";
	signal FR				: STD_LOGIC_VECTOR(15 downto 0) := x"0000";	-- Flag Register: <...DIVbyZero|StackUnderflow|StackOverflow|DIVByZero|ARITHmeticOverflow|carRY|zero|equal|lesser|greater>
	signal auxFR			: STD_LOGIC_VECTOR(15 downto 0) := x"0000";	-- Representa um barramento conectando a ULA ao Mux6 para escrever no FR
	
	--Registrador de controle do processador
	signal CR0				: STD_LOGIC_VECTOR(15 downto 0) := x"8000";	-- 
	
	-- Sinais de interrupcao
	signal mask 		: std_logic_vector(15 downto 0) := x"0000";
	signal mirq			: std_logic_vector(15 downto 0) := x"0000";
	signal att			: std_logic_vector(15 downto 0) := x"0000";
	signal addrInt 		: std_logic_vector(15 downto 0);	
	
	signal regs : Registers;
begin

-- Maquina de Controle
process(clk, reset)

	--Register Declaration:	
	variable PC		: STD_LOGIC_VECTOR(15 downto 0);		-- Program Counter
	variable IR		: STD_LOGIC_VECTOR(15 downto 0);		-- Instruction Register
	variable SP		: STD_LOGIC_VECTOR(15 downto 0);		-- Stack Pointer
	variable MAR	: STD_LOGIC_VECTOR(15 downto 0);		-- Memory address Register
	
	variable reg : Registers;
	
	-- Mux dos barramentos de dados internos	
	VARIABLE	M2				:STD_LOGIC_VECTOR(15 downto 0);	-- Mux dos barramentos de dados internos para os Registradores
	VARIABLE M3, M4, M7		:STD_LOGIC_VECTOR(15 downto 0);	-- Mux dos Registradores para as entradas da ULA
	
	-- Novos Sinais da Versao 2: Controle dos registradores internos (Load-Inc-Dec)
	variable LoadReg		: LoadRegisters; 
	variable LoadIR		: std_LOGIC;
	variable LoadMAR		: std_LOGIC;
	variable LoadPC		: std_LOGIC;
	variable IncPC 		: std_LOGIC;
	VARIABLE LoadSP		: STD_LOGIC;
	variable IncSP 		: std_LOGIC;
	variable DecSP			: std_LOGIC;
	
	-- Selecao dos Mux 2 e 6
	variable selM2 		: STD_LOGIC_VECTOR(2 downto 0); 
	variable selM6 		: STD_LOGIC_VECTOR(2 downto 0); 
	variable selM7 		: STD_LOGIC;
	
	VARIABLE BreakFlag	: STD_LOGIC;  -- Para sinalizar a mudanca para Clock manual/Clock Automatico para  a nova instrucao Break
	
	variable state : STATES;  -- Estados do processador: fetch, decode, exec, halted
	
	-- Seletores dos registradores para execussao das instrucoes
	variable RX : integer;   
	variable RY : integer;
	variable RZ : integer;
	
	
begin

	if(reset = '1') then
	
		state := fetch;		-- inicializa o estado na busca!
		M1(15 downto 0) <=	x"0000";  -- inicializa na linha Zero da memoria -> Programa tem que comecar na linha Zero !!
		M5(15 downto 0) <=	x"0000";  -- inicializa na linha Zero da memoria -> Programa tem que comecar na linha Zero !!
		
		att <= (others => '0');
		
		bus_rw <= '0';
		bus_req <= '0';
		bus_data <= (others =>'Z');
		bus_addr <= (others => '0');
		
		
		RX := 0;
		RY := 0;
		RZ := 0;
		
		RW <= '0';
		
		LoadIR	:= '0';
		LoadMAR	:= '0';
		LoadPC	:= '0';
		IncPC		:= '0';
		IncSP		:= '0';
		DecSP		:= '0';
		selM2		:= sMem;
		selM6		:= sULA;
		selM7		:= boot;
		
		LoadReg(0) := '0';
		LoadReg(1) := '0';
		LoadReg(2) := '0';
		LoadReg(3) := '0';
		LoadReg(4) := '0';
		LoadReg(5) := '0';
		LoadReg(6) := '0';
		LoadReg(7) := '0';
		
		REG(0)  := x"0000";
		REG(1)  := x"0000";	
		REG(2)  := x"0000";
		REG(3)  := x"0000";
		REG(4)  := x"0000";
		REG(5)  := x"0000";
		REG(6)  := x"0000";
		REG(7)  := x"0000";
		
		PC := x"0000";  -- inicializa na linha Zero da memoria -> Programa tem que comecar na linha Zero !!
		SP := x"3eff";  -- Inicializa a Pilha no final da mem�ria: 3eff
		IR := x"0000";
		MAR := x"0000";
			
		 BreakFlag:= '0';	-- Break Point Flag
		 BREAK <= '0'; 	-- Break Point output to switch to manual clock	

		 -- Novo na Versao 3
		HALT_ack <= '0';
		FR <= (others => '0');
		CR0 <= x"8000";
		
			
	elsif(rising_edge(clk)) then
	
		if (selM7 = boot) THEN M7 := boot_mem;			
		elsif (selM7 = mainmem) THEN M7 := Mem;
		end if;
		
		if(LoadIR = '1')	then IR := M7; 					end if;
	
		if(LoadPC = '1')	then PC := M7; 				end if;
	
		if(IncPC = '1')	then PC := PC + x"0001"; 	end if;
	
		if(LoadMAR = '1' ) then MAR := M7; 			end if;
	
		if(LoadSP = '1') 	then SP := M3; 				end if;
	
		if(IncSP = '1')	then SP := SP + x"0001"; 	end if;
	
		if(DecSP = '1')	then SP := SP - x"0001"; 	end if;
	
		-- Selecao do Mux6
		if (selM6 = sULA) THEN FR <= auxFR;				-- Sempre recebe flags da ULA
		ELSIF (selM6 = sMem) THEN FR <= Mem; END IF;	-- A menos que seja POP FR, quando recebe da Memoria
		
		-- Atualiza o nome dos registradores!!!
		RX := conv_integer(IR(9 downto 7));
		RY := conv_integer(IR(6 downto 4));
		RZ := conv_integer(IR(3 downto 1));
	
		-- Selecao do Mux2
		if (selM2 = sULA) 		THEN M2 := RESULT;
		ELSIF (selM2 = sMem) 	THEN M2 := M7;
		ELSIF (selM2 = sM4) 		THEN M2 := M4;
		ELSIF (selM2 = sBUS)    THEN M2 := bus_data;
		ELSIF (selM2 = sSP) 		THEN M2 := SP; 
		END IF;			
		
		-- Carrega dados do Mux 2 para os registradores
		if(LoadReg(RX) = '1') then reg(RX) := M2; end if;
	
		-- Reseta os sinais de controle APOS usa-los acima
		-- Zera todos os sinais de controle, para depois ligar um por um nas instrucoes a medida que for necessario: a ultima atribuicao e' a que vale no processo!!!
		LoadIR  := '0';
		LoadMAR := '0';
		LoadPC  := '0';	
		IncPC   := '0';
		IncSP   := '0';
		DecSP   := '0';
		LoadSP  := '0';
		selM6	  := sULA;	-- Sempre atualiza o FR da ULA, a nao ser que a instrucao seja POP FR

		LoadReg(0) := '0';
		LoadReg(1) := '0';
		LoadReg(2) := '0';
		LoadReg(3) := '0';
		LoadReg(4) := '0';
		LoadReg(5) := '0';
		LoadReg(6) := '0';
		LoadReg(7) := '0';

		bus_rw <= '0';
		bus_req <= '0';
		bus_data <= (others =>'Z');

		RW <= '0';  -- Sinal de Letura/Ecrita da memoria em Leitura  (0 - ler, 1 - escrever)

		-- Novo na Versao 3
		if(halt_req = '1') then state := halted; end if;

		-- Novo na Versao 3: para escrever PC no LCD da placa
		PC_data <= PC;

		case state is

--************************************************************************
-- FETCH STATE
--************************************************************************		
		
		when fetch =>
			PONTO <= "0001";
			if(PC > x"00ff" and CR0(15)= '1')then
				CR0(15) <= '0';
				PC := x"0000";
			else
				if(CR0(15)= '1')then
					selM7 := boot;
				else
					selM7 := mainmem;
				end if;
				-- Inicio das acoes do ciclo de Busca !!       
				M1 <= PC;
				RW <= '0';
				LoadIR := '1';
				IncPC := '1';

				STATE := decode;
			
			end if;
			
-- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX        			

--************************************************************************
-- DECODE STATE
--************************************************************************
		when decode =>
			PONTO <= "0010";
		
--========================================================================
-- INWORD  			RY <- bus[RX]
--========================================================================		
			IF(IR(15 DOWNTO 10) = INWORD) THEN			
				if(bus_ack='1') then
					state := int;	
				else		
					M3 := Reg(Ry); 							-- M3 <- Rx
					bus_req <= '1';
					bus_addr <= M3; 
					bus_rw <= '0';
					selM2 := sBUS;
					loadReg(Rx) := '1';
				end if;
			END IF;			
			
--========================================================================
-- OUTWORD			bus[RY] <- RX
--========================================================================
			IF(IR(15 DOWNTO 10) = OUTWORD) THEN
				M3 := Reg(Rx); 							-- M3 <- Rx
				M4 := Reg(Ry); 							-- M4 <- Ry

				bus_data	<= M3;
				bus_addr <= M4; 
				bus_rw <= '1';
				bus_req <= '1';
				state := int;		
			END IF;					
		
--========================================================================
-- MOV  			RX/SP <- RY/SP

-- MOV RX RY    RX <- RY	  		Format: < inst(6) | RX(3) | RY(3) | xx | x0 >
-- MOV RX SP    RX <- SP         Format: < inst(6) | RX(3) | xxx | xx | 01 >
-- MOV SP RX    SP <- RX         Format: < inst(6) | RX(3) | xxx | xx | 11 >

--========================================================================		
			IF(IR(15 DOWNTO 10) = MOV) THEN 
			
			    -- MOV RX <- SP 
				IF(IR(1 DOWNTO 0) = "01") THEN
					selM2:= sSP;
					LoadReg(Rx):= '1';
					
				-- MOV SP <- RX
				ELSIF(IR(1 DOWNTO 0) = "11") THEN
					M3 := Reg(Rx);
					selM7 := mainmem;
					loadPC:='1';
				
				-- MOV RX <- RY
				ELSE
					M4 := Reg(Ry);
					selM2 := sM4;
					loadReg(Rx) := '1';
				END IF;
				state := int;	
			END IF;
--========================================================================
-- STORE   DIReto			M[END] <- RX
--========================================================================			
			IF(IR(15 DOWNTO 10) = STORE) THEN  -- Busca o endereco
				M1 <= PC;				-- M1 <- PC
				Rw <= '0';				-- Rw <= '0'
				
				LoadMAR := '1';		-- LoadMAR <- 1
				state := exec;  -- Vai para o estado de Executa para gravar Registrador no endereco
			END IF;					
		
--========================================================================
-- STORE indexado por registrador 			M[RX] <- RY
--========================================================================		
			IF(IR(15 DOWNTO 10) = STOREINDEX) THEN 
				M4 := Reg(Rx);
				M1 <= M4;
				Rw <= '1';
				M3 := Reg(Ry);
				M5 <= M3;
				state := int;	
			END IF;					
		
--========================================================================
-- LOAD Direto  			RX <- M[End]
--========================================================================		
			IF(IR(15 DOWNTO 10) = LOAD) THEN -- Busca o endereco
				M1 <= PC;				-- M1 <- PC
				Rw <= '0';				-- Rw <= '0'
				if(CR0(15)= '1')then
					selM7 := boot;
				else
					selM7 := mainmem;
				end if;
				LoadMAR := '1';		-- LoadMAR <- 1
				state := exec;  -- Vai para o estado de Executa para buscar o dado do endereco
			END IF;			
			
--========================================================================
-- LOAD Imediato 			RX <- Nr
--========================================================================			
			IF(IR(15 DOWNTO 10) = LOADIMED) THEN
				M1 <= PC;				-- M1 <- PC
				Rw <= '0';				-- Rw <= '0'
				if(CR0(15)= '1')then
					selM7 := boot;
				else
					selM7 := mainmem;
				end if;
				selM2 := sMem; 		-- M2 <- MEM	
				LoadReg(RX) := '1';	-- LRx <- 1	
				IncPC := '1';  		-- IncPC <- 1	
				state := int;	
			END IF;					
			
--========================================================================
-- LOAD Indexado por registrador 			RX <- M(RY)
--========================================================================		
			IF(IR(15 DOWNTO 10) = LOADINDEX) THEN
				M4 := Reg(Ry);
				M1 <= M4;
				Rw <= '0';
				selM7 := mainmem;
				selM2 := sMem;
				loadReg(Rx) := '1';
				state := int;	
			END IF;					
		
--========================================================================
-- LOGIC OPERATION ('SHIFT', and 'CMP'  NOT INCLUDED)  			RX <- RY (?) RZ
--========================================================================		
			IF(IR(15 DOWNTO 14) = LOGIC AND IR(13 DOWNTO 10) /= SHIFT AND IR(13 DOWNTO 10) /= CMP) THEN 
				
				M3 := Reg(Ry);
				M4 := Reg(Rz);
				
				X <= M3;
				Y <= M4;
			
				OP(5 DOWNTO 0) <= IR (15 DOWNTO 10);

				selM2 := sULA;
				loadReg(Rx) := '1';
				state := int;	
			END IF;			
		
--========================================================================
-- CMP		RX, RY
--========================================================================		
			IF(IR(15 DOWNTO 14) = LOGIC AND IR(13 DOWNTO 10) = CMP) THEN 
				M3 := Reg(Rx);
				M4 := Reg(Ry);
				
				X <= M3;
				Y <= M4;
				
				OP(5 downto 4) <= LOGIC;
				OP(3 downto 0) <= CMP;
				
				selM6 := sULA;
				
				state := int;	
			END IF;
		
--========================================================================
-- SHIFT		RX, RY     RX  <- SHIFT[ RY]        ROTATE INCluded !
--========================================================================		
			IF(IR(15 DOWNTO 14) = LOGIC and (IR(13 DOWNTO 10) = SHIFT)) THEN
				if(IR(6 DOWNTO 4) = "000") then	 	-- SHIFT LEFT 0
					Reg(RX) := To_StdLOGICVector(to_bitvector(Reg(RY))sll conv_integer(IR(3 DOWNTO 0)));
				elsif(IR(6 DOWNTO 4) = "001") then	-- SHIFT LEFT 1
					Reg(RX) := not (To_StdLOGICVector(to_bitvector(not Reg(RY))sll conv_integer(IR(3 DOWNTO 0))));
				elsif(IR(6 DOWNTO 4) = "010") then	-- SHIFT RIGHT 0
					Reg(RX) := To_StdLOGICVector(to_bitvector(Reg(RY))srl conv_integer(IR(3 DOWNTO 0)));
				elsif(IR(6 DOWNTO 4) = "011") then	-- SHIFT RIGHT 0
					Reg(RX) := not (To_StdLOGICVector(to_bitvector(not Reg(RY))srl conv_integer(IR(3 DOWNTO 0))));
				elsif(IR(6 DOWNTO 5) = "11") then	-- ROTATE RIGHT
					Reg(RX) := To_StdLOGICVector(to_bitvector(Reg(RY))ror conv_integer(IR(3 DOWNTO 0)));
				elsif(IR(6 DOWNTO 5) = "10") then	-- ROTATE LEFT
					Reg(RX) := To_StdLOGICVector(to_bitvector(Reg(RY))rol conv_integer(IR(3 DOWNTO 0)));
				end if;	
				
				state := int;	
			end if;			

--========================================================================
-- JMP END    PC <- 16bit END : b9-b6 = COND
-- Flag Register: <...Negative|StackUnderflow|StackOverflow|DIVByZero|ARITHmeticOverflow|carRY|zero|equal|lesser|greater>
-- JMP Condition: (UNconditional, EQual, Not Equal, Zero, Not Zero, CarRY, Not CarRY, GReater, LEsser, Equal or Greater, Equal or Lesser, OVerflow, Not OVerflow, Negative, DIVbyZero, NOT USED)	
--========================================================================		
			IF(IR(15 DOWNTO 10) = JMP) THEN 
				IF((IR(9 DOWNTO 6) = "0000") OR
				((IR(9 DOWNTO 6) = "0111") AND FR(0) = '1') OR
				((IR(9 DOWNTO 6) = "1001") AND (FR(2) = '1' OR FR(0) = '1')) OR
				((IR(9 DOWNTO 6) = "1000") AND FR(1) = '1') OR
				((IR(9 DOWNTO 6) = "1010") AND (FR(2) = '1' OR FR(1) = '1')) OR
				((IR(9 DOWNTO 6) = "0001") AND FR(2) = '1') OR
				((IR(9 DOWNTO 6) = "0010") AND FR(2) = '0') OR
				((IR(9 DOWNTO 6) = "0011") AND FR(3) = '1') OR
				((IR(9 DOWNTO 6) = "0100") AND FR(3) = '0') OR
				((IR(9 DOWNTO 6) = "0101") AND FR(4) = '1') OR
				((IR(9 DOWNTO 6) = "0110") AND FR(4) = '0') OR
				((IR(9 DOWNTO 6) = "1011") AND FR(5) = '1') OR
				((IR(9 DOWNTO 6) = "1100") AND FR(5) = '0') OR
				((IR(9 DOWNTO 6) = "1101") AND FR(6) = '1') OR
				((IR(9 DOWNTO 6) = "1110") AND FR(9) = '1')) THEN
					M1 <= PC;				-- M1 <- PC
					Rw <= '0';				-- Rw <= '0'
					if(CR0(15)= '1')then
						selM7 := boot;
					else
						selM7 := mainmem;
					end if;
					LoadPC := '1';			-- LoadPC <- 1
				ELSE
					IncPC := '1';
				END IF;
				state := int;	
			END IF;

--========================================================================
-- PUSH RX
--========================================================================		
			IF(IR(15 DOWNTO 10) = PUSH) THEN
				M1 <= SP;
				Rw <= '1';
				
				IF(IR(6)= '0') THEN
					M3 := Reg(Rx);
				ELSIF(ir(6) = '1') THEN
					M3 := FR;
				END IF;
				
				M5 <= M3;
				DecSP := '1';
				state := int;	
			END IF;
		
--========================================================================
-- POP RX
--========================================================================
			IF(IR(15 DOWNTO 10) = POP) THEN
				IncSP := '1';
				state := exec;
			END IF;						
				
--========================================================================
-- CALL END    PC <- 16bit END : b9-b6 = COND PUSH(PC)
-- Flag Register: <...Negative|StackUnderflow|StackOverflow|DIVByZero|ARITHmeticOverflow|carRY|zero|equal|lesser|greater>
-- JMP Condition: (UNconditional, EQual, Not Equal, Zero, Not Zero, CarRY, Not CarRY, GReater, LEsser, Equal or Greater, Equal or Lesser, OVerflow, Not OVerflow, Negative, DIVbyZero, NOT USED)	
--========================================================================
			IF(IR(15 DOWNTO 10) = CALL) THEN 
				-- do simao
				
				IF((IR(9 DOWNTO 6) = "0000") OR
				((IR(9 DOWNTO 6) = "0111") AND FR(0) = '1') OR
				((IR(9 DOWNTO 6) = "1001") AND (FR(2) = '1' OR FR(0) = '1')) OR
				((IR(9 DOWNTO 6) = "1000") AND FR(1) = '1') OR
				((IR(9 DOWNTO 6) = "1010") AND (FR(2) = '1' OR FR(1) = '1')) OR
				((IR(9 DOWNTO 6) = "0001") AND FR(2) = '1') OR
				((IR(9 DOWNTO 6) = "0010") AND FR(2) = '0') OR
				((IR(9 DOWNTO 6) = "0011") AND FR(3) = '1') OR
				((IR(9 DOWNTO 6) = "0100") AND FR(3) = '0') OR
				((IR(9 DOWNTO 6) = "0101") AND FR(4) = '1') OR
				((IR(9 DOWNTO 6) = "0110") AND FR(4) = '0') OR
				((IR(9 DOWNTO 6) = "1011") AND FR(5) = '1') OR
				((IR(9 DOWNTO 6) = "1100") AND FR(5) = '0') OR
				((IR(9 DOWNTO 6) = "1101") AND FR(6) = '1') OR
				((IR(9 DOWNTO 6) = "1110") AND FR(9) = '1')) THEN
					Rw <= '1';				-- Rw <= '1'
					M1 <= SP;				-- M1 <- SP
					M5 <= PC;
					DecSP := '1';	
					state := exec;
				ELSE
					IncPC := '1';
					state := int;	
				END IF;
			END IF;

--========================================================================
-- RTS 			PC <- Mem[SP]
--========================================================================				
			IF(IR(15 DOWNTO 10) = RTS) THEN
				IncSP := '1';
				state := exec;
			END IF;

--========================================================================
-- ARITH OPERATION ('INC' NOT INCLUDED) 			RX <- RY (?) RZ
--========================================================================
			IF(IR(15 DOWNTO 14) = ARITH AND IR(13 DOWNTO 10) /= INC) THEN
				M3 := Reg(Ry);
				M4 := Reg(Rz);
			
				X <= M3;
				Y <= M4;
				
				
				OP(5 downto 0) <= IR (15 DOWNTO 10);
				OP(6) <= IR(0);
				
				selM2 := sULA;
				loadReg(Rx) := '1';
				state := int;	
			END IF;
			
--========================================================================
-- INC/DEC			RX <- RX (+ or -) 1
--========================================================================			
			IF(IR(15 DOWNTO 14) = ARITH AND (IR(13 DOWNTO 10) = INC))	THEN
				M3 := Reg(Rx);
				M4 := "0000000000000001";
				X <= M3;
				Y <= M4;
				OP(5 downto 4) <= ARITH;
				
				IF (IR(6) = '0') THEN
					OP(3 downto 0) <= ADD;
				ELSE 
					OP(3 downto 0) <= SUB;
				END IF;
				
				selM2 := sULA;
				loadReg(Rx) := '1';
				state := int;	
			END IF;
			
--========================================================================
-- NOP
--========================================================================
			IF( IR(15 DOWNTO 10) = NOP) THEN 
				state := int;	
			end if;

--========================================================================
-- HALT
--========================================================================
			IF( IR(15 DOWNTO 10) = HALT) THEN 
				state := halted;
			END IF;		
			
--========================================================================
-- SETC/CLEARC
--========================================================================			
			IF( IR(15 DOWNTO 10) = SETC) THEN 
				FR(4) <= IR(9);  -- Bit 9 define se vai ser SET ou CLEAR
				state := int;	
			end if;
			
--========================================================================
-- BREAKP
--========================================================================			
			IF( IR(15 DOWNTO 10) = BREAKP) THEN 
				BreakFlag := not(BreakFlag);  -- Troca entre clock manual e clock autom�tico
				BREAK <= BreakFlag;
				state := int;	
				PONTO <= "1111";
			END IF;		
							
--========================================================================
-- EI
--========================================================================			
			IF( IR(15 DOWNTO 10) = EI) THEN 
				CR0(0) <= IR(0);
				state := int;	
			END IF;	
-- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX			
			
						

--************************************************************************
-- EXECUTE STATE
--************************************************************************								
					
			when exec =>
				PONTO <= "0011";
				
--========================================================================
-- EXEC STORE DIReto 			M[END] <- RX
--========================================================================
			IF(IR(15 DOWNTO 10) = STORE) THEN 
				M1 <= MAR;				-- M1 <- PC
				Rw <= '1';				-- Rw <= '0'
				M3 := Reg(Rx);
				M5 <= M3;
				IncPC := '1';  		-- IncPC <- 1	
				state := int;	
			END IF;
						
--========================================================================
-- EXEC LOAD DIReto  			RX <- M[END]
--========================================================================
			IF(IR(15 DOWNTO 10) = LOAD) THEN
				M1 <= MAR;				-- M1 <- PC
				Rw <= '0';				-- Rw <= '0'
				selM7 := mainmem;
				selM2 := sMem; 		-- M2 <- MEM	
				LoadReg(RX) := '1';	-- LRx <- 1
				IncPC := '1';  		-- IncPC <- 1	
				state := int;	
			END IF;
			
--========================================================================
-- EXEC CALL    Pilha <- PC e PC <- 16bit END :
--========================================================================
			IF(IR(15 DOWNTO 10) = CALL) THEN
				M1 <= PC;				-- M1 <- PC
				Rw <= '0';				-- Rw <= '0'
				if(CR0(15)= '1')then
					selM7 := boot;
				else
					selM7 := mainmem;
				end if;
				LoadPC := '1';			-- LoadMAR <- 1
				state := fetch;	
			END IF;

--========================================================================
-- EXEC RTS 			PC <- Mem[SP]
--========================================================================
			IF(IR(15 DOWNTO 10) = RTS) THEN
				M1 <= SP;
				Rw <= '0';
				selM7 := mainmem;
				LoadPC := '1';
				IncPC := '1';
				state := fetch;	
				cr0(1) <= '0';
			END IF;
			
--========================================================================
-- EXEC POP RX/FR
--========================================================================
			IF(IR(15 DOWNTO 10) = POP) THEN
				M1 <= SP;
				Rw <= '0';
				selM7 := mainmem;
				IF(IR(6) = '0') THEN
					selM2 := sMem;
					LoadReg(Rx) := '1';
				ELSIF(IR(6) = '1') THEN
					selM6 := sMem;	
				END IF;
				state := int;	
			END IF;	
			
-- XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
				
--************************************************************************
-- Interuption STATE
--************************************************************************				
		when int =>
			ponto <= "0100";	
			att <= (others => '0');	
			if(mirq /= x"0000" and CR0(0) = '1' and CR0(1) = '0')then
				Rw <= '1';				-- Rw <= '1'
				M1 <= SP;				-- M1 <- SP
				M5 <= PC-'1';
				DecSP := '1';	
				state := intExec;
				att <= (others =>'0');
				cr0(1) <= '1';
			else
				state := fetch;
			end if;		
				
--************************************************************************
-- Interuption Execution STATE
--************************************************************************		
		when intExec =>
			ponto <= "0101";
			Rw <= '0';				-- Rw <= '0'
			selM7 := mainmem;
			LoadPC := '1';			-- LoadMAR <- 1
			if(mirq(0) = '1') then
				M1 <= x"3f00";
				att(0) <= '1';
			elsif (mirq(1) = '1') then
				M1 <= x"3f01";	
				att(1) <= '1';		
			elsif (mirq(2) = '1') then
				M1 <= x"3f02";	
				att(2) <= '1';
			elsif (mirq(3) = '1') then
				M1 <= x"3f03";	
				att(3) <= '1';
			elsif (mirq(4) = '1') then
				M1 <= x"3f04";	
				att(4) <= '1';
			elsif (mirq(5) = '1') then
				M1 <= x"3f05";	
				att(5) <= '1';
			elsif (mirq(6) = '1') then
				M1 <= x"3f06";
				att(6) <= '1';
			elsif (mirq(7) = '1') then
				M1 <= x"3f07";	
				att(7) <= '1';
			elsif (mirq(8) = '1') then
				M1 <= x"3f08";	
				att(8) <= '1';
			elsif (mirq(9) = '1') then
				M1 <= x"3f09";	
				att(9) <= '1';
			elsif (mirq(10) = '1') then
				M1 <= x"3f0a";
				att(10) <= '1';
			elsif (mirq(11) = '1') then
				M1 <= x"3f0b";	
				att(11) <= '1';
			elsif (mirq(12) = '1') then
				M1 <= x"3f0c";	
				att(12) <= '1';
			elsif (mirq(13) = '1') then
				M1 <= x"3f0d";
				att(13) <= '1';	
			elsif (mirq(14) = '1') then
				M1 <= x"3f0e";	
				att(14) <= '1';
			elsif (mirq(15) = '1') then
				M1 <= x"3f0f";	
				att(15) <= '1';
			end if;
			state := fetch;
--************************************************************************
-- HALT STATE
--************************************************************************				
			
		WHEN halted =>
			PONTO <= "0111";	
			if(irq /= x"0000" and CR0(0) = '1')then
				Rw <= '1';				-- Rw <= '1'
				M1 <= SP;				-- M1 <- SP
				M5 <= PC;
				DecSP := '1';	
				state := intExec;
				halt_ack <= '0';
			else
				state := halted;
				halt_ack <= '1';
			end if;
			
		WHEN OTHERS =>
			state := fetch;
			BUS_req <= '0';
			BUS_rw <= '0';
			PONTO <= "0000";
		
		END CASE;	
		regs(0)<= reg(0);
		regs(1)<= reg(1);
		regs(2)<= reg(2);
		regs(3)<= reg(3);
		regs(4)<= reg(4);
		regs(5)<= reg(5);
		regs(6)<= reg(6);
		regs(7)<= reg(7);
	end if;	
	end process;
	
	process(irq, reset, att) 
	begin 
		if(reset = '1') then
			mirq <= (others => '0');
		else
			mirq <= (mirq and (not att)) or irq;
		end if;
	end process;
	
--************************************************************************
-- ULA --->  3456  (3042)
--************************************************************************
PROCESS (OP, X, Y, reset)

	VARIABLE AUX		: STD_LOGIC_VECTOR(15 downto 0);
	VARIABLE RESULT32 : STD_LOGIC_VECTOR(31 downto 0);	
	
BEGIN

	IF (reset = '1') THEN
		auxFR <= x"0000";		
		RESULT <= x"0000";
	else
		auxFR <= FR;

--========================================================================
-- ARITH 
--========================================================================
		IF (OP (5 downto 4) = ARITH) THEN
			CASE OP (3 downto 0) IS
				WHEN ADD =>
					IF (OP(6) = '1') THEN --Soma com carRY
						AUX := X + Y + FR(4);
						RESULT32 := (x"00000000" + X + Y + FR(4));
					ELSE  --Soma sem carRY
						AUX := X + Y;
						RESULT32 := (x"00000000" + X + Y);					
					end if;	
					if(RESULT32 > "01111111111111111") THEN -- CarRY
						auxFR(4) <= '1';
					ELSE
						auxFR(4) <= '0';
					end if;
					
				WHEN SUB =>
					AUX := X - Y;
					
				WHEN MULT =>
					RESULT32 := X * Y;
					AUX := RESULT32(15 downto 0);
					if(RESULT32 > x"0000FFFF") THEN -- ARITHmetic Overflow
						auxFR(5) <= '1';
					ELSE
						auxFR(5) <= '0';
					end if;

				WHEN DIV =>
					IF(Y = x"0000") THEN
						AUX := x"0000";
						auxFR(6) <= '1'; -- DIV by Zero
					ELSE
						AUX := CONV_STD_LOGIC_VECTOR(CONV_INTEGER(X)/CONV_INTEGER(Y), 16);		
						auxFR(6) <= '0';
					END IF;
				WHEN LMOD =>
					IF(Y = x"0000") THEN
						AUX := x"0000";
						auxFR(6) <= '1'; -- DIV by Zero
					ELSE
						AUX := CONV_STD_LOGIC_VECTOR(CONV_INTEGER(X) mod CONV_INTEGER(Y), 16);		
						auxFR(6) <= '0';
					END IF;			
				WHEN others =>   -- invalid operation, defaults to nothing
					AUX := X;
			END CASE;
			if(AUX = x"0000") THEN
				auxFR(3) <= '1';  -- FR = <...|zero|equal|lesser|greater>
			ELSE
				auxFR(3) <= '0';  -- FR = <...|zero|equal|lesser|greater>
			end if;
			if(AUX < x"0000") THEN   -- NEGATIVO
				auxFR(9) <= '1';  
			ELSE
				auxFR(9) <= '0';  
			end if;	
			RESULT <= AUX;
			
		ELSIF (OP (5 downto 4) = LOGIC) THEN
			IF (OP (3 downto 0) = CMP) THEN
				result <= x;
				IF (x > y) THEN
					auxFR(2 downto 0) <= "001"; -- FR = <...|zero|equal|lesser|greater>
				ELSIF (x < y) THEN
					auxFR(2 downto 0) <= "010"; -- FR = <...|zero|equal|lesser|greater>
				ELSIF (x = y) THEN
					auxFR(2 downto 0) <= "100"; -- FR = <...|zero|equal|lesser|greater>
				END IF;
			ELSE
				CASE OP (3 downto 0) IS
					WHEN LAND => result <= x and y;

					WHEN LXOR => result <= x xor y;

					WHEN LOR =>	 result <= x or y;

					WHEN LNOT => result <= not x;
	
					WHEN others =>   -- invalid operation, defaults to nothing
						RESULT <= X;
				END CASE;
				if(result = x"0000") THEN
					auxFR(3) <= '1';  -- FR = <...|zero|equal|lesser|greater>
				ELSE
					auxFR(3) <= '0';  -- FR = <...|zero|equal|lesser|greater>
				end if;	
			END IF;
		END IF;
	END IF; -- Reset
END PROCESS;
end main;
