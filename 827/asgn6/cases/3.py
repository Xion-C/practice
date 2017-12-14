x=y=z=10.101
def f1(x):
    a=x+10
    print a + x
    return a + x
def f2(y):
    z = f1(y) + x
    def f3(z):
        return f1(z)
    print f3(z)
f2(z)
