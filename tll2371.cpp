#include <bits/stdc++.h>
using namespace std;
struct  comp
{	
	bool operator()(const int& a,const int& b)const
	{
		return a>b;
	}
};
int main()
{
	int n,i,val1,val2;
	scanf("%d",&n);
	vector<int> v;
	for(i=0;i<n;i++)
		v.push_back(0);
	make_heap(v.begin(),v.end(),comp());
	char s[100009]={};
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='1')
		{
			pop_heap(v.begin(),v.end(),comp());
			val1=v.back();
			v.back()=val1+1;
			push_heap(v.begin(),v.end(),comp());
		}
		else
		{
			pop_heap(v.begin(),v.end(),comp());
			v.pop_back();
			val1=v.front();
			pop_heap(v.begin(),v.end(),comp());
			v.pop_back();
			val2=v.front();
			v.push_back(val1);
			push_heap(v.begin(),v.end(),comp());
			v.push_back(val2+1);
			push_heap(v.begin(),v.end(),comp());
		}
	}
	pop_heap(v.begin(),v.end(),comp());
	v.pop_back();
	val1=v.front();
	pop_heap(v.begin(),v.end(),comp());
	v.pop_back();
	val2=v.front();
	printf("%d %d\n", val1,val2);
	return 0;
}