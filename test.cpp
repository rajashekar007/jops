#include <bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"Enter number of values of P:";
	int np;
	cin>>np;
	cout<<"Enter "<<np<<" P values:";
	int p[np],i;
	for(i=0;i<np;i++)
		cin>>p[i];
	cout<<"Enter number of values of r:";
	int nr;
	cin>>nr;
	cout<<"Enter "<<nr<<" r values:";
	double r[nr];
	for(i=0;i<nr;i++)
		cin>>r[i];
	cout<<"Enter number of values of n:";
	int nn;
	cin>>nn;
	cout<<"Enter "<<nn<<" n values:";
	int n[nn];
	for(i=0;i<nn;i++)
		cin>>n[i];
	int j,k;
	for(i=0;i<np;i++)
	{
		for(j=0;j<nr;j++)
		{
			for(k=0;k<nn;k++)
			{
				cout<<"For P="<<p[i]<<", r="<<r[j]<<", n="<<n[k]<<" ; V="<<p[i]*pow(r[j]+1,n[k])<<endl;
			}
		}
	}
	return 0;
}