Algoritmo "Multiplos"
// Disciplina  :  Algoritmos
// Professor   :
// Descri��o   :
// Autor(a)    : Vin�cius Takeo e Rodrigo Silva
// Data atual  : 01/04/2018
Var
// Se��o de Declara��es das vari�veis
n1,n2,resul:inteiro
Inicio
escreval("Digite um n�mero qualquer")
leia(n1)
escreval("Digite outro n�mero qualquer")
leia(n2)
        se(n1<=n2)entao
        resul<-(n2)mod(n1)
        senao
        resul<-(n1)mod(n2)
        fimse
             se(resul=0)entao
             escreval("Esses dois n�meros s�o multiplos entre si")
             senao
             escreval("Esses dois n�meros n�o s�o multiplos entre si")
             fimse
fimalgoritmo

