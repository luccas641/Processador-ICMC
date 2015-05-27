LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
USE  IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

ENTITY videolatch IS
	PORT(
			CLK : IN STD_LOGIC;
			RST : IN STD_LOGIC;
			iDRAW : IN STD_LOGIC;
			iLPOS : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			iCHAR : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			
			oDRAW : out STD_LOGIC;
			oLPOS : out STD_LOGIC_VECTOR(15 DOWNTO 0);
			oCHAR : out STD_LOGIC_VECTOR(15 DOWNTO 0)
		);
END videolatch;

ARCHITECTURE behavioral OF videolatch IS
SIGNAL DRAW : STD_LOGIC := '0';
SIGNAL LPOS : STD_LOGIC_VECTOR(15 DOWNTO 0);
SIGNAL CHAR : STD_LOGIC_VECTOR(15 DOWNTO 0);
BEGIN
	process(clk)
	begin
		if(rising_edge(clk)) then
			oDRAW <= DRAW;
			oLPOS <= LPOS;
			oCHAR <= CHAR;
		end if;
	end process;
	
	process(iDRAW)
	begin
		if(rising_edge(iDRAW)) then
			DRAW <= iDRAW;
			LPOS <= iLPOS;
			CHAR <= iCHAR;
			-- Este bloco troca a cor do preto pelo branco: agora a cor "0000" = Branco !
			if( iCHAR(11 downto 8) = "0000" ) then
				CHAR(11 downto 8) <= "1111";
			elsif( iCHAR(11 downto 8) = "1111" ) then
				CHAR(11 downto 8) <= "0000";
			end if;
		end if;
	end process;
end architecture;