
def smallPow2(v):
	v-=1
	v|=v>>1
	v|=v>>2
	v|=v>>4
	v|=v>>8
	v|=v>>16
	v+=1
	return v>>1
t=input()
md=1000000007
while t:
	t-=1
	n=input()
	if n%4==0 or n%4==2:
		if n&(n-1)==0:
			ans=1
		else:
			ans=n-smallPow2(n)+1
	elif n%4==1:
		ans=(n+1)/2
	else:
		ans=0
	print 2**n%md,ans