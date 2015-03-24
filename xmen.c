#include <stdio.h>
int lcs( int *X, int *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
		if (i == 0 || j == 0)
		L[i][j] = 0;
		else if (X[i-1] == Y[j-1])
		L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = (L[i-1][j]>L[i][j-1])?L[i-1][j]:L[i][j-1];
     }
   }
   return L[m][n];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		int x[100007],y[100007];
		for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&y[i]);
		}
		printf("%d\n", lcs(x,y,n,n));
	}
	return 0;
}