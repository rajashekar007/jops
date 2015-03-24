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
		p.append(i)
		j=i+i
		while j<MAX:
			primes[j]=0
			j+=i

t=input()
while t>0:
	t-=1
	a=raw_input()
	L,U=a.split()
	L=int(L)
	U=int(U)
	ap=[]
	if U>MAX:
		i=L
		while i<U:
			si=int(math.sqrt(i))
			for j in p:
				if j<si :
					if i%j==0:
						break
				else:
					break
			if j>=si:
				ap.append(i)
			i+=1
	else:
		for i in range(L,U+1):
			if primes[i]==1:
				ap.append(i)

	for i in ap:
		print i