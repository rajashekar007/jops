#include <stdio.h>
#include <algorithm>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		double a[n],s;
		for(i=0;i<n;i++)
			scanf("%lf",&a[i]);
		if(n<=2)
		{
			s=a[0]+a[1];
			if(s>1 && s<2)
				printf("found\n");
			else
				printf("not found\n");
		}
		else
		{
			double n1=3,n2=3,m1=-1,m2=-1,s1,s2;
			for(i=0;i<n;i++)
			{
				if(a[i]<n1)
				{
					n2=n1;
					n1=a[i];
				}
				else if(a[i]<n2)
					n2=a[i];
				if(a[i]>m1)
				{
					m2=m1;
					m1=a[i];
				}
				else if(a[i]>m2)
					m2=a[i];
			}
			s1=n1+n2;
			s2=m1+m2;
			// printf("%lf %lf %lf %lf\n", n1,n2,m2,m1);
			if(s1>2 || s2<1)
				printf("not found\n");
			else
				printf("found\n");
		}
	}
	return 0;
}