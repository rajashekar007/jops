from random import randint
n=input()
a=[]
for i in range(1,n*n+1):
	a.append(i)
for i in range(n):
	for j in range(n):
		k=randint(0,len(a)-1)
		print a[k],
		del a[k]
	print ''

