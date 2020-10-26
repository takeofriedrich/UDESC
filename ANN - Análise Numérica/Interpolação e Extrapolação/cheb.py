import math

def z(k,n):
    return math.cos( ((2*k + 1) * math.pi )/ (2*(n+1))  )

def x(k,n,a,b):
    return ((b-a)/2)*z(k,n) + ((b-a)/2)

def f(x):
    return math.exp(-x**2)*2

def delta(x1,x0,y1,y0):
    return (y1-y0)/(x1-x0)

vetorX = []
vetorY = []

for i in range (6):
    vetorX.append(x(i,5,1,2))
    vetorY.append(f(vetorX[i]))
d1 = []

for i in range (5):
    d1.append(delta(vetorX[i+1],vetorX[i],vetorY[i+1],vetorY[i]))

d2 = []

for i in range (4):
    d2.append(delta(d1[i+1],d1[i],vetorX[i+2],vetorX[i]))

d3 = []

for i in range (3):
    d3.append(delta(d2[i+1],d2[i],vetorX[i+3],vetorX[i]))

d4 = []

for i in range (2):
    d4.append(delta(d3[i+1],d3[i],vetorX[i+4],vetorX[i]))

d5 = []

for i in range (1):
    d5.append(delta(d4[i+1],d4[i],vetorX[i+5],vetorX[i]))

deltas = []
deltas.append(d1[0])
deltas.append(d2[0])
deltas.append(d3[0])
deltas.append(d4[0])
deltas.append(d5[0])

for i in range (len(deltas)):
    print("delta",i," = ",deltas[i])

for i in range (len(vetorX)):
    print(vetorX[i],",",vetorY[i])
