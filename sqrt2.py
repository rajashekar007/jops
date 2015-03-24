a=1.0
b=1.0
n=1000
while n>0:
	n-=1
	t=a
	a=a+2*b
	b=t+b
print a/b