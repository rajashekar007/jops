
def RepresentsInt(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False

n=input()

for i in range(n):
	s=raw_input()
	s=raw_input()
	s=s.split()
	# print s
	if RepresentsInt(s[0]) and RepresentsInt(s[2]):
		print s[0]+' + '+s[2]+' = '+str(int(s[0])+int(s[2]))
	elif RepresentsInt(s[0]) and RepresentsInt(s[4]):
		t=int(s[4])-int(s[0])
		print s[0]+' + '+str(t)+' = '+s[4]
	else:
		t=int(s[4])-int(s[2])
		print str(t)+' + '+s[2]+' = '+s[4]
	# s=raw_input()