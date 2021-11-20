//WSQ
#include<cstdio>
#define mod 998244353
#define LL long long
using namespace std;
int n,m,k;
LL v[2050];
int a[2050];
int b[2050];
LL ans;
void dfs(int now,LL sum){
	if(now==n+1){
		for(int i=0;i<=m;i++)b[i]=a[i];
		int tot=0;
		b[m+1]=0;
		for(int i=0;i<=m;i++){
			b[i+1]+=b[i]/2;
			b[i]=b[i]%2;
			tot+=b[i];
		}
		for(int i=m+1;b[i]!=0;i++){
			b[i+1]=b[i]/2;
			b[i]=b[i]%2;
			tot+=b[i];
		}
		if(tot>k)return;
		ans=(ans+sum)%mod;
		return;
	}
	for(int i=0;i<=m;i++){
		a[i]++;
		dfs(now+1,sum*v[i]%mod);
		a[i]--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%lld",&v[i]);
	dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}
