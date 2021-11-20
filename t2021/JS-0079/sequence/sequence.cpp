#include <bits/stdc++.h>
#define ll long long
#define N 110
using namespace std;

ll n, m, k, v[N], f[150000][35], mod = 998244353, ans;
ll dp(ll x, ll y){
	if(y < 0) return 0;
	if(f[x][y] != -1) return f[x][y];
	if(x == 0){
		if(y == 0) return f[x][y] = 1;
		else return f[x][y] = 0;
	}
	ll sum = 0, js = 0;
	for(int i = 0; i <= m; i++){
		if(x < (1 << i)) break;
		sum = (sum + v[i] * dp(x - (1 << i),y-1) % mod) % mod;
	}
	return f[x][y] = (sum % mod);
}
ll cnt(ll x){
	ll js = 0;
	while(x){
		if(x & 1) js++;
		x >>= 1;
	}
	return js;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	memset(f,-1,sizeof(f));
	for(int i = 0; i <= m; i++) scanf("%lld",&v[i]);
	for(int i = n; i <= n * (1 << m); i++){
		if(cnt(i) <= k) ans = (ans + dp(i,n)) % mod;
	}
	printf("%lld\n",ans);
	return 0;
}
