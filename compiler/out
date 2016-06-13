;---------- BEGIN - PRE PROCESSAMENTO ----------
; variavel: x alocada em 28000 com 1 bytes

; endereco temporario(27999) constante recebe o conteudo: 0
loadn r0, #0
store 27999, r0

load r0, 27999
store 28000, r0
; variavel: y alocada em 27999 com 1 bytes

; endereco temporario(27998) constante recebe o conteudo: 220
loadn r0, #220
store 27998, r0

load r0, 27998
store 27999, r0
; @(117) INSTRUCAO - while
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
; @(3) INSTRUCAO - ; declarando funcao: kbHandler
__function_label_kbHandler__:

push fr
pop r4
mov r5, r0
mov r6, r1
; variavel: c alocada em 27998 com 1 bytes

; endereco temporario(27997) constante recebe o conteudo: 2304
loadn r0, #2304
store 27997, r0

load r1, 27997
in r0, r1
store 27997, r0
load r0, 27997
store 27998, r0
; endereco temporario(27997) recebe o conteudo da variavel: c(27998)
load r0, 27998
store 27997, r0

; endereco temporario(27996) constante recebe o conteudo: 'd'
loadn r0, #'d'
store 27996, r0

; @(9) INSTRUCAO - relacao_binaria
load r0, 27997
load r1, 27996
loadn r2, #27997
call __equal_routine__
load r0, 27997
loadn r1, #0
cmp r0, r1
jeq __exit_if_label1__
jmp __if_label1__
__if_label1__:
; endereco temporario(27997) recebe o conteudo da variavel: x(28000)
load r0, 28000
store 27997, r0

load r0, 27997
inc r0
store 27997, r0
store 28000, r0
jmp __exit_else_label1__
__exit_if_label1__:
; endereco temporario(27996) recebe o conteudo da variavel: c(27998)
load r0, 27998
store 27996, r0

; endereco temporario(27995) constante recebe o conteudo: 'a'
loadn r0, #'a'
store 27995, r0

; @(11) INSTRUCAO - relacao_binaria
load r0, 27996
load r1, 27995
loadn r2, #27996
call __equal_routine__
load r0, 27996
loadn r1, #0
cmp r0, r1
jeq __exit_if_label2__
jmp __if_label2__
__if_label2__:
; endereco temporario(27996) recebe o conteudo da variavel: x(28000)
load r0, 28000
store 27996, r0

load r0, 27996
dec r0
store 27996, r0
store 28000, r0
jmp __exit_else_label2__
__exit_if_label2__:
; endereco temporario(27995) recebe o conteudo da variavel: c(27998)
load r0, 27998
store 27995, r0

; endereco temporario(27994) constante recebe o conteudo: 'w'
loadn r0, #'w'
store 27994, r0

; @(13) INSTRUCAO - relacao_binaria
load r0, 27995
load r1, 27994
loadn r2, #27995
call __equal_routine__
load r0, 27995
loadn r1, #0
cmp r0, r1
jeq __exit_if_label3__
jmp __if_label3__
__if_label3__:
; endereco temporario(27995) recebe o conteudo da variavel: y(27999)
load r0, 27999
store 27995, r0

load r0, 27995
dec r0
store 27995, r0
store 27999, r0
jmp __exit_else_label3__
__exit_if_label3__:
; endereco temporario(27994) recebe o conteudo da variavel: c(27998)
load r0, 27998
store 27994, r0

; endereco temporario(27993) constante recebe o conteudo: 's'
loadn r0, #'s'
store 27993, r0

; @(15) INSTRUCAO - relacao_binaria
load r0, 27994
load r1, 27993
loadn r2, #27994
call __equal_routine__
load r0, 27994
loadn r1, #0
cmp r0, r1
jeq __exit_if_label4__
jmp __if_label4__
__if_label4__:
; endereco temporario(27994) recebe o conteudo da variavel: y(27999)
load r0, 27999
store 27994, r0

