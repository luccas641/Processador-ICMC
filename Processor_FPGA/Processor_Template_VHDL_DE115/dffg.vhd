LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.ALL;
USE  IEEE.STD_LOGIC_ARITH.ALL;
USE  IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY dffg IS
	generic(
		width : integer := 16
	);
	PORT(
			rst 		: in std_logic;
			clk 		: in std_logic;
			en			: in std_logic;
			d			: in std_logic_vector(width-1 downto 0);
			q			: out std_logic_vector(width-1 downto 0)
		);
END dffg;

ARCHITECTURE main OF dffg IS
BEGIN
	PROCESS(clk, rst)
	BEGIN
		if rst='1' then
			q <= (others => '0');
		elsif(rising_edge(clk)) then
			if(en = '1') then
				q <= d;
			end if;
		end if;
	END PROCESS;
END main;