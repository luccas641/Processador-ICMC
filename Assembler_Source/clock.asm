loadn R7, #pit0Handler
store 16128, R7
store 16129, R7
store 16130, R7

loadn r7, #2451	; PIT Controller	
loadn r0, #4			; Activate counter 2
out r0, r7

loadn r7, #2450	; PIT Counter 2
loadn r0, #2000
out r0, r7

loadn r0, #0
loadn r1, #0
loadn r2, #0
loadn r3, #0

EI
main: jmp main

pit0Handler:	
	loadn r6, #10
	loadn r7, #6
	;;seg dig 1
	inc r0
	cmp r0, r6
	jne continue
	loadn r0, #0
	;;seg dig 2
	inc r1
	cmp r1, r7
	jne continue
	loadn r1, #0
	;;min dig 1
	inc r2
	cmp r2, r6
	jne continue
	loadn r2, #0
	;;min dig2
	inc r3
	continue:
	loadn r4, #2416 
	loadn r5, #2417
	loadn r6, #2418
	loadn r7, #2419
	out r0, r4
	out r1, r5
	out r2, r6
	out r3, r7
	rts