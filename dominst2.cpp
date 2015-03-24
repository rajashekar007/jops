#include <bits/stdc++.h>
using namespace std;
bool fun(char *a,char *b)
{
	return strcmp(a,b)<0?1:0;
}
int superset(int *a,int *b)//a is superset of b
{
	int i;
	for(i=0;i<27;i++)
	{
		if(b[i]>a[i])
			return 0;
	}
	return 1;
}
int main()
{
	char st[27]={};
	int i=0,j,k;
	map< map<char,int> ,char*> mp;
	while(gets(st)!=NULL)
	{
		int tp[27]={};
		for(j=0;j<strlen(st);j++)
		{
			tp[st[j]-97]++;
		}
		int flag=1;
		for(j=0;j<ans.size();j++)
		{
			if(superset(mp[ind[j]],mp[i]))
			{
				flag=0;
				break;
			}	
			else if(superset(mp[i],mp[ind[j]]))
			{
				ans[j]=st;
				ind[j]=i;
				flag=0;
				break;
			}
		}
		if(flag)
		{
			ans.push_back(st);
			ind[ans.size()-1]=i;
		}
		i++;
	}
	sort(ans.begin(),ans.end(),fun);
	for(j=0;j<ans.size();j++)
		printf("%s\n", ans[j]);
	return 0;
}
