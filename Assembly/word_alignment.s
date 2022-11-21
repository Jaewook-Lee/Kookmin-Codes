	.data 0x10010000
a:
	.byte 1
	.byte -2
	.space 3
	.byte 's'

w1:
	.byte 's'
	.byte 't'
	.byte 'a'
	.byte 'r'
	.byte 0

w2:
	.word 1
	.word -1

	.text
	.globl main

main:
	la $5, a
	la $6, w1
	lw $4, 0($6)
