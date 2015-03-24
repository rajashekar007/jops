import math

def point_in():
	a=raw_input()
	x,y=a.split()
	x,y=float(x),float(y)
	return x,y

def dis(x1,y1,x2,y2):
	return math.sqrt((x1-x2)**2+(y1-y2)**2)

def angle(a,b,c):
	return math.degrees(math.acos((a*a+b*b-c*c)/(2*a*b)))
def abs(a):
	if a>0:
		return a
	else:
		return -a
t=input()
for i in range(1,t+1):
	x1,y1=point_in()
	x2,y2=point_in()
	x3,y3=point_in()
	a=dis(x1,y1,x2,y2)
	b=dis(x1,y1,x3,y3)
	c=dis(x2,y2,x3,y3)

	st=''
	if abs(a-b)<=0.01 and abs(b-c)<=0.01 and abs(c-a)<=0.01:
		st='Equilateral Equiangular'
	else:
		g1=angle(a,b,c)
		g2=angle(a,c,b)
		g3=angle(b,c,a)
		if abs(a-b)<=0.01 or abs(b-c)<=0.01 or abs(c-a)<=0.01:
			st='Isosceles '
		else:
			st='Scalene '
		if abs(g1-90)<=0.01 or abs(g2-90)<=0.01 or abs(g3-90)<=0.01:
			st+='Right Triangle'
		elif g1>90 or g2>90 or g3>90:
			st+='Obtuse'
		else:
			st+='Acute'
	print 'Scenario #%d: %s' %(i,st)
