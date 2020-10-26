  .text
  .globl main
main:
  li $s0, 2 # a = 2
  li $v0, 5
  syscall
  addi $s2, $v0, 0
  addi $s1, $v0, 0
loop:
  beq $s0, $s1, fim #  desvie se s0 for igual a s1
  mul $s2, $s2, $s0 # fat = fat * a
  addi $s0, $s0, 1 # contador s0 incrementa 1 # a = a * 2
  j loop
fim:
  addi $a0, $s2, 0
  li $v0, 1
  syscall
end:
  li $v0, 10
  syscall
