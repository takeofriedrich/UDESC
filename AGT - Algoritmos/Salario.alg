algoritmo "semnome"
// Função :
// Autor :
// Data : 15/03/2018
// Seção de Declarações 
var
codven:caracter
salar,percentual,salartot:real
nvend:inteiro
inicio
escreval("Entre com o código do vendedor")
leia(codven)
escreval("Entre com o salário fixo do vendedor")
leia(salar)
escreval("Entre com o número de vendas do vendedor")
leia(nvend)
escreval("Entre com o percentual sobre o total de vendas do vendedor")
leia(percentual)
salartot<-salar+(nvend*(percentual/100))
escreva("O salário total do vendedor de código ")
escreva(codven)
escreva(" é: R$")
escreva(salartot)
fimalgoritmo
