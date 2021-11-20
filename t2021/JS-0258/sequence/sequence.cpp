#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ri register ll 
template<typename yx>inline void read(yx &a){
	yx x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
	a=x*f; 
}
ll a[40],s[40],cnt[40],c[40],n,m,k,ans=0,mod=998244353;
ll ksm(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll C(ll n,ll m){
	return c[n]*ksm(c[m],mod-2)%mod*ksm(c[n-m],mod-2)%mod;
}
void dfs1(ll x,ll y,ll sum,ll ss){
	if(sum>ss)return;
	if(sum==ss&&x==n){
		ll res=1;
		for(ri i=0;i<=y&&x;i++){
			if(cnt[i]){res=res*ksm(a[i],cnt[i])%mod*C(x,cnt[i])%mod;x-=cnt[i];}
		}
		ans=(ans+res)%mod;
		return;
	}
	if(x>n)return;
	for(ri i=y;i<=m;i++){
		cnt[i]++;
		dfs1(x+1,i,sum+s[i],ss);
		cnt[i]--;
	}
}
ll lowbit(ll x){
	ll res=0;
	while(x){
		if(x&1)res++;
		x>>=1;
	}
	return res;
}
void dfs2(ll x,ll y,ll sum,ll ss){
	if(sum>ss)return;
	if(x==n&&lowbit(sum)<=k){
		ll res=1;
		for(ri i=0;i<=y&&x;i++){
			if(cnt[i]){res=res*ksm(a[i],cnt[i])%mod*C(x,cnt[i])%mod;x-=cnt[i];}
		}
		ans=(ans+res)%mod;
		return;
	}
	if(x>n)return;
	for(ri i=y;i<=m;i++){
		cnt[i]++;
		dfs2(x+1,i,sum+s[i],ss);
		cnt[i]--;
	}
}

int main()
{
	for(ri i=0;i<=32;i++)s[i]=(1<<i);
	c[0]=1;
	for(ri i=1;i<=32;i++)c[i]=c[i-1]*i%mod;
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(k);
	for(ri i=0;i<=m;i++)read(a[i]);
	if(k==1){
		ll emm=n*s[m];
		for(ri i=1;s[i]<=emm;i++){
			if(s[i]<n)continue;
			dfs1(0,0,0,s[i]);
		//	printf("%lld %lld %lld\n",s[i],i,n);
		}
		printf("%lld\n",ans);
	}
	else {
		ll emm=n*s[m];
		dfs2(0,0,0,emm);
		printf("%lld\n",ans);
	}
	return 0;
}
