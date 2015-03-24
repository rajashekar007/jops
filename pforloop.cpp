#include <bits/stdc++.h>
using namespace std;
int a[1000009]={};
int main()
{
	int n=0,i=0,s,e,j;
	while(scanf("%d",&a[i])!=EOF)
	{
		i++;
	}
	n=i;
	sort(a,a+n);
	for(i=0;i<n;)
	{
		e=a[i];
		s=a[i];
		for(j=i+1;j<n;j++)
		{
			if(a[j]-a[j-1]!=1)
			{
				e=a[j-1];
				break;
			}
		}
		if(j==n)
			e=a[j-1];
		printf("for (int i = %d; i <= %d; i++) cout << i << \" \";\n",s,e );
		i=j;
	}
	return 0;
}