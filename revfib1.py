a=[0]*100001
a[0],a[1]="1","1"
b,c,d=1,1,2
def ndigits(n):
	ans=0
	while n!=0:
		n=n/10
		ans+=1
	return ans

# print ndigits(2567)
for i in xrange(2,100001):
	# k=ndigits(d)
	# if(k>40):
	# 	a[i]=d/(10**(k-40))
	# else:
	# 	a[i]=d
	# b=c
	# c=d
	# d=b+c
	# print d
	a[i]=(a[i-1])+a[i-2]
	# d=str(a[i])
	# print ndigits(a[i]),
# print ndigits(a[226])
print ndigits(a[100000])
# print a[226]/(10**(8))
# t=input()
# while t:
# 	t-=1
# 	n=input()
# 	ans=-1
# 	for i in xrange(100001):
# 		k=ndigits(n)
# 		l=ndigits(a[i])
# 		if l>=k and n==a[i]/10**(l-k):
# 			ans=i
# 			break
# 	print ans
