LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.ALL;
USE  IEEE.STD_LOGIC_ARITH.ALL;
USE  IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY busTriState IS
	PORT(
			clk : in std_logic;
			rst : in std_logic;
			rw	 : in std_logic;
			d	 : in std_logic_vector(15 downto 0);
			q	 : out std_logic_vector(15 downto 0);
			dq  : inout std_logic_vector
		);
END busTriState;

ARCHITECTURE main OF busTriState IS
BEGIN
	PROCESS(clk, rst)
	BEGIN
		if (rst ='1') then
			dq <= (others => 'Z');
		elsif (rising_edge(clk)) then
			if (rw = '1') then
				dq <= d;
			else
				dq <= (others => 'Z');
				q <= dq;
			end if;
		end if;
	END PROCESS;
END main;