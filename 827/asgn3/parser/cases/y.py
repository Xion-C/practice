
def f():
    for a in range(9):
        for x in range(3):
            if x < 3:
                print x
            elif x > 8:
                print x + 100
            else:
                print x+1

def g(n):
    x = 0
    while x < n:
        if x < 3:
            print x
        elif x > 8:
            print x + 100
        else:
            print x+1
    x += 1

def m():
    b = 0
    def h():
        sum = 0
        for x in range(3):
            for y in range(4):
                for z in range(5):
                    sum += z
                    def i(n):
                        x = 0
                        while x < n:
                            if x < 3:
                                print x
                            elif x > 8:
                                print x + 100
                            else:
                                print x+1
                        x += 1
        return sum
    a = 2
    a += 1
def n():
    with open('scan.l') as f:
        print f.readlines()

f()
g(3)
m()
n()
