#include<bits/stdc++.h>
using namespace std;

#define int long long
#define _P 998244353

int n,m,k;
int v[110];
int ans;

int p[110];

int ksm(int a,int q)
{
	int res=1;
	int base=a;
	while(q)
	{
		if(q&1)
		{
			res*=base;
			res%=_P;
		}
		base*=base;
		base%=_P;
		q>>=1;
	}
	return res;
}

void solve(int x,int c)
{
	if(x==m)
	{
		p[m]=n-c;
		c=n;
	}
	if(c==n)
	{
		int f=0;
		int t[110]={};
		for(int i=0;i<=109;i++)
		{
			t[i]+=p[i];
			t[i+1]+=t[i]/2;
			t[i]%=2;
			f+=t[i];
		}
		if(f>k) return;
		int res=1;
		for(int i=0;i<=m;i++)
		{
			res*=ksm(v[i],p[i]);
			res%=_P;
		}
		ans+=res;
		return;
	}
	for(int i=x;i<=m;i++)
	{
		for(int j=0;j<=n-c;j++)
		{
			p[i]=j;
			solve(i+1,c+j);
			p[i]=0;
		}
	}
}

signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	{
		cin>>v[i];
	}
	solve(0,0);
	cout<<ans<<endl;
	
	return 0;
}
