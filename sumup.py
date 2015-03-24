t=input()
while t>0:
	t-=1
	n=input()
	s=0.0
	for i in range(n+1):
		s+=(i+0.0)/((i**2 +i+1)*(i**2 -i+1))
	print '%.5f' %s