#include <stdio.h>
#include <string.h>
inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;
 
    while (c < 33)
        c = getchar_unlocked();
 
    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
    str[i] = '\0';
}

int main()
{
	int t;
	scanf("%d",&t);
	// char c;
	// gets(&c);
	while(t--)
	{
		char a[1000005]={},b[1000005]={};
		scanf("%s",a);
		// gets(a);
		// fastRead_string(a);
		int i=0,j,n=strlen(a),swap=0;
		strcpy(b,a);
		j=n-1;
		while(i<=j)
		{
			a[j]=a[i];
			i++;
			j--;
		}
		i--;
		j++;//printf("i=%d , j=%d\n", i,j);
		if(n%2==0)
			i=n/2;
		else
			i=n/2+1;
		int g=0;
		while(!g && i<n)
		{
			if(a[i]>b[i])
				g=1;
			else if(a[i]==b[i])
				i++;
			else
				break;
		}
		j=n/2;
		i=n%2==0?n/2-1:n/2;
		int f=1;
		while(!g)
		{
			if(a[i]-48<9)
			{
				a[i]+=1;
				if(i!=j)
					a[j]+=1;//printf("a=%s b=%s\n", a,b);
				g=1;
			}
			else if(i>0)
			{
				a[i]='0';
				a[j]='0';
				i--;
				j++;
				if(i==0)
				{
					a[i]='1';
					a[n-1]='0';
					a[n]='1';
					break;
				}
			}
		}
		// if(f)
		printf("%s\n", a);
			// puts(a);
	}
	return 0;
}
