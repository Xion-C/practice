def tryTest():
    try:
        den = input("input a number:")
        x = 1.0/int(den)
        for y in range(10):
            if x > 0 and y > x:
                print x
        with open('scan.l') as f:
            print f.readlines()
    finally:
        print x
        print "this is a finally"
    return 1

result = tryTest()
