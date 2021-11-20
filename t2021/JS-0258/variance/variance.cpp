#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ri register ll 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
template<typename yx>inline void read(yx &a){
	yx x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
	a=x*f; 
}
const ll N=1e5+5;
ll n,a[N],vis[N],sum,ans,k,res=0;
struct nx{
	ll sum,sqrsum;
	#define s(p) tr[p].sum
	#define ss(p) tr[p].sqrsum
}tr[N<<2];
inline ll ab(ll x){
	return x<0?-x:x;
}
inline void push_up(ll p){
	s(p)=s(ls(p))+s(rs(p));
	ss(p)=ss(ls(p))+ss(rs(p));
}
void build(ll p,ll l,ll r){
	if(l==r){
		s(p)=a[l];
		ss(p)=a[l]*a[l];
		return;
	}
	ll mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
void update(ll p,ll l,ll r,ll x,ll v){
	if(l==r){
		s(p)=v;
		ss(p)=v*v;
		return ;
	}
	ll mid=l+r>>1;
	if(x<=mid)update(ls(p),l,mid,x,v);
	else update(rs(p),mid+1,r,x,v);
	push_up(p);
}
void dfs(ll x){
	//if(x>=n)return;
	for(ri i=2;i<n;i++){
		if(vis[i])continue;
		a[i]=a[i+1]+a[i-1]-a[i];
		update(1,1,n,i,a[i]);
		vis[i]++;
		ans=min(ans,ab(n*ss(1)-s(1)*s(1)));
		dfs(x+1);
		vis[i]--;
		a[i]=a[i+1]+a[i-1]-a[i];
		update(1,1,n,i,a[i]);
	}
	return;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(ri i=1;i<=n;i++)read(a[i]);
	build(1,1,n);
	ans=ab(n*ss(1)-s(1)*s(1));
//	printf("%lld\n",ans);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
