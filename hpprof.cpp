#include <bits/stdc++.h>
using namespace std;
char a[25];
int ans,n;
void permute(int i)
{
	if(i>=n)
		ans++;
	else
	{
		if(i+1<n && (a[i]-48)!=0 && (a[i]-48)*10+(a[i+1]-48)<=20)
			permute(i+2);
		permute(i+1);
	}
}
int main()
{
	scanf("%s",a);
	n=strlen(a);
	permute(0);
	printf("%d\n", ans);
	return 0;
}