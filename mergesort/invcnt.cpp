#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <stdint.h>
#include <unistd.h>
using namespace std;
typedef long long ll;
ll merge(int *a,int l,int m,int h,int temp[])
{
	ll cnt=0;
	int i=l,j=m+1,k=0;
	for(i=l;i<=m;i++)
	{
		for(j=m+1;j<=h;j++)
		{
			if(a[i]>a[j])
				cnt++;
			else
				break;
		}
	}
	i=l;j=m+1;
	for(k=l;i<=m && j<=h;)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=m)
		{temp[k]=a[i];k++;i++;}
	while(j<=h)
		{temp[k]=a[j];k++;j++;}
	for(k=l;k<=h;k++)
		a[k]=temp[k];
	return cnt;
}
ll mergesort(int a[],int l,int h,int temp[])
{
	if(l==h)
		return 0;
	int m=(l+h)/2;
	ll lc,hc,mc;
	lc=mergesort(a,l,m,temp);
	hc=mergesort(a,m+1,h,temp);
	mc=merge(a,l,m,h,temp);
	return lc+hc+mc;
}
class FastInput {
public:
    FastInput() {
        m_dataOffset = 0;
        m_dataSize = 0;
        m_v = 0x80000000;
    }
    uint32_t ReadNext() {
        if (m_dataOffset == m_dataSize) {
            int r = read(0, m_buffer, sizeof(m_buffer));
            if (r <= 0) return m_v;
            m_dataOffset = 0;
            m_dataSize = 0;
            int i = 0;
            if (m_buffer[0] < '0') {
                if (m_v != 0x80000000) {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                }
                for (; (i < r) && (m_buffer[i] < '0'); ++i);
            }
            for (; i < r;) {
                if (m_buffer[i] >= '0') {
                    m_v = m_v * 10 + m_buffer[i] - 48;
                    ++i;
                } else {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                    for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                }
            }
        }
        return m_data[m_dataOffset++];
    }
public:
    uint8_t m_buffer[32768];
    uint32_t m_data[16384];
    size_t m_dataOffset, m_dataSize;
    uint32_t m_v;
};
int main()
{
	FastInput fi;
	int t;
	scanf("%d",&t);
	// t=fi.ReadNext();
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[200007],i,temp[200007];
		for(i=0;i<n;i++)
			// a[i]=fi.ReadNext();
			scanf("%d",&a[i]);
		printf("%lld\n", mergesort(a,0,n-1,temp));

	}
	return 0;
}