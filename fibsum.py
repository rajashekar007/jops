def f(n):
	a,b,i,c=0,1,3,1
	while i<=n:a,b,i,c=b,c,i+1,b+c
	return c
for i in range(input()):a=input();print f(a+11)-f(a+1)+f((a+246)%60)%10