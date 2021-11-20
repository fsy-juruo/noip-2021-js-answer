#include<bits/stdc++.h>
#define N 10000000
using namespace std;
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while (ch<48 || ch>57) {if (ch=='-') f=-1; ch=getchar();}
	while (ch>=48 && ch<=57) {s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
	return s*f;
}
int T,n,a[800010],cnt,l,r,mid;
bool f[N+10];
bool check(int x)
{
	for (;x;x/=10)
	if ((x%10)==7)
	return 1;
	return 0;
}
void init()
{
	for (int i=1;i<=N;++i)
	if (!f[i])
	{
		if (check(i))
		{
			for (int j=1;i*j<=N;++j)
			f[i*j]=1;
		}
		else a[++cnt]=i;
	}
	a[++cnt]=N+1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	T=read();
	while (T--)
	{
		n=read();
		if (f[n]) puts("-1");
		else
		{
			l=1,r=cnt+1;
			while (l<r)
			{
				mid=(l+r)>>1;
				if (n>a[mid]) l=mid+1;
				else r=mid;
			}
			printf("%d\n",a[l+1]);
		}
	}
	return 0;
}

