from sympy import *
A = Symbol('A')
B = Symbol('B')
V = Symbol('V')
print solve([sin(A)/600-sin(B)/V, 1-tan(A)-tan(B), 0.04421-1/(60*cos(A))-10/(V*cos(B))],[A, B, V])
#print solve([sin(A)/600-sin(B), 1-tan(A)-tan(B)],[A, B])
print tan(pi/4)
