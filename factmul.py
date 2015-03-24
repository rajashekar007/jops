
m=109546051211
n=input()
if(n>=587117):
	print 0
else:
	a=[1]*(n+1)
	ans=1
	for i in range(2,n+1):
		a[i]=(i*a[i-1])%m
		ans=(ans*a[i])%m
	print ans