load r0, 27994
inc r0
store 27994, r0
store 27999, r0
__exit_if_label4__:
__exit_else_label3__:
__exit_else_label2__:
__exit_else_label1__:
mov r0, r5
mov r1, r6
push r4
pop fr
RTI
rts
; @(24) INSTRUCAO - ; declarando funcao: main
__function_label_main__:

; variavel: xg alocada em 27998 com 1 bytes

; variavel: pos alocada em 27997 com 1 bytes

; endereco temporario(27996) constante recebe o conteudo: 16131
loadn r0, #16131
store 27996, r0

load r0, 27996
store 27997, r0
; endereco temporario(27996) recebe o conteudo da variavel: pos(27997)
load r0, 27997
store 27996, r0

load r0, 27996
store 27996, r0
; endereco temporario(27995) recebe o conteudo da variavel: kbHandler(-1)
loadn r0, #__function_label_kbHandler__
store 27995, r0

; @(27) INSTRUCAO - ; endereco
; assignment salvando no endereco apontado por: endereco temporario(27996) o conteudo de endereco temporario(27995)
load r0, 27995
;Assignment ponteiro
load r7, 27997
storei r7, r0 ; endereco apontado por r7 recebe o conteudo de r0

EI
; variavel: i alocada em 27996 com 1 bytes

; endereco temporario(27995) constante recebe o conteudo: 0
loadn r0, #0
store 27995, r0

; endereco temporario(27994) constante recebe o conteudo: 0
loadn r0, #0
store 27994, r0

load r0, 27995
load r1, 27994
out r0, r1
;----- begin for -----
; endereco temporario(27993) recebe o conteudo da variavel: i(27996)
load r0, 27996
store 27993, r0

; endereco temporario(27992) constante recebe o conteudo: 0
loadn r0, #0
store 27992, r0

; assignment salvando no endereco apontado por: endereco temporario(27993) o conteudo de endereco temporario(27992)
load r0, 27992
; valor da stack: 27991
store 27996, r0 ; variavel i recebe o conteudo de r0

__loop_label_begin3__:
; endereco temporario(27993) recebe o conteudo da variavel: i(27996)
load r0, 27996
store 27993, r0

; endereco temporario(27992) constante recebe o conteudo: 1200
loadn r0, #1200
store 27992, r0

; @(32) INSTRUCAO - relacao_binaria
load r0, 27993
load r1, 27992
loadn r2, #27993
call __less_routine__
load r0, 27993
loadn r1, #0
cmp r0, r1
jeq __exit_loop_label3__
jmp __loop_label3_begin3__
__loop_label2_begin3__:
; endereco temporario(27993) recebe o conteudo da variavel: i(27996)
load r0, 27996
store 27993, r0

load r0, 27993
inc r0
store 27993, r0
store 27996, r0
jmp __loop_label_begin3__
__loop_label3_begin3__:
; endereco temporario(27992) constante recebe o conteudo: 0
loadn r0, #0
store 27992, r0

; endereco temporario(27991) constante recebe o conteudo: 1
loadn r0, #1
store 27991, r0

load r0, 27992
load r1, 27991
out r0, r1
; endereco temporario(27990) constante recebe o conteudo: 0
loadn r0, #0
store 27990, r0

; endereco temporario(27989) constante recebe o conteudo: 1
loadn r0, #1
store 27989, r0

load r0, 27990
load r1, 27989
out r0, r1
jmp __loop_label2_begin3__
__exit_loop_label3__:
; ----- end for -----
; endereco temporario(27988) constante recebe o conteudo: 0
loadn r0, #0
store 27988, r0

; endereco temporario(27987) constante recebe o conteudo: 4
loadn r0, #4
store 27987, r0

load r0, 27988
load r1, 27987
out r0, r1
; endereco temporario(27986) constante recebe o conteudo: 255
loadn r0, #255
store 27986, r0

; endereco temporario(27985) constante recebe o conteudo: 5
loadn r0, #5
store 27985, r0

load r0, 27986
load r1, 27985
out r0, r1
; endereco temporario(27984) constante recebe o conteudo: 255
loadn r0, #255
store 27984, r0

; endereco temporario(27983) constante recebe o conteudo: 5
loadn r0, #5
store 27983, r0

