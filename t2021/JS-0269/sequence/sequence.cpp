#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define fi first
#define sc second
typedef long long ll;
using namespace std;

int rdi(){
	int cur=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		cur*=10;
		cur+=((int)ch-'0');
		ch=getchar();
	}
	return cur;
}
const int MAXM=110;
const int MAXN=40;
const ll p=998244353ll;
int n,m,k;
ll ans,val,mask,v[MAXM];
inline void dfs(int pos){
	//cout<<pos<<" "<<mask<<" "<<val<<endl;
	if(pos==n){
		if(__builtin_popcount(mask)<=k){
			ans+=val;
			ans%=p;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		mask+=(1ll<<i);
		ll vp=val;
		val=val*v[i]%p;
		dfs(pos+1);
		val=vp;
		mask-=(1ll<<i);
	}
}
void g1(){
	mask=0ll;
	val=1ll;
	dfs(0);
	printf("%lld\n",ans);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=rdi();
	m=rdi();
	k=rdi();
	rep(i,m+1){
		v[i]=rdi();
	}
	if(n<=8&&m<=9){
		g1();
	}
	return 0;
}
