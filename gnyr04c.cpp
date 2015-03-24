// #include <bits/stdc++.h>
// using namespace std;
// int n,m,cnt;
// // void func(int a,int i)
// // {
// // 	if(i==n)
// // 		cnt++;
// // 	else
// // 	{
// // 		a=2*a;
// // 		while(a<=m)
// // 		{
// // 			func(a,i+1);
// // 			a++;
// // 		}
// // 	}
// // }
// int func(int a,int i)
// {
// 	if(i==n)
// 		return 1;
// 	else
// 	{
// 		int r=0;
// 		a=2*a;
// 		while(a<=m)
// 		{
// 			r+=func(a,i+1);
// 			a++;
// 		}
// 		return r;
// 	}
// }
// int main()
// {
// 	int t;
// 	// scanf("%d",&t);
// 	// while(t--)
// 	for(n=1;n<=10;n++)
// 	{cnt=0;
// 		for(m=2<<(n-2);cnt<30;m++,cnt++)
	
// 	{
// 		// scanf("%d%d",&n,&m);
		
// 		// func(1,1);
// 		// printf("%d ", cnt);
// 		printf("%d ", func(1,1));
// 	}
// 	printf("\n");
// }
// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
void func(int a,int i)
{
	if(i==n)
		cnt++;
	else
	{
		a=2*a;
		while(a<=m)
		{
			func(a,i+1);
			a++;
		}
	}
}
int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++)
	{
		scanf("%d%d",&n,&m);
		cnt=0;
		func(1,1);
		printf("Data set %d: %d %d %d\n",ti,n,m, cnt);
	}
	return 0;
}