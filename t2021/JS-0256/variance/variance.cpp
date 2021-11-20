#include <bits/stdc++.h>
const int MAXN=405;
int n,i,x,ret,s,sq,a[MAXN];
inline void read(int &x)
{
	short negative=1;
	x=0;
	char c=getchar();
	while (c<'0' || c>'9')
	{
		if (c=='-')
			negative=-1;
		c=getchar();
	}
	while (c>='0' && c<='9')
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=negative;
} 
inline void print(int x)
{
	if (x<0)
		putchar('-'),x=-x;
	if (x>9)
		print(x/10);
	putchar(x%10+'0');
}
signed main(void)
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	if (n>400)
		return 0;
	for (i=1;i<=n;i++)
		read(a[i]);
	for (i=1;i<=n;i++)
		s+=a[i],sq+=a[i]*a[i];
	while (true)
	{
		ret=0;
		for (i=2;i<n;i++)
		{
			x=a[i-1]+a[i+1]-a[i];
			if (n*(sq-a[i]*a[i]+x*x)-(s-a[i]+x)*(s-a[i]+x)<n*sq-s*s)
			{
				sq=sq-a[i]*a[i]+x*x;
				s=s-a[i]+x;
				a[i]=x,ret++;
			}
		}
		if (!ret)
			break;
	}
	print(n*sq-s*s);
	return 0;
}
