from collections import Counter
st=[]
while True:
	try:
		st.append(raw_input())
	except EOFError:
		break
st1=[]

# st1.sort()
st2=[]
# print st1
for i in st:
	st2.append(Counter(i))
# print st2
c=Counter()
dominant=set()
dominated=set()
dt=[0]*15009
dd=[0]*15009
ind=[]
for i in xrange(len(st2)-1):
	for j in xrange(i+1,len(st2)):
		if st2[j]-st2[i]==c:
			dominant.add(i)
			dominated.add(j)
			dt[i]=1
			dd[j]=1
			# print '%s d by %s' %(st2[j],st2[i])
		elif st2[i]-st2[j]==c:
			dominant.add(j)
			dominated.add(i)
			dt[j]=1
			dd[i]=1
			# print '%s d by %s' %(st2[i],st2[j])
	if dd[i]==0 and dt[i]==0:
		dominant.add(i)
		dt[i]=1
for i in dominant:
	if dd[i]!=1:
		ind.append(i)
ans=[]
for i in ind:
	ans.append(st[i])
ans.sort()
for s in ans:
	print s
