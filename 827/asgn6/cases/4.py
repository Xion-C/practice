def f(x):
    x=1
    def f1(x):
        def f11(x):
            def f111(x):
                print x
                return x
            print x
            def f112(x):
                x=20
                return x
            print x
            y = f111(x)+f112(x)
            f111(y)
            return y
        def f12(x):
            y = f11(x)
            if y>x :
                print y
                return y
            else:
                return x
        return f12(x)
    print x
    return f1(x)
x=-11.11
print f(x)
print x
