def tryTest():
    try:
        den = input("input a number:")
        x = 1.0/int(den)
        for y in range(10):
            if x > 0 and y > x:
                print x
        try:
            for x in range(3):
                if x < 3:
                    print x
                elif x > 8:
                    print x + 100
                else:
                    print x+1
            try:
                den = input("input a number:")
                x = 1.0/int(den)
                for y in range(10):
                    if x > 0 and y > x:
                        print x
            except x:
                print x
            except:
                print "end except"
        except:
            x=0

    except Exception, e:
        for i in range(3):
            print e
        return 0

result = tryTest()
