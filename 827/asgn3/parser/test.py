#!/usr/bin/python
import os, sys
import fnmatch
import subprocess
import filecmp

def testCode( retcode, msg ) :
  if retcode > 0 :
    print msg
    sys.exit( 1 )

testDir = os.path.join( os.getcwd(), 'cases')
tmpOutFile = os.path.join(os.getcwd(), 'tmp')
if not os.path.isdir( testDir ) :
  print testDir, "isn't a directory"
  sys.exit( 1 )
if not os.path.isdir( tmpOutFile ) :
  os.mkdir( tmpOutFile )
tmpOutFile = os.path.join(tmpOutFile, 'out')

executable = os.path.join(os.getcwd(), "run")
if os.path.isfile( executable ) :
  retcode = subprocess.call("make clean",shell=True)
  testCode( retcode, "\tFAILED to make clean the scanner" )
retcode = subprocess.call("make",shell=True)
testCode( retcode, "\tFAILED to make the scanner" )

files = os.listdir( testDir )
print('Temporary Output Directory : ' + tmpOutFile)
for x in files :
  if fnmatch.fnmatch(x, "*.py") :
    testcase = os.path.join(testDir, x)
    output = testcase[:-3] + ".out"
    if not os.path.isfile( output ) :
        os.mknod(output)
    retcode = subprocess.call("./run < "+testcase+"> " + tmpOutFile + x[:-3], shell=True)
    retcode = retcode | subprocess.call("python -m mccabe "+testcase+" > " + output, shell=True)
    if retcode != 0 :
      testCode( retcode, "\tFAILED to run test case " + x)
    else:
      if not filecmp.cmp(tmpOutFile + x[:-3], output) :
        print "\tTEST CASE FAILED", x
      else :
        print "testcase:", x, "passed"
