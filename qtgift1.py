mx=-1
def gift(a,j,i,n,s,k):
	global mx
	if i==n:
		if s>mx:
			mx=s
	elif j==k:
		gift(a,1,i+1,n,s,k)
	else:
		gift(a,j+1,i+1,n,s+a[i],k)
		gift(a,j+1,i+1,n,s,k)

a=[]
n=input()
k=input()
for i in xrange(n):
	a.append(input())

gift(a,1,0,n,0,k)
print mx