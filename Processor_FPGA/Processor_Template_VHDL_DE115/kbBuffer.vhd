LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
USE  IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

ENTITY kbBuffer IS
	PORT(
			CLK : IN STD_LOGIC;
			CLR : IN STD_LOGIC;
			LOAD : IN STD_LOGIC;
			I : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
			O : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
		);
END kbBuffer;

ARCHITECTURE behavioral OF kbBuffer IS
SIGNAL DATA : STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN
	PROCESS(CLK, CLR)
	BEGIN
		IF(CLK'EVENT AND CLK = '1') THEN
			IF(LOAD = '1' and DATA = x"00") THEN
				DATA <= I;
			ELSIF(CLR = '1') THEN
				O <= "00000000" & DATA;
				DATA <= (others => '0');
			else
				O <= (others => 'Z');
			END IF;
		END IF;
	END PROCESS;
END behavioral;