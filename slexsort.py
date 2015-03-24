t=input()
while t:
	t-=1;a=raw_input();n=input();l=[]
	while n:
		n-=1;l.append(raw_input())
	for x in sorted(l, key=lambda w: [a.index(c) for c in w]):
		print x
	print ''
	if t:
		raw_input()