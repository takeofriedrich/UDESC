import math

def f(x): # função f(x) = x.e^x
    return math.cos(x**x)

def n(h,p): # Usando a formula do enunciado
    return (f(p)-f(p-h))/h

def e(h,p): # calcula o erro subtraindo o valor da derivada exata no ponto pela aproximação da derivada utilizando um h
    # retorna o modulo de f'(p) - N(h)
    return abs(  (-p*math.cos(p)*math.sin(p)) - n(h,p) )

for i in range (0.1, 0.000001 , -0.05):
    print(n(i,1))
