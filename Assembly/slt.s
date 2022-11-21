.text
.globl main
main:
	addi $s3, $0, -1
	addi $s4, $0, 1
	add $s0, $0, $0
	slt $s0, $s3, $s4
	bne $s0, $0, target
	nop

target:
	sltu $s0, $s3, $s4
	slti $s0, $s3, 0
	sltiu $s0, $s3, 0
	blt $s3, $s4, target
