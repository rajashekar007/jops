t=input()
m=1000000007
for j in range(1,t+1):
	n=input()
	n2=2*n
	ans=0
	i=1
	while i<=n2:
		k=n2-i-n2/i+2
		ans=(ans+2**(k-1)%m)%m
		i+=1
	ans=(2**n2%m-(ans)%m+m)%m
	print 'Case %d: %d' %(j,ans-1)
	# print ''