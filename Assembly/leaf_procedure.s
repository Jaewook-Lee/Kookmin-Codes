.text
.globl main
main:
addi $t0, $0, 100
addi $t1, $0, 200
addi $s0, $0, 300
addi $a0, $0, 4    # g
addi $a1, $0, 3    # h
addi $a2, $0, 1    # i
addi $a3, $0, 2    # j
jal leaf_example
add $a0, $v0, $0
addi $v0, $0, 1
syscall
add $a0, $t1, $t0
syscall

leaf_example:
sw $t1, 8($sp)
sw $t0, 4($sp)
sw $s0, 0($sp)
add $t0, $a0, $a1    # g + h
add $t1, $a2, $a3    # i + j
sub $s0, $t0, $t1    # f
add $v0, $s0, $0
lw $s0, 0($sp)
lw $t0 4($sp)
lw $t1, 8($sp)
addi $sp, $sp, 12
jr $ra
