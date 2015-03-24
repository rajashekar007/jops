def p(n):
	ans,q=0,2
	while n/q:
		ans+=n/q
		q=2*q
	return ans
t=input()
while t:
	t-=1
	n=input()
	o,e,pn=2,0,p(n)
	for k in range(1,n):
		if pn-p(k)-p(n-k):
			e+=1
		else:
			o+=1
	print '%d %d' %(e,o)