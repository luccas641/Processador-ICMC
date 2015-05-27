library IEEE;
use  IEEE.STD_LOGIC_1164.all;
use  IEEE.STD_LOGIC_ARITH.all;
use  IEEE.STD_LOGIC_UNSIGNED.all;

ENTITY dec_keyboard IS

 PORT( hex_bus		: IN	STD_LOGIC_VECTOR(7 downto 0);
	   scan_rd 		: IN 	STD_LOGIC;
	   clk	 		: IN 	STD_LOGIC;		
	   bin_digit    : OUT 	STD_LOGIC_VECTOR(7 downto 0);
		int 			: out std_LOGIC;
		rst 			: in std_LOGIC
	 );
	 
END dec_keyboard;

-------------------------- -- ------------------------------------

ARCHITECTURE a OF dec_keyboard IS
type states is (idle, press, pressed, released);
signal state : states;
signal code : std_logic_vector(7 downto 0) := x"00";
signal buffero : std_logic_vector(7 downto 0) := x"00";
signal f : std_logic;
signal f2 : std_logic;
signal f3 : std_logic;
signal s : std_logic;
BEGIN

------------------------ -- ----------------------------------------
  PROCESS (clk, rst)
   variable saida : STD_LOGIC_VECTOR (7 downto 0) := x"00";
	
   BEGIN
	 if(rst = '1') then
		state <= idle;
		int <= '0';
	 elsif(rising_edge(clk)) then
		case hex_bus is --bloco das teclas normais (n�o e' case sensitive)
			  when x"1c" => saida := x"41"; --A
			  when x"32" => saida := x"42"; --B
			  when x"21" => saida := x"43"; --C
			  when x"23" => saida := x"44"; --D
			  when x"24" => saida := x"45"; --E
			  when x"2b" => saida := x"46"; --F
			  when x"34" => saida := x"47"; --G
			  when x"33" => saida := x"48"; --H
			  when x"43" => saida := x"49"; --I
			  when x"3b" => saida := x"4a"; --J
			  when x"42" => saida := x"4b"; --K
			  when x"4b" => saida := x"4c"; --L
			  when x"3a" => saida := x"4d"; --M
			  when x"31" => saida := x"4e"; --N
			  when x"44" => saida := x"4f"; --O
			  when x"4d" => saida := x"50"; --P
			  when x"15" => saida := x"51"; --Q
			  when x"2d" => saida := x"52"; --R
			  when x"1b" => saida := x"53"; --S
			  when x"2c" => saida := x"54"; --T
			  when x"3c" => saida := x"55"; --U
			  when x"2a" => saida := x"56"; --V
			  when x"1d" => saida := x"57"; --W
			  when x"22" => saida := x"58"; --X
			  when x"35" => saida := x"59"; --Y
			  when x"1a" => saida := x"5a"; --Z

			  when x"29" => saida := x"20"; --space
			  when x"66" => saida := x"08"; --backspace
			  when x"5a" => saida := x"0d"; --enter

			  when x"12" => saida := x"0e"; --shift esquerdo
			  when x"59" => saida := x"0f"; --shift direito
			  when x"14" => saida := x"fd"; --ctrl  Codigo Inventado
			  when x"11" => saida := x"fe"; --alt  Codigo Inventado
			  when x"0d" => saida := x"09"; --tab
			  when x"76" => saida := x"1b"; --ESC
			  
			  when x"41" => saida := x"3c"; -- <
			  when x"49" => saida := x"3e"; -- >
			  when x"61" => saida := x"5c"; -- \
			  when x"4a" => saida := x"3f"; -- ?
			  when x"51" => saida := x"2f"; -- /
			  when x"4c" => saida := x"3b"; -- ;
			  when x"52" => saida := x"7e"; -- ~ 
			  when x"5d" => saida := x"5d"; -- ] 
			  when x"54" => saida := x"60"; -- ` 
			  when x"5b" => saida := x"5b"; -- [
				
			  when x"69" => saida := x"e1"; --num1  Codigo Inventado
			  when x"72" => saida := x"e2"; --num2  Codigo Inventado
			  when x"7a" => saida := x"e3"; --num3  Codigo Inventado
			  when x"6b" => saida := x"e4"; --num4  Codigo Inventado
			  when x"73" => saida := x"e5"; --num5  Codigo Inventado
			  when x"74" => saida := x"e6"; --num6  Codigo Inventado
			  when x"6c" => saida := x"e7"; --num7  Codigo Inventado
			  when x"75" => saida := x"e8"; --num8  Codigo Inventado
			  when x"7d" => saida := x"e9"; --num9  Codigo Inventado
			 
				
			  when x"16" => saida := x"31"; --1
			  when x"1e" => saida := x"32"; --2
			  when x"26" => saida := x"33"; --3
			  when x"25" => saida := x"34"; --4
			  when x"2e" => saida := x"35"; --5
			  when x"36" => saida := x"36"; --6
			  when x"3d" => saida := x"37"; --7
			  when x"3e" => saida := x"38"; --8
			  when x"46" => saida := x"39"; --9
			  when x"45" => saida := x"30"; --0
			  
			  when x"05" => saida := x"f1"; --F1  Codigo Inventado
			  when x"06" => saida := x"f2"; --F2  Codigo Inventado
			  when x"04" => saida := x"f3"; --F3  Codigo Inventado
			  when x"0C" => saida := x"f4"; --F4  Codigo Inventado
			  when x"03" => saida := x"f5"; --F5  Codigo Inventado
			  when x"0B" => saida := x"f6"; --F6  Codigo Inventado
			  when x"83" => saida := x"f7"; --F7  Codigo Inventado
			  when x"0A" => saida := x"f8"; --F8  Codigo Inventado
			  when x"01" => saida := x"f9"; --F9	Codigo Inventado
			  when x"09" => saida := x"fa"; --F10  Codigo Inventado
			  when x"78" => saida := x"fb"; --F11  Codigo Inventado
			  when x"07" => saida := x"fc"; --F12  Codigo Inventado
				
			  when others => saida := x"ff";	-- Se nao for nenhum desses, responde FF
			end case;
		case state is
			when idle =>
				int <= '0';
				if(saida /= x"ff") then					--pressiona
				  state <= press;
				end if;
				buffero <= saida;
			when press =>
				int <= '1';		
				state <= pressed;
			when pressed =>
				if(saida = x"ff") then					--pressiona	
					state <= released;
				end if;
				int <= '0';
			when released =>
				buffero <= x"80" or buffero;
				int <= '1';		
				saida := x"ff";
				state <= idle;	
			when others =>
				state <= idle;
		end case;
		bin_digit <= buffero;
    end if;
END PROCESS;


PROCESS (f2, scan_rd)
	
 BEGIN
  if(f2='0') then
	 if(scan_rd'EVENT AND scan_rd='1') then
		f<='1';
	 end if;
  else 
	 f<='0';
  end if;
END PROCESS;

----------------- -- -------------------------------

PROCESS(clk) 
 BEGIN
	if(rising_edge(clk))then	 
	 if(f='1') then
		case s is
			when '0' =>
			  f3 <= '1';
				s <= '1';
			when '1' =>
			  f3 <= '0';
			  f2 <= '1';
				s <= '0';
		end case;
	 else
		 f2 <='0';
	 end if;
 end if;

END PROCESS;
--------------- -- ----------------------------------


END a;
