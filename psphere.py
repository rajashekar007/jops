import math
import random
t=input()
while t:
	t-=1
	n=input()
	for i in range(n):
		phi=random.uniform(0,2*math.pi)
		ctheta=random.uniform(-1,1)
		theta=math.acos(ctheta)
		print '%.5f %.5f %.5f' %(math.sin(theta)*math.cos(phi),math.sin(theta)*math.sin(phi),math.cos(theta))
