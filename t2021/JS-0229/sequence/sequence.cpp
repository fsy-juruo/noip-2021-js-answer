#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int M=110,N=40,MOD=998244353;
int n,m,k,vh[M],a[N];
ll ans,v[M],A[N],F[N];
ll niyuan(ll x){
	ll p=MOD-2;
	ll yuan=1;
	while(p){
		if(p&1)yuan=yuan*x%MOD;
		x=x*x%MOD;
		p>>=1;
	}
	return yuan;
}
void pre(int n){
	A[0]=1;
	for(int i=1;i<=n;i++)
	A[i]=A[i-1]*i%MOD;
	F[0]=1;
	for(int i=1;i<=m;i++)
	F[i]=F[i-1]*2%MOD;
}
bool check(ll x){
	int num=0;
	while(x){
		if(x%2==1)num++;
		x>>=1;
	}
	if(num<=k)return true;
	return false;
}
void dfs(int t,int step,ll num,ll sum,ll times){
	if(step>n){
		if(!check(sum))return;
		ans=(ans+(num*A[n]%MOD)*niyuan(times)%MOD)%MOD;
		return;
	}
	for(int i=t;i<=m;i++){
		vh[i]++;
		dfs(i,step+1,num*v[i]%MOD,(sum+F[i])%MOD,times*vh[i]%MOD);
		vh[i]--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%lld",&v[i]);
	pre(n);
	dfs(0,1,1,0,1);
	printf("%lld\n",ans);
	return 0;
}
