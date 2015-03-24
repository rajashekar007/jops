n=input()
# b=raw_input()
ar=map(int,raw_input().split())
k=input()
lr=[0]*n
rl=[0]*n
for i in xrange(n):
	if i%k==0:
		lr[i]=ar[i]
	else:
		lr[i]=max(lr[i-1],ar[i])
i=n-1
while i>=0:
	if i==n-1 or i%k==k-1:
		rl[i]=ar[i]
	else :
		rl[i]=max(ar[i],rl[i+1])
	i-=1

for i in xrange(n-k+1):
	print max(rl[i],lr[i+k-1]),