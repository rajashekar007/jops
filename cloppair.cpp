#include <bits/stdc++.h>
using namespace std;
// typedef pair<int,int> pii;
typedef long long ll;
struct pii
{
	int x,y,i;
};
bool funx(pii a,pii b)
{
	return a.x<b.x;
}
bool funy(pii a,pii b)
{
	return a.y<b.y;
}

float dist(pii a,pii b)
{
	int x=a.x-b.x,y=a.y-b.y;
	float r=sqrt((double)((ll)x*x)+((ll)y*y));cout<<r<<" ";
	return r;
}
float conq(vector<pii > a,float k,int *si,int *ei)
{
	float m=k,l;
	int i,j;
	sort(a.begin(),a.end(),funy);
	for(i=0;i<a.size()-1;i++)
	{
		for(j=i+1;j<a.size() && a[j].y-a[i].y<m;j++)
		{
			l=dist(a[i],a[j]);
			if(l<m)
			{	
				m=l;
				*si=a[i].i;
				*ei=a[j].i;
			}
		}
	}
	return m;
}
float div_conq(vector<pii > a,int s,int e,int* si,int *ei)
{
	if(e-s<3)
	{
		int i,j;
		float m=2000002,k;
		for(i=s;i<e;i++)
		{
			for(j=i+1;j<=e;j++)
			{
				k=dist(a[i],a[j]);
				if(k<m)
				{	
					m=k;
					*si=i;
					*ei=j;
				}
			}
		}
		return m;
	}
	else
	{
		int m=s+(e-s)/2,i,ti,tj,rti,rtj;
		float rd,d,dl,dr;
		dl=div_conq(a,s,m,si,ei);
		ti=*si;
		tj=*ei;cout<<"s,m,si,ei:"<<s<<","<<m<<","<<*si<<","<<*ei<<endl;
		dr=div_conq(a,m+1,e,si,ei);cout<<"m+1,e,si,ei:"<<m+1<<","<<e<<","<<*si<<","<<*ei<<endl;
		if(dl<dr)
		{
			*si=ti;
			*ei=tj;
			d=dl;
		}
		else
			d=dr;
		vector<pii > strip;
		int flag=1,st=s;
		for(i=s;i<=e;i++)
		{
			if(abs(a[i].x-a[m].x)<d)
			{
				if(flag)
				{
					st=i;
					flag=0;
				}
				pii tp;tp.x=a[i].x;tp.y=a[i].y;tp.i=i-st;
				strip.push_back(a[i]);
			}
		}
		rd= conq(strip,d,&rti,&rtj);
		if(rd<d)
		{
			*si=rti+st;
			*ei=rtj+st;
		}
		return rd;
	}
}

int main()
{
	vector<pii > points;
	int n,i,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		pii tp;
		tp.x=x;tp.y=y;tp.i=i;
		points.push_back(tp);
	}
	sort(points.begin(),points.end(),funx);
	float ans=div_conq(points,0,n-1,&x,&y);
	printf("\n%d %d %.6f\n", points[x].i,points[y].i,ans);
	return 0;
}