algoritmo "semnome"
// Função :
// Autor : Vinícius Takeo e Rodrigo Silva
// Data : 01/04/2018
// Seção de Declarações
var
n1,n2,res:real
op:caracter
inicio
escreval("Digite um número")
leia(n1)
escreval("Digite mais um número")
leia(n2)
escreval("Digite + para somar esses dois números")
escreval("Digite - para subtrair esses dois números")
escreval("Digite : para dividir esses dois números")
escreval("Digite * para multiplica esses dois números")
escreval("Digite ^ para elevar um número ao outro")
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
                  escreval("É impossivel dividir um número por zero")
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
