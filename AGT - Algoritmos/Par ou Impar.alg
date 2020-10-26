algoritmo "Par ou Impar"
// Função :
// Autor : Vinícius Takeo e Rodrigo Silva
// Data : 01/04/2018
// Seção de Declarações
var
a:inteiro
inicio
escreval("Digite um número inteiro maior do que 0")
leia(a)
se (a<=0) entao
   escreval("Tente outro número maior do que 0")
   interrompa
senao
   se(a)mod(2)=0 entao
      escreval("Esse número é par")
   senao
      escreval("Esse número é impar")
      se (a<=20) entao
         escreval("Esse número é menor ou igual a 20")
      senao
         se (a)mod(19)=0 entao
            escreval("Esse número é múltiplo de 19")
         senao
            se (a)mod(17)=0 entao
               escreval("Esse número é múltiplo de 17")
            senao
               se (a)mod(13)=0 entao
                  escreval("Esse número é múltiplo de 13")
               senao
                  se (a)mod(11)=0 entao
                     escreval("Esse número é múltiplo de 11")
                  senao
                     se (a)mod(7)=0 entao
                        escreval("Esse número é múltiplo de 7")
                     senao
                        se (a)mod(5)=0 entao
                           escreval("Esse número é múltiplo de 5")
                        senao
                           se (a)mod(3)=0 entao
                              escreval("Esse número é múltiplo de 3")
                           fimse
                        fimse
                     fimse
                  fimse
               fimse
            fimse
         fimse
      fimse
   fimse
fimse
fimalgoritmo
