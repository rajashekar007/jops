import math
md=10**9+7
def msum(a):
	return (a*(a+1))/2
# t=input()
for n in xrange(1,100):
	# t-=1
	# n=input()
	ans=0
	x=1
	a=n/x
	b=n/(x+1)
	while a!=int(math.sqrt(n)):
		ans=(ans+a*x+x*(msum(a)-msum(b)))%md
		x+=1
		a=n/x
		b=n/(x+1)
	if(a>=x):
		ans=(ans+a*a)%md
	# print ans

	a1=0
	for x in xrange(1,n+1):
		y=n/x
		a1+=x*y
	# print a1

	if(a1!=ans):
		print  'found'

