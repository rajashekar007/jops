#include <bits/stdc++.h>
using namespace std;
// typedef pair<int,int> pii;
typedef long long ll;
struct pii
{
	int x,y,i;
};
struct sdp
{
	int a,b;
	float d;
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
	float r=sqrt((double)((ll)x*x)+((ll)y*y));
	return r;
}
sdp conq(vector<pii > a,float k)
{
	float l;
	sdp r;r.d=k;
	int i,j;
	sort(a.begin(),a.end(),funy);
	for(i=0;i<a.size()-1;i++)
	{
		for(j=i+1;j<a.size() && a[j].y-a[i].y<r.d;j++)
		{
			l=dist(a[i],a[j]);
			if(l<r.d)
			{
				r.d=l;
				r.a=a[i].i;
				r.b=a[j].i;
			}
		}
	}
	return r;
}
sdp div_conq(vector<pii > a,int s,int e)
{
	if(e-s<3)
	{
		int i,j;
		float k;
		sdp ra;ra.d=FLT_MAX;
		for(i=s;i<e;i++)
		{
			for(j=i+1;j<=e;j++)
			{
				k=dist(a[i],a[j]);
				if(k<ra.d)
				{	
					ra.d=k;
					ra.a=a[i].i;
					ra.b=a[j].i;
				}
			}
		}
		return ra;
	}
	else
	{
		int m=s+(e-s)/2,i,ti,tj,rti,rtj;
		float d;
		sdp dl,dr,rd,rs;
		dl=div_conq(a,s,m);
		dr=div_conq(a,m+1,e);
		if(dl.d<dr.d)
		{
			d=dl.d;
			rs.d=dl.d;
			rs.a=dl.a;
			rs.b=dl.b;
		}
		else
		{
			d=dr.d;
			rs.d=dr.d;
			rs.a=dr.a;
			rs.b=dr.b;
		}
		vector<pii > strip;
		for(i=s;i<=e;i++)
		{
			if(abs(a[i].x-a[m].x)<d)
			{
				pii tp;tp.x=a[i].x;tp.y=a[i].y;tp.i=a[i].i;
				strip.push_back(a[i]);
			}
		}
		rd= conq(strip,d);
		if(rd.d<d)
		{
			return rd;
		}
		else
			return rs;
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
	sdp ans;
	ans=div_conq(points,0,n-1);
	if(ans.a>ans.b)
		swap(ans.a,ans.b);
	printf("%d %d %.6f\n", ans.a,ans.b,ans.d);
	return 0;
}