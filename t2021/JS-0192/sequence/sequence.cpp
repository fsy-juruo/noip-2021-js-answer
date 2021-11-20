#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
typedef long long ll;

template<typename T>inline void rd(T &x){
	x=0;ll f=1;char c=gc();
	for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=gc())x=x*10+c-'0';
	x*=f;
}

const ll mod=998244353;
int lg[50]={0,0,1},v[50],cnt[110];
ll h[110],n,m,k,ans;
bitset<110> s;

inline int turn(){
	int sum=0;
	for(int i=0;i<=20;i++)sum+=s[i]*(1<<i);
	return sum;
}

inline int ck(){
	return s.count()<=k;
}

inline void add(int k){
	while(s[k])s[k++]=0;
	s[k]=1;
}

inline void mns(int k){
	while(!s[k])s[k++]=1;
	s[k]=0;
}

inline ll jcm(int k){
	ll sss=1;
	for(int i=2;i<=k;i++)sss=sss*i%mod;
	return sss;
}

inline ll calc(){
	ll s1=1;
	for(int i=0;i<=m;i++)s1*=cnt[i]?jcm(cnt[i]):1;
	return jcm(n)/s1;
}

inline void dfs(int k,ll val){
	if(k>n){
		if(ck())ans=(ans+val*calc())%mod;
		return;
	}
	for(int i=v[k-1];i<=m;i++)v[k]=i,++cnt[i],add(i),dfs(k+1,val*h[i]%mod),--cnt[i],mns(i);
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=3;i<=30;i++)lg[i]=lg[i>>1]+1;
	rd(n),rd(m),rd(k);
	for(int i=0;i<=m;i++)rd(h[i]);
	dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}

