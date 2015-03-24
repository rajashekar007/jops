def ndecodings(a,i,n):
	if i>=n:
		return 1
	elif a[i]=='1' or (a[i]=='2' and a[i+1]<='6'):
		return ndecodings(a,i+1,n)+ndecodings(a,i+2,n)
	else:
		return ndecodings(a,i+1,n)

a=raw_input()
print ndecodings(a,0,len(a)-1)