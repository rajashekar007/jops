#include <stdio.h>
#define SZ 100007
int discard_ind(int *a,int l,int r,int b)
{
	int m;
	while(r-l>1)
	{
		m=l+(r-l)/2;
		if(a[m]>=b)
			r=m;
		else
			l=m;
	}
	return r;
}
int lis(int *a,int s)
{
	int *t=new int[s];
	t[0]=a[0];
	int len=1,i;
	for(i=1;i<s;i++)
	{
		if(t[0]>a[i])
			t[0]=a[i];
		else if(t[len-1]<a[i])
			t[len++]=a[i];
		else
			t[discard_ind(t,0,len-1,a[i])]=a[i];
	}
	return len;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a1[SZ]={0},a2[SZ]={0},n,i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			a1[j]=i;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			a2[i]=a1[j];
		}
		printf("%d\n",lis(a2,n));
	}
	return 0;
}