load r0, 27984
load r1, 27983
out r0, r1
; endereco temporario(27982) constante recebe o conteudo: 255
loadn r0, #255
store 27982, r0

; endereco temporario(27981) constante recebe o conteudo: 5
loadn r0, #5
store 27981, r0

load r0, 27982
load r1, 27981
out r0, r1
; endereco temporario(27980) constante recebe o conteudo: 255
loadn r0, #255
store 27980, r0

; endereco temporario(27979) constante recebe o conteudo: 5
loadn r0, #5
store 27979, r0

load r0, 27980
load r1, 27979
out r0, r1
; endereco temporario(27978) constante recebe o conteudo: 255
loadn r0, #255
store 27978, r0

; endereco temporario(27977) constante recebe o conteudo: 5
loadn r0, #5
store 27977, r0

load r0, 27978
load r1, 27977
out r0, r1
; endereco temporario(27976) constante recebe o conteudo: 255
loadn r0, #255
store 27976, r0

; endereco temporario(27975) constante recebe o conteudo: 5
loadn r0, #5
store 27975, r0

load r0, 27976
load r1, 27975
out r0, r1
; endereco temporario(27974) constante recebe o conteudo: 255
loadn r0, #255
store 27974, r0

; endereco temporario(27973) constante recebe o conteudo: 5
loadn r0, #5
store 27973, r0

load r0, 27974
load r1, 27973
out r0, r1
; endereco temporario(27972) constante recebe o conteudo: 255
loadn r0, #255
store 27972, r0

; endereco temporario(27971) constante recebe o conteudo: 5
loadn r0, #5
store 27971, r0

load r0, 27972
load r1, 27971
out r0, r1
; endereco temporario(27970) constante recebe o conteudo: 8
loadn r0, #8
store 27970, r0

; endereco temporario(27969) constante recebe o conteudo: 5
loadn r0, #5
store 27969, r0

load r0, 27970
load r1, 27969
out r0, r1
; endereco temporario(27968) constante recebe o conteudo: 90
loadn r0, #90
store 27968, r0

; endereco temporario(27967) constante recebe o conteudo: 5
loadn r0, #5
store 27967, r0

load r0, 27968
load r1, 27967
out r0, r1
; endereco temporario(27966) constante recebe o conteudo: 42330
loadn r0, #42330
store 27966, r0

; endereco temporario(27965) constante recebe o conteudo: 5
loadn r0, #5
store 27965, r0

load r0, 27966
load r1, 27965
out r0, r1
; endereco temporario(27964) constante recebe o conteudo: 42330
loadn r0, #42330
store 27964, r0

; endereco temporario(27963) constante recebe o conteudo: 5
loadn r0, #5
store 27963, r0

load r0, 27964
load r1, 27963
out r0, r1
; endereco temporario(27962) constante recebe o conteudo: 255
loadn r0, #255
store 27962, r0

; endereco temporario(27961) constante recebe o conteudo: 5
loadn r0, #5
store 27961, r0

load r0, 27962
load r1, 27961
out r0, r1
; endereco temporario(27960) constante recebe o conteudo: 20735
loadn r0, #20735
store 27960, r0

; endereco temporario(27959) constante recebe o conteudo: 5
loadn r0, #5
store 27959, r0

load r0, 27960
load r1, 27959
out r0, r1
; endereco temporario(27958) constante recebe o conteudo: 63999
loadn r0, #63999
store 27958, r0

; endereco temporario(27957) constante recebe o conteudo: 5
loadn r0, #5
store 27957, r0

load r0, 27958
load r1, 27957
out r0, r1
; endereco temporario(27956) constante recebe o conteudo: 65535
loadn r0, #65535
store 27956, r0

; endereco temporario(27955) constante recebe o conteudo: 5
loadn r0, #5
store 27955, r0

load r0, 27956
load r1, 27955
out r0, r1
; endereco temporario(27954) constante recebe o conteudo: 15420
loadn r0, #15420
store 27954, r0

; endereco temporario(27953) constante recebe o conteudo: 5
loadn r0, #5
store 27953, r0

