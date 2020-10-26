	.text
	.globl main
main:
	li $v0, 5
	syscall
	addi $s0, $v0, 0 # carrega em s0 o valor lido
	slti $t1, $s0, 101 # if( s0<101 ) t1 = 1; else t1 = 0
	beqz $t1, endif # se t1 = 1 pula para o fim do if
if:
	la $a0, nota50
	li $v0, 4
	syscall
	li $t1, 50 # define no registrador temporário o valor da nota
	div $s0, $t1 # divide s0 por 50
	mfhi $s0 # carrega o resto da divisão em a0
	mflo $a0 # carrega o quociente em a0
  	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  	syscall # chama o sistema operacional
  	la $a0, barraN
  	li $v0, 4
  	syscall
  	
  	la $a0, nota20
	li $v0, 4
	syscall
	li $t1, 20 # define no registrador temporário o valor da nota
	div $s0, $t1 # divide s0 por 20
	mfhi $s0 # carrega o resto da divisão em a0
	mflo $a0 # carrega o quociente em a0
  	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  	syscall # chama o sistema operacional
  	la $a0, barraN
  	li $v0, 4
  	syscall
  	
  	la $a0, nota10
	li $v0, 4
	syscall
	li $t1, 10 # define no registrador temporário o valor da nota
	div $s0, $t1 # divide s0 por 10
	mfhi $s0 # carrega o resto da divisão em a0
	mflo $a0 # carrega o quociente em a0
  	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  	syscall # chama o sistema operacional
  	la $a0, barraN
  	li $v0, 4
  	syscall
  	
  	la $a0, nota5
	li $v0, 4
	syscall
	li $t1, 5 # define no registrador temporário o valor da nota
	div $s0, $t1 # divide s0 por 5
	mfhi $s0 # carrega o resto da divisão em a0
	mflo $a0 # carrega o quociente em a0
  	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  	syscall # chama o sistema operacional
  	la $a0, barraN
  	li $v0, 4
  	syscall
  	
  	la $a0, nota2
	li $v0, 4
	syscall
	li $t1, 2 # define no registrador temporário o valor da nota
	div $s0, $t1 # divide s0 por 2
	mfhi $s0 # carrega o resto da divisão em s0
	mflo $a0 # carrega o quociente em a0
  	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  	syscall # chama o sistema operacional
  	la $a0, barraN
  	li $v0, 4
  	syscall
  	
  	la $a0, nota1
	li $v0, 4
	syscall
	addi $a0, $s0, 0
  	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  	syscall # chama o sistema operacional
  	la $a0, barraN
  	li $v0, 4
  	syscall
  	
  	j end
endif:
	la $a0, notaMaior
	li $v0, 4
	syscall
end:
	li $v0, 10
	syscall
	.data
notaMaior:
	.asciiz "Valor maior que 100, programa finalizado\n"
nota50:
	.asciiz "Notas de 50: "
nota20:
	.asciiz "Notas de 20: "
nota10:
	.asciiz "Notas de 10: "
nota5:
	.asciiz "Notas de 5: "
nota2:
	.asciiz "Notas de 2: "
nota1:
	.asciiz "Notas de 1: "
barraN:
	.asciiz "\n"