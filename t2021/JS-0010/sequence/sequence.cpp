#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const double eps=1e-9;
typedef long long ll;
int power(int x,int y){
	int ret=1;
	do{
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
	}while(y>>=1);
	return ret;
}
int n,m,k,v[105],cnt[105],f[105][105];
int dp[105][32][32][32],fact[555],inv[555];
void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)cin>>v[i];
	for(int i=0;i<=m;i++){
		f[i][0]=1;
		for(int j=1;j<=100;j++)f[i][j]=1ll*f[i][j-1]*v[i]%mod;
	}
	fact[0]=1;for(int i=1;i<=500;i++)fact[i]=1ll*fact[i-1]*i%mod;
	for(int i=0;i<=500;i++)inv[i]=power(fact[i],mod-2);
	for(int i=0;i<105;i++)for(int j=0;j<10;j++)if(i&(1<<j))cnt[i]++;
	for(int i=0;i<=n;i++)dp[0][i][i/2][i&1]=1ll*inv[i]*f[0][i]%mod;
	for(int i=0;i<m;i++){
		for(int tk=0;tk<=n;tk++){
			for(int u=0;u<=n;u++){
				for(int cur=0;cur<=n;cur++)if(dp[i][tk][u][cur]){
//					cerr<<i<<" "<<tk<<" "<<u<<" "<<cur<<" "<<dp[i][tk][u][cur]<<endl;
					for(int nxt=0;tk+nxt<=n;nxt++){
						add(dp[i+1][tk+nxt][(u+nxt)/2][cur+(u+nxt)%2],1ll*dp[i][tk][u][cur]*inv[nxt]%mod*f[i+1][nxt]%mod);
					}
				}
			}
		}
	}
	int ans=0;
	for(int u=0;u<=n;u++)for(int cur=0;cur<=k;cur++)if(dp[m][n][u][cur]){
		int tmp=cur+cnt[u];if(tmp>k)continue;
		add(ans,dp[m][n][u][cur]);
	}
	ans=1ll*ans*fact[n]%mod;
	cout<<ans<<endl;
	return 0;
}