load r0, 27954
load r1, 27953
out r0, r1
; endereco temporario(27952) constante recebe o conteudo: 15934
loadn r0, #15934
store 27952, r0

; endereco temporario(27951) constante recebe o conteudo: 5
loadn r0, #5
store 27951, r0

load r0, 27952
load r1, 27951
out r0, r1
; endereco temporario(27950) constante recebe o conteudo: 5160
loadn r0, #5160
store 27950, r0

; endereco temporario(27949) constante recebe o conteudo: 5
loadn r0, #5
store 27949, r0

load r0, 27950
load r1, 27949
out r0, r1
; endereco temporario(27948) constante recebe o conteudo: 60
loadn r0, #60
store 27948, r0

; endereco temporario(27947) constante recebe o conteudo: 5
loadn r0, #5
store 27947, r0

load r0, 27948
load r1, 27947
out r0, r1
; endereco temporario(27946) constante recebe o conteudo: 32475
loadn r0, #32475
store 27946, r0

; endereco temporario(27945) constante recebe o conteudo: 5
loadn r0, #5
store 27945, r0

load r0, 27946
load r1, 27945
out r0, r1
; endereco temporario(27944) constante recebe o conteudo: 15360
loadn r0, #15360
store 27944, r0

; endereco temporario(27943) constante recebe o conteudo: 5
loadn r0, #5
store 27943, r0

load r0, 27944
load r1, 27943
out r0, r1
; endereco temporario(27942) constante recebe o conteudo: 15360
loadn r0, #15360
store 27942, r0

; endereco temporario(27941) constante recebe o conteudo: 5
loadn r0, #5
store 27941, r0

load r0, 27942
load r1, 27941
out r0, r1
; endereco temporario(27940) constante recebe o conteudo: 9252
loadn r0, #9252
store 27940, r0

; endereco temporario(27939) constante recebe o conteudo: 5
loadn r0, #5
store 27939, r0

load r0, 27940
load r1, 27939
out r0, r1
; endereco temporario(27938) constante recebe o conteudo: 255
loadn r0, #255
store 27938, r0

; endereco temporario(27937) constante recebe o conteudo: 5
loadn r0, #5
store 27937, r0

load r0, 27938
load r1, 27937
out r0, r1
; endereco temporario(27936) constante recebe o conteudo: 16575
loadn r0, #16575
store 27936, r0

; endereco temporario(27935) constante recebe o conteudo: 5
loadn r0, #5
store 27935, r0

load r0, 27936
load r1, 27935
out r0, r1
; endereco temporario(27934) constante recebe o conteudo: 1275
loadn r0, #1275
store 27934, r0

; endereco temporario(27933) constante recebe o conteudo: 5
loadn r0, #5
store 27933, r0

load r0, 27934
load r1, 27933
out r0, r1
; endereco temporario(27932) constante recebe o conteudo: 255
loadn r0, #255
store 27932, r0

; endereco temporario(27931) constante recebe o conteudo: 5
loadn r0, #5
store 27931, r0

load r0, 27932
load r1, 27931
out r0, r1
; endereco temporario(27930) constante recebe o conteudo: 1275
loadn r0, #1275
store 27930, r0

; endereco temporario(27929) constante recebe o conteudo: 5
loadn r0, #5
store 27929, r0

load r0, 27930
load r1, 27929
out r0, r1
; endereco temporario(27928) constante recebe o conteudo: 255
loadn r0, #255
store 27928, r0

; endereco temporario(27927) constante recebe o conteudo: 5
loadn r0, #5
store 27927, r0

load r0, 27928
load r1, 27927
out r0, r1
; endereco temporario(27926) constante recebe o conteudo: 8415
loadn r0, #8415
store 27926, r0

; endereco temporario(27925) constante recebe o conteudo: 5
loadn r0, #5
store 27925, r0

load r0, 27926
load r1, 27925
out r0, r1
; endereco temporario(27924) constante recebe o conteudo: 255
loadn r0, #255
store 27924, r0

