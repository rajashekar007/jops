import math
def eql(x1,x2):
	l1=len(x1)
	l2=len(x2)
	if l1!=l2:
		return False
	d=abs(int(int(x1[0])-int(x2[0])))
	for i in xrange(1,l1):
		if abs(int(int(x1[i])-int(x2[i])))!=d:
			return False
	return True
t=input()
for j in xrange(1,t+1):
	t-=1
	n=input()
	s=[]
	for i in xrange(n):
		s.append(raw_input())
	ans=[]
	for x in s:
		flag=1
		for y in ans:
			if eql(x,y):
				flag=0
				break
		if flag==1:
			ans.append(x)
	print 'Case %d: %d' %(j,len(ans))
