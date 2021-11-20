#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {
		if (ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*neg;
}
const int MAXN=10;
int n,ans=2147483647;
int a[MAXN+5];
map<vector<int>, bool> mp;
vector<int> g;
inline void dfs(int u) {
	int flag=0,sum=0,res=0;
	g.clear();
	for (int i=1;i<=n;++i) sum+=a[i],res=res+a[i]*a[i]*n,g.pb(a[i]);
	if (mp[g]) return ;
	else mp[g]=1;
	res=res+sum*sum;
	for (int i=1;i<=n;++i) res=res-2*a[i]*sum;
	ans=min(ans,res);
	for (int i=2;i<n;++i) {
		if (a[i]!=(a[i-1]+a[i+1]-a[i])) {
			flag=1;
			a[i]=(a[i-1]+a[i+1]-a[i]);
			dfs(u+1);
			a[i]=(a[i-1]+a[i+1]-a[i]);
		}
	}
	if (!flag) return ;
}
signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
/*
4
1 2 4 6
*/
