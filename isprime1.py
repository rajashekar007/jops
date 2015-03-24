from random import randint
def isPrime(n):
	k=2
	for i in range(k):
		a=randint(1,n)
		if (a**(n-1))%n!=1:
			return 0
	return 1
t=input()
while t>0:
	t-=1
	n=input()
	if(isPrime(n)):
		print 'YES'
	else:
		print 'NO'