import bisect
t=input()
ar=[]
while t>0:
	t-=1
	while 1:
		a=input()
		if(a>0):
			bisect.insort(ar,a)
		elif(a==0):
			ar=[]
			break;
		else:
			i=(len(ar)-1)/2
			print ar[i]
			del ar[i]
