import Crypto.Util.number
t=input()
while t>0:
	t-=1
	n=input()
	if(Crypto.Util.number.isPrime(n)):
		print 'YES'
	else:
		print 'NO'