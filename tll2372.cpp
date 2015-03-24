#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,val1,val2;
	scanf("%d",&n);
	priority_queue<int,vector<int>,greater<int> > h;
	for(i=0;i<n;i++)
		h.push(0);
	char s[100009]={};
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='1')
		{
			val1=h.top();h.pop();
			val1++;
			h.push(val1);
		}
		else
		{
			val1=h.top();h.pop();
			val2=h.top();h.pop();
			val2++;
			h.push(val1);
			h.push(val2);
		}
	}
	val1=h.top();h.pop();
	val2=h.top();h.pop();
	printf("%d %d\n", val1,val2);
	return 0;
	return 0;
}