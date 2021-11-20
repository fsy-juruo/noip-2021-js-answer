#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
typedef long long ll;
typedef pair<int,int> pii;
inline bool cmax(int &x,int y){if(x<y){x=y;return true;}return false;}
inline bool cmin(int &x,int y){if(x>y){x=y;return true;}return false;}
inline int fastin(){int x=0,f=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}return x*f;}

const ll mod=998244353;
int n,m,k;
ll dp[35][1000005],v[105];

ll ans=0;

void dfs(int pos,ll sum,ll S){
	if(pos==n+1){
		if(__builtin_popcount(S)<=k){
			ans+=sum;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		dfs(pos+1,sum*v[i],S+(1LL<<i));
	}
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	n=fastin(); m=fastin(); k=fastin();
	for(int i=0;i<=m;i++)v[i]=fastin();
	
	if(m<=15){
		int bound=n*(1<<m);
		
		dp[0][0]=1;
		for(int i=0;i<n;i++){
			for(int mask=0;mask<=bound;mask++)if(dp[i][mask]!=0){
				for(int j=0;j<=m;j++){
					( dp[i+1][mask+(1<<j)]+= dp[i][mask]*v[j] )%=mod;
				}
			}
		}	
		
		for(int mask=0;mask<=bound;mask++){
			if(__builtin_popcount(mask)<=k){
				ans+=dp[n][mask];
				if(ans>=mod)ans-=mod;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	
	dfs(1,1,0);
	
	printf("%lld\n",ans%mod);	
	return 0;
}

