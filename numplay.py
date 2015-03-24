def cnt(n,i,l):
	if i==n:
		return 1
	else:
		if l==1:
			return cnt(n,i+1,3)
		elif l==3:
			return cnt(n,i+1,1)+cnt(n,i+1,5)
		elif l==5:
			return cnt(n,i+1,7)
		elif l==7:
			return cnt(n,i+1,5)+cnt(n,i+1,3)
t=input()
while t:
	t-=1
	a=input()
	print cnt(a,1,1)+cnt(a,1,3)+cnt(a,1,5)+cnt(a,1,7)