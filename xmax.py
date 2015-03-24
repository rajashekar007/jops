def msb(k):
	r=64
	p=1<<r
	while (p&k)!=p:
		p=p>>1
		r-=1
	return r+1

print msb(input())
# t=input()
# a=[]
# while t:
# 	t-=1
# 	a.append(input())

# a.sort()
# b=[]
# i=0
# j=msb(a[i])
# b.append(a[0])
# while i<len(a):
# 	k=i+1
# 	while k<len(a) and msb(a[k])==msb(a[i]):
# 		a[k]=a[k]^a[i]
# 		k+=1
# 	k=i+1
# 	while k<len(a) and msb(a[k])==j-1:
# 		k+=1
# 	if k<len(a):
# 		a[i+1],a[k]=a[k],a[i+1]
# 		i+=1
# 	else:
# 		j