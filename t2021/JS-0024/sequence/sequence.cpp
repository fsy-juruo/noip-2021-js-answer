#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG printf("Passing Line %d in Function [%s].\n",__LINE__,__FUNCTION__);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int > pii;

const int maxn=200007;
const int INF=0x3f3f3f3f;
const ll MOD=998244353;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

inline int mod1(int x){return x>=MOD?x-MOD:x;}
inline int mod2(int x){return x<0?x+MOD:x;}
inline void add(int &x,int y){x=mod1(x+y);}
inline void sub(int &x,int y){x=mod2(x-y);}

int n,m,K;
int dp[107][37][37][37];
int C[107][107];
int v[107][107];
int dfs(int i,int j,int k,int l){
	
	if(i==-1){
		if(j==0&&k==0&&l==0)return 1;
		else return 0;
	}
	if(dp[i][j][k][l]!=-1)return dp[i][j][k][l];
	
	int ans=0;
	for(int jj=0;jj<=j;jj++){
		//d=0
		if(2*l+jj-j>=0&&2*l+jj-j<=n)add(ans,1ll*dfs(i-1,jj,k,2*l+jj-j)*C[j][jj]%MOD*v[i][j-jj]%MOD);
		if(2*l+jj-j+1>=0&&2*l+jj-j+1<=n&&k>=1)add(ans,1ll*dfs(i-1,jj,k-1,2*l+jj-j+1)*C[j][jj]%MOD*v[i][j-jj]%MOD);
	}
//	cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<ans<<endl;
	return dp[i][j][k][l]=ans;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=mod1(C[i-1][j-1]+C[i-1][j]);
		}
	}
	for(int i=0;i<=m;i++){
		scanf("%d",&v[i][1]);
		v[i][0]=1;
		for(int j=2;j<=n;j++){
			v[i][j]=1ll*v[i][1]*v[i][j-1]%MOD;
		}
	}
	memset(dp,-1,sizeof(dp));
	int ans=0;
	for(int k=0;k<=K;k++){
		for(int l=0;l<=n;l++){
			dfs(m,n,k,l);
			if(__builtin_popcount(l)+k<=K)add(ans,dp[m][n][k][l]);
		}
	}
	printf("%d",ans);

	return 0;
}

