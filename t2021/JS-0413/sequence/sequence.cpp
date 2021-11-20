#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(v) (int)(v).size()
#define all(v) (int)(v).begin(),(v).end()
typedef long long ll;
typedef pair<int,int> pi;
template <class T> void chmax(T &x,T y) {x=x>y?x:y;}
template <class T> void chmin(T &x,T y) {x=x<y?x:y;}
const int inf=1000000000;
const ll mod=998244353;

const int maxn=35;
const int maxm=105;
const int maxs=35;
int n,m,K;
ll v[maxm];
ll C[maxn][maxn];
ll pw[maxm][maxn];
ll f[maxm][maxn][maxn][maxs];
bool vis[maxm][maxn][maxn][maxs];

int cnt(int msk) {
	int ret=0;
	while(msk) {
		if(msk&1) ret++;
		msk>>=1;
	}
	return ret;
}

ll dfs(int i,int j,int k,int l) {
	if(i==0) {
		if(j!=l) return 0ll;
		if(k!=0) return 0ll;		
		return pw[0][j];
	}
	if(vis[i][j][k][l]) return f[i][j][k][l];
	ll &ret=f[i][j][k][l];
	vis[i][j][k][l]=1;
	ret=0;
	for(int p=0;p<=j;p++) {		
		for(int q=0;q<2;q++) {			
			int nxti=i-1;
			int nxtj=j-p;
			int nxtk=k;
			if(q==1) nxtk--;
			if((l-p)&(1<<4)) continue;
			if(nxtk<0) continue;
			int nxtl=(l-p)<<1|q;
			ll trans=dfs(nxti,nxtj,nxtk,nxtl)*pw[i][p]%mod;			
			trans*=C[j][p];
			ret+=trans;
			ret%=mod;			
		}
	}
	return ret;
}

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>K;
	for(int i=0;i<maxn;i++) {
		C[i][0]=C[i][i]=1ll;
		for(int j=1;j<i;j++) {
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	for(int i=0;i<=m;i++) {
		cin>>v[i];
	}
	for(int i=0;i<=m;i++) {
		pw[i][0]=1ll;
		for(int j=1;j<=n;j++) {
			pw[i][j]=pw[i][j-1]*v[i]%mod;
		}
	}
	ll ans=0;
	for(int k=0;k<=K;k++) {
		for(int l=0;l<32;l++) {
			int sk=k-cnt(l);
			ans+=dfs(m,n,sk,l);
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}

