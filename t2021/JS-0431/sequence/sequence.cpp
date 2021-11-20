#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define init(a,i) memset(a,i,sizeof(a))
#define mod 998244353
int n,m,k;
int v[110];
int dp[31][101][15361],ans=0;
int ni[110],q[110];
int x,y;
void exgcd(int a,int b){
	if(!b){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int xx=x;
	x=y;
	y=xx-a/b*y;
}
int cnt(int i){
	int sum=0;
	while(i){
		sum++;
		i-=(i&(-i));
	}
	return sum;
}
void solve(){
	cin>>n>>m>>k;
	m++;
	rep(i,m)cin>>v[i];
	dp[0][0][0]=1;
	rep(i,m){
		rep(j,n+1){
			rep(s,n*q[m]){
			ll pi=dp[i][j][s];
			for(int l=0;j+l<=n;l++){
				//*=(j+l) /=l
				if(l){
					pi*=(n+1-(j+l));
					pi%=mod;
					pi*=ni[l];
					pi%=mod;
					pi=pi*v[i]%mod;
				}
				dp[i+1][j+l][s+q[i]*l]+=pi;
				dp[i+1][j+l][s+q[i]*l]%=mod;
			}
			}
		}
	}
	rep(i,n*q[m]){
		if(cnt(i)<=k)
			ans=(ans+dp[m][n][i])%mod;
	}
	cout<<ans;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int s=1;
	q[0]=1;
	repp(i,100){
		s*=2;
		q[i]=s;
		exgcd(i,mod);
		ni[i]=(x%mod+mod)%mod;
	}
	int T=1;
	//cin>>T;
	while(T--){solve();}
	return 0;
}
  
