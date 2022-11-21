.text
.globl main
main:
	addi $s3, $0, 1	# i
	addi $s4, $0, -1	# j
	addi $s0, $0, 8	# f
	addi $s2, $0, 20	# g
	addi $s2, $0, 5	# h
	bne $s3, $s4, Else
	add $s0, $s1, $s2
	j Exit

Else:
	sub $s0, $s1, $s2

Exit:
	add $s0, $s0, $s0
