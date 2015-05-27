LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.ALL;
USE  IEEE.STD_LOGIC_ARITH.ALL;
USE  IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY PIT IS
	PORT(
			clk 		: 	in std_logic;
			rst 	 	: 	in std_logic;
			bus_dq 	: 	inout std_logic_vector(15 downto 0);
			bus_rw 	:	in std_logic;
			bus_req 	:	in std_logic;
			bus_addr :  in std_logic_vector(15 downto 0);
			int		: out std_logic_vector(2 downto 0);
			bus_ack		: out std_logic_vector(2 downto 0)
		);
END PIT;

ARCHITECTURE behavioral OF PIT IS

-- Internal Registers
signal div1			: unsigned(15 downto 0) := x"ffff";
signal div1c		: unsigned(15 downto 0):= x"0000";
signal f1			: std_logic :='0';

signal div2			: unsigned(15 downto 0):= x"ffff";
signal div2c		: unsigned(15 downto 0):= x"0000";
signal f2			: std_logic:='0';

signal div3			: unsigned(15 downto 0):= x"ffff";
signal div3c		: unsigned(15 downto 0):= x"0000";
signal f3			: std_logic:='0';

signal controller  : std_logic_vector(15 downto 0) := x"0000";

signal counter1  : unsigned(15 downto 0):= x"000A";
signal counter2  : unsigned(15 downto 0):= x"0064";
signal counter3  : unsigned(15 downto 0):= x"03E8";

signal inta			: std_logic_vector(2 downto 0);
BEGIN
	process(clk, rst) 
	begin
		if(rst='1') then
			controller <= (others => '0');
			div1 <= (others => '1');
			div2 <= (others => '1');
			div3 <= (others => '1');
		elsif(rising_edge(clk)) then
			bus_ack <= "000";
			if(bus_req = '1') then
				case bus_addr is				
					when x"0990" =>
						if(bus_rw = '1') then
							bus_dq <= (others => 'Z');
							div1 <= unsigned(bus_dq);
						else
							bus_dq <= std_logic_vector(counter1);
							bus_ack <= "001";
						end if;
					when x"0991" =>
						if(bus_rw = '1') then
							bus_dq <= (others => 'Z');
							div2 <= unsigned(bus_dq);
						else
							bus_dq <=std_logic_vector(counter2);
							bus_ack <= "010";
						end if;
					when x"0992" =>
						if(bus_rw = '1') then
							bus_dq <= (others => 'Z');
							div3 <= unsigned(bus_dq);
						else
							bus_dq <=std_logic_vector(counter3);
							bus_ack <= "100";
						end if;
					when x"0993" =>
						if(bus_rw = '1') then
							bus_dq <= (others => 'Z');
							controller <= bus_dq;
						else
							bus_dq <= (others => '0');
						end if;
					when others =>
				end case;
			end if;
		end if; 
	end process;
	
	--geradore de clock
	process(clk, rst)
	begin
		if(rst = '1') then
			div1c <= x"0000";
		elsif(rising_edge(clk)) then
			IF div1c < div1 THEN
				div1c <= div1c + '1';
			ELSE
				div1c <= x"0000";
				f1 <= not f1;
			END IF;	
			IF div2c < div2 THEN
				div2c <= div2c + '1';
			ELSE
				div2c <= x"0000";
				f2 <= not f2;
			END IF;	
			IF div3c < div3 THEN
				div3c <= div3c + '1';
			ELSE
				div3c <= x"0000";
				f3 <= not f3;
			END IF;	
		end if;
	end process;
	
	process(f1, div1, rst)
	begin
		if(rst='1') then
			counter1 <= x"000A";
		elsif(rising_edge(f1)) then
			counter1 <= counter1 - 1;
			if(std_logic_vector(counter1) = x"0000") then
				counter1 <= x"000A";
			end if;
		end if;
	end process;
	
	process(f2, div2, rst)
	begin
		if(rst = '1') then
			counter2<= x"0064";
		elsif(rising_edge(f2)) then
			counter2 <= counter2 - 1;
			if(std_logic_vector(counter2) = x"0000") then
				counter2 <= x"0064";
			end if;
		end if;
	end process;
		
	process(f3, div3, rst)
	begin
		if(rst = '1') then
			counter3 <= x"03E8";
		elsif(rising_edge(f3)) then
			counter3 <= counter3 - 1;
			if(std_logic_vector(counter3) = x"0000") then
				counter3 <= x"03E8";
			end if;
		end if;
	end process;
	
	process(rst, clk)
	begin
		if(rst = '1') then
			int <= "000";
		elsif(rising_edge(clk))then
			int <= "000";
			if(std_logic_vector(counter1) = x"0000") then
				if(controller(0) = '1' and inta(0) = '0') then
					int(0) <= '1';
					inta(0) <= '1';
				end if;
			else
				inta(0) <= '0';
			end if;
			if(std_logic_vector(counter2) = x"0000") then
				if(controller(1) = '1' and inta(1) = '0') then
					int(1) <= '1';
					inta(1) <= '1';
				end if;
			else
				inta(1) <= '0';
			end if;
			if(std_logic_vector(counter3) = x"0000") then
				if(controller(2) = '1' and inta(2) = '0') then
					int(2) <= '1';
					inta(2) <= '1';
				end if;
			else
				inta(2) <= '0';
			end if;
		end if;
	end process;
END behavioral;