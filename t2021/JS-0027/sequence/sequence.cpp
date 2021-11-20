#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define F first
#define S second
#define mod 998244353
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
ll dp[113][37][37][17],v[113],c[37][37],ans=0;
const int bp[16]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
int n,m,k;
int main(){
	
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	int t1,t2,nmsk;
	ll mi;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i) scanf("%lld",v+i);
	c[0][0]=1;
	for(int i=1;i<=n;++i){
		c[i][0]=c[i-1][0];
		for(int j=1;j<=i;++j) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	dp[0][0][0][0]=1;
	for(int i=0;i<=m;++i){
		for(int j=0;j<=k;++j){
			for(int l=0;l<=n;++l){
				for(int msk=0;msk<16;++msk){
					if(!dp[i][j][l][msk]) continue;
					//printf("#(%d,%d,%d,%d):%lld\n",i,j,l,msk,dp[i][j][l][msk]);
					t1=bp[msk];
					mi=1;
					for(int a=0;l+a<=n;++a,mi=mi*v[i]%mod){
						nmsk=a+msk;
						t2=(nmsk&1);
						nmsk>>=1;
						t2+=bp[nmsk];
						//printf("%d:%d %d %lld %lld\n",a,t2,nmsk,c[n-l][n-l-a],mi);
						if(j-t1+t2>k) continue;
						dp[i+1][j-t1+t2][l+a][nmsk]=(dp[i+1][j-t1+t2][l+a][nmsk]+dp[i][j][l][msk]*c[n-l][n-l-a]%mod*mi)%mod;
						//printf("#(%d,%d,%d,%d):%lld\n",i+1,j-t1+t2,l+a,nmsk,dp[i+1][j-t1+t2][l+a][nmsk]);
					}
				}
			}
		}
	}
	for(int j=1;j<=k;++j) for(int msk=0;msk<16;++msk) ans=(ans+dp[m+1][j][n][msk])%mod;
	printf("%lld\n",ans);
	return 0;
}
