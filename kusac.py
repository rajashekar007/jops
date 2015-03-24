import math
def kusac(n,m):
	# print n,m
	if n==m or n==0 or m==1 or m==0:
		return 0
	elif n>m:
		return kusac(n%m,m)
	else:
		k=int(math.ceil(float(m)/n)-1)
		return (k*n +kusac(n,m-k*n))

a=map(int,raw_input().split())
print kusac(a[0],a[1])