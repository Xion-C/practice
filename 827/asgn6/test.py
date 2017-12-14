#!/usr/bin/python

import os, sys
import fnmatch
import subprocess
import filecmp

def testCode( retcode, msg ):
    if retcode > 0:
        print msg
        sys.exit( 1 )

testDir = os.path.join( os.getcwd(), 'cases')
tempDir = os.path.join( os.getcwd(), 'casestmp')

if not os.path.isdir( tempDir ) :
    os.mkdir( tempDir )
print "tmp directory : ", tempDir

if not os.path.isdir( testDir ):
    print testDir, "isn't a directory"
    sys.exit( 1 )

executable = os.path.join(os.getcwd(), "run")
# if os.path.isfile( executable ) :
    # retcode = subprocess.call("make clean",shell=True)
    # testCode( retcode, "\tFAILED to make clean" )
if not os.path.isfile( executable ) :
    retcode = subprocess.call("make",shell=True)
    testCode( retcode, "\tFAILED to make" )

files = os.listdir( testDir )
for x in files:
    if fnmatch.fnmatch(x, "*.py"):
        testcase = os.path.join(testDir, x)
        tmpcase = os.path.join(tempDir, x)
        tmpout = tmpcase[:-3]+".tmpout"
        retcode = subprocess.call("./run < "+testcase+"> "+tmpout,shell=True)
        if retcode != 0:
            testCode( retcode, "\tFAILED to run test case "+x)
            sys.exit( 1 )
        # else
        output = testcase[:-3]+".out"
        if not os.path.isfile( output ):
            print "test case", x[:-3]+'.out', "doesn't exist"
            sys.exit( 1 )
        # print " @@@ Compare ", tmpout, output
        if not filecmp.cmp(tmpout, output):
            print " --- --- TEST CASE:", x, "- FAILED -"
        else :
            print " *** *** Test Case:", x, "* Passed *"
