import math
md=1000000007
def msum(a):
	return ((a*(a+1))/2)
t=input()
while t:
	t-=1
	n=input()
	ans=0
	x=1
	a=n/x
	b=n/(x+1)
	# print x,a,b
	while a!=int(math.sqrt(n)):
		ans=(ans+a*x+x*(msum(a)-msum(b)))%md
		x+=1
		a=n/x
		b=n/(x+1)
		# print x,a,b
	if(a>=x):
		ans=(ans+a*a)%md
	print ans