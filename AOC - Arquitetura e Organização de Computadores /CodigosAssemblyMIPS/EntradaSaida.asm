  .text
  .globl main
main:
  li $v0, 5 # carrega em v0 o valor lido pelo usuario
  syscall # chama o sistema operacional
  addi $a0, $v0, 0 # adiciona em a0 o valor que foi lido com 0
  li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  syscall # chama o sistema operacional
end:
  li $v0,10
  syscall
