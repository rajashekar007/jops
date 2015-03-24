import math
t=input()
while t:
	t-=1
	a,b=raw_input().split()
	a,b=int(a),int(b)
	ans=0
	if a!=b:
		a1,b1=math.sqrt(a),math.sqrt(b)
		a1,b1=int(a1),int(b1)
		xor=(a1+1)**2-a;nd=xor
		for i in range(a1+1,b1):
			i=(i+1)**2-i**2
			xor=xor^i
			nd=nd&i
		ans=xor&nd
	print ans