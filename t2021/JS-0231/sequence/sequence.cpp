#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
ll c[105][105],v[105],ans;
int n,m,k,a[105],cnt;
void yh(int n){
	for(int i=0;i<=n;++i){
		c[i][0]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
//			printf("c[%d][%d]=%lld ",i,j,c[i][j]);
		}
//		puts("");
	}
}
ll fpow(ll x,int y){
	ll r=1;
	while(y){
		if(y&1) r=r*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return r;
}
bool chk(){
	int res=0,cnt=0;
	for(int i=0;i<=m;++i){
		cnt+=(a[i]+res)&1;
		res=(a[i]+res)>>1;
	}
	while(res){
		cnt+=res&1;
		res>>=1;
	}
//	printf("cnt=%d\n",cnt);
	return cnt>k;
}
void calc(){
//	printf("-------start-------\n");
	if(chk()){
//		puts("-----break-----");
		return;
	} 
//	for(int i=0;i<=m;++i){
//		printf("%d:%d\n",i,a[i]);
//	}
	ll sum=1;
	int tmp=0;
	for(int i=0;i<=m;++i){
		if(a[i]){
			tmp+=a[i];
//			printf("%d:sum=%lld\n",i,sum);
//			printf("fpow(%lld,%d)=%lld\n",v[i],a[i],fpow(v[i],a[i]));
//			printf("c[%d][%d]=%lld\n",tmp,a[i],c[tmp][a[i]]);
			sum=sum*fpow(v[i],a[i])%mod*c[tmp][a[i]]%mod;
//			printf("%d:sum=%lld\n",i,sum);
		}
	}
	ans=(ans+sum)%mod;
//	printf("--------end---------\n");
} 
void dfs(int p,int s){
	if(s==0){
		calc();
		return;
	}
	if(p>m) return;
	for(int i=0;i<=s;++i){
		a[p]=i;
		dfs(p+1,s-i);
	} 
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i){
		scanf("%lld",&v[i]);
	}
	yh(100);
	dfs(0,n);
	printf("%lld\n",ans);
	return 0;
}
