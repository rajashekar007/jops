def zfun(s):
	n=len(s)
	z=[0]*n
	l,r,i=0,0,1
	while i<n:
		if i<=r:
			z[i]=min(r-i+1,z[i-l])
		while i+z[i]<n and s[z[i]]==s[i+z[i]]:
			z[i]+=1
		if i<r:
			l,r=i,i+z[i]-1
		i+=1
	i,cnt=1,0
	while i<n:
		if z[i]==n-i:
			cnt+=1
		i+=1
	return cnt
t=input()
i=1
while i<=t:
	s=raw_input()
	print 'Case %d: %d' %(i,zfun(s))
	i+=1