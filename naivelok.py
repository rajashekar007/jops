m=1000000007
t=input()
while t:
	t-=1
	s=raw_input()
	n=len(s)
	total=(1<<n)
	if(n%2==0):
		ps=3*(1<<(n/2))-2
	else:
		ps=(1<<(((n+1)/2)+1))-2
	print (total-ps)%m