#include<bits/stdc++.h>
#define ll long long
#define rep(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
template <typename T> void read(T&x){
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
const int mod=998244353;
ll fa(ll a,int x){
	ll s=1;
	for(;x;s=(x&1)?s*a:s,s%=mod,a*=a,a%=mod,x>>=1);
	return s%mod;
}
ll jc[105];
void init(){
	jc[0]=1;
	rep(i,1,100){
		jc[i]=jc[i-1]*i%mod;
	}
}
ll C(int n,int m){
	if(m==0)return 1;
	return (((jc[n]*fa(jc[m],mod-2)%mod)*fa(jc[n-m],mod-2))%mod);
}
int u[105];
ll n,m,k,v[105];
bool check(){
	ll s=0;
	rep(i,0,m){
		s=s+u[i]*(1<<i);
	}
	int ans=0;
	while(s){
		s-=s&-s;
		ans++;
	}
	if(ans<=k)return 1;
	return 0;
}
ll ans=0;
void cnt(){
	ll s=1;
	for(int i=0;i<=m;i++){
		s=(s*fa(v[i],u[i]))%mod;
	}
	ll l=1,p=n;
	for(int i=0;i<=m;i++){
		l*=C(p,p-u[i]);
		p-=u[i];
		l%=mod;
	}
	l*=s;
	l%=mod;
	ans+=l;
	ans%=mod;
}
void dfs(int dep,int sum){
	if(dep>m){
		if(check()&&sum==n){
			cnt();
		}
		return;
	}
	for(int i=0;i<=n;i++){
		if(sum+i>n)break;
		u[dep]=i;
		dfs(dep+1,sum+i);
		u[dep]=0;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	init();
	read(n),read(m),read(k);
	rep(i,0,m)read(v[i]);
	dfs(0,0);
	printf("%lld\n",ans);
	return 0;
}

