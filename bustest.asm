loadn R7, #timer
store 16130, R7

loadn r7, #2451		; PIT Controller	
loadn r0, #4		; Activate counter 2
out r0, r7

loadn r7, #2450		; PIT Counter 2
loadn r0, #10000
out r0, r7

loadn r3, #'0'
loadn r2, #0

EI
loop:
	jmp loop
	
timer:	
	push FR
	out r3, r2
	inc r3
	pop FR
	rts
	