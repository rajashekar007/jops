#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j=0,flag=0;
		scanf("%d",&n);
		float a,s,m1=2,m0=0,n0=2;
		for(i=0;i<n;i++)
		{
			scanf("%f",&a);
			if(!flag)
			{
				if(a>=1)
				{
					if(m1>a)
						m1=a;
					if(m1+n0<2)
						flag=1;
				}
				else if(a<=0.5)
				{
					if(m0<a)
						m0=a;
					if(n0>a)
						n0=a;
					if(m1+a<2)
						flag=1;
				}
				else
				{
					if(j==1 || a+m0>1)
						flag=1;
					else
					{
						j++;
						if(n0>a)
							n0=a;
					}
				}
				// if(m1+m0<2 || m1+n0<2 || (m0+n0>1))
				// 	flag=1;
			}
		}
		if(flag==1)
			printf("found\n");
		else
			printf("not found\n");
	}
	return 0;
}