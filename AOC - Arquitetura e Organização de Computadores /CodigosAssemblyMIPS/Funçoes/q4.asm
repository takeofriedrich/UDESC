	.text
	.globl main
main:	
	addi $sp, $sp, -20
	
	li $v0, 5
	syscall
	sw $v0, 0($sp)
	
	li $v0, 5
	syscall
	sw $v0, 4($sp)
	
	li $v0, 5
	syscall
	sw $v0, 8($sp)
	
	li $v0, 5
	syscall
	sw $v0, 12($sp)
	
	li $v0, 5
	syscall
	sw $v0, 16($sp)
	
	jal polinomio
	addi $a0, $v0, 0
	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
	addi $sp, $sp, 20
  	syscall # chama o sistema operacional
end:	
	li $v0, 10
	syscall
polinomio:
	
	lw $s0, 0($sp) # x
	lw $s1, 4($sp) # a
	lw $s2, 8($sp) # b
	lw $s3, 12($sp) # c
	lw $s4, 16($sp) # d
	
	addi $s5, $s4, 0 # adiciona em s5 o valor de d
	mul $t0, $s0, $s3 # t0 = x*c
	add $s5, $s5, $t0 # s5 = d + cx
	mul $s0, $s0, $s0 # x = x*x
	mul $t0, $s2, $s0 # t0 = x*x*b
	add $s5, $s5, $t0 # s5 = d + cx + bxx
	mul $s0, $s0, $s0 # x = x*x*x
	mul $t0, $s1, $s0 # t0 = x*x*x*a
	add $s5, $s5, $t0 # s5 = d +cx + bxx + axxx
	
	addi $v0, $s5, 0 # adiciona em a0 o valor de s2
	
	jr $ra