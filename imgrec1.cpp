#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		while(n--)
		{
			int h,w,i,j;
			char a[50][50]={};
			cin>>h>>w;
			for(i=0;i<h;i++)
			{
				for(j=0;j<w;j++)
				{
					cin>>a[i][j];
				}
			}
			int flg=0;
			for(i=1;i<h-1;i++)
			{
				for(j=1;j<w-1;j++)
				{
					if(a[i][j]=='x')
					{
						int cnt=0,cnt1=0;
						if(a[i-1][j-1]=='x')cnt++;
						if(a[i-1][j]=='x')cnt1++;
						if(a[i-1][j+1]=='x')cnt++;
						if(a[i][j-1]=='x')cnt1++;
						if(a[i][j+1]=='x')cnt1++;
						if(a[i+1][j-1]=='x')cnt++;
						if(a[i+1][j]=='x')cnt1++;
						if(a[i+1][j+1]=='x')cnt++;
						// cout<<"cnt = "<<cnt;
						if(cnt==4 || cnt1==4)
						{
							flg=1;
							break;
						}
					}
					// else
					// 	cout<<a[i][j];
				}
				if(flg==1)
					break;
			}
			if(flg==1)
				cout<<"x";
			else
				cout<<"0";
		}
		cout<<endl;
	}
}