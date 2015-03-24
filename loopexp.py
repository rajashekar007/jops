
a=[0.0]*100001
a[1]=1.0
a[2]=2.0
for i in range(3,100001):
	a[i]=a[i-1]+(1/float(i-1))

s=[0.0]*100001
s[1]=1.0
for i in range(2,100001):
	s[i]=s[i-1]+a[i]


# for i in range(6):
# 	print a[i]
# print ''
# for i in range(6):
# 	print s[i]
t=input()
while t:
	t-=1
	n=input()
	print '%.6f' %(s[n]/n)