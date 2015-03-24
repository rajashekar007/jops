import skiplist
t=input()
while t>0:
	t-=1
	ar=[]
	while 1:
		a=input()
		if(a==0):
			break
		ar.append(a)
	n=len(ar)
	s=skiplist.IndexableSkiplist(n)
	for i in ar:
		if i!=-1:
			s.insert(i)
		else:
			l=len(s)-1
			print s[l/2]
			del s[l/2]
