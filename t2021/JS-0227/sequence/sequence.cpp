#include<bits/stdc++.h>
using namespace std;
long long n,v[100010],cnt[135],M,ans,k,m;
const long long mod= 998244353;
inline void dfs(int x,long long p){
	if(x==n){
		for(int i=0;i<=M;i++)
			cnt[i+1]+=cnt[i]>>1,cnt[i]&=1;
		int Cnt=0;
		for(int i=0;i<=M&&Cnt<=k;i++)
			Cnt+=cnt[i];
		if(Cnt<=k)
			ans=(ans+p)%mod;
		return;
	}
	x++;
	for(int i=0;i<=m;i++)
		cnt[i]++,dfs(x,p*v[i]%mod),cnt[i]--;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;M=m+33;
	for(int i=0;i<=m;i++)
		cin>>v[i];
	dfs(0,1);
	cout<<ans;
	return 0;
}	                                                                            

