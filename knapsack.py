def knapsack(val,wt,v,w,i,n,c):
	if i==n:
		return v
	elif w+wt[i]<=c:
		return max(knapsack(val,wt,v+val[i],w+wt[i],i+1,n,c.append(i)),knapsack(val,wt,v,w,i+1,n,c))
	else:
		return knapsack(val,wt,v,w,i+1,n,c)

s,n=map(int,raw_input().split())
val=[0]*n
wt=[0]*n
for i in xrange(n):
	wt[i],val[i]=map(int,raw_input().split())

print knapsack(val,wt,0,0,0,n,s)