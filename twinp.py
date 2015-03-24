#!/usr/bin/python

import math
MAX=10**5
MMAX=10**9
primes=[1]*MAX
p=[]
k=0
for i in range(2,MAX):
	if(primes[i]==1):
		k+=1
		print i
		p.append(i)
		j=i+i
		while j<MAX:
			primes[j]=0
			j+=i

i=MAX
while i<MMAX:
	si=int(math.sqrt(i))
	for j in p:
		if j<si :
			if i%j==0:
				break
		else:
			break
	if j>=si:
		print i
		p.append(i)
	i+=1

for i in p:
	print i
# last_prime=2
# twin_prime_index=0
# for i in range(3,MAX):
# 	if primes[i]==1:
# 		if i-last_prime==2:
# 			twin_prime_index+=1
# 			print twin_prime_index,last_prime,i
# 		last_prime=i

