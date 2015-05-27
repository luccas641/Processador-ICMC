LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
USE  IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

ENTITY busActive IS
	generic(
			addrini		: std_logic_vector(15 downto 0) := x"0000";
			addrfim		: std_logic_vector(15 downto 0) := x"0000";
			rw				: std_logic := '0'
	);
	PORT(	bus_addr : in std_logic_vector(15 downto 0);
			bus_req 	: in std_logic;
			bus_rw	: in std_logic;
			en			: out std_logic
	);
END busActive;

ARCHITECTURE behavioral OF busActive IS
BEGIN
	en <= '1' when bus_addr >= addrini and bus_addr <= addrfim and bus_rw = rw and bus_req = '1' else
			'0';
	
END behavioral;
