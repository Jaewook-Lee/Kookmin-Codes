	.data 0x10010000
arr:	.word 11
	.word 11
	.word 7
	.word 11
	.word 11

	.text
	.globl main
main:	la $s6, arr
	addi $s3, $0, 1
	addi $s5, $0, 11

Loop:	sll $t1, $s3, 2
	add $t1, $t1, $s6
	lw $t0, 0($t1)
	bne $t0, $s5, Exit
	addi $s3, $s3, 1
	j Loop

Exit:	nop

