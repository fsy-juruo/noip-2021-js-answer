#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
#define MP make_pair
using namespace std;
typedef long long ll;

inline void read(int &x) {
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}
const int N=110,MOD=998244353;
int n,m,k,v[N],ans;
void dfs(int p,int tot,int mul) {
	if(p==n+1) {
		int cnt=0;
		while(tot) {
			cnt+=(tot&1);
			tot>>=1;
		}
		if(cnt<=k) ans=(ans+mul)%MOD;
		return;
	}
	for(int i=0;i<=m;i++) {
		dfs(p+1,tot+(1<<i),(ll)mul*v[i]%MOD);
	}
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=0;i<=m;i++) {
		read(v[i]);
	}
	dfs(1,0,1);
	printf("%d\n",ans);
	return 0;
}

