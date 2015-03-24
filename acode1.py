dp=[0]*5007
while 1:
	a=raw_input()
	if a=='0':
		break
	n=len(a)
	for i in range(n):
		dp[i]=0
	dp[n]=1
	i=n-1
	while i>=0:
		if i<n-1 and (a[i]=='1' or (a[i]=='2' and a[i+1]<='6')):
			dp[i]=dp[i+1]+dp[i+2]
		else:
			dp[i]=dp[i+1]
		i-=1
	print dp[0]