def tryTest():
    try:
        den = input("input a number:")
        x = 1.0/int(den)
        for y in range(10):
            if x > 0 and y > x:
                print x
        return 1
    except Exception, e:
        for i in range(3):
            print e
        return 0
    finally:
        for i in range(3):
            for j in range(3):
                print "this is a finally test"

result = tryTest()