; endereco temporario(27923) constante recebe o conteudo: 5
loadn r0, #5
store 27923, r0

load r0, 27924
load r1, 27923
out r0, r1
; endereco temporario(27922) constante recebe o conteudo: 0
loadn r0, #0
store 27922, r0

; endereco temporario(27921) constante recebe o conteudo: 6
loadn r0, #6
store 27921, r0

load r0, 27922
load r1, 27921
out r0, r1
; endereco temporario(27920) constante recebe o conteudo: 0
loadn r0, #0
store 27920, r0

; endereco temporario(27919) constante recebe o conteudo: 7
loadn r0, #7
store 27919, r0

load r0, 27920
load r1, 27919
out r0, r1
; endereco temporario(27918) constante recebe o conteudo: 7674
loadn r0, #7674
store 27918, r0

; endereco temporario(27917) constante recebe o conteudo: 7
loadn r0, #7
store 27917, r0

load r0, 27918
load r1, 27917
out r0, r1
; endereco temporario(27916) constante recebe o conteudo: 7674
loadn r0, #7674
store 27916, r0

; endereco temporario(27915) constante recebe o conteudo: 7
loadn r0, #7
store 27915, r0

load r0, 27916
load r1, 27915
out r0, r1
; endereco temporario(27914) constante recebe o conteudo: 7674
loadn r0, #7674
store 27914, r0

; endereco temporario(27913) constante recebe o conteudo: 7
loadn r0, #7
store 27913, r0

load r0, 27914
load r1, 27913
out r0, r1
; endereco temporario(27912) constante recebe o conteudo: 0
loadn r0, #0
store 27912, r0

; endereco temporario(27911) constante recebe o conteudo: 7
loadn r0, #7
store 27911, r0

load r0, 27912
load r1, 27911
out r0, r1
; endereco temporario(27910) constante recebe o conteudo: 5923
loadn r0, #5923
store 27910, r0

; endereco temporario(27909) constante recebe o conteudo: 7
loadn r0, #7
store 27909, r0

load r0, 27910
load r1, 27909
out r0, r1
; endereco temporario(27908) constante recebe o conteudo: 5763
loadn r0, #5763
store 27908, r0

; endereco temporario(27907) constante recebe o conteudo: 7
loadn r0, #7
store 27907, r0

load r0, 27908
load r1, 27907
out r0, r1
; endereco temporario(27906) constante recebe o conteudo: 27378
loadn r0, #27378
store 27906, r0

; endereco temporario(27905) constante recebe o conteudo: 7
loadn r0, #7
store 27905, r0

load r0, 27906
load r1, 27905
out r0, r1
; endereco temporario(27904) constante recebe o conteudo: 0
loadn r0, #0
store 27904, r0

; endereco temporario(27903) constante recebe o conteudo: 7
loadn r0, #7
store 27903, r0

load r0, 27904
load r1, 27903
out r0, r1
; endereco temporario(27902) constante recebe o conteudo: 25521
loadn r0, #25521
store 27902, r0

; endereco temporario(27901) constante recebe o conteudo: 7
loadn r0, #7
store 27901, r0

load r0, 27902
load r1, 27901
out r0, r1
; endereco temporario(27900) constante recebe o conteudo: 31
loadn r0, #31
store 27900, r0

; endereco temporario(27899) constante recebe o conteudo: 7
loadn r0, #7
store 27899, r0

load r0, 27900
load r1, 27899
out r0, r1
; endereco temporario(27898) constante recebe o conteudo: 31744
loadn r0, #31744
store 27898, r0

; endereco temporario(27897) constante recebe o conteudo: 7
loadn r0, #7
store 27897, r0

load r0, 27898
load r1, 27897
out r0, r1
; endereco temporario(27896) constante recebe o conteudo: 0
loadn r0, #0
store 27896, r0

; endereco temporario(27895) constante recebe o conteudo: 7
loadn r0, #7
store 27895, r0

load r0, 27896
load r1, 27895
out r0, r1
; endereco temporario(27894) constante recebe o conteudo: 17490
loadn r0, #17490
store 27894, r0

