m=1000000007
def powm(e):
	return (e*(2**(e-1)%m))%m
def fun(n):
	if n==0:
		return 0
	elif n==1:
		return 1
	elif n==2:
		return 2
	elif n==3:
		return 4
	else:
		b=bin(n)
		b=b[2:]
		l=len(b)-1
		ib=int('1'*l,2)
		# print b,l,ib
		return (powm(l)+n-ib+fun(int(b[1:],2)))%m
t=input()
while t:
	t-=1
	n=input()
	print fun(n)