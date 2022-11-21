  .data 0x10010000

a:

  .word 30

  .word 50

  .word -10

  .word 45

  .word 100

   .text

   .globl main

main:  lui $s0, 0x1001

           addi $s1, $0, 5

           add $t0, $0, $0

           add $s2, $0, $0

for:     slt $t1, $t0, $s1

           beq $t1, $0, end

           lw  $t2, 0($s0)

           add $s2, $s2, $t2

           addi $t0, $t0, 1

           addi $s0, $s0, 4

           j for

end:   nop
           jr $ra
