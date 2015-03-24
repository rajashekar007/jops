t=input()
for j in range(1,t+1):
	n=input()
	ans=''
	ind=[]
	for i in range(n):
		a=raw_input()
		if not a in ans:
			ind.append(len(ans)+1)
			ans+=a
		else:
			ind.append(ans.index(a)+1)
	print 'case %d Y' %(j)
	print ans
	for i in ind:
		print i