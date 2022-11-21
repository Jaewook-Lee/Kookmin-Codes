.text
.globl main
main:
	addi $t1, $0, 0x7FFFFFFF
	add $t2, $t1, $t1
	addu $t3, $t1, $t1
	addiu $t4, $t1, -1
