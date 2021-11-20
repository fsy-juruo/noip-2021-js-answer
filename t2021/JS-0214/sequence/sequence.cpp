#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m,k,v[204];
long long ans,jc = 1;
long long lowbit(long long x) {
	return x & -x;
}
int count(long long k) {
	int ret = 0;
	while(k) {
		++ret;
		k -= lowbit(k);
	}
	return ret;
}
void dfs(int x,int i,long long s,long long sv) {
	if(x > m) return;
	if(i == n) {
		if(count(s) <= k) ans = (ans + sv) % mod;
		return;
	}
	for(int j = 0; j <= m; ++j) dfs(j,i + 1,s + (1ll << j),sv * v[j] % mod);
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0; i <= m; ++i) cin >> v[i];
	dfs(0,0,0,1);
	cout << ans;
	return 0;
}
