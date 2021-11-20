#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100005;
const ll MOD=998244353;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int n,m,k;
ll ans;
ll C[35][35]; 
int cnt[12500];
ll v[35][35];

void init1(){
	C[0][0]=1;
	C[1][0]=C[1][1]=1;
	for(int i=2;i<=30;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	cnt[0]=0;
	for(int j=1;j<12500;++j)cnt[j]=cnt[j/2]+(j%2);
}

namespace bf{
	int vv[35];
	ll cy;
	
	void calc(){
		ll res=1;
		int cc=n;
		for(int i=0;i<=m;++i){
			cy++;
			res*=C[cc][vv[i]];
			res%=MOD;
			cc-=vv[i];
		}
		for(int i=0;i<=m;++i){
			cy++;
			res*=v[i][vv[i]];
			res%=MOD;
		}
		ans+=res;
		ans%=MOD;
	}

	void dfs(int id,int curSum,int curCnt,int S){
		if(id==0){
			int d=S-curSum;
			if(d!=curCnt)return;
			vv[id]=d;
			calc();
			return;
		}
		for(int i=0;i<=curCnt;++i){
			if(curSum+(1<<id)*i>S)break;
			if(curSum+(1<<id)*i+(1<<id-1)*(curCnt-i)<S)continue;
			vv[id]=i;
			dfs(id-1,curSum+(1<<id)*i,curCnt-i,S);
		}
		
	}
	
	void solve(){
		int tt=n*(1<<m);
		for(int S=n;S<=tt;++S){
			if(cnt[S]>k)continue;
			dfs(m,0,n,S);
		}
		printf("%lld\n",ans);
	}
}

/*
namespace ezdp{	
	ll dp[13][35][12500];
	void solve(){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n;++i){
			dp[0][i][i]=C[n][i];
		}
		int tt=n*(1<<m);
		for(int i=0;i<m;++i){
			for(int j=0;j<=n;++j){
				for(int msk=0;msk<=tt;++msk){
					if(!dp[i][j][msk])continue;
					for(int k=0;k<=n-j;++k){
						dp[i+1][j+k][msk+(1<<i+1)*k]=(dp[i+1][j+k][msk+(1<<i+1)*k]+dp[i][j][msk]*
					}
				}
			}
		}
	}
}*/

int main(){
	init1();
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;++i)v[i][0]=1,v[i][1]=read();
	for(int i=0;i<=m;++i){
		for(int j=2;j<=n;++j)v[i][j]=v[i][j-1]*v[i][1]%MOD;
	}
	if(n<=30)bf::solve();
//	else ezdp::solve(); 
	return 0;
}

