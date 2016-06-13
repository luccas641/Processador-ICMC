jmp bootstrap


;;Mario X e Y na tela
x : var #1
y : var #1

;;	SPRITES
;
;	Parecido com o CHARMAP mas usa os 16 bits para conseguir 4 cores por sprite
; Pra escolher a cor, vc junta os numeros da mesma posicao:
;	10000000 10000001 <- dessa forma o sprite vai ter o primeiro prixel a direita a cor 1 da paleta (01) e o mais a esquerda 3 (11)
; a cada 8 entradas forma 1 sprite.
;
sprites : var #2048
static sprites + #0, #255 ;Sprite 0 - Bloco preenchido com cor 1
static sprites + #1, #255
static sprites + #2, #255
static sprites + #3, #255
static sprites + #4, #255
static sprites + #5, #255
static sprites + #6, #255
static sprites + #7, #255
static sprites + #8, #255 ; Sprite 1 - Bloco Preenchido com cor 1
static sprites + #9, #255
static sprites + #10, #255
static sprites + #11, #255
static sprites + #12, #255
static sprites + #13, #255
static sprites + #14, #255
static sprites + #15, #255
static sprites + #16, #15420	; Sprite 2 - Mario
static sprites + #17, #15934
static sprites + #18, #5160
static sprites + #19, #60
static sprites + #20, #32475
static sprites + #21, #15360
static sprites + #22, #15360
static sprites + #23, #9252
static sprites + #24, #255
static sprites + #25, #255
static sprites + #26, #255
static sprites + #27, #255
static sprites + #28, #255
static sprites + #29, #255
static sprites + #30, #255
;Adicionar os outros

;; PALETA
;
;	Temos 32 paletas, cada paleta tem 3 cores + 1 transparente
; A cada 4 entradas forma 1 paleta.
;	Mesmo que vc coloque uma cor na primeira entrada de uma paleta, ela vai continuar sendo transparente.
; as cores sao no formato RGB -> 0RRRRRGGGGGBBBBB
;
paleta : var #128
static paleta + #0, #7674	; Paleta 0 - transparente
static paleta + #1, #7674 ; Cor azul do BG
static paleta + #2, #7674 ; Cor azul do BG
static paleta + #3, #7674 ; Cor azul do BG
static paleta + #4, #0		; Paleta 1 -
static paleta + #5, #0
static paleta + #6, #0
static paleta + #7, #0
static paleta + #8, #0		; Paleta 2 - Mario
static paleta + #9, #25521
static paleta + #10, #31
static paleta + #11, #31744
static paleta + #12, #0
static paleta + #13, #0
static paleta + #14, #0
static paleta + #15, #0
static paleta + #16, #0
static paleta + #17, #0
static paleta + #18, #0
static paleta + #19, #0
static paleta + #20, #0
;Adicionar os outros

;; Background
;
;	Parecido com o do video anterior.
;	cada posicao vc escolhe uma paleta e um sprite pra ser o background
; Primeiro vc envia o sprite e depois envia a paleta que esse sprite vai usar
;
background : var #1200			; 1200 posicoes da tela
static background + #0, #0
static background + #1, #0
static background + #2, #0
static background + #3, #0
static background + #4, #0
static background + #5, #0
;Adicionar os outros

;; OAM Object Attribute Memory
;	OAM é a memoria que guarda os personagens e objetos que se mexem. Ex: Mario
;	Tem que enviar 4 dados nessa ordem:
;			Coordenada X
;			Coordenada Y
;			Endereco do Sprite
;			Endereco da Paleta
;
oam : var #512					; 128 personagens na tela ao mesmo tempo, cada um usa 4 posicoes.
static oam + #0, #0			; OAM 0 - x
static oam + #1, #0			; y
static oam + #2, #16		; sprite
static oam + #3, #2			; Paleta
static oam + #4, #0			; OAM 1
static oam + #5, #0
static oam + #6, #0
static oam + #7, #0
;Adicionar os outros

bootstrap:

;Carregar rotina de interrupcao que vai ler teclado
;esta rotina tem que terminar com RTI
loadn R7, #kb
store 16131, R7

EI		;habilitar interrupcao, sem isso o teclado e o timer nao funcionam

;Endereça os sprites para 0
loadn r0, #0
loadn r1, #4
out r0, r1

;Adiciona os sprites
loadn r1, #5						;porta do sprites
loadn r2, #sprites			;endereco dos sprites
loadn r3, #30						;repeticoes
loopLoadSprites:
	loadi r0, r2
	out r0, r1
	inc r2
	dec r3
	jnz loopLoadSprites


;Adiciona as paletas de cores
loadn r1, #7						;porta do paleta
loadn r2, #paleta				;endereco dos paletas
loadn r3, #30						;repeticoes
loopLoadPaletas:
	loadi r0, r2
	out r0, r1
	inc r2
	dec r3
	jnz loopLoadPaletas


;Adiciona as OAM
loadn r1, #3						;porta do oam
loadn r2, #oam					;endereco dos OAMs
loadn r3, #30						;repeticoes
loopLoadOAMs:
	loadi r0, r2
	out r0, r1
	inc r2
	dec r3
	jnz loopLoadOAMs

main:
	;;Endereça o OAM
	loadn r0, #0	; Endereço 0 pra alterar o mario
	loadn r1, #2	; Porta de setar endereço do OAM
	out r0, r1
	inc r1
	load r0, x		; Enviar X novo
	out r0, r1
	load r0, y		; Envia Y novo
	out r0, r1

	jmp main

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
	rti ;retorno de interrupcao
