#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second

using namespace std;
const int mod=998244353;
const int M=105;
const int N=35;
bool vis[M][N][N][52];
ll dp[M][N][N][52];
ll fac[M],inv[M];
ll pw[M][M];
ll ksm(ll x,ll y)
{
	if(!y)return 1;
	ll res=ksm(x,y/2);
	res=res*res%mod;
	if(y%2)res=res*x%mod;
	return res;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=100;i++)fac[i]=fac[i-1]*i%mod;
	inv[100]=ksm(fac[100],mod-2);
	for(int i=100-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	return;
}
inline ll C(int x,int y){return fac[x]*inv[x-y]%mod*inv[y]%mod;}

int n,m,k;
ll dfs(int now,int ch,int q,int l)
{
	if(q>k)return 0;
	if(now==m)
	{
		int nxt=n-ch+l;
		if(q+__builtin_popcount(nxt)<=k)
			return pw[m][n-ch];
		else
			return 0;
	}
	if(vis[now][ch][q][l])return dp[now][ch][q][l];
	ll res=0;vis[now][ch][q][l]=true;
	for(int i=0;i<=n-ch;i++)
	{
		int j=i+l;
		res=(res+dfs(now+1,ch+i,q+j%2,j/2)*pw[now][i]%mod*C(n-ch,i)%mod)%mod;
	}
	return dp[now][ch][q][l]=res;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	init();
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	{
		pw[i][0]=1;
		cin>>pw[i][1];
		for(int j=2;j<=n;j++)
		{
			pw[i][j]=pw[i][j-1]*pw[i][1]%mod;
		}
	}
	cout<<dfs(0,0,0,0)<<"\n";
	return 0;
}
