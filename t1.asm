;---------- BEGIN - PRE PROCESSAMENTO ----------
; variavel: x alocada em 28000 com 1 bytes

; endereco temporario(27999) recebe o conteudo: 0
loadn r0, #0
store 27999, r0

load r0, 27999
store 28000, r0
; variavel: y alocada em 27999 com 1 bytes

; endereco temporario(27998) recebe o conteudo: 0
loadn r0, #0
store 27998, r0

load r0, 27998
store 27999, r0
; @(55) INSTRUCAO - while
;---------- END PRE PROCESSAMENTO ----------
;---------- BEGIN ----------
; variavel: x alocada em 28000

; variavel: y alocada em 27999

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
; @(3) INSTRUCAO - ; declarando funcao: kb
__function_label_kb__:

; endereco temporario(27998) recebe o conteudo da variavel: x(28000)
load r0, 28000
store 27998, r0

load r0, 27998
inc r0
store 27998, r0
store 28000, r0
rts
; @(7) INSTRUCAO - ; declarando funcao: main
__function_label_main__:

; variavel: i alocada em 27998 com 1 bytes

; endereco temporario(27997) recebe o conteudo: 0
loadn r0, #0
store 27997, r0

; endereco temporario(27996) recebe o conteudo: 0
loadn r0, #0
store 27996, r0

load r0, 27997
load r1, 27996
out r0, r1
;----- begin for -----
; endereco temporario(27995) recebe o conteudo da variavel: i(27998)
load r0, 27998
store 27995, r0

; endereco temporario(27994) recebe o conteudo: 0
loadn r0, #0
store 27994, r0

; assignment salvando no endereco apontado por: endereco temporario(27995) o conteudo de endereco temporario(27994)
load r0, 27994
; valor da stack: 27993
store 27998, r0 ; variavel i recebe o conteudo de r0

__loop_label_begin3__:
; endereco temporario(27995) recebe o conteudo da variavel: i(27998)
load r0, 27998
store 27995, r0

; endereco temporario(27994) recebe o conteudo: 1200
loadn r0, #1200
store 27994, r0

; @(10) INSTRUCAO - relacao_binaria
load r0, 27995
load r1, 27994
loadn r2, #27995
call __less_routine__
load r0, 27995
loadn r1, #0
cmp r0, r1
jeq __exit_loop_label3__
jmp __loop_label3_begin3__
__loop_label2_begin3__:
; endereco temporario(27995) recebe o conteudo da variavel: i(27998)
load r0, 27998
store 27995, r0

load r0, 27995
inc r0
store 27995, r0
store 27998, r0
jmp __loop_label_begin3__
__loop_label3_begin3__:
; endereco temporario(27994) recebe o conteudo: 0
loadn r0, #0
store 27994, r0

; endereco temporario(27993) recebe o conteudo: 1
loadn r0, #1
store 27993, r0

load r0, 27994
load r1, 27993
out r0, r1
; endereco temporario(27992) recebe o conteudo: 0
loadn r0, #0
store 27992, r0

; endereco temporario(27991) recebe o conteudo: 1
loadn r0, #1
store 27991, r0

load r0, 27992
load r1, 27991
out r0, r1
jmp __loop_label2_begin3__
__exit_loop_label3__:
; ----- end for -----
; endereco temporario(27990) recebe o conteudo: 0
loadn r0, #0
store 27990, r0

; endereco temporario(27989) recebe o conteudo: 4
loadn r0, #4
store 27989, r0

load r0, 27990
load r1, 27989
out r0, r1
; endereco temporario(27988) recebe o conteudo: 255
loadn r0, #255
store 27988, r0

; endereco temporario(27987) recebe o conteudo: 5
loadn r0, #5
store 27987, r0

load r0, 27988
load r1, 27987
out r0, r1
; endereco temporario(27986) recebe o conteudo: 255
loadn r0, #255
store 27986, r0

; endereco temporario(27985) recebe o conteudo: 5
loadn r0, #5
store 27985, r0

load r0, 27986
load r1, 27985
out r0, r1
; endereco temporario(27984) recebe o conteudo: 255
loadn r0, #255
store 27984, r0

; endereco temporario(27983) recebe o conteudo: 5
loadn r0, #5
store 27983, r0

load r0, 27984
load r1, 27983
out r0, r1
; endereco temporario(27982) recebe o conteudo: 255
loadn r0, #255
store 27982, r0

; endereco temporario(27981) recebe o conteudo: 5
loadn r0, #5
store 27981, r0

load r0, 27982
load r1, 27981
out r0, r1
; endereco temporario(27980) recebe o conteudo: 255
loadn r0, #255
store 27980, r0

; endereco temporario(27979) recebe o conteudo: 5
loadn r0, #5
store 27979, r0

load r0, 27980
load r1, 27979
out r0, r1
; endereco temporario(27978) recebe o conteudo: 255
loadn r0, #255
store 27978, r0

