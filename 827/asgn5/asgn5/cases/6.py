def f():
    a=b=c=d=10
    a*=c
    if b+d>a:
        print b+d
    else:
        def g():
            x=99
            return x
        print g()
    return a
def h():
    return 11.11
print f()+h()
