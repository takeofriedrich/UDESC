	.text
	.globl main
main:
	li $s1, 0 # primeiro numero de fibonacci
	li $s2, 1 # segundo numero de fibonacci
	li $s3, 1 # contador (começa em 2 pois já possui dois numeros)
	li $v0, 5 # quantidade de numeros da sequenciali $v0, 5 # le um valor
  	syscall
  	add $s0, $v0, 0 # quantidade de numeros da sequencia
loop:
	beq $s3, $s0, fimloop # pula para o final do loop se o contador for igual a 20
	add $t0, $s1, $s2 # t0 = s1 + s2
	addi $s1, $s2, 0 # s1 = s2
	addi $s2, $t0, 0 # s2 = t0
	addi $s3, $s3, 1 # incrementa o contador
	j loop
fimloop:
	addi $a0, $s2, 0 # adiciona em a0 o valor de s2
  	li $v0, 1 # requisita ao sistema operacional para imprimir o valor que existe a0
	syscall # chama o sistema operacional
end:
	li $v0, 10
	syscall
