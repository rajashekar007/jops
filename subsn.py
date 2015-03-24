t=input()
for ind in range(1,t+1):
	s=raw_input()
	q=input()
	print 'Case %d:' %ind
	while q>0:
		q-=1
		a=raw_input()
		j=0
		i=0
		while i<len(a) and j<len(s):
			if a[i]==s[j]:
				i+=1
			j+=1
		if i==len(a):
			print 'YES'
		else:
			print 'NO'