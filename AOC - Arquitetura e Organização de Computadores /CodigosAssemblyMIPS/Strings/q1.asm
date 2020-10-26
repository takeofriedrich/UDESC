	.text
	.globl main
main:
	li $s0, 0
	li $s2, 2
loop:
	li $v0, 5
	syscall
	add $s1, $v0, 0
	beq $s0, $s1, fimloop
	div $s1, $s2
	mfhi $t0
	beqz $t0, par
impar:
	la $a0, ehImpar
	li $v0, 4
	syscall
	j loop
par:
	la $a0, ehPar
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
