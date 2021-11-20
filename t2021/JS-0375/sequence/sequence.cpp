#include <bits/stdc++.h>
#define N 1005
#define mod 998244353
#define ll unsigned long long
using namespace std;
int n,m,k;
long long v[N],num[N],ans=0;

ll jc(int x){
	ll k=1;
	for(int i=1;i<=x;++i) k=(k*i)%mod;
	return k%mod;
}

ll pw(int a,int b){
	ll k=1;
	a%=mod;
	for(int i=0;i<b;++i) k=(k*a)%mod;
	return k%mod;
}

void calc(){
//	for(int i=0;i<=m;++i)
//		printf("%d ",num[i]);
//	puts("");
	ll a=1,b=jc(n);
	for(int i=0;i<=m;++i){
		a=a*pw(v[i],num[i])%mod;
		b=b/jc(num[i])%mod;
	}
	ans=(ans+a*b)%mod; 
}

bool ch(int x){
	int num=0;
	while(x){
		if(x&1) num++;
		x>>=1;
	} 
	return num<=k;
}

void ind(int p,int ls,int sumx){
	if(p>m+1 || ls<0) return;
//	if(ls==0){
//		ind(m+1,0,sumx);
//		return;
//	}
	if(p==m+1 && ch(sumx) && ls==0) calc();
	for(num[p]=0;num[p]<=ls;++num[p]){
		ind(p+1,ls-num[p],sumx+num[p]*(1<<p));
	}
}


int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i) scanf("%lld",&v[i]);
	ind(0,n,0);
	printf("%lld",ans%mod);
	return 0;
}
