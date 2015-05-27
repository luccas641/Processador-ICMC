LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
USE  IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

ENTITY BUSREG IS
	generic(
		width : integer := 16
	);
	
	PORT(
			iCLK : IN STD_LOGIC;
			oCLK : IN STD_LOGIC;
			CLR : IN STD_LOGIC;
			LOAD : IN STD_LOGIC;
			OE	  : in STD_LOGIC;
			I : IN STD_LOGIC_VECTOR(width-1 DOWNTO 0);
			O : OUT STD_LOGIC_VECTOR(width-1 DOWNTO 0);
			bus_ack : out STD_LOGIC
		);
END BUSREG;

ARCHITECTURE main OF BUSREG IS
SIGNAL DATA : STD_LOGIC_VECTOR(width-1 DOWNTO 0) := x"ffff";
BEGIN
	PROCESS(iCLK, CLR)
	BEGIN
		IF(CLR = '1') THEN
			DATA <= x"ffff";
		ELSIF(rising_edge(iCLK)) THEN
			IF(LOAD = '1') THEN
				DATA <= I;
			END IF;
		end if;
	END PROCESS;
	
	PROCESS(oCLK, CLR)
	BEGIN
		IF(CLR = '1') THEN
			O <= (others => 'Z');
			bus_ack <= '0';
		ELSIF(rising_edge(oCLK)) THEN
			if(oe = '1') then
				O <= DATA;
				bus_ack <= '1';
			else
				O <= (others => 'Z');
				bus_ack <= '0';
			end if;
		END IF;
	END PROCESS;
END main;