.text
.globl main
main:
	addi $t0, $0, 10 # $t0 is an alias of $8
	addi $t1, $0, 16
	add $t2, $t0, $t1
