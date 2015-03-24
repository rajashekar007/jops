import math
n=raw_input()
k=1
for i in n:
	j=int(i)
	if j>0:
		k=k*j
# print k
l=int(math.sqrt(k))
ans=0
for i in xrange(l):
	t=k-i*i
	j=int(math.sqrt(t))
	if j*j==t:
		ans+=1
print ans