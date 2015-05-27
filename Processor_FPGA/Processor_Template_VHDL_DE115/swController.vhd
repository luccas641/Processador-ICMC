LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.ALL;
USE  IEEE.STD_LOGIC_ARITH.ALL;
USE  IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY swController IS
	PORT(
			clk : in std_logic;
			rst : in std_logic;
			bus_addr : in std_LOGIC_VECTOR(15 downto 0);
			bus_dq 	: OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
			bus_ack 	: OUT std_LOGIC;
			bus_req 	: in std_LOGIC;
			bus_rw 	: in std_LOGIC;
			d : IN STD_LOGIC_VECTOR(15 downto 0);
			int : out std_logic
		);
END swController;

ARCHITECTURE behavioral OF swController IS
SIGNAL obuffer : STD_LOGIC_VECTOR(15 DOWNTO 0) := x"0000";
SIGNAL ibuffer : STD_LOGIC_VECTOR(15 DOWNTO 0) := x"0000";
signal counter : integer := 0;
BEGIN
	readp: process(rst, clk)
	begin
		if(rising_edge(clk)) then
			if(bus_req = '1' and bus_rw = '0' and bus_addr = x"0967") then
				bus_dq <= obuffer;
				bus_ack <= '1';
			else
				bus_ack <= '0';
				bus_dq <= (others => 'Z');
			end if;
		end if;
	end process;
	
	
	writep: process(rst, clk)
	begin
		if(rst = '1') then	
			counter <= 0;
			ibuffer <= x"1111";
			ibuffer <= x"2222";
		elsif(rising_edge(clk)) then
			int <= '0';
			if(unsigned(d) /= unsigned(ibuffer)) then
				counter <= 0;	
				ibuffer <= d;
			elsif(counter > 10000) then
				if(unsigned(ibuffer) /= unsigned(obuffer)) then
					obuffer <= d;
					int <= '1';
				end if;
				counter <= 0;	
			else
				counter <= counter + 1;
			end if;
		end if;
	end process;

END behavioral;