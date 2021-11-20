#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
const int MOD=998244353;
int n,m,k;
int v[110];
int ans,ans1,ans2;
int a[110];
int vis[1000010];
int maxx=0;
bool check(int x){
	int t=0;
	while(x){
		if(x&1)t++;
		x>>=1;
	}
	if(t<=k)return true;
	else return false;
}
void dfs(int dep,int s,long long val){
	if(dep>n){
		ans=(ans+val*vis[s])%MOD;
		return;
	}
	if(s>=maxx)return;
	for(int i=0;i<=m;i++){
		dfs(dep+1,s+(1<<i),(val*v[i])%MOD);
	}
}
void dfs1(int dep,int s,long long val,int lst){
	if(dep>n){
		ans1=(ans1+val*vis[s])%MOD;
		return;
	}
	if(s>=maxx)return;
	for(int i=lst+1;i<=m;i++){
		dfs1(dep+1,s+(1<<i),(val*v[i])%MOD,i);
	}
}
void dfs2(int dep,int s,long long val,int lst){
	if(dep>n){
		ans2=(ans2+val*vis[s])%MOD;
		return;
	}
	if(s>=maxx)return;
	for(int i=lst;i<=m;i++){
		dfs2(dep+1,s+(1<<i),(val*v[i])%MOD,i);
	}
}
void baoli(){
	for(int i=0;i<=m;i++)read(v[i]),v[i]%=MOD;
	for(int i=n;i<=n*(1<<m);i++)if(check(i))vis[i]=1,maxx=max(maxx,i);
//	dfs1(1,0,1,-1);
//	dfs2(1,0,1,0);
	dfs(1,0,1);
	cout<<ans<<endl;
//	cout<<(ans1*2+ans2)%MOD<<endl;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(k);
	if(n<=8&&m<=9){
		baoli();
	}
	
	return 0;
}
/*
5 1 1
2 1
*/
