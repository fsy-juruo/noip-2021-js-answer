#include<bits/stdc++.h>
#define lint long long
#define filename "sequence"
using namespace std;
const int maxn=105,mod=998244353;
int read(){
	int re=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		re=(re<<3)+(re<<1)+(ch^48);
		ch=getchar();
	}
	return f*re;
}
int n,m,k,val[maxn],use[maxn];
lint ans,inv[maxn]={1},fac[maxn]={1};
lint quick_pow(lint x,lint y){
	lint re=1,base=x;
	while(y){
		if(y&1) re=re*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return re;
}
bool check(){
	lint re=0;
	for(int i=0;i<=m;i++) re+=use[i]*(1<<i);
	int cnt=0;
	while(re){
		cnt++;
		re-=re&-re;
	}
	return cnt<=k;
}
lint appear(){
	int sum=0;
	for(int i=0;i<=m;i++) sum+=use[i];
	lint re=fac[sum];
	for(int i=0;i<=m;i++) re=re*inv[use[i]]%mod;
	return re;
}
void calc(){
	lint temp=1;
	for(int i=0;i<=m;i++)
	  for(int j=1;j<=use[i];j++) temp=(temp*val[i])%mod;
	ans=(ans+temp*appear()%mod)%mod;
}
bool ex(int x){
	lint re=0;
	for(int i=0;i<=m;i++) re+=use[i]*(1<<i);
	re=re&((1<<x)-1);
	int cnt=0;
	while(re){
		cnt++;
		re-=re&-re;
	}
	return cnt>k;
}
void dfs(int x,int cnt){
	if(ex(x)) return;
	if(cnt==n){
		if(check()) calc();
		return;
	}
	if(x==m){
		use[x]=n-cnt;
		if(check()) calc();
		use[x]=0;
		return;
	}
	for(int i=0;i+cnt<=n;i++){
		use[x]=i;
		dfs(x+1,cnt+i);
		use[x]=0;
	}
}
int main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
    for(int i=1;i<=50;i++) fac[i]=i*fac[i-1]%mod;
    for(int i=1;i<=50;i++) inv[i]=quick_pow(fac[i],mod-2);
    n=read(),m=read(),k=read();
    for(int i=0;i<=m;i++) val[i]=read();
    dfs(0,0);
    printf("%lld\n",ans);
	return 0;
}
