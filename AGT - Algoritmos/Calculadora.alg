algoritmo "semnome"
// Fun��o :
// Autor : Vin�cius Takeo e Rodrigo Silva
// Data : 01/04/2018
// Se��o de Declara��es
var
n1,n2,res:real
op:caracter
inicio
escreval("Digite um n�mero")
leia(n1)
escreval("Digite mais um n�mero")
leia(n2)
escreval("Digite + para somar esses dois n�meros")
escreval("Digite - para subtrair esses dois n�meros")
escreval("Digite : para dividir esses dois n�meros")
escreval("Digite * para multiplica esses dois n�meros")
escreval("Digite ^ para elevar um n�mero ao outro")
leia(op)
se(op="+")entao
   res<-(n1+n2)
senao
   se(op="-")entao
      res<-(n1-n2)
   senao
      se(op="^")entao
         res<-exp(n1,n2)
      senao
         se(op="*")entao
            res<-n1*n2
         senao
            se(op=":")e(n2<>0)entao
               res<-(n1/n2)
            senao
               se(op=":")e(n2=0)entao
                  escreval("� impossivel dividir um n�mero por zero")
                  interrompa
               senao
                  escreval("Entre com um dos operadores da lista")
                  interrompa
               fimse
            fimse
         fimse
      fimse
   fimse
fimse
escreval("----------------------------------------------------------------------------------------")
escreval("                                    ",n1," ",op,n2," =",res)
escreval("----------------------------------------------------------------------------------------")
fimalgoritmo
