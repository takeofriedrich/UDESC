  .text
  .globl main
main:
  li $s0, -1 # variável de controle do loop # a
  li $s1, 0 # variável da soma # som
  li $s2, 0 # variável de leitura # b
loop:
  li $v0, 5 # le um valor
  syscall
  addi $s2, $v0, 0 # variável de leitura # armazena o valor em b
  beq $s2, $s0, fimloop # while( a != b )
  add $s1, $s1, $s2 # som = som + b
  j loop
fimloop:
  addi $a0, $s1, 0 # adiciona em a0 o valor de som
  li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  syscall # chama o sistema operacional
end:
  li $v0, 10
  syscall
