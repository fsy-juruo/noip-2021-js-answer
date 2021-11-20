#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,k;
int v[110],p[110][32];
int C[32][32];
unordered_map<int,int>dp[32][32],ndp[32][32];
unordered_map<int,int>::iterator it;
inline int ksm(int x,int kk){
	if(kk==0)return 1;
	int res=ksm(x,kk>>1);
	res=1ll*res*res%mod;
	if(kk&1)res=1ll*res*x%mod;
	return res; 
}
inline void upd(int&x,int y){x=(x+y)%mod;}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)cin>>v[i];
	for(int i=0;i<=m;i++)for(int j=0;j<=n;j++)p[i][j]=ksm(v[i],j);
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for(int i=0;i<=n;i++)dp[i][i&1][i>>1]=p[0][i];
	for(int val=0;val<m;val++){
		for(int i=0;i<=n;i++)for(int j=0;j<=k;j++){
			for(it=dp[i][j].begin();it!=dp[i][j].end();it++){
				int s=it->first;
				for(int x=1;x+i<=n;x++)if(j+((s+x)&1)<=k){
					upd(ndp[i+x][j+((s+x)&1)][(s+x)>>1],
					1ll*it->second*p[val+1][x]%mod*C[i+x][x]%mod);
				}
				upd(ndp[i][j+(s&1)][s>>1],it->second);
			}
		}
		swap(dp,ndp);
		for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)ndp[i][j].clear();
	}
	int ans=0;
	for(int i=0;i<=k;i++)for(it=dp[n][i].begin();it!=dp[n][i].end();it++){
		if(__builtin_popcount(it->first)+i<=k)upd(ans,it->second);
	}
	cout<<ans<<endl;
	return 0;
}
