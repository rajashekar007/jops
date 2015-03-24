def p(n):
	ans=1
	while n:
		ans*=((n&1)+1)
		n=n>>1
	return ans
t=input()
while t:
	t-=1
	n=input()
	k=p(n)
	print '%d %d' %(n+1-k,k)