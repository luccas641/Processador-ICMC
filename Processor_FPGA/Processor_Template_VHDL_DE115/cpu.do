# reading C:\altera\13.1\modelsim_ase\win32aloem/../modelsim.ini
vcom -work work -O0 {D:/desktop/AP9 - Template/cpu.vhd}
# Model Technology ModelSim ALTERA vcom 10.1d Compiler 2012.11 Nov  2 2012
# -- Loading package STANDARD
# -- Loading package TEXTIO
# -- Loading package std_logic_1164
# -- Loading package std_logic_arith
# -- Loading package STD_LOGIC_UNSIGNED
# -- Compiling entity cpu
# -- Compiling architecture main of cpu
vsim -voptargs=+acc work.cpu
# vsim -voptargs=+acc work.cpu 
# Loading std.standard
# Loading std.textio(body)
# Loading ieee.std_logic_1164(body)
# Loading ieee.std_logic_arith(body)
# Loading ieee.std_logic_unsigned(body)
# Loading work.cpu(main)
add wave -position insertpoint  \
sim:/cpu/clk \
sim:/cpu/reset \
sim:/cpu/Mem \
sim:/cpu/M5 \
sim:/cpu/M1 \
sim:/cpu/RW \
sim:/cpu/bus_data \
sim:/cpu/bus_addr \
sim:/cpu/bus_rw \
sim:/cpu/bus_req \
sim:/cpu/bus_ack \
sim:/cpu/irq \
sim:/cpu/Ponto \
sim:/cpu/halt_ack \
sim:/cpu/halt_req \
sim:/cpu/PC_data \
sim:/cpu/break \
sim:/cpu/boot_mem \
sim:/cpu/CR0 \
sim:/cpu/mirq
force -freeze sim:/cpu/clk 1 0, 0 {50 ps} -r 100
force -freeze sim:/cpu/reset 1 0
force -freeze sim:/cpu/Mem 0000000000000000 0
force -freeze sim:/cpu/boot_mem 0000000000000000 0
force -freeze sim:/cpu/irq 0000000000000000 0
force -freeze sim:/cpu/halt_req 0 0
run
force -freeze sim:/cpu/reset 0 0
run
# ** Warning: There is an 'U'|'X'|'W'|'Z'|'-' in an arithmetic operand, the result will be 'X'(es).
#    Time: 100 ps  Iteration: 1  Instance: /cpu
# ** Warning: There is an 'U'|'X'|'W'|'Z'|'-' in an arithmetic operand, the result will be 'X'(es).
#    Time: 100 ps  Iteration: 1  Instance: /cpu
