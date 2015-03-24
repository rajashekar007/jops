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

long long max(long long x, long long y)
{
	return x>y?x:y;
}
long long goldcoins(long long *ar,long long cur,long long s)
{
	if(cur<s-1)
	{
		return max(ar[cur]+goldcoins(ar,cur+2,s),goldcoins(ar,cur+1,s));
	}
	else if(cur<s)
	{
		return ar[cur];
	}
	else
	{
		return 0;
	}
}
int main()
{
	int t,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		FastInput fi;
		long long n;
		scanf("%lld",&n);
		long long i,a[10007]={};
		for(i=0;i<n;i++)
		{
			a[i]=(long long)fi.ReadNext();
			// inp(a[i]);
		}
		// printf("Case %d: %lld\n",j,goldcoins(a,0,n));
		cout<<"Case "<<j<<": "<<goldcoins(a,0,n)<<endl;
	}
	return 0;
}