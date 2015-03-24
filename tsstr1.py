t=input()
for j in range(1,t+1):
	n=input()
	a=[]
	ans=''
	ind=[]
	for i in range(n):
		a.append(raw_input())
	i=len(a);
	while i:
		i-=1
		if not a[i] in ans:
			ind.append(len(ans)+1)
			ans+=a[i]
		else:
			ind.append(ans.index(a[i])+1)
	print 'case %d Y' %(j)
	print ans
	i=len(ind)
	while i:
		i-=1
		print ind[i]