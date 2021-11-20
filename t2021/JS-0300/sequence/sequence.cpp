#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=35,Mod=998244353;
int n,m,k;
int v[N];
LL ans;
LL qmi(LL a,LL b){
	LL res=1;
	while(b){
		if(b&1) res=res*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return res;
}
void dfs(int num,LL sum,LL res){
	if(num==n){
		int tmp=0;
		while(sum){
			if(sum&1) tmp++;
			sum>>=1;
		}
		if(tmp<=k) ans=(ans+res)%Mod;
		return;
	}
	for(int i=0;i<=m;i++){
		sum=(sum+qmi(2,i))%Mod;
		dfs(num+1,sum,res*v[i]);
		sum=(sum+Mod-qmi(2,i))%Mod;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%d",&v[i]);
	dfs(0,0,1);
	printf("%lld\n",ans);
	return 0;
}

