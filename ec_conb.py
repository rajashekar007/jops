def rbinary(a):
	r=[]
	while a!=0:
		r.append(a%2)
		a=a/2
	j=len(r)-1
	ans=0
	for i in range(len(r)):
		ans+=(2**j)*r[i]
		j-=1
	return ans
n=input()
for i in range(n):
	a=input()
	if(a%2==1):
		print a
	else:
		print rbinary(a)