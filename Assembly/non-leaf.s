.text
.globl main
main: addi $sp, $sp, -24
sw $ra, 0($sp)
sw $a0, 4($sp)
sw $a1, 8($sp)
sw $a2, 12($sp)
sw $a3, 16($sp)
sw $v0, 20($sp)
addi $a0, $0, 4
addi $a1, $0, 3
addi $a2, $0, 1
addi $a3, $a0, 2
jal leaf_example
add $a0, $v0, $0
addi $v0, $0, 1
syscall
lw $ra, 0($sp)
lw $a0, 4($sp)
lw $a1, 8($sp)
lw $a2, 12($sp)
lw $a3, 16($sp)
lw $v0, 20($sp)
addi $sp, $sp, 24
jr $ra

leaf_example: addi $sp, $sp, -12
sw $t1, 8($sp)
sw $t0, 4($sp)
sw $s0, 0($sp)
add $t0, $a0, $a1
add $t1, $a2, $a3
sub $s0, $t0, $t1
add $v0, $s0, $zero
lw $s0, 0($sp)
lw $t0, 4($sp)
lw $t1, 8($sp)
addi $sp, $sp, 12
jr $ra
