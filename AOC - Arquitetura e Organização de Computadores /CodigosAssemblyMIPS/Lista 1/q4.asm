  .text
  .globl main
main:
  li $s0, -1 # variável de controle do loop # a
  li $s1, 0 # variável da soma # som
  li $s2, 0 # variável de leitura # b
  li $s3, 2048 # variaável 2 de controle do loop # b
loop:
  li $v0, 5 # le um valor
  syscall
  addi $s2, $v0, 0 # variável de leitura # armazena o valor em b
  beq $s2, $s0, fimloop # se o que foi lido for igual a -1 pula para o fim do loop
  add $s1, $s1, $s2 # som = som + b
  slti $t1, $s1, 2048 # if( s1<2048 ) t1 = 1; else t1 = 0
  beqz $t1, fimloop # if ( t1 == 0 ) fimloop; else loop
  j loop
fimloop:
  addi $a0, $s1, 0 # adiciona em a0 o valor que foi lido com 0
  li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  syscall # chama o sistema operacional
end:
  li $v0, 10
  syscall
