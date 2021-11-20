#include<bits/stdc++.h>
using namespace std;
const int MAXN=30,MAXM=110,p=998244353;
long long pwr[MAXN],inv[MAXN];
int v[MAXM];
long long ans;
int n,m,k;
void build(){
	pwr[1]=inv[1]=1;
	for(int i=2;i<=n;i++){
		pwr[i]=pwr[i-1]*i%p;
		inv[i]=(p-p/i)*inv[p%i]%p;
	}
	for(int i=2;i<=n;i++)
		inv[i]=inv[i]*inv[i-1]%p;
	return;
}
int popcount(long long tmp){
	int s=0;
	while(tmp){
		tmp-=(tmp&(-tmp));
		s++;
	}
	return s;
}
void dfs(int dep,int cur,int cnt,long long f,long long tmp,long long sum){
//	cout<<dep<<endl;
	if(dep>n){
		f=popcount(f);
		tmp=tmp*inv[cnt]%p;
		if(f<=k){
		//	cout<<cur<<' '<<cnt<<' '<<f<<' '<<tmp<<' '<<sum<<endl; 
			ans=(ans+pwr[n]*tmp%p*sum%p)%p;
		}
		return;
	}
	dfs(dep+1,cur,cnt+1,f+(1<<cur),tmp,sum*v[cur]%p);
	if(cnt)
		tmp=tmp*inv[cnt]%p;
	for(int i=cur+1;i<=m;i++)
		dfs(dep+1,i,1,f+(1<<i),tmp,sum*v[i]%p);
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
		scanf("%d",&v[i]);
	build();
	dfs(1,0,0,0,1,1);
	printf("%lld",ans);
	return 0;
}
