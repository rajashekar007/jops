t=input()
n=[]
s=0
for i in range(t):
	a=input()
	n.append((a,i))
	s+=a

s1=s/2
s2=0
for (a,b) in sorted(n):
	s2+=a
	print b+1
	if(s2>=s1):
		break
