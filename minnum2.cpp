#include <stdio.h>
using namespace std;

int main()
{
	while(1)
	{	
		char a[35]={};
		scanf("%s",a);
		if(a[0]=='-')
			break;
		if(a[1]=='\0')
			printf("1\n");
		else
		{
			int i,p=a[0]-48,d,m,j=0,b[35]={},p1,flag=1;
			// printf("p=%d\n", p);
			for(i=1;a[i]!='\0';i++)
			{
				d=p*10+(a[i]-48);
				m=d/9;
				if(m>9)
				{
					b[j]=1;
					b[j+1]=m%10;
					j+=2;
				}
				else
				{
					b[j++]=m;
				}
				p=d%9;
				// if(a[i+1]=='\0' && p!=0)
				// 	m=m+1;
				// printf("%d", m);
			}
			if(p!=0)
			{
				for(i=j-1;i>=0;i--)
				{
					if(b[i]<9)
					{
						b[i]++;
						flag=0;
						break;
					}
					else
					{
						b[i]=0;
					}

				}
			}
			if(flag==1)
			printf("1");
			for(i=0;i<j;i++)
				printf("%d", b[i]);
			printf("\n");
		}
	}
	return 0;
}