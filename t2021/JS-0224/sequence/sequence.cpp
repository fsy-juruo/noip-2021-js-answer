#include<bits/stdc++.h>
using namespace std;
#define N 32
#define M 14
#define mod 998244353
long long  f[N][N*(1<<M)];//?
long long  n,m,k;
long long  v[N];
long long  calc(long long  x){
	long long  res=0;
	while(x){
		if(x&1)res++;
		x>>=1;
	}
	return res;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(long long  i=0;i<=m;i++)cin>>v[i];
	for(long long  j=0;j<=m;j++){
		f[1][(1<<j)]=v[j];
	}
	for(long long  i=1;i<n;i++){
		for(long long  S=0;S<=n*(1<<m);S++){
			for(long long  j=0;j<=m;j++){
				if(S+(1<<j)>n*(1<<m))continue;
				f[i+1][S+(1<<j)]+=f[i][S]*v[j];
				f[i+1][S+(1<<j)]%=mod;
			}
		}
	}
	long long  ans=0;
	for(long long  S=0;S<n*(1<<(m+1));S++){
		if(calc(S)<=k){
			ans+=f[n][S];
			ans%=mod;
		}
	}
	while(ans<0)ans+=mod;
	cout<<ans<<endl;
	return 0;
}
