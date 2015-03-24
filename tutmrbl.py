#!/usr/bin/python

import math
while True:
	a=input()
	if a==0:
		break
	else:
		print a,' = ',
		b=a
		num_div=1
		for i in range(2,a):
			cnt=0
			if a%i==0 and b==a:
				print i,
				a=a/i
				cnt+=1
			while a%i==0:
				print ' * ',i,
				a=a/i
				cnt+=1
			cnt+=1
			num_div*=cnt
		if b==a:
			print a
		else:
			print ''
		print 'With ',b,' marbles, ',(num_div+1)/2,' different rectangles can be constructed.'
