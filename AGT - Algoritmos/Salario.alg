algoritmo "semnome"
// Fun��o :
// Autor :
// Data : 15/03/2018
// Se��o de Declara��es 
var
codven:caracter
salar,percentual,salartot:real
nvend:inteiro
inicio
escreval("Entre com o c�digo do vendedor")
leia(codven)
escreval("Entre com o sal�rio fixo do vendedor")
leia(salar)
escreval("Entre com o n�mero de vendas do vendedor")
leia(nvend)
escreval("Entre com o percentual sobre o total de vendas do vendedor")
leia(percentual)
salartot<-salar+(nvend*(percentual/100))
escreva("O sal�rio total do vendedor de c�digo ")
escreva(codven)
escreva(" �: R$")
escreva(salartot)
fimalgoritmo
