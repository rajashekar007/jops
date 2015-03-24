#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
char al[256]={};
int i,j,k;
int ind(char c)
{
	for(i=0;i<256;i++)
		if(al[i]==c)
			return i;
}
bool fun(string a,string b)
{
	j=a.length();k=b.length();
	for(i=0;i<j && i<k;i++)
		if(ind(a[i])<ind(b[i]))
			return 1;
		else if(ind(a[i]>ind(b[i])))
			return 0;
	if(i==j)
		return 1;
	else
		return 0;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",al,&n);
		string a[100000];
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n,fun);
		for(i=0;i<n;i++)
			cout<<a[i]<<endl;
		cout<<endl;
	}
	return 0;
}