t=input()
while t:
	t-=1
	s=raw_input().split()
	n=int(s[0])
	k=int(s[1])
	if k==1 or k==n:
		print n-1
	elif k>n:
		print n
	else:
		ans,a,b,p,i=k-1,k*k,k,k-2,2
		while n>=a:
			p=a-b-1-p
			# print p
			ans+=p
			if i%2==0:
				ans+=1
			b=a
			a=a*k
			i+=1
		for j in range(b+1,n+1):
			c=0
			while(j%k==0):
				j=j/k
				c+=1
			if c%2==0:
				ans+=1
		print ans