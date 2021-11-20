#include<bits/stdc++.h>
#define ll long long
const ll maxn=1000+500;
const ll mod=998244353;
using namespace std;
inline ll read(){
	char c=getchar();bool f=0;ll num=0;
	for(;c<'0'||c>'9';f=(c=='-')?1:0,c=getchar());
	for(;c>='0'&&c<='9';num=(num<<3)+(num<<1)+(c^'0'),c=getchar());
	return  f?-num:num;
}
ll n,m,k;
ll V[maxn];
ll jc[maxn],p[maxn];
ll C(ll n,ll m){
	if(n>m) swap(n,m);
	return jc[m]/jc[m-n]/jc[n];
}
bool check(ll num){
	ll cnt=0;
	for(ll i=0;(1<<i)<=num;i++){
		ll i1=(1<<i);
		if((num&i1)==i1) cnt++;
		if(cnt>k) return false;
	}
	if(cnt<=k) return true;
	return false;
}
ll cho[maxn];
ll ans;
ll P(ll a,ll b){
	ll num=a;
	b--;
	while(b>0){
//		cout<<b<<" "<<num<<endl;
		if(b%2==1){
			num=(num*a)%mod;
			b--;
		}
		a=(a*a)%mod;
		b/=2;
		
	}
	return num;
}
void dfs(ll num,ll sum,ll dep,ll shangyige){
	if(sum>num) return;
//	cout<<num<<" "<<sum<<endl;
	if(sum+(n-dep+1)*p[m]<num) return;
	if(sum+(n-dep)*p[shangyige]>num) return;
	if(dep==n-1){
		ll f=0;
		for(ll i=0;i<=m+1;i++){
			if(i==m+1) return ;
			if(p[i]==num-sum){
				cho[i]++;
				f=i;
				break;
			}
		}
		if(f<shangyige){
			cho[f]--;
			return;
		}
		ll dishu=n;
		ll ls=1;
		ll v=1;
		
		for(ll i=0;i<=m;i++){
			if(cho[i]==0||dishu==0) continue;
//			cout<<i<<" "<<cho[i]<<" "<<V[i]<<endl;
			v=(v*(P(V[i],cho[i]))%mod)%mod;
			ls=(ls*C(cho[i],dishu))%mod;
			dishu-=cho[i];
		}
		ans=(ans+ls*v)%mod;
		cho[f]--;
		return;
	}
	for(ll i=shangyige;i<=m;i++){
		cho[i]++;
		dfs(num,sum+p[i],dep+1,i);
		cho[i]--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	jc[0]=1;
	p[0]=1;
	n=read();
	m=read();
	k=read();
	for(ll i=1;i<=30;i++){
		jc[i]=jc[i-1]*i;
		p[i]=p[i-1]*2;
	}
	for(ll i=0;i<=m;i++){
		V[i]=read();
	}

	ll MAX=P(2,m);
	for(ll i=n;i<=n*MAX;i++){
		if(check(i)){
//			cout<<i<<endl;
			dfs(i,0,0,0);
//			cout<<i<<endl;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
5 1 1
2 1
*/
