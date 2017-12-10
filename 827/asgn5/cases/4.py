def f():
    x=1
    def f1():
        x=100
        def f11():
            x=999
            def f111():
                print x
                return x
            print x
            def f112():
                x=20
                return x
            print x
            return f111()+f112()
        def f12():
            y = f11()
            if y>x :
                print y
                return y
            else:
                return x
        return f12()
    print x
    return f1()
x=-11.11
print f()
print x
