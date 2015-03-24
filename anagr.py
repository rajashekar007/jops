# alphabets='abcdefghijklmnopqrstuvwxyz'
t=input()
while t:
	t-=1
	s1=raw_input();s1=s1.lower()
	s2=raw_input();s2=s2.lower()
	a1=[0]*26;a2=[0]*26
	l1=0;l2=0
	for i in s1:
		j=ord(i)
		if j>=97 and j<=122:
			a1[j-97]+=1
			l1+=1
	for i in s2:
		j=ord(i)
		if j>=97 and j<=122:
			a2[j-97]+=1
			l2+=1
	if l1<l2:
		temp=a1
		a1=a2
		a2=temp
	flag=1
	od=0
	st=''
	for i in range(26):
		if a1[i]<a2[i]:
			flag=2
			break;
		elif a1[i]>a2[i]:
			flag=0
			l=len(st)
			dif=a1[i]-a2[i]
			at=chr(i+97)*(dif)
			if l%2==1 and dif%2==1:
				flag=2
				break
			elif l%2==1:
				st=st[:l/2]+at[:dif/2]+st[l/2]+at[dif/2:]+st[l/2+1:]
			else:
				st=st[:l/2]+at+st[l/2:]
	if flag==1:
		print 'YES'
	elif flag==2:
		print 'NO LUCK'
	else:
		print st