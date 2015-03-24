import random
t=input()
while t:
	t-=1
	n,x,y,s=map(int,raw_input().split())
	w=0
	a=[]
	b=[]
	for i in xrange(n):
		x1,y1,s1=map(int,raw_input().split())
		b.append(s1)
	for i in xrange(len(b)):
		k=random.choice(range(len(b)))
		s1=b[k]
		b.remove(s1)
		if w+s1<=s:
			w+=s1
			print -(k+1),
			a.append(k+1)
		else:
			w=s1
			for j in a:
				print j,
			print -(k+1),
			a=[k+1]
	for j in a:
		print j,
	print 0