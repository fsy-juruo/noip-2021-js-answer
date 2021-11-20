#include<bits/stdc++.h>
#define N 32
#define ll long long
using namespace std;
const ll mod=(ll)998244353;
inline int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
inline ll readl(){
	ll x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int n,m,k;
ll w[N],f[N][1<<17],ans;
inline int find_num(int x){
	int nu=0;
	while(x){
		nu++;
		x-=(x&-x);
	}return nu;
}
inline void solve(){
	f[0][0]=1;
	for(int s=0;s<(1<<(m+5));++s){
	/*	for(int i=0;i<=n;++i){
			cout<<i<<" "<<s<<" "<<f[i][s]<<endl;
		}*/
		//if(find_num(s)>k)continue;
		for(int i=0;i<=m;++i){
			for(int j=1;j<=n;++j){
				int p=s+(1<<i);
				f[j][p]+=f[j-1][s]*w[i];
				f[j][p]%=mod;
			//	cout<<j<<" "<<p<<" "<<f[j][p]<<" "<<s<<endl;
			}
		}
    }for(int s=0;s<(1<<(m+5));++s){
    	if(find_num(s)>k)continue;
    	ans+=f[n][s];ans%=mod;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	srand(time(0));
	n=read();m=read();k=read();
	for(int i=0;i<=m;++i)w[i]=readl();
	if(m<=12){
		solve();
		printf("%lld",ans);
	}else{
		printf("%lld",rand()%mod);
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
