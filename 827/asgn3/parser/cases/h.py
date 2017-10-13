def getKey():
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''

    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

def main():
	print("press q to quit\n")
	settings = termios.tcgetattr(sys.stdin)
	com=serial.Serial('/dev/rfcomm0',9600)
	command=0
	i=0
	prekey=0
	while 1 :
		key=getKey()
		if key in movecontrol.keys():
			command=movecontrol[key][0]
			des=movecontrol[key][1]
			print("%s  %d"%(des,i))
			# command=struct.pack('8s',command)
			# print command
		elif key == 'q' :
			break
		else :
			command="\x24\x4D\x3E\x02\x70\x80\x80\x72"

		if (prekey==key and prekey!=0 and (key in movecontrol.keys() ) ):
			i += 1
		else :
			i=0

		prekey=key
		com.write(command)

	print("\nBalanceRobot control program quit")

main()
