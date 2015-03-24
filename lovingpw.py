n=input()
cnt=0
for i in xrange(n+1):
	for j in xrange(i+1,n+1):
		x=i^j
		if x&(x-1)==0:
			cnt+=1
			print i,j,i^j
print cnt