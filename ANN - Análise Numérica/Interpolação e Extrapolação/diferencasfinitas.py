import math

def f(x):
    return math.exp(x)

def dk(x1,x0,y1,y0):
    return (y1-y0)/(x1-x0)

def deltas(vetorX):
    



y0 = f(x0)
print(y0)
y1 = f(x1)
print(y1)
y2 = f(x2)
print(y2)

d1 = dk(x1,x0,y1,y0)
print("d1 = ",d1)
d2 = dk(x2,x1,y2,y1)
print("d2 = ",d2)

d3 = dk(d2,d1,x2,y1)
print("d3 = ",d3)

print("d1 * x0 = ",d1*x0)
print("d2 * (x1-x0) = ",d2*(x1-x0))
