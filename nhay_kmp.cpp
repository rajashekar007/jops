#include <bits/stdc++.h>
using namespace std;
//http://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
void consttable(char *p,int *t,int n)
{
	int pos=2,cnd=0;
	t[0]=-1;
	t[1]=0;
	while(pos<n)
	{
		if(p[pos-1]==p[cnd])
		{
			cnd++;
			t[pos]=cnd;
			pos++;
		}
		else if(cnd>0)
			cnd=t[cnd];
		else
		{
			t[pos]=0;
			pos++;
		}
	}
}
void findpat(char *s,char *p,int sn,int pn)
{
	int table[pn];
	consttable(p,table,pn);
	int m=0,i=0;
	while(m+i<sn)
	{
		if(p[i]==s[m+i])
		{
			if(i==pn-1)
			{
				printf("%d\n", m);
				if(table[i]>-1)
				{
					m=m+i-table[i];
					i=table[i];
				}
				else
				{
					i=0;
					m=m+1;
				}
			}
			else
			{
				i++;
			}
		}
		else
		{
			if(table[i]>-1)
			{
				m=m+i-table[i];
				i=table[i];
			}
			else
			{
				i=0;
				m=m+1;
			}
		}
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		char needle[n+3];
		scanf("%s",needle);
		char haystack[1000009]={};
		scanf("%s",haystack);
		findpat(haystack,needle,strlen(haystack),strlen(needle));
		printf("\n");
	}
	return 0;
}