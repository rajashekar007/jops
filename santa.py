t=input()
while t:
	t-=1
	n,x,y,s=map(int,raw_input().split())
	w=0
	a=[]
	for i in xrange(n):
		x1,y1,s1=map(int,raw_input().split())
		if w+s1<=s:
			w+=s1
			print -(i+1),
			a.append(i+1)
		else:
			w=s1
			for j in a:
				print j,
			print -(i+1),
			a=[i+1]
	for j in a:
		print j,
	print 0