x=y=z=10.101
def f1():
    a=10
    print a
    return a + x
def f2():
    def f3():
        return f1()
    print f3()
f2()
