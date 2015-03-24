a=0
def w(x,y,m):
	global a
	if x==m and y==m:
		a+=1
	elif x<=m and y<=m:
		w(x+1,y,m)
		w(x,y+1,m)
for i in range(1,21):a=0;w(0,0,i);print a