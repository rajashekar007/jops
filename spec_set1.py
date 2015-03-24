t=input()
while t:
	t-=1
	s=raw_input().split()
	n=int(s[0])
	k=int(s[1])
	if k==1:
		print 0
	elif k==n:
		print n-1
	elif k>n:
		print n
	else:
		ans=0
		a=k
		p=1
		while a<=n:
			cnt=n/a
			if p%2==0:
				ans=ans-cnt
			else:
				ans=ans+cnt
			a=a*k
			p+=1
		# while a<=n:
		# 	a=a*k*k
		# 	cnt+=1
		print n-ans