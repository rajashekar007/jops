s,n=map(int,raw_input().split())
K=[[]]*(n+1)
for i in xrange(n+1):
	K[i]=[0]*(s+1)
val=[0]*(n+1)
wt=[0]*(n+1)
for i in xrange(1,n+1):
	wt[i],val[i]=map(int,raw_input().split())

for i in xrange(1,n+1):
	for w in xrange(1,s+1):
		if wt[i]<=w:
			K[i][w]=max(val[i]+K[i-1][w-wt[i]],K[i-1][w])
		else:
			K[i][w]=K[i-1][w]
	# print i,w,K[i][w]
print K[n][s]