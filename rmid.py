import sys
ar=[]
for line in sys.stdin:
	if len(line) !=1:
		a=int(line)
		if(a==0):
			ar=[]
			print ''
		elif(a==-1):
			i=(len(ar)-1)/2
			if i>=0:
				print ar[i]
				del ar[i]
		else:
			ar.append(a)
