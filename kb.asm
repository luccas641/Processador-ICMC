loadn R7, #kb
store 16131, R7

loadn r1, #2304
loadn r2, #0
EI
loop:
	jmp loop
	
kb:	
	push FR
	in r3, r1
	out r3, r2
	pop FR
	rts
	