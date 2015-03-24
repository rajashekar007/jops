md=10**9+7
# a=[1]*503
# for i in xrange(1,503):
# 	a[i]=a[i-1]*i%md
import math
while 1:
	n=input()
	if n==0:
		break;
	b=map(int,raw_input().split())
	c=map(int,raw_input().split())
	d=[0]*n
	for i in xrange(n):
		d[i]=c[i]-b[i]
	s=0
	for i in d:
		s+=i
	ans=math.factorial(s)
	for i in d:
		ans=ans/math.factorial(i)
	print ans%md
