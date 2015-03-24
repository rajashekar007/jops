a=0
b=1
c=a+b
i=1
while i<=50:
	i+=1
	a=b
	b=c
	c=a+b
	print i,',',c%10
