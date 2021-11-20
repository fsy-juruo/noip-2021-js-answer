#include<bits/stdc++.h>
#define ll long long
#define ge getchar()
#define pu putchar
#define P 998244353
using namespace std;
inline void read(ll &x){
	x=0;ll f=0,c=ge;
	for(;c<48||c>57;c=ge)if(c==45)f=1;
	for(;48<=c&&c<=57;c=ge)x=(x<<3)+(x<<1)+(c^48);
	if(f)x=-x;
}
void write(ll x){
	if(x<0){pu(45);x=-x;}
	if(x>9)write(x/10);
	pu(x%10+48);
}
ll n,m,k,v[105],ans=0;
void dfs(ll h,ll s,ll g){
	if(g>=P)g%=P;
	if(h>n){
		ll cnt=0;
		while(s){++cnt;s&=s-1;}
		if(cnt<=k)ans+=g;
		if(ans>=P)ans-=P;
		return;
	}
	for(int i=0;i<=m;++i)dfs(h+1,s+(1<<i),g*v[i]);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=0;i<=m;++i)read(v[i]);
	dfs(1,0,1);write(ans);
	return 0;
}
