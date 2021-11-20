#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll const mod=998244353;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll qsm(ll x,ll k){
	ll a=x,b=k,ans=1;
	while(b){
		if(b&1){
			ans=(ans*a)%mod;
		}
		b>>=1;
		a=(a*a)%mod;
	}
	if(ans>=mod) ans%=mod;
	return ans;
}
ll ans=0;
ll n,m,d,s[200],k,v[110],inv[200],jc[200],b[200];
ll c(ll x,ll y){
	return ((jc[x]*inv[y])%mod)*inv[x-y]%mod;
}
bool check(){
	ll tot=0;
	for(int i=0;i<=m;i++){
		if(s[i]>0){
			s[i+1]+=s[i]/2;
			s[i]%=2;
		}
	}
	int i=m+1;
	while(s[i]>=2){
		s[i+1]+=s[i]/2;
		s[i]%=2;
		i++;
	}
	for(int j=0;j<=i;j++) {
		if(s[j]) tot++;
		s[j]=b[j];
	}
	if(tot<=k) return 1;
	return 0;
}
void gt(){
	ll tot=0,sum=1;
	for(int i=0;i<=m;i++){
		if(b[i]){
			tot+=b[i];
			sum*=c(tot,b[i]);
			sum%=mod;
			sum*=qsm(v[i],b[i]);
			sum%=mod;
		}
	}
	ans+=sum;
	if(ans>=mod) ans%=mod;
	return;
}
void dfs(ll x,ll lf){
	if(lf<0) return;
	if(x==m+1){
		if(lf!=0) return;
	}
	if(!lf){
		if(check()){
		gt();
	}
		return;
	}
	for(int i=0;i<=lf;i++){
		s[x]=i;
		b[x]=i;
		dfs(x+1,lf-i);
		s[x]=0;
		b[x]=0;
	}
}
int main(){

freopen("sequence.in","r",stdin);
freopen("sequence.out","w",stdout);
n=read();
m=read();
k=read();
for(int i=0;i<=m;i++){
	v[i]=read();
}
jc[0]=1;
inv[0]=1;
for(int i=1;i<=31;i++){
	jc[i]=(jc[i-1]*i)%mod;
	inv[i]=qsm(jc[i],mod-2);
//	printf("%lld %lld\n",jc[i],inv[i]);
}
dfs(0,n);
printf("%lld\n",ans);
return 0;
}

