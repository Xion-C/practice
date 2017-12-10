def f():
    x=1
    y=2
    z=3
    def g():
        print x+101
        def h():
            print y+102
        h()
        print z+103
    g()
    def gg():
        print 1011
    gg()
def ff():
    print 104
f()
ff()
