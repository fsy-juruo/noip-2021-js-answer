#include <bits/stdc++.h>
using namespace std;

const long long N=105;
const long long MOD=998244353;
long long n,m,k;
long long V[N],s[N];
long long ans;

long long GetC(long long x,long long y){
	if(x==0) return 1;
	long long ret=1;
	for (long long i=y;i>=y-x+1;i--){
		ret*=i;
		ret%=MOD;
	}
	for (long long i=x;i>=1;i--){
		ret/=i;
	}
	return ret;
}

void dfs(long long x,long long l){//depth,lft
	if(x==m){
		s[m]=l;
		long long f=0,sum=0,lst=0;
		for (long long i=0;i<=m+4;i++){
			if((s[i]+lst)%2==1){
				sum++;
			}
			lst=(s[i]+lst)/2; 
			if(sum>k) break;
		}
		if(sum<=k){
			//prlong longf("%d\n",sum);
			//for (long long i=0;i<=m;i++){
			//	prlong longf("%d ",s[i]);
			//}
			//
			long long p=1,ap=1;
			for (long long i=0;i<=m;i++){
				for (long long j=0;j<s[i];j++){
					p=p*V[i];
					p%=MOD;
				}
			}
			//printf("%d\n",p);
			long long now=n,now2=0;
			for (long long i=0;i<=m;i++){
				if(s[i]==0) continue;
				else{
					ap*=GetC(now2,now);
					now-=now2;
					now2=s[i];
					ap%=MOD;
				}
			}
			ans+=((p*ap)%MOD);
			ans%=MOD;
		}
		return;
	}
	for (long long i=0;i<=l;i++){
		s[x]=i;
		dfs(x+1,l-i);
		s[x]=0;
	}
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (long long i=0;i<=m;i++){
		scanf("%lld",&V[i]);
	}
	dfs(0,n);
	printf("%lld",ans);
	return 0;
}
