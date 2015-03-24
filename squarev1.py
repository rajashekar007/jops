n=raw_input()
r=[0]*4
for i in n:
	i=int(i)
	if i==2:
		r[0]+=1
	elif i==3:
		r[1]+=1
	elif i==4:
		r[0]+=2
	elif i==5:
		r[2]+=1
	elif i==6:
		r[0]+=1
		r[1]+=1
	elif i==7:
		r[3]+=1
	elif i==8:
		r[0]+=3
	elif i==9:
		r[1]+=2
# print r
ans=0
if r[1]%2==0 and r[3]%2==0:
	b=r[2]+1
	# if b%2==0:
	# 	ans=b/2
	# else:
	# 	c=-1
	# 	if r[0]%2==0:
	# 		c=1
	# 	ans=(b-c)/2
	# if r[0]%2==0 and r[2]%2==0:
	# 	ans+=1
	# if r[0]%2==1 and r[2]%2==0:
	# 	ans=((b-1)/2)+1
	# else:
	# 	ans=b/2
	# 	if r[0]%2==0 and r[2]%2==0:
	# 		ans+=1
	if b%2==0:
		ans=b/2
	else:
		c=-1
		if r[0]%2==0:
			c=1
		ans=(b-c)/2
	# if r[0]%2==0 and r[2]%2==0:
		if r[0]%2==0:
			ans+=1
print ans