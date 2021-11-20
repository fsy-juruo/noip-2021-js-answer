#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=1;i<=n;++i)
#define N 500099
#define irep(i,l,r) for(ll i=l;i<=r;++i)
#define drep(i,l,r) for(ll i=r;i>=l;--i)

using namespace std;
const ll mod=998244353;
inline ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s*=10,s+=ch-'0';
		ch=getchar();
	}
	return s*w;
}

ll inv[N];

void FILEREAD(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}
ll qp(ll a,ll b){
	if(b==1)return a%mod;
	if(b==0)return 1;
	ll x=qp(a,b>>1);
	return b&1?x*x%mod*a%mod:x*x%mod;
}

//ll ans,v[10000],c[800][800],f[32][105][32][32],g[32][105][32][32];
ll ans=0,n,m,k,v[N],vis[N],pre,fr[N]={1};
unsigned ll p;
ll popcnt(ll x){
	if(x==0)return 0;
	x-=x&(-x);
	return popcnt(x)+1;
}
int cte[N];
void dfs(ll x){
//	cout<<x<<endl;
	if(x==n+1){
		if(popcnt(p)<=k){
			ll s=1;
			for(int i=0;i<=m;++i)cte[i]=0;
			for(ll i=1;i<=n;++i){
				cte[vis[i]]++;
				s*=v[vis[i]]%mod;
				s%=mod;
			}
			ll xs=fr[n];
			s%=mod;
			for(int i=0;i<=m;++i){
				//xs*=qp(fr[cte[i]],mod-2);
				xs*=inv[cte[i]];
				xs%=mod;
			}
		//	cout<<xs<<endl;
			s*=xs%mod;
			s%=mod;
			ans+=s;
		}
		ans%=mod;
		return;
	}
	ll temp=pre;
	for(ll i=vis[x-1];i<=m;++i){
		vis[x]=i;
		p+=(1ll<<i);
		dfs(x+1);
		p-=(1ll<<i);
	}
}
int main(){
	FILEREAD();
	n=read(),m=read(),k=read();
	for(int i=1;i<=300;++i){
		fr[i]=fr[i-1]*i;
		fr[i]%=mod;

	//	cout<<fr[i]<<' '<<inv[i]<<endl;
	}
	for(int i=1;i<=300;++i){
		inv[i]=qp(fr[i],mod-2);
		inv[i]%=mod;
	}
	inv[0]=1;
	for(ll i=0;i<=m;++i){
		v[i]=read();
	}
	dfs(1);
	cout<<ans%mod;
	/*
	ll n=read(),m=read(),K=read(); 
	c[0][0]=c[1][0]=c[1][1]=1;
	for(ll i=2;i<=m;++i){
		c[i][0]=1;
		for(ll j=1;j<=i;++j){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=mod;
		}
	} 
	for(ll i=0;i<=m;++i)v[i]=read();
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=m;++j){
			f[i][j][0][0]=1;
		}
	}
	for(ll i=1;i<=n;++i){
		for(ll j=0;j<=m;++j){
			for(ll k=0;k<=K;++k){
				for(ll l=0;l<=n;++l){
					for(ll s=0;s<=n;++s){
						cerr<<i<<' '<<j<<' '<<l<<' '<<s<<endl;
						g[j][k][l+1][s+1]=f[j][k][l][s];
						for(ll x=1;j+x<=m;++x)
							g[j+x][k+s%2][1][s/2]=f[j][k][l][s]*c[i][l]%mod*qp(v[j],l)%mod;
					}
				}
			}
		}
		swap(f,g);
		memset(g,0,sizeof(g));
	}
	for(ll k=1;k<=K;++k){
		for(ll s=0;s<=n;++s){
			if(calc(s)+k<=K)ans+=g[n][m][k][s];
			ans%=mod;
		}
	}
	cout<<ans;
	*/
	return 0;
} 
