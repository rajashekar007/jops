def ispalin(a):
	if a==a[::-1]:
		return True
	return False
ans=0
def subseq(a,i,n,b):
	global ans
	if i==n :
		print b
		if ispalin(b):
			ans+=1
			print 'palin'
	else:
		subseq(a,i+1,n,b+a[i])
		subseq(a,i+1,n,b)
s='abcba'
subseq(s,0,len(s),'')
print ans