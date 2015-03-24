#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		// char needle[n+3];
		string needle;
		// scanf("%s",needle);
		cin>>needle;
		string haystack;
		// scanf("%s",haystack);
		cin>>haystack;
		int f=-1;
		do
		{
			f=haystack.find(needle,f+1);
			if(f!=string::npos)
				printf("%d\n", f);
		}while(f!=string::npos);
		printf("\n");
	} 
	return 0;
}