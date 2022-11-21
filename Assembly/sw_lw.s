.text
.globl main
main:
lui $5, 0x1000
lui $4, 0x789A
ori $4, $4, 0xBCDE
sw $4, 8($5)
lw $6, 8($5)
