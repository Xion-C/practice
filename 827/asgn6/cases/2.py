def factorial(n):
    if n == 1:
        print 1
        return 1
    else:
        print n * factorial(n-1)
        return n * factorial(n-1)
print factorial(4)
