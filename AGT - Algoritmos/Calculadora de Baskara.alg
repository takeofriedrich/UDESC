algoritmo "Fun��o Quadr�tica"
// Fun��o : Dar as coordenadas do plano cartesiano de uma fun��o quadratica
// Autor : Kiceatos
// Data : 18/03/2018
// Se��o de Declara��es 
var
ca,cb,cc,delta,x1,x2,xv,yv,x3,x4,y1,y2,y3,y4:real
inicio
escreval("Digite o coeficiente A da sua equa��o")
leia(ca)
se(ca=0)entao
             escreval("A n�o pode ser 0, tente novamente")
             interrompa
fimse
escreval("Digite o coeficiente B da sua equa��o")
leia(cb)
escreval("Digite o coeficiente C da sua equa��o")
leia(cc)
delta<-exp(cb,2)-4*ca*cc
se(delta>=1)entao
            x1<-(-cb+raizq(delta))/(2*ca)
            x2<-(-cb-raizq(delta))/(2*ca)
            xv<-(x1+x2)/2
            yv<-ca*exp(xv,2)+cb*xv+cc
            x3<-x1+1
            x4<-x2-1
            y1<-ca*exp(x1,2)+cb*x1+cc
            y2<-ca*exp(x2,2)+cb*x2+cc
            y3<-ca*exp(x3,2)+cb*x3+cc
            y4<-ca*exp(x4,2)+cb*x4+cc
            escreval("Aqui est�o cinco pares ordenados da fun��o que voc� pediu")
            escreval("x=",x4," y=",y4)
            escreval("x=",x2," y=",0)
            escreval("x=",xv," y=",yv)
            escreval("x=",x1," y=",0)
            escreval("x=",x3," y=",y3)
            escreval("")
            escreval("O Dom�nio dessa fun��o �: D=R")
            se(ca>=1)entao
                          escreval("O conjunto Imagem dessa fun��o �: Im={y e R|y>=",yv)
            fimse
            se(ca<=-1)entao
                           escreval("O conjunto Imagem dessa fun��o �: Im={y e R|y<=",yv)
            fimse
fimse
se(delta=0)entao
           x1<--cb/(2*ca)
           y1<-ca*exp(x1,2)+cb*x1+cc
           x3<-x1+1
           x4<-x1-1
           y3<-ca*exp(x3,2)+cb*x3+cc
           y4<-ca*exp(x4,2)+cb*x4+cc
           escreval("Aqui est�o tr�s pares ordenados da fun��o que voc� pediu")
           escreval("x=",x4," y=",y4)
           escreval("x=",x1," y=",y1)
           escreval("x=",x3," y=",y3)
           escreval("")
           escreval("O Dom�nio dessa fun��o �: D=R")
           se(ca>=1)entao
                         escreval("O conjunto Imagem dessa fun��o �: Im={y e R|y>=",y1)
           fimse
           se(ca<=1)entao
                         escreval("O conjunto Imagem dessa fun��o �: Im={y e R|y<=",y1)
           fimse
fimse
se(delta<0)entao
escreval("")
escreval("Essa fun��o apresenta delta negativo, ")
escreval("logo ela n�o possui valores de x reais para formar um gr�fico")
escreval("")
fimse
interrompa
fimalgoritmo
