a=[0]*37
for i in xrange(1,36):
	a[i]=3*a[i-1]+2
t=input()
while t:
	t-=1
	print a[input()]