; endereco temporario(27977) recebe o conteudo: 5
loadn r0, #5
store 27977, r0

load r0, 27978
load r1, 27977
out r0, r1
; endereco temporario(27976) recebe o conteudo: 255
loadn r0, #255
store 27976, r0

; endereco temporario(27975) recebe o conteudo: 5
loadn r0, #5
store 27975, r0

load r0, 27976
load r1, 27975
out r0, r1
; endereco temporario(27974) recebe o conteudo: 255
loadn r0, #255
store 27974, r0

; endereco temporario(27973) recebe o conteudo: 5
loadn r0, #5
store 27973, r0

load r0, 27974
load r1, 27973
out r0, r1
; endereco temporario(27972) recebe o conteudo: 16
loadn r0, #16
store 27972, r0

; endereco temporario(27971) recebe o conteudo: 4
loadn r0, #4
store 27971, r0

load r0, 27972
load r1, 27971
out r0, r1
; endereco temporario(27970) recebe o conteudo: 15420
loadn r0, #15420
store 27970, r0

; endereco temporario(27969) recebe o conteudo: 5
loadn r0, #5
store 27969, r0

load r0, 27970
load r1, 27969
out r0, r1
; endereco temporario(27968) recebe o conteudo: 15934
loadn r0, #15934
store 27968, r0

; endereco temporario(27967) recebe o conteudo: 5
loadn r0, #5
store 27967, r0

load r0, 27968
load r1, 27967
out r0, r1
; endereco temporario(27966) recebe o conteudo: 5160
loadn r0, #5160
store 27966, r0

; endereco temporario(27965) recebe o conteudo: 5
loadn r0, #5
store 27965, r0

load r0, 27966
load r1, 27965
out r0, r1
; endereco temporario(27964) recebe o conteudo: 60
loadn r0, #60
store 27964, r0

; endereco temporario(27963) recebe o conteudo: 5
loadn r0, #5
store 27963, r0

load r0, 27964
load r1, 27963
out r0, r1
; endereco temporario(27962) recebe o conteudo: 32475
loadn r0, #32475
store 27962, r0

; endereco temporario(27961) recebe o conteudo: 5
loadn r0, #5
store 27961, r0

load r0, 27962
load r1, 27961
out r0, r1
; endereco temporario(27960) recebe o conteudo: 15360
loadn r0, #15360
store 27960, r0

; endereco temporario(27959) recebe o conteudo: 5
loadn r0, #5
store 27959, r0

load r0, 27960
load r1, 27959
out r0, r1
; endereco temporario(27958) recebe o conteudo: 15360
loadn r0, #15360
store 27958, r0

; endereco temporario(27957) recebe o conteudo: 5
loadn r0, #5
store 27957, r0

load r0, 27958
load r1, 27957
out r0, r1
; endereco temporario(27956) recebe o conteudo: 9252
loadn r0, #9252
store 27956, r0

; endereco temporario(27955) recebe o conteudo: 5
loadn r0, #5
store 27955, r0

load r0, 27956
load r1, 27955
out r0, r1
; endereco temporario(27954) recebe o conteudo: 0
loadn r0, #0
store 27954, r0

; endereco temporario(27953) recebe o conteudo: 6
loadn r0, #6
store 27953, r0

load r0, 27954
load r1, 27953
out r0, r1
; endereco temporario(27952) recebe o conteudo: 0
loadn r0, #0
store 27952, r0

; endereco temporario(27951) recebe o conteudo: 7
loadn r0, #7
store 27951, r0

load r0, 27952
load r1, 27951
out r0, r1
; endereco temporario(27950) recebe o conteudo: 7674
loadn r0, #7674
store 27950, r0

; endereco temporario(27949) recebe o conteudo: 7
loadn r0, #7
store 27949, r0

load r0, 27950
load r1, 27949
out r0, r1
; endereco temporario(27948) recebe o conteudo: 7674
loadn r0, #7674
store 27948, r0

; endereco temporario(27947) recebe o conteudo: 7
loadn r0, #7
store 27947, r0

load r0, 27948
load r1, 27947
out r0, r1
; endereco temporario(27946) recebe o conteudo: 7674
loadn r0, #7674
store 27946, r0

; endereco temporario(27945) recebe o conteudo: 7
loadn r0, #7
store 27945, r0

load r0, 27946
load r1, 27945
out r0, r1
; endereco temporario(27944) recebe o conteudo: 8
loadn r0, #8
store 27944, r0

; endereco temporario(27943) recebe o conteudo: 6
loadn r0, #6
store 27943, r0

load r0, 27944
load r1, 27943
out r0, r1
; endereco temporario(27942) recebe o conteudo: 0
loadn r0, #0
store 27942, r0

; endereco temporario(27941) recebe o conteudo: 7
loadn r0, #7
store 27941, r0

load r0, 27942
load r1, 27941
out r0, r1
; endereco temporario(27940) recebe o conteudo: 25521
loadn r0, #25521
store 27940, r0

