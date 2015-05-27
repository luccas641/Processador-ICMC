LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.ALL;
USE  IEEE.STD_LOGIC_ARITH.ALL;
USE  IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY gpioController IS
	PORT(
			clk		: in std_logic;
			rst 		: in std_logic;
			gpio1		: inout STD_LOGIC_VECTOR(15 downto 0);
			gpio2		: inout STD_LOGIC_VECTOR(15 downto 0);
			bus_dq 	: inout STD_LOGIC_VECTOR(15 DOWNTO 0);
			bus_addr : in std_logic_vector(15 downto 0);
			bus_req 	: in std_logic;
			bus_rw	: in std_logic;
			int   	: out std_logic_vector(1 downto 0)
		);
END gpioController;

ARCHITECTURE behavioral OF gpioController IS
SIGNAL data1 : STD_LOGIC_VECTOR(15 DOWNTO 0) := x"0000";
SIGNAL data2 : STD_LOGIC_VECTOR(15 DOWNTO 0) := x"0000";

signal write1 : std_logic;
signal write2 : std_logic;
BEGIN
	PROCESS(rst, clk)
	BEGIN
		if(rising_edge(clk))then
			write1<= '0';
			write2<= '0';
			if(bus_rw= '1'and bus_req = '1') then
				if(bus_addr = x"0963") then
					write1 <= '1';
					bus_dq <= (others => 'Z');
				elsif(bus_addr = x"0964") then
				elsif(bus_addr = x"0965") then
					write2 <= '1';
					bus_dq <= (others => 'Z');				
				elsif(bus_addr = x"0966") then	
				end if;			
			elsif(bus_rw= '0'and bus_req = '1') then
				if(bus_addr = x"0963") then
					bus_dq <= data1;				
				elsif(bus_addr = x"0965") then
					bus_dq <= data1;				
				end if;
			else
				bus_dq <= (others => 'Z');
			end if;
		end if;
	END PROCESS;

	process(gpio1, write1, clk, rst)
	begin
		if(rst = '1') then
			int(0) <= '0';
		elsif(write1 = '1') then
			data1 <= bus_dq;
		elsif(gpio1 /= data1 and gpio1 /= "ZZZZZZZZZZZZZZZZ") then
			gpio1 <= "ZZZZZZZZZZZZZZZZ";
			data1 <= gpio1;
			int(0) <= '1';
		elsif(rising_edge(clk))then
			int(0) <= '0';
		end if;
	end process;
	
	process(gpio2, write2, clk, rst)
	begin
		if(rst = '1') then
			int(1) <= '0';
		elsif(write2 = '1') then
			data2 <= bus_dq;
		elsif(gpio2 /= data2 and gpio2 /= "ZZZZZZZZZZZZZZZZ") then
			gpio2 <= "ZZZZZZZZZZZZZZZZ";
			data2 <= gpio2;
			int(1) <= '1';
		elsif(rising_edge(clk))then
			int(1) <= '0';
		end if;
	end process;
END behavioral;