t=input()
while t:
	t-=1
	n=input()
	if n%2:
		k=n/2
		ans=n*n + 1 -((k*(k+1))/2+n+k+1)
	else:
		k=n/2+1
		ans=n*n-((k*(k+1)/2))
	if ans>=1:
		print 'DWON %d' %(ans)
	else:
		print 'DDOWN'