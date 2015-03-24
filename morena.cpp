#include <stdio.h>
#include <algorithm>
int m;
void ap(int *a,int l,int c,int p,int len,int inc)
{
	if(l==c)
	{
		if(inc==1 && a[p]<a[c])
			len++;
		else if(inc==0 && a[p]>a[c])
			len++;
		else if(inc==-1)
			len=1;
		m=len>m?len:m;
	}
	else if(c<l)
	{
		int j;
		for(j=c;j<l;j++)
		{	
			if(inc==1 && a[p]<a[j])
				ap(a,l,j+1,j,len+1,0);
			else if(inc==0 && a[p]>a[j])
				ap(a,l,j+1,j,len+1,1);
			else if(inc==1)
				ap(a,l,j+1,p,len,1);
			else if(inc==0)
				ap(a,l,j+1,p,len,0);
			else if(inc==-1)
				ap(a,l,j+2,j+1,len+2,a[j+1]<a[c]?1:0);
		}
	}
	
}
int main()
{
	int a[100]={},n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	m=0;
	ap(a,n-1,0,0,0,-1);
	printf("%d\n", m);
	return 0;
}