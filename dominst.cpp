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
	char st[15009][27]={};
	int i=0,j,k,dominant[15009]={},dominated[15009]={};
	int mp[15009][27]={};
	while(gets(st[i])!=NULL)
	{
		for(j=0;j<strlen(st[i]);j++)
		{
			mp[i][st[i][j]-97]++;
		}
		i++;
	}
	for(j=0;j<i;j++)
	{
		for(k=j+1;k<i;k++)
		{
			if(superset(mp[j],mp[k]))
			{
				dominant[j]=1;
				dominated[k]=1;
			}
			else if(superset(mp[k],mp[j]))
			{
				dominant[k]=1;
				dominated[j]=1;
			}
		}
		if (dominated[j]==0 && dominant[j]==0)
			dominant[j]=1;
	}
	vector<char*> ans;
	for(j=0;j<i;j++)
	{
		if(dominant[j]==1 && dominated[j]==0)
			ans.push_back(st[j]);
	}
	sort(ans.begin(),ans.end(),fun);
	for(j=0;j<ans.size();j++)
		printf("%s\n", ans[j]);
	return 0;
}
