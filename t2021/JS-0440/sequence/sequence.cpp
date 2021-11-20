#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,k;
long long v[105],f[35][35*1024*8],ans;
int q(int x){
	int res=0;
	while(x){
		if(x&1)res++;
		x>>=1;
	}
	return res;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)cin>>v[i],f[1][1<<i]=v[i];
	for(int i=2;i<=n;i++)
		for(int j=0;j<=n*(1<<m);j++)
			for(int _k=0;_k<=m;_k++){
				if(j<(1<<_k))continue;
				f[i][j]=(f[i][j]+f[i-1][j-(1<<_k)]*v[_k])%mod;
			}
	for(int i=0;i<=n*(1<<m);i++)if(q(i)<=k)ans=(ans+f[n][i])%mod;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	
}
