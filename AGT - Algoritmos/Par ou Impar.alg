algoritmo "Par ou Impar"
// Fun��o :
// Autor : Vin�cius Takeo e Rodrigo Silva
// Data : 01/04/2018
// Se��o de Declara��es
var
a:inteiro
inicio
escreval("Digite um n�mero inteiro maior do que 0")
leia(a)
se (a<=0) entao
   escreval("Tente outro n�mero maior do que 0")
   interrompa
senao
   se(a)mod(2)=0 entao
      escreval("Esse n�mero � par")
   senao
      escreval("Esse n�mero � impar")
      se (a<=20) entao
         escreval("Esse n�mero � menor ou igual a 20")
      senao
         se (a)mod(19)=0 entao
            escreval("Esse n�mero � m�ltiplo de 19")
         senao
            se (a)mod(17)=0 entao
               escreval("Esse n�mero � m�ltiplo de 17")
            senao
               se (a)mod(13)=0 entao
                  escreval("Esse n�mero � m�ltiplo de 13")
               senao
                  se (a)mod(11)=0 entao
                     escreval("Esse n�mero � m�ltiplo de 11")
                  senao
                     se (a)mod(7)=0 entao
                        escreval("Esse n�mero � m�ltiplo de 7")
                     senao
                        se (a)mod(5)=0 entao
                           escreval("Esse n�mero � m�ltiplo de 5")
                        senao
                           se (a)mod(3)=0 entao
                              escreval("Esse n�mero � m�ltiplo de 3")
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
