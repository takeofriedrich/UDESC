algoritmo "Triângulos"
// Função :
// Autor : Vinícius Takeo e Rodrígo Silva
// Data : 01/04/2018
// Seção de Declarações
var
a,b,c:real
inicio
escreval("Digite 3 números correspondentes a lados de um triângulo")
leia(a)
leia(b)
leia(c)
se(a>=b+c)ou(b>=c+a)ou(c>=a+b)entao
   escreval("             Esse triângulo não existe             ")
   interrompa
senao
   se((a=b)e(b=c))entao
      escreval("             Esse triângulo é equilátero             ")
   senao
      se(a=b)ou(b=c)ou(c=a)entao
         escreval("             Esse triângulo é isósceles             ")
      senao
         escreval("             Esse triângulo é escaleno             ")
      fimse
   fimse
   se(exp(a,2)=(exp(b,2)+exp(c,2)))ou(exp(b,2)=(exp(a,2)+exp(c,2)))ou(exp(c,2)=(exp(a,2)+exp(c,2)))entao
      escreva("             Esse triângulo é retângulo             ")
   senao
      se(exp(a,2)>(exp(b,2)+exp(c,2)))ou(exp(b,2)>(exp(a,2)+exp(c,2)))ou(exp(c,2)>(exp(a,2)+exp(b,2)))entao
         escreva("             Esse triângulo é obtusangulo             ")
      senao
            escreva("             Esse triângulo é acutângulo             ")
            escreval("")
      fimse
   fimse
fimse
fimalgoritmo
