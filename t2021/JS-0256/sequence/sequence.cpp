#include <bits/stdc++.h>
const int p=998244353;
int n,k,m,i,ans,v[20],t[20],a[20];
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
inline int ksm(int a,int n,int p)
{
	int ret(1);
	while (n)
	{
		if (n&1)
			ret=1ll*ret*a%p;
		a=1ll*a*a%p,n>>=1;
	}
	return ret;
}
inline void dfs(int x)
{
	if (x==n+1)
	{
		int ret=0;
		for (int i=0;i<19;i++)
			a[i]=t[i];
		for (int i=0;i<19;i++)
		{
			if (t[i]%2)
				ret++;
			t[i+1]+=t[i]/2;
		}
		for (int i=0;i<19;i++)
			t[i]=a[i];
		if (ret<=k)
		{
			int s=1;
			for (int i=0;i<=19;i++)
				s=1ll*s*ksm(v[i],t[i],p)%p;
			print(s),putchar('\n');
			(ans+=s)%=p;
		}
		return;
	}
	for (int i=0;i<=m;i++)
	{
		t[i]++;
		dfs(x+1);
		t[i]--;
	}
}
signed main(void)
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(k),read(m);
	if (n>8 || m>9)
		return 0;
	for (i=0;i<=m;i++)
		read(v[i]);
	dfs(1);
	print(ans);
	return 0;
}
