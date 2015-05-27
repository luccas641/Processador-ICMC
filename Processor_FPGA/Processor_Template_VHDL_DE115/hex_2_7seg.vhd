LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.ALL;
USE  IEEE.STD_LOGIC_ARITH.ALL;
USE  IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY hex_2_7seg IS
	PORT(
			rst 		: in std_logic;
			clk 		: in std_logic;
			bus_dq 	: IN STD_LOGIC_VECTOR(15 downto 0);
			bus_addr : in std_logic_vector(15 downto 0);
			bus_req  : in std_LOGIC;
			bus_rw	: in std_LOGIC;
			HEX0 : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			HEX1 : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			HEX2 : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			HEX3 : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			HEX4 : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			HEX5 : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			HEX6 : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			HEX7 : OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
		);
END hex_2_7seg;

ARCHITECTURE main OF hex_2_7seg IS
SIGNAL data0 : STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000000";
SIGNAL data1 : STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000000";
SIGNAL data2 : STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000000";
SIGNAL data3 : STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000000";
SIGNAL data4 : STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000000";
SIGNAL data5 : STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000000";
SIGNAL data6 : STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000000";
SIGNAL data7 : STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000000";

function hex2seg(hex : std_logic_vector(15 downto 0))
              return std_logic_vector is
begin
  	CASE hex(3 downto 0) IS
			WHEN "0000" =>
				return "0111111";
			WHEN "0001" =>
				return "0000110";
			WHEN "0010" =>
				return "1011011";
			WHEN "0011" =>
				return "1001111";
			WHEN "0100" =>
				return "1100110";
			WHEN "0101" =>
				return "1101101";
			WHEN "0110" =>
				return "1111101";
			WHEN "0111" =>
				return "0000111";
			WHEN "1000" =>
				return "1111111";
			WHEN "1001" =>
				return "1101111"; 
			WHEN "1010" =>
				return "1110111";
			WHEN "1011" =>
				return "1111100"; 
			WHEN "1100" =>
				return "0111001"; 
			WHEN "1101" =>
				return "1011110"; 
			WHEN "1110" =>
				return "1111001"; 
			WHEN "1111" =>
				return "1110001"; 
			WHEN OTHERS =>
				return "1000000";
		END CASE;
end hex2seg;


BEGIN
	PROCESS(clk, rst)
	BEGIN
		if rst='1' then
			data0 <= "0000000";
			data1 <= "0000000";
			data2 <= "0000000";
			data3 <= "0000000";
			data4 <= "0000000";
			data5 <= "0000000";
			data6 <= "0000000";
			data7 <= "0000000";
		elsif(rising_edge(clk)) then
			if(bus_rw = '1' and bus_req= '1') then
				case bus_addr is
					when x"0970" =>
						data0 <= hex2seg(bus_dq);
					when x"0971" =>
						data1 <= hex2seg(bus_dq);
					when x"0972" =>
						data2 <= hex2seg(bus_dq);
					when x"0973" =>
						data3 <= hex2seg(bus_dq);
					when x"0974" =>
						data4 <= hex2seg(bus_dq);
					when x"0975" =>
						data5 <= hex2seg(bus_dq);
					when x"0976" =>
						data6 <= hex2seg(bus_dq);
					when x"0977" =>
						data7 <= hex2seg(bus_dq);
					when others =>
				end case;
			end if;
		end if;
		HEX0 <= NOT data0;
		HEX1 <= NOT data1;
		HEX2 <= NOT data2;
		HEX3 <= NOT data3;
		HEX4 <= NOT data4;
		HEX5 <= NOT data5;
		HEX6 <= NOT data6;
		HEX7 <= NOT data7;
	END PROCESS;


END main;