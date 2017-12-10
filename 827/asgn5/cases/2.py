def f():
    x=1
    y=2
    z=3
    def g():
        print 101
        def h():
            print 102
        print 103
    if x>0:
        y=22
    else:
        y=11
    def gg():
        print 1011
def ff():
    print 104
# f()
