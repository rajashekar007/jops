#include <stdio.h>
#include <math.h>
#define LT 1390007
int p[LT],PS;
void g(){int S[LT],j,i,up=(int)sqrt((double)LT);for(i=1;i<LT;i++)S[i]=1;for(i=2;i<=up;i++)if(S[i])for(j=i+i;j<=LT;j+=i)S[j]=0;for(i=2;i<LT;i++)if(S[i]==1)p[PS++]=i;}main(){g();int i,c=0;for(i=0;p[i]<PS;i++){printf("%d ",p[p[i]-1]);c++;if(c==10000)break;}}