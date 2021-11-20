#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,k,v[40],rec[40],ans;
void dfs(int p,int num){
	if(p==n){
		int c=0;
		while(num){
			c+=num&1;
			num>>=1;
		}
		if(c>k) return;
		int tmp=1;
		for(int i=1;i<=n;++i)
			tmp=(long long)tmp*v[rec[i]]%M;
		ans=(ans+tmp)%M;
		return;
	}
	for(int i=0;i<=m;++i){
		rec[p+1]=i;
		dfs(p+1,num+(1<<i));
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;++i) cin>>v[i];
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
// T2 written by Skaditxdy
