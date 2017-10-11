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
if not os.path.isdir( testDir ):
  print testDir, "isn't a directory"
  sys.exit( 1 )

executable = os.path.join(os.getcwd(), "run")
if os.path.isfile( executable ):
  retcode = subprocess.call("make clean",shell=True)
  testCode( retcode, "\tFAILED to make the scanner" )
retcode = subprocess.call("make",shell=True)
testCode( retcode, "\tFAILED to make the scanner" )

files = os.listdir( testDir )
outdir = "./tme/out"
for x in files:
  if fnmatch.fnmatch(x, "*.py"):
    testcase = os.path.join(testDir, x)
    retcode = subprocess.call("./run < "+testcase+"> "+outdir,shell=True)
    if retcode != 0:
      testCode( retcode, "\tFAILED to run test case "+x)
    else:
      output = testcase[:-3]+".out"
      if not os.path.isfile( output ):
        print "test case", x[:-3]+'.out', "doesn't exist"
        sys.exit( 1 )
      if not filecmp.cmp(outdir, output): 
        print "\tTEST CASE FAILED", x
      else :
        print "testcase:", x, "passed"


