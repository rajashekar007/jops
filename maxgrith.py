t=input()
while t:
	t-=1
	n=input()
	r=n%3;
	ans=(2*(n/3)+r)%(10**9+7)
	print ans