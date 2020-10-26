	.text
	.globl main
main:
	ori $v0,$zero,5
	syscall #lê do teclado
	ori $a0,$v0, 0 #coloca como argumento
	jal fib_rec
	ori $a0,$v0,0 #coloca o resultado como argumento
	ori $v0,$zero,1 #impressão de inteiro
	syscall #imprime o resultado
	j end
fib_rec:
	stli $t0, $a0, 2
	bne $t0, $zero, sentinela
	addi $sp, $sp, -20
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $ra, 16($sp)
	
	jal fib_rec
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $ra, 16($sp)
	addi $sp, $sp, 20
sentinela:
	ori $v0, $zero, 1
	jr $ra
end:
	li $v0, 10 #10 em $v0 para informar que o programa terminou
	syscall