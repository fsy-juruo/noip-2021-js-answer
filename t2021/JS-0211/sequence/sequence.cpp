#include<bits/stdc++.h>
#define int long long
#define P 998244353
using namespace std;
int f[50][300000],h[50][300000],a[1000],ans=0;
int c(int x){
	int s=0;
	while(x){
		if(x%2)s++;
		x/=2;
	}
	return s;
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>a[i];
	}
	h[0][0]=1;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int l=0;l<=m;l++){
			for(int j=1;j<=200000;j++){
				if(j>=(1<<l)&&h[i-1][j-(1<<l)]){
					h[i][j]=1;
					f[i][j]+=f[i-1][j-(1<<l)]*a[l];
					f[i][j]%=P;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=10;j++){
//			cout<<setw(4)<<f[i][j]<<' ';
//		}cout<<endl;
//	}
	for(int i=0;i<=200000;i++){
		if(c(i)<=k)ans+=f[n][i],ans%=P;
	}
	cout<<ans<<endl;
return 0;
}