; endereco temporario(27893) constante recebe o conteudo: 7
loadn r0, #7
store 27893, r0

load r0, 27894
load r1, 27893
out r0, r1
; endereco temporario(27892) constante recebe o conteudo: 27378
loadn r0, #27378
store 27892, r0

; endereco temporario(27891) constante recebe o conteudo: 7
loadn r0, #7
store 27891, r0

load r0, 27892
load r1, 27891
out r0, r1
; endereco temporario(27890) constante recebe o conteudo: 4
loadn r0, #4
store 27890, r0

; endereco temporario(27889) constante recebe o conteudo: 2
loadn r0, #2
store 27889, r0

load r0, 27890
load r1, 27889
out r0, r1
;----- begin for -----
; endereco temporario(27888) recebe o conteudo da variavel: i(27996)
load r0, 27996
store 27888, r0

; endereco temporario(27887) constante recebe o conteudo: 0
loadn r0, #0
store 27887, r0

; assignment salvando no endereco apontado por: endereco temporario(27888) o conteudo de endereco temporario(27887)
load r0, 27887
; valor da stack: 27886
store 27996, r0 ; variavel i recebe o conteudo de r0

__loop_label_begin4__:
; endereco temporario(27888) recebe o conteudo da variavel: i(27996)
load r0, 27996
store 27888, r0

; endereco temporario(27887) constante recebe o conteudo: 40
loadn r0, #40
store 27887, r0

; @(96) INSTRUCAO - relacao_binaria
load r0, 27888
load r1, 27887
loadn r2, #27888
call __less_routine__
load r0, 27888
loadn r1, #0
cmp r0, r1
jeq __exit_loop_label4__
jmp __loop_label3_begin4__
__loop_label2_begin4__:
; endereco temporario(27888) recebe o conteudo da variavel: i(27996)
load r0, 27996
store 27888, r0

load r0, 27888
inc r0
store 27888, r0
store 27996, r0
jmp __loop_label_begin4__
__loop_label3_begin4__:
; endereco temporario(27887) recebe o conteudo da variavel: xg(27998)
load r0, 27998
store 27887, r0

; endereco temporario(27886) recebe o conteudo da variavel: i(27996)
load r0, 27996
store 27886, r0

; endereco temporario(27885) constante recebe o conteudo: 8
loadn r0, #8
store 27885, r0

; expressao_binaria: 27886 * 27885
load r0, 27886
load r1, 27885
mul r2, r0, r1
store 27886, r2

; assignment salvando no endereco apontado por: endereco temporario(27887) o conteudo de endereco temporario(27886)
load r0, 27886
; valor da stack: 27885
store 27998, r0 ; variavel xg recebe o conteudo de r0

; endereco temporario(27887) recebe o conteudo da variavel: xg(27998)
load r0, 27998
store 27887, r0

; endereco temporario(27886) constante recebe o conteudo: 3
loadn r0, #3
store 27886, r0

load r0, 27887
load r1, 27886
out r0, r1
; endereco temporario(27885) constante recebe o conteudo: 224
loadn r0, #224
store 27885, r0

; endereco temporario(27884) constante recebe o conteudo: 3
loadn r0, #3
store 27884, r0

load r0, 27885
load r1, 27884
out r0, r1
; endereco temporario(27883) constante recebe o conteudo: 8
loadn r0, #8
store 27883, r0

; endereco temporario(27882) constante recebe o conteudo: 3
loadn r0, #3
store 27882, r0

load r0, 27883
load r1, 27882
out r0, r1
; endereco temporario(27881) constante recebe o conteudo: 1
loadn r0, #1
store 27881, r0

; endereco temporario(27880) constante recebe o conteudo: 3
loadn r0, #3
store 27880, r0

load r0, 27881
load r1, 27880
out r0, r1
; endereco temporario(27879) recebe o conteudo da variavel: xg(27998)
load r0, 27998
store 27879, r0

; endereco temporario(27878) constante recebe o conteudo: 3
loadn r0, #3
store 27878, r0

