LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.ALL;
USE  IEEE.STD_LOGIC_ARITH.ALL;
USE  IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY ledController IS
	PORT(
			clk : in std_logic;
			rst : in std_logic;
			bus_addr : in std_LOGIC_VECTOR(15 downto 0);
			bus_dq 	: in STD_LOGIC_VECTOR(15 DOWNTO 0);
			bus_req 	: in std_LOGIC;
			bus_rw 	: in std_LOGIC;
			q : out STD_LOGIC_VECTOR(15 downto 0)
		);
END ledController;

ARCHITECTURE behavioral OF ledController IS
SIGNAL data : STD_LOGIC_VECTOR(15 DOWNTO 0) := x"0000";
BEGIN	
	process(rst , clk)
	begin
		if(rst = '1') then
				data <= x"0000";
		elsif(rising_edge(clk)) then
			if(bus_req = '1' and bus_rw = '1' and bus_addr= x"978") then
				data <= bus_dq;
			end if;
			q <= data;
		end if;
	end process;

END behavioral;