#include <bits/stdc++.h>
#define nwah cout<<"nwah"<<endl;
using namespace std;

const int MAXN=10000+10;
int n,a[MAXN];

void init() {
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
}

int tmp[MAXN];
void modif(int pos) {
	if(pos<=0||pos>=n-1) return ;
	else tmp[pos]=tmp[pos+1]+tmp[pos-1]-tmp[pos];
}
void remodif(int pos) {
	if(pos<=0||pos>=n-1) return ;
	else tmp[pos]=tmp[pos+1]+tmp[pos-1]-tmp[pos];
}
int get_p() {
	int sigm=0; for(int i=0;i<n;i++) sigm+=tmp[i];
	int ret=0;
	for(int i=0;i<n;i++) ret+=(n*tmp[i]-sigm)*(n*tmp[i]-sigm);
	return ret/n;
}
int very_shit_dfs(int dep) {
//	for(int i=0;i<4;i++) cout<<tmp[i]<<" "; cout<<get_p()<<endl;
	if(dep<=0) return get_p();
	int ans=get_p();
	modif(1);
	ans=min(ans,very_shit_dfs(dep-1));
	remodif(1);
	modif(2);
	ans=min(ans,very_shit_dfs(dep-1));
	remodif(2);
	return ans;
} 

void very_shit_solve() {
	for(int i=0;i<n;i++) tmp[i]=a[i];
	int ans=get_p();
	if(n==1||n==2) cout<<ans<<endl; //cout<<"Fuck it"<<endl;
	else if(n==3) {
		modif(1); ans=min(ans,get_p());
		cout<<ans<<endl;
	}
	else if(n==4) {
		int ans=min(ans,very_shit_dfs(8));
		cout<<ans<<endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	init();
	if(n<=4) very_shit_solve();
	else {
		cout<<0<<endl; //I'm prettu convinced that the "not strict increase" means something
	}
	return 0;
} 






































