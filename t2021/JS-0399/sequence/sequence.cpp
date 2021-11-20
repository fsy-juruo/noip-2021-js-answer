#include<bits/stdc++.h>
#define ALL(v) v.begin(),v.end()
#define srt(v) sort(ALL(v))
#define rALL(v) v.rbegin(),v.rend()
#define rsrt(v) sort(rALL(v))
#define rev(v) reverse(ALL(v))
#define sz(v) (int)(v.size())
#define inf 0x3f3f3f3f
#define eps 1e-9
#define pii pair<int,int>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
ll dp[33][110][110][33];
ll v[110];
ll C[33][33];
const ll mod=998244353;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=0;i<33;i++)
		C[i][i]=C[i][0]=1;
	for(int i=2;i<33;i++)
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<=M;i++)
		scanf("%lld",v+i);
	dp[0][0][0][0]=1;
	for(int j=0;j<=M;j++)
		for(int i=0;i<=N;i++)
			for(int k=0;k<=j;k++)
				for(register int l=0;k+l+l<=i;l++)
				{
					ll tmp=1;
					for(register int x=0;x<=N-i;x++)
					{
						dp[i+x][j+1][k+(l+x)%2][(l+x)/2]+=dp[i][j][k][l]*tmp%mod*C[N-i][x]%mod;
						dp[i+x][j+1][k+(l+x)%2][(l+x)/2]%=mod;
						tmp=tmp*v[j]%mod;
					}
				}
	ll ans=0;
	for(int x=0;x<=K;x++)
		for(int y=0;y<=N;y++)
			if(x+__builtin_popcount(y)<=K)
				ans=(ans+dp[N][M+1][x][y])%mod;
	cout<<ans<<endl;
	return 0;
}
