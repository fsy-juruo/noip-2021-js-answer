#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void read(int &x) {
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}
const int N=110,base=131;
const ll MOD=1000000000000000003;
int n,a[N];
ll ans=1e18;
set<ull> s;
inline void calc() {
	ll res=0,sum=0;
	for(int i=1;i<=n;i++) {
		sum+=a[i];
	}
	for(int i=1;i<=n;i++) {
		res+=(sum-a[i]*n)*(sum-a[i]*n);
	}
	ans=min(ans,res/n);
}
inline ull get() {
	ull hash=0;
	for(int i=1;i<=n;i++) {
		hash=(hash*base+a[i])%MOD;
	}
	return hash;
}
void dfs() {
	for(int i=2;i<n;i++) {
		int nxt=a[i-1]+a[i+1]-a[i];
		if(nxt==a[i]) continue;
		int tmp=a[i];
		a[i]=nxt;
		int hash=get();
		if(!s.count(hash)) {
			s.insert(hash);
			calc();
			dfs();
		}
		a[i]=tmp;
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) {
		read(a[i]);
	}
	calc();
	s.insert(get());
	dfs();
	printf("%lld\n",ans);
	return 0;
}

