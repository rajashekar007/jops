def p(n):
	ans=1
	while n:
		ans*=((n&1)+1)
		n=n>>1
	return ans

import sys
t=input()
num=sys.stdin.readlines()
for n in num
	k=p(n)
	print '%d %d' %(n+1-k,k)