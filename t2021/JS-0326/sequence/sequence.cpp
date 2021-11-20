#include<bits/stdc++.h>
using namespace std;
inline void file(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}
//≤ª∑¡∞¥’’kµ›Õ∆
#define int long long
#define mod 998244353
int a[101];
int n,m,k;
int s[39];
int ans=0;
inline bool check(){
	int hx[100];
	memset(hx,0,sizeof(hx));
	int mx=0;
	for(register int i=1;i<=n;i++){
		hx[s[i]]++;mx=max(mx,s[i]);
	}
	int cnt=0;
	for(register int i=1;i<=mx*7;i++){
		if(hx[i]>=2){
			int xsc=hx[i]/2;
			hx[i]%=2;
			hx[i+1]+=xsc;
		//	cout<<i<<endl;
		}
		if(hx[i]==1)++cnt;
		if(cnt>k)return false;
	}
	
	if(k>=cnt)return true;
	else return false;
}
inline void dfs(int depth,int val){
	if(depth>n){
		if(check()){
//			cout<<val<<endl;
//			for(register int i=1;i<=n;i++){
//				cout<<s[i]<<' ';
//			}cout<<endl;
			ans+=val;
			ans%=mod;
		}
		return ;
	}
	for(register int i=1;i<=m+1;i++){
		s[depth]=i;
		dfs(depth+1,val*a[i]%mod);
	}
}
signed main(){
	file();
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(register int i=1;i<=m+1;i++)cin>>a[i];
	dfs(1,1);
	cout<<ans%mod<<endl;
	return 0;
}

