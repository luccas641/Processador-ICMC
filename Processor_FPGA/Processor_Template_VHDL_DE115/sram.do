vcom -reportprogress 300 -work work {D:/desktop/AP9 - Template/sram_controller.vhd}
vsim -voptargs=+acc work.sram_controller
add wave -position insertpoint  \
sim:/sram_controller/bus_addr \
sim:/sram_controller/bus_req \
sim:/sram_controller/bus_rw \
sim:/sram_controller/clk \
sim:/sram_controller/rst \
sim:/sram_controller/bus_ack \
sim:/sram_controller/sram_addr \
sim:/sram_controller/sram_ce_n \
sim:/sram_controller/sram_oe_n \
sim:/sram_controller/sram_we_n \
sim:/sram_controller/bus_d \
sim:/sram_controller/bus_q \
sim:/sram_controller/sram_dq \
sim:/sram_controller/current_state \
sim:/sram_controller/next_state
# Loading work.sram_controller(behavioral)
force -freeze sim:/sram_controller/rst 1 0
force -freeze sim:/sram_controller/clk 1 0, 0 {50 ps} -r 100
force -freeze sim:/sram_controller/bus_req 1 0
run
run
force -freeze sim:/sram_controller/bus_addr 00000000000000000000 0
force -freeze sim:/sram_controller/bus_rw 0 0
run
run
force -freeze sim:/sram_controller/rst 0 0
run
run
run
run
force -freeze sim:/sram_controller/bus_req 1 0
force -freeze sim:/sram_controller/bus_addr 00000000000000000001 0
run
force -freeze sim:/sram_controller/bus_addr 00000000000000000000 0
run
run
run
run
run
run
run
force -freeze sim:/sram_controller/sram_dq 1111111111111111 0
force -freeze sim:/sram_controller/bus_addr 00000000000000000001 0
run
run
run
force -freeze sim:/sram_controller/sram_dq 1111111111111110 0
run
run
run
run
run
run
