#include<bits/stdc++.h>
using namespace std;
const int N=11000005,mx=10000100;
int a[N],f[N];
inline int rd()
{
	char c=getchar();int x=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
inline int ok(int x)
{
	while(x)
	{
		if(x%10==7)
			return 1;
		x/=10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=mx;i++)
	{
		if(a[i])
			continue;
		if(ok(i))
		{
			a[i]=1;
			for(int j=i+i;j<=mx;j+=i)
				a[j]=1;
		}
	}
	for(int i=mx;i>=1;i--)
	{
		f[i]=f[i+1];
		if(!a[i])
			f[i]=i;
	}
	int t=rd();
	while(t--)
	{
		int x=rd();
		if(a[x])
			puts("-1");
		else
			printf("%d\n",f[x+1]);
	}
	return 0;
}

