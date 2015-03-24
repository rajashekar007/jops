m=1000000007
def mod(x):
	return (x%m + m)%m
t=input()
while t>0:
	t-=1
	s=raw_input()
	l=[-1]*256
	sd=[0]*(len(s)+1)
	sd[0]=1
	for i in range(1,len(s)+1):
		if l[ord(s[i-1])]>0:
			sd[i]=mod(2*sd[i-1]-sd[l[ord(s[i-1])]-1])
		else:
			sd[i]=mod(2*sd[i-1])
		l[ord(s[i-1])]=i
	print sd[len(s)]