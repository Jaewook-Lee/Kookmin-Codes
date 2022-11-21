.text
.globl main
main:
lui $t0, 0xffff
ori $t0, 0xfffa
lui $t1, 0x7fff
ori $t1, 0xffff
subu $t2, $t0, $t1
