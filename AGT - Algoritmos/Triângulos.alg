algoritmo "Tri�ngulos"
// Fun��o :
// Autor : Vin�cius Takeo e Rodr�go Silva
// Data : 01/04/2018
// Se��o de Declara��es
var
a,b,c:real
inicio
escreval("Digite 3 n�meros correspondentes a lados de um tri�ngulo")
leia(a)
leia(b)
leia(c)
se(a>=b+c)ou(b>=c+a)ou(c>=a+b)entao
   escreval("             Esse tri�ngulo n�o existe             ")
   interrompa
senao
   se((a=b)e(b=c))entao
      escreval("             Esse tri�ngulo � equil�tero             ")
   senao
      se(a=b)ou(b=c)ou(c=a)entao
         escreval("             Esse tri�ngulo � is�sceles             ")
      senao
         escreval("             Esse tri�ngulo � escaleno             ")
      fimse
   fimse
   se(exp(a,2)=(exp(b,2)+exp(c,2)))ou(exp(b,2)=(exp(a,2)+exp(c,2)))ou(exp(c,2)=(exp(a,2)+exp(c,2)))entao
      escreva("             Esse tri�ngulo � ret�ngulo             ")
   senao
      se(exp(a,2)>(exp(b,2)+exp(c,2)))ou(exp(b,2)>(exp(a,2)+exp(c,2)))ou(exp(c,2)>(exp(a,2)+exp(b,2)))entao
         escreva("             Esse tri�ngulo � obtusangulo             ")
      senao
            escreva("             Esse tri�ngulo � acut�ngulo             ")
            escreval("")
      fimse
   fimse
fimse
fimalgoritmo
