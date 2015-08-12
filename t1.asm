;---------- BEGIN - PRE PROCESSAMENTO ----------
; @(27) INSTRUCAO - while
;---------- END PRE PROCESSAMENTO ----------
;---------- BEGIN ----------
jmp __function_label_main__
__and_routine__:
and r0, r1, r0
loadn r1, #0
cmp r0, r1
jne __true__
jmp __false__
__or_routine__:
or r0, r1, r0
loadn r1, #0
cmp r0, r1
jne __true__
jmp __false__
__equal_routine__:
cmp r0, r1
jne __false__
jmp __true__
__not_equal_routine__:
cmp r0, r1
jne __true__
jmp __false__
__less_routine__:
cmp r0, r1
jle __true__
jmp __false__
__more_routine__:
cmp r0, r1
jgr __true__
jmp __false__
__equal_less_routine__:
cmp r0, r1
jel __true__
jmp __false__
__equal_more_routine__:
cmp r0, r1
jeg __true__
jmp __false__
__true__:
loadn r0, #1
storei r2, r0
rts
__false__:
loadn r0, #0
storei r2, r0
rts
; @(1) INSTRUCAO - ; declarando funcao: main
__function_label_main__:

; variavel: i alocada em 28000 com 1 bytes

; endereco temporario(27999) recebe o conteudo: 8
loadn r0, #8
store 27999, r0

; endereco temporario(27998) recebe o conteudo: 4
loadn r0, #4
store 27998, r0

load r0, 27999
load r1, 27998
out r0, r1
; endereco temporario(27997) recebe o conteudo: 15420
loadn r0, #15420
store 27997, r0

; endereco temporario(27996) recebe o conteudo: 5
loadn r0, #5
store 27996, r0

load r0, 27997
load r1, 27996
out r0, r1
; endereco temporario(27995) recebe o conteudo: 15934
loadn r0, #15934
store 27995, r0

; endereco temporario(27994) recebe o conteudo: 5
loadn r0, #5
store 27994, r0

load r0, 27995
load r1, 27994
out r0, r1
; endereco temporario(27993) recebe o conteudo: 5160
loadn r0, #5160
store 27993, r0

; endereco temporario(27992) recebe o conteudo: 5
loadn r0, #5
store 27992, r0

load r0, 27993
load r1, 27992
out r0, r1
; endereco temporario(27991) recebe o conteudo: 60
loadn r0, #60
store 27991, r0

; endereco temporario(27990) recebe o conteudo: 5
loadn r0, #5
store 27990, r0

load r0, 27991
load r1, 27990
out r0, r1
; endereco temporario(27989) recebe o conteudo: 32475
loadn r0, #32475
store 27989, r0

; endereco temporario(27988) recebe o conteudo: 5
loadn r0, #5
store 27988, r0

load r0, 27989
load r1, 27988
out r0, r1
; endereco temporario(27987) recebe o conteudo: 15360
loadn r0, #15360
store 27987, r0

; endereco temporario(27986) recebe o conteudo: 5
loadn r0, #5
store 27986, r0

load r0, 27987
load r1, 27986
out r0, r1
; endereco temporario(27985) recebe o conteudo: 15360
loadn r0, #15360
store 27985, r0

; endereco temporario(27984) recebe o conteudo: 5
loadn r0, #5
store 27984, r0

load r0, 27985
load r1, 27984
out r0, r1
; endereco temporario(27983) recebe o conteudo: 9252
loadn r0, #9252
store 27983, r0

; endereco temporario(27982) recebe o conteudo: 5
loadn r0, #5
store 27982, r0

load r0, 27983
load r1, 27982
out r0, r1
; endereco temporario(27981) recebe o conteudo: 0
loadn r0, #0
store 27981, r0

; endereco temporario(27980) recebe o conteudo: 6
loadn r0, #6
store 27980, r0

load r0, 27981
load r1, 27980
out r0, r1
; endereco temporario(27979) recebe o conteudo: 0
loadn r0, #0
store 27979, r0

; endereco temporario(27978) recebe o conteudo: 7
loadn r0, #7
store 27978, r0

load r0, 27979
load r1, 27978
out r0, r1
; endereco temporario(27977) recebe o conteudo: 25521
loadn r0, #25521
store 27977, r0

; endereco temporario(27976) recebe o conteudo: 7
loadn r0, #7
store 27976, r0

load r0, 27977
load r1, 27976
out r0, r1
; endereco temporario(27975) recebe o conteudo: 31
loadn r0, #31
store 27975, r0

; endereco temporario(27974) recebe o conteudo: 7
loadn r0, #7
store 27974, r0

load r0, 27975
load r1, 27974
out r0, r1
; endereco temporario(27973) recebe o conteudo: 31744
loadn r0, #31744
store 27973, r0

; endereco temporario(27972) recebe o conteudo: 7
loadn r0, #7
store 27972, r0

load r0, 27973
load r1, 27972
out r0, r1
; variavel: x alocada em 27971 com 1 bytes

