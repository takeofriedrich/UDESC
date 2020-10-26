	.text
	.globl main
main:
while:
	li $v0, 5
	syscall
	addi $s0, $v0, 0 # carrega em s0 o valor lido
	addi $s1, $zero, 1
	slti $t1, $s0, 0 # if( s0<0 ) t1 = 0; else t1 = 1
	beq $t1, $s1, endW
	ori $a0, $s0, 0
	jal fibonacci
	addi $a0, $v0, 0
	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  	syscall # chama o sistema operacional
	j while	
endW:
	
	addi $a0, $s0, 0
	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
  	syscall # chama o sistema operacional

end:
	li $v0, 10
	syscall
fibonacci:
	addi $sp, $sp, -8
	sw $s0, 0($sp)
	sw $s0, 4($sp)
	li $s1, 0 # primeiro numero de fibonacci
	li $s2, 1 # segundo numero de fibonacci
	li $s3, 1 # contador (começa em 2 pois já possui dois numeros)
loop:
	beq $s3, $a0, fimloop # pula para o final do loop se o contador for igual a 20
	add $t0, $s1, $s2 # t0 = s1 + s2
	addi $s1, $s2, 0 # s1 = s2
	addi $s2, $t0, 0 # s2 = t0
	addi $s3, $s3, 1 # incrementa o contador
	j loop
fimloop:
	addi $v0, $s2, 0 # adiciona em a0 o valor de s2
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	addi $sp,$sp,8
	jr $ra
