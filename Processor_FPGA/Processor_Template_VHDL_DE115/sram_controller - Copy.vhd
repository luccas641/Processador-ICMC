LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
USE  IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

ENTITY SRAM_CONTROLLER IS
	PORT(
			--controls
			 clk			: in std_logic;
			 rst			: in std_logic;
			 --wishbone
			 bus_d	 	: in std_logic_vector(15 downto 0);
			 bus_q	 	: out std_logic_vector(15 downto 0);
			 bus_addr	: in std_logic_vector(19 downto 0);
			 bus_rw 		: in std_logic;
			 bus_req 	: in std_logic;
			 bus_ack		: out std_logic;
			 --sram 
			 sram_dq 	: inout std_logic_vector(15 downto 0);
			 sram_addr	: out std_logic_vector(19 downto 0);
			 sram_ce_n	: out std_logic;
			 sram_oe_n	: out std_logic;
			 sram_we_n	: out std_logic;
			 sram_ub_n	: out std_logic;
			 sram_lb_n	: out std_logic
			);
END SRAM_CONTROLLER;

ARCHITECTURE behavioral OF SRAM_CONTROLLER IS
type States is (idle, r0, r1, w0, w1);

signal current_state : States;
signal next_state : States;



signal sram_addr_r : std_logic_vector(19 downto 0) := (others => '0');
signal sram_dq_r : std_logic_vector(15 downto 0) := (others => '0');
signal sram_we_n_r : std_logic := '0';
signal sram_oe_n_r : std_logic := '0';


signal addr_r : std_logic_vector(19 downto 0);
signal dat_o_r : std_logic_vector(15 downto 0);
signal ack_o_r : std_logic;
signal dat_i_r : std_logic_vector(15 downto 0) := x"0000";
signal we_i_r : std_logic;
signal oe : std_logic;
signal stb_i_r : std_logic;
signal oe_r : std_logic;

begin

  -- register command
  process (clk, rst) begin
	if(rst = '0' and  rising_edge(clk)) then
		if ((stb_i_r='1') and (current_state = w0 or current_state = r0)) then
		  stb_i_r <= '0';
		elsif (bus_req = '1') then 
		  addr_r <= bus_addr;
		  if(bus_rw = '1') then
			dat_i_r <= bus_d;
		  end if;
		  we_i_r <= bus_rw;
		  stb_i_r <= bus_req;
		end if;
    end if;
  end process;
  
  
	  process(clk,rst) begin
		 if (rst='1') then 
			current_state <= idle;
		 elsif(rising_edge(clk)) then
			current_state <= next_state;
		 end if;
	  end process;
	  
   process (next_state, current_state, clk) begin
	if(rst = '1') then
		next_state <= idle;
	else
		case (current_state) is
				when idle =>
					if (stb_i_r='1' and we_i_r='1') then         next_state <= w0;
					elsif (stb_i_r='1' and we_i_r='0') then      next_state <= r0;
					else                         						next_state <= Idle;
					end if;
				when w0 =>
					next_state <= w1;
				when w1 =>
					next_state <= idle;
				when r0 =>
					next_state <= r1;
				when r1 =>
					next_state <= idle;
				when others =>
					next_state <= idle;
			end case;
		end if;
	end process;
	
	-- ack_o signal
  process(clk, rst) begin
	if (rst='1') then 
	    ack_o_r <= '0';
	elsif(rising_edge(clk)) then
		if (current_state = idle) then
		  ack_o_r <= '0';
		elsif (current_state = r1 or
			current_state = w1) then
		  ack_o_r <= '1';
		end if;
	end if;
	end process;

  
  -- data
  process(clk, rst) begin
    if (rst='1') then
      dat_o_r <= (others => '0');
      sram_dq_r <= (others => '0');
      oe_r <= '0';
	elsif(rising_edge(clk)) then
		 if (current_state = W0) then
		   dat_o_r <= dat_i_r;
			sram_dq_r <= dat_i_r;
			oe_r <= '1';
		 elsif (current_state = W1) then
			sram_dq_r <= dat_i_r;
			dat_o_r <= dat_i_r;
			oe_r <= '1';
		 elsif (current_state = R0) then
			sram_dq_r <= (others => 'Z');
			dat_o_r <= sram_dq;
			oe_r <= '0';
		 elsif (current_state = R1) then
			dat_o_r <= sram_dq;
			sram_dq_r <= (others => 'Z');
			oe_r <= '0';
		 else
			sram_dq_r <= (others => 'Z');
			oe_r <= '0';
		 end if;
	end if;
  end process;

  
  -- address
  process(clk) begin
    if(rising_edge(clk)) then
		 if (current_state = W0 or current_state = R0) then
			sram_addr_r <= addr_r;
		 end if;
	 end if;
  end process;

  
  -- commands
  process(clk) begin
	 if(rising_edge(clk)) then
		if (current_state = R0 or current_state = R1) then
			 sram_oe_n_r <= '0' ;
		 else
			 sram_oe_n_r <= '1';
		  end if;
		if (current_state = W0 or current_state = W1)then
			sram_we_n_r <= '0' ;
		else
			sram_we_n_r <= '1';
		end if;
	end if;
  end process;
	
	sram_addr <= sram_addr_r;
	sram_we_n <= sram_we_n_r;
	sram_oe_n <= sram_oe_n_r;
	sram_ub_n <= '0';
	sram_lb_n <= '0';
	sram_ce_n <= '0';
	sram_dq <= sram_dq_r when oe_r = '1' else
				(others => 'Z');
				
	bus_q <= dat_o_r ;
	bus_ack <= ack_o_r;	

end architecture;