load r0, 27879
load r1, 27878
out r0, r1
; endereco temporario(27877) constante recebe o conteudo: 232
loadn r0, #232
store 27877, r0

; endereco temporario(27876) constante recebe o conteudo: 3
loadn r0, #3
store 27876, r0

load r0, 27877
load r1, 27876
out r0, r1
; endereco temporario(27875) constante recebe o conteudo: 24
loadn r0, #24
store 27875, r0

; endereco temporario(27874) constante recebe o conteudo: 3
loadn r0, #3
store 27874, r0

load r0, 27875
load r1, 27874
out r0, r1
; endereco temporario(27873) constante recebe o conteudo: 3
loadn r0, #3
store 27873, r0

; endereco temporario(27872) constante recebe o conteudo: 3
loadn r0, #3
store 27872, r0

load r0, 27873
load r1, 27872
out r0, r1
jmp __loop_label2_begin4__
__exit_loop_label4__:
; ----- end for -----
; endereco temporario(27871) constante recebe o conteudo: 0
loadn r0, #0
store 27871, r0

; endereco temporario(27870) constante recebe o conteudo: 2
loadn r0, #2
store 27870, r0

load r0, 27871
load r1, 27870
out r0, r1
; endereco temporario(27869) recebe o conteudo da variavel: x(28000)
load r0, 28000
store 27869, r0

; endereco temporario(27868) constante recebe o conteudo: 3
loadn r0, #3
store 27868, r0

load r0, 27869
load r1, 27868
out r0, r1
; endereco temporario(27867) recebe o conteudo da variavel: y(27999)
load r0, 27999
store 27867, r0

; endereco temporario(27866) constante recebe o conteudo: 3
loadn r0, #3
store 27866, r0

load r0, 27867
load r1, 27866
out r0, r1
; endereco temporario(27865) constante recebe o conteudo: 16
loadn r0, #16
store 27865, r0

; endereco temporario(27864) constante recebe o conteudo: 3
loadn r0, #3
store 27864, r0

load r0, 27865
load r1, 27864
out r0, r1
; endereco temporario(27863) constante recebe o conteudo: 2
loadn r0, #2
store 27863, r0

; endereco temporario(27862) constante recebe o conteudo: 3
loadn r0, #3
store 27862, r0

load r0, 27863
load r1, 27862
out r0, r1
; @(117) INSTRUCAO - while
__loop_label_begin5__:
; endereco temporario(27861) constante recebe o conteudo: 1
loadn r0, #1
store 27861, r0

load r0, 27861
loadn r1, #0
cmp r0, r1
jeq __exit_loop_label5__
jmp __loop_label5__
__loop_label5__:
; endereco temporario(27860) constante recebe o conteudo: 0
loadn r0, #0
store 27860, r0

; endereco temporario(27859) constante recebe o conteudo: 2
loadn r0, #2
store 27859, r0

load r0, 27860
load r1, 27859
out r0, r1
; endereco temporario(27858) recebe o conteudo da variavel: x(28000)
load r0, 28000
store 27858, r0

; endereco temporario(27857) constante recebe o conteudo: 3
loadn r0, #3
store 27857, r0

load r0, 27858
load r1, 27857
out r0, r1
; endereco temporario(27856) recebe o conteudo da variavel: y(27999)
load r0, 27999
store 27856, r0

; endereco temporario(27855) constante recebe o conteudo: 3
loadn r0, #3
store 27855, r0

load r0, 27856
load r1, 27855
out r0, r1
; endereco temporario(27854) constante recebe o conteudo: 16
loadn r0, #16
store 27854, r0

; endereco temporario(27853) constante recebe o conteudo: 3
loadn r0, #3
store 27853, r0

load r0, 27854
load r1, 27853
out r0, r1
; endereco temporario(27852) constante recebe o conteudo: 2
loadn r0, #2
store 27852, r0

; endereco temporario(27851) constante recebe o conteudo: 3
loadn r0, #3
store 27851, r0

load r0, 27852
load r1, 27851
out r0, r1
jmp __loop_label_begin5__
__exit_loop_label5__:
; ----- end while -----
breakp
rts
;---------- END ----------
