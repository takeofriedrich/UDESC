def gcd(x, y):

    if x > y:
        small = y
    else:
        small = x
    for i in range(1, small+1):
        if((x % i == 0) and (y % i == 0)):
            gcd = i

    return gcd


def prime(x):
    for i in range(2, pow(x, 1/2) <= x):
        if x % d == 0:
            return False
    return True


p = 83
q = 211
n = 17513
phi = 17220
e = 79
d = 17221

print(prime(p))
print(prime(q))
print(((p-1)*(q-1)) == phi)
print(e < phi)
print(gcd(e, phi) == 1)
print(pow(d, e, phi) == 1)

a = pow(64, e, n)
print(a)
print(pow(a, d, n))