; endereco temporario(27939) recebe o conteudo: 7
loadn r0, #7
store 27939, r0

load r0, 27940
load r1, 27939
out r0, r1
; endereco temporario(27938) recebe o conteudo: 31
loadn r0, #31
store 27938, r0

; endereco temporario(27937) recebe o conteudo: 7
loadn r0, #7
store 27937, r0

load r0, 27938
load r1, 27937
out r0, r1
; endereco temporario(27936) recebe o conteudo: 31744
loadn r0, #31744
store 27936, r0

; endereco temporario(27935) recebe o conteudo: 7
loadn r0, #7
store 27935, r0

load r0, 27936
load r1, 27935
out r0, r1
; endereco temporario(27934) recebe o conteudo: 0
loadn r0, #0
store 27934, r0

; endereco temporario(27933) recebe o conteudo: 2
loadn r0, #2
store 27933, r0

load r0, 27934
load r1, 27933
out r0, r1
; endereco temporario(27932) recebe o conteudo da variavel: x(28000)
load r0, 28000
store 27932, r0

; endereco temporario(27931) recebe o conteudo: 3
loadn r0, #3
store 27931, r0

load r0, 27932
load r1, 27931
out r0, r1
; endereco temporario(27930) recebe o conteudo da variavel: y(27999)
load r0, 27999
store 27930, r0

; endereco temporario(27929) recebe o conteudo: 3
loadn r0, #3
store 27929, r0

load r0, 27930
load r1, 27929
out r0, r1
; endereco temporario(27928) recebe o conteudo: 16
loadn r0, #16
store 27928, r0

; endereco temporario(27927) recebe o conteudo: 3
loadn r0, #3
store 27927, r0

load r0, 27928
load r1, 27927
out r0, r1
; endereco temporario(27926) recebe o conteudo: 2
loadn r0, #2
store 27926, r0

; endereco temporario(27925) recebe o conteudo: 3
loadn r0, #3
store 27925, r0

load r0, 27926
load r1, 27925
out r0, r1
; @(55) INSTRUCAO - while
__loop_label_begin4__:
; endereco temporario(27924) recebe o conteudo: 1
loadn r0, #1
store 27924, r0

load r0, 27924
loadn r1, #0
cmp r0, r1
jeq __exit_loop_label4__
jmp __loop_label4__
__loop_label4__:
; endereco temporario(27923) recebe o conteudo: 0
loadn r0, #0
store 27923, r0

; endereco temporario(27922) recebe o conteudo: 2
loadn r0, #2
store 27922, r0

load r0, 27923
load r1, 27922
out r0, r1
; endereco temporario(27921) recebe o conteudo da variavel: x(28000)
load r0, 28000
store 27921, r0

; endereco temporario(27920) recebe o conteudo: 3
loadn r0, #3
store 27920, r0

load r0, 27921
load r1, 27920
out r0, r1
; endereco temporario(27919) recebe o conteudo da variavel: y(27999)
load r0, 27999
store 27919, r0

; endereco temporario(27918) recebe o conteudo: 3
loadn r0, #3
store 27918, r0

load r0, 27919
load r1, 27918
out r0, r1
; @(59) INSTRUCAO - ; call funcao: kb
; @(59) INSTRUCAO - ; salvando as variaveis do escopo
load r0, 27998
push r0
; @(59) INSTRUCAO - ; nao tem parametros
call __function_label_kb__
; @(59) INSTRUCAO - ; recupera as variaveis do escopo da funcao
pop r0
store 27998, r0

;----- begin for -----
; endereco temporario(27917) recebe o conteudo da variavel: i(27998)
load r0, 27998
store 27917, r0

; endereco temporario(27916) recebe o conteudo: 0
loadn r0, #0
store 27916, r0

; assignment salvando no endereco apontado por: endereco temporario(27917) o conteudo de endereco temporario(27916)
load r0, 27916
; valor da stack: 27915
store 27998, r0 ; variavel i recebe o conteudo de r0

__loop_label_begin5__:
; endereco temporario(27917) recebe o conteudo da variavel: i(27998)
load r0, 27998
store 27917, r0

; endereco temporario(27916) recebe o conteudo: 1000
loadn r0, #1000
store 27916, r0

; @(60) INSTRUCAO - relacao_binaria
load r0, 27917
load r1, 27916
loadn r2, #27917
call __less_routine__
load r0, 27917
loadn r1, #0
cmp r0, r1
jeq __exit_loop_label5__
jmp __loop_label3_begin5__
__loop_label2_begin5__:
; endereco temporario(27917) recebe o conteudo da variavel: i(27998)
load r0, 27998
store 27917, r0

load r0, 27917
inc r0
store 27917, r0
store 27998, r0
jmp __loop_label_begin5__
__loop_label3_begin5__:
jmp __loop_label2_begin5__
__exit_loop_label5__:
; ----- end for -----
jmp __loop_label_begin4__
__exit_loop_label4__:
; ----- end while -----
breakp
rts
;---------- END ----------
