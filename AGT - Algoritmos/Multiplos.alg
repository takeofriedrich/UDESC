Algoritmo "Multiplos"
// Disciplina  :  Algoritmos
// Professor   :
// Descrição   :
// Autor(a)    : Vinícius Takeo e Rodrigo Silva
// Data atual  : 01/04/2018
Var
// Seção de Declarações das variáveis
n1,n2,resul:inteiro
Inicio
escreval("Digite um número qualquer")
leia(n1)
escreval("Digite outro número qualquer")
leia(n2)
        se(n1<=n2)entao
        resul<-(n2)mod(n1)
        senao
        resul<-(n1)mod(n2)
        fimse
             se(resul=0)entao
             escreval("Esses dois números são multiplos entre si")
             senao
             escreval("Esses dois números não são multiplos entre si")
             fimse
fimalgoritmo

