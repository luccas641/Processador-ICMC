loadn R7, #kb
store 16131, R7

EI

loadn r0, #0
out r0, r0
loadn r1, #1
loadn r2, #1200

;bg
;bg:
	;out r0, r1
	;out r0, r1
	;dec r2
;jnz bg

;sprite 0
loadn r1, #4
out r0, r1
inc r1
loadn r0, #255
out r0, r1
out r0, r1
out r0, r1
out r0, r1
out r0, r1
out r0, r1
out r0, r1
out r0, r1


dec r1
loadn r0, #16
out r0, r1
inc r1

loadn r0, #15420
out r0, r1
loadn r0, #15934
out r0, r1
loadn r0, #5160
out r0, r1
loadn r0, #60
out r0, r1
loadn r0, #32475
out r0, r1
loadn r0, #15360
out r0, r1
loadn r0, #15360
out r0, r1
loadn r0, #9252
out r0, r1

;addr color 0
loadn r0, #0
loadn r1, #6
out r0, r1

loadn r0, #0
loadn r1, #7
out r0, r1
loadn r0, #7674
out r0, r1
out r0, r1
out r0, r1

;addr color 2
loadn r0, #8
loadn r1, #6
out r0, r1

loadn r0, #0
loadn r1, #7
out r0, r1
loadn r0, #25521
out r0, r1
loadn r0, #31
out r0, r1
loadn r0, #31744
out r0, r1

;OAM #0
loadn r0, #0
loadn r1, #2
out r0, r1
inc r1
load r0, x
out r0, r1
load r0, y
out r0, r1
loadn r0, #16
out r0, r1
loadn r0, #2
out r0, r1

loop:
	loadn r0, #0
	loadn r1, #2
	out r0, r1
	inc r1
	load r0, x
	out r0, r1
	load r0, y
	out r0, r1
	jmp loop
	
kb:	
	push FR
	push r0
	push r1
	push r2
	push r3

	loadn r1, #2304
	in r3, r1
	load r0, x
	inc r0
	store x, r0

	pop r3
	pop r2
	pop r1
	pop r0
	pop FR
	rti
	
x : var #1
y : var #1