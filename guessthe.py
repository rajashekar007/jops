
def gcd(a,b):
	while 1:
		if a==0:
			return b
		b%=a
		if b==0:
			return a
		a%=b
def lcm(a,b):
	t=gcd(a,b)
	return a*b/t if t else a*b

s=raw_input()
while s!='*':
	ans=1;
	i=len(s)-1;
	while i>=0:
		if s[i]=='Y':
			ans=lcm(ans,(i+1))
		i-=1
	for i in range(len(s)):
		if s[i]=='N' and ans%(i+1)==0:
			ans=-1
			break;
	print ans
	s=raw_input()