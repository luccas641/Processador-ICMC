loadn R7, #kb
store 16131, R7

loadn r2, #0
EI

x : var #1
y : var #1

loadn r0, #0
out r0, r0
loadn r1, #1
loadn r2, #1200

;bg
bg:
	out r0, r1
	out r0, r1
	dec r2
jnz bg
breakp
;sprite 0
loadn r1, #4
out r0, r1
inc r1
loadn r0, #255
out r5, r1
out r5, r1
out r5, r1
out r5, r1
out r5, r1
out r5, r1
out r5, r1
out r5, r1


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
	pop FR
	rts
	