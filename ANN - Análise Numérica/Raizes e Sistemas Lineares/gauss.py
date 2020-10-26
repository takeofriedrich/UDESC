def pivotamento(A):
    for i in range(len(A) - 1):
        for j in range(i + 1,len(A)):
            n1 = A[j][i]
            if n1 == 0:
                for k in range(i,len(A)):
                    if A[k][i] != 0:
                        swap(A, i, k)
                        n1 = A[j][i]
            n2 = A[i][i]
            if n2 == 0:
                continue
            div = n1 / n2
            A[j] = sumVector(multVector(A[i], -div), A[j])
    return A


def multVector(v, x):
    newV = []
    for i in range(len(v)):
        newV += [v[i] * x]
    return newV

def sumVector(v1, v2):
    newV = []
    for i in range(len(v1)):
        newV += [v1[i] + v2[i]]
    return newV

def swap(A, i, j):
    newI = []
    newJ = []
    for index in range(len(A) + 1):
        newI += [A[j][index]]
        newJ += [A[i][index]]
    A[i] = newI
    A[j] = newJ

def printMatrix(A,n):
  for i in range (n):
      print(A[i])

def resolveTriangular(A,n):
    x = [0 for i in range (n)]
    b = [0 for i in range(n)]

    for i in range (n):
        b[i] = A[i][n]

    x[n-1] = b[n-1] / A[n-1][n-1]

    for i in range (n-2,-1,-1):
        s = 0
        for j in range (i+1,n,1):
            s = s + A[i][j]*x[j]
        x[i] = (b[i] - s)/A[i][i]

    return x

def resolveGauss(A,n):
    pivotamento(A)
    x = resolveTriangular(A,n)

    for i in range (n):
        print("x[",i,"] = ",x[i])

def leMatriz(n):
    A = [0 for i in range(n)]
    print("Digite a matriz:\n")
    for i in range (n):
        x = [0 for i in range(n+1)]
        for j in range (n+1):
            x[j] = float(input())
        A[i] = x
    return A

#A = [[3.0, 2.0, -1.0, 8.0], [2.0, -4.0, 2.0, -4.0], [-1.0, 1.0, 5.0, 3.0]]
print("Digite o numero de variáveis do sistema")
n = int(input())
A = leMatriz(n)
printMatrix(A,n)
resolveGauss(A,n)
