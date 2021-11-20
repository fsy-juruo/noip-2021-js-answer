#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c=getchar();
	int x=0;
	while(c>='0' && c<='9')
	{
		x=x*10+c-48;
		c=getchar();
	}
	return x;
}
int a[10000005];
bool f[10000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	n=read();
	int k=0;
	int last=0;
	memset(f,1,sizeof(f));
	for(int i=1;i<=10000001;i++)
	{
		if(f[i]==true)
		{
				int m=i;
			if(i%7==0)
			{
				f[i]=false;
			}
			else
			{
				while(m!=0)
				{
					if(m%10==7)
					{
						f[i]=false;
						break;
					}
					m/=10;
				}
				if(f[i]==false)
				{
					for(int j=i;j<=10000001;j+=i)
					{
						f[j]=false;
					}
				}
			}
			if(f[i]==true)
			{
				a[last]=i;
				last=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(f[x]==false)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",a[x]);
		}
	}
	return 0;
}

