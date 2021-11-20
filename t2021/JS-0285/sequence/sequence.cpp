#include <bits/stdc++.h>
using namespace std;
int p=998244353;
int v[110],f[40][110][100000],mmax;
int g;
int lowbit(int x)
{
	return x&(-x);
}
bool mcheck(int x)
{
	int sum=0;
	while(x)
	{
		sum++;
		x-=lowbit(x);
	}
	return sum<=g;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m;
	cin>>n>>m>>g;
	for(int i=0;i<=m;i++)
	cin>>v[i];
	mmax=(1<<m)*n;
	for(int i=0;i<=m;i++)
	{
		int x=(1<<i);
		f[1][i][x]=v[i];	
	}
	for(int i=2;i<=n;i++)
	for(int j=0;j<=m;j++)
	{
		int x=(1<<j)+(i-1),xx=(1<<j);
		for(int sum=x;sum<=mmax;sum++)
		{
			for(int k=0;k<=m;k++)
			{
				int y=(1<<k);
				if(sum>=y+(i-2)+xx)	
				f[i][j][sum]=(f[i][j][sum]+1ll*f[i-1][k][sum-xx]*v[j]%p)%p;
				else break;
			}
		}
	}
	int ans=0;
	for(int j=0;j<=m;j++)
	{
		int x=(1<<j)+(n-1);
		for(int sum=x;sum<=mmax;sum++)
		if(mcheck(sum))
		ans=(ans+f[n][j][sum])%p;
	}
	cout<<ans<<endl;
	return 0;
}

