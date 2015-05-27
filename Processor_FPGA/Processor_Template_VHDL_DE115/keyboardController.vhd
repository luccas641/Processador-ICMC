LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
USE  IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

ENTITY keyboardController IS
	PORT(	keyboard_clk, keyboard_data, 
			reset, read		: IN	STD_LOGIC;
			scan_code		: OUT	STD_LOGIC_VECTOR(7 DOWNTO 0);
			scan_ready		: OUT	STD_LOGIC);
END keyboardController;

ARCHITECTURE a OF keyboardController IS
	SIGNAL INCNT					: std_logic_vector(3 downto 0);
	SIGNAL SHIFTIN 					: std_logic_vector(8 downto 0);
	SIGNAL READ_CHAR 				: std_logic;
	SIGNAL INFLAG, ready_set		: std_logic;
	SIGNAL filter 					: std_logic_vector(7 downto 0);
BEGIN

PROCESS (read, ready_set)
BEGIN
  IF read = '1' THEN scan_ready <= '0';
  ELSIF ready_set'EVENT and ready_set = '1' THEN
	scan_ready <= '1';
  END IF;
END PROCESS;

--This process reads in serial data coming from the terminal
PROCESS
BEGIN
WAIT UNTIL (KEYBOARD_CLK'EVENT AND KEYBOARD_CLK='1');
IF RESET='1' THEN
        INCNT <= "0000";
        READ_CHAR <= '0';
ELSE
  IF KEYBOARD_DATA='0' AND READ_CHAR='0' THEN
        READ_CHAR<= '1';
        ready_set<= '0';
  ELSE
			-- Shift in next 8 data bits to assemble a scan code
    IF READ_CHAR = '1' THEN
        IF INCNT < "1001" THEN
         	INCNT 				<= INCNT + 1;
         	SHIFTIN(7 DOWNTO 0) <= SHIFTIN(8 DOWNTO 1);
         	SHIFTIN(8) 			<= KEYBOARD_DATA;
  	ready_set <= '0';
			-- End of scan code character, so set flags and exit loop
        ELSE
	 	   	scan_code 			<= SHIFTIN(7 DOWNTO 0);
	   		READ_CHAR			<='0';
	    	ready_set 			<= '1';
	    	INCNT 				<= "0000";
        END IF;
     END IF;
   END IF;
 END IF;
END PROCESS;
END a;
