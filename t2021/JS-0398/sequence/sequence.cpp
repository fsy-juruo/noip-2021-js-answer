#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n,m,k,v[110],c[40][40],pw[110][40],dp[110][40][40][40];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++) c[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=c[i-1][j];
			add(c[i][j],c[i-1][j-1]);
		}
	}
	for(int i=0;i<=m;i++) cin>>v[i];
	for(int i=0;i<=m;i++){
		pw[i][0]=1;
		for(int j=1;j<=n;j++) pw[i][j]=1ll*pw[i][j-1]*v[i]%MOD;
	}
	for(int i=0;i<=n;i++) dp[0][i][0][i]=1ll*pw[0][i]*c[n][i]%MOD;
	for(int i=1;i<=m+5;i++){
		for(int j=0;j<=n;j++){
			for(int l=0;l<=n;l++){
				for(int o=0;o<=n;o++){
					if(i>m){
						if(2*o<=n) add(dp[i][j][l][o],dp[i-1][j][l][2*o]);
						if(2*o+1<=n) add(dp[i][j][l][o],dp[i-1][j][l-1][2*o+1]);
					}
					else{
						for(int p=0;p<=min(o,j);p++){
							int val=1ll*pw[i][p]*c[n-j+p][p]%MOD;
							if(2*(o-p)<=n) add(dp[i][j][l][o],1ll*dp[i-1][j-p][l][2*(o-p)]*val%MOD);
							if(2*(o-p)+1<=n) add(dp[i][j][l][o],1ll*dp[i-1][j-p][l-1][2*(o-p)+1]*val%MOD);
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=k;i++) add(ans,dp[m+5][n][i][0]);
	cout<<ans<<'\n';
	return 0;
}
