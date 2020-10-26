	.globl main
main:
	li $s0, 0
loop:
	li $v0, 5
	syscall
	add $s1, $v0, 0
	beq $s0, $s1, fimloop
	andi $t1, $s1, 1
	li $t2, 1
	beq $t1, $t2, impar
par:
	la $a0, ehPar
	li $v0, 4
	syscall
	j loop
impar:
	la $a0, ehImpar
	li $v0, 4
	syscall
	j loop
fimloop:

end:
	li $v0, 10
	syscall
	.data
ehPar:
	.asciiz "Eh par\n"
ehImpar:
	.asciiz "Eh impar\n"