; variavel: y alocada em 27970 com 1 bytes

; @(27) INSTRUCAO - while
__loop_label_begin2__:
; endereco temporario(27969) recebe o conteudo: 1
loadn r0, #1
store 27969, r0

load r0, 27969
loadn r1, #0
cmp r0, r1
jeq __exit_loop_label2__
jmp __loop_label2__
__loop_label2__:
; endereco temporario(27968) recebe o conteudo da variavel: x(27971)
load r0, 27971
store 27968, r0

; endereco temporario(27967) recebe o conteudo da variavel: x(27971)
load r0, 27971
store 27967, r0

; endereco temporario(27966) recebe o conteudo: 1
loadn r0, #1
store 27966, r0

; expressao_binaria: 27967 + 27966
load r0, 27967
load r1, 27966
add r2, r0, r1
store 27967, r2

; endereco temporario(27966) recebe o conteudo: 512
loadn r0, #512
store 27966, r0

; expressao_binaria: 27967 % 27966
load r0, 27967
load r1, 27966
mod r2, r0, r1
store 27967, r2

; assignment salvando no endereco apontado por: endereco temporario(27968) o conteudo de endereco temporario(27967)
load r0, 27967
; valor da stack: 27966
store 27971, r0 ; variavel x recebe o conteudo de r0

; endereco temporario(27968) recebe o conteudo da variavel: y(27970)
load r0, 27970
store 27968, r0

; endereco temporario(27967) recebe o conteudo da variavel: y(27970)
load r0, 27970
store 27967, r0

; endereco temporario(27966) recebe o conteudo: 1
loadn r0, #1
store 27966, r0

; expressao_binaria: 27967 + 27966
load r0, 27967
load r1, 27966
add r2, r0, r1
store 27967, r2

; endereco temporario(27966) recebe o conteudo: 512
loadn r0, #512
store 27966, r0

; expressao_binaria: 27967 % 27966
load r0, 27967
load r1, 27966
mod r2, r0, r1
store 27967, r2

; assignment salvando no endereco apontado por: endereco temporario(27968) o conteudo de endereco temporario(27967)
load r0, 27967
; valor da stack: 27966
store 27970, r0 ; variavel y recebe o conteudo de r0

; endereco temporario(27968) recebe o conteudo: 0
loadn r0, #0
store 27968, r0

; endereco temporario(27967) recebe o conteudo: 2
loadn r0, #2
store 27967, r0

load r0, 27968
load r1, 27967
out r0, r1
; endereco temporario(27966) recebe o conteudo da variavel: x(27971)
load r0, 27971
store 27966, r0

; endereco temporario(27965) recebe o conteudo: 3
loadn r0, #3
store 27965, r0

load r0, 27966
load r1, 27965
out r0, r1
; endereco temporario(27964) recebe o conteudo da variavel: y(27970)
load r0, 27970
store 27964, r0

; endereco temporario(27963) recebe o conteudo: 3
loadn r0, #3
store 27963, r0

load r0, 27964
load r1, 27963
out r0, r1
; endereco temporario(27962) recebe o conteudo: 8
loadn r0, #8
store 27962, r0

; endereco temporario(27961) recebe o conteudo: 3
loadn r0, #3
store 27961, r0

load r0, 27962
load r1, 27961
out r0, r1
; endereco temporario(27960) recebe o conteudo: 0
loadn r0, #0
store 27960, r0

; endereco temporario(27959) recebe o conteudo: 3
loadn r0, #3
store 27959, r0

load r0, 27960
load r1, 27959
out r0, r1
;----- begin for -----
; endereco temporario(27958) recebe o conteudo da variavel: i(28000)
load r0, 28000
store 27958, r0

; endereco temporario(27957) recebe o conteudo: 0
loadn r0, #0
store 27957, r0

; assignment salvando no endereco apontado por: endereco temporario(27958) o conteudo de endereco temporario(27957)
load r0, 27957
; valor da stack: 27956
store 28000, r0 ; variavel i recebe o conteudo de r0

__loop_label_begin3__:
; endereco temporario(27958) recebe o conteudo da variavel: i(28000)
load r0, 28000
store 27958, r0

; endereco temporario(27957) recebe o conteudo: 2000
loadn r0, #2000
store 27957, r0

; @(35) INSTRUCAO - relacao_binaria
load r0, 27958
load r1, 27957
loadn r2, #27958
call __less_routine__
load r0, 27958
loadn r1, #0
cmp r0, r1
jeq __exit_loop_label3__
jmp __loop_label3_begin3__
__loop_label2_begin3__:
; endereco temporario(27958) recebe o conteudo da variavel: i(28000)
load r0, 28000
store 27958, r0

load r0, 27958
inc r0
store 27958, r0
store 28000, r0
jmp __loop_label_begin3__
__loop_label3_begin3__:
jmp __loop_label2_begin3__
__exit_loop_label3__:
; ----- end for -----
jmp __loop_label_begin2__
__exit_loop_label2__:
; ----- end while -----
breakp
rts
;---------- END ----------
