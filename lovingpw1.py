m=1000000007
def powm(e):
	return (e*(2**(e-1)%m))%m
n=input()
b=bin(n)
b=b[2:]
l=len(b)
ans=powm(l-1)
for i in xrange(1,l):
	if b[i]=='1':
		ans=(ans+powm(l-i-1))%m
print ans
print b