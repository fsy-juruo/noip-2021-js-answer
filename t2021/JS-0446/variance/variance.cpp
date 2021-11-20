#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e4 + 5;
ll n = 0, m = 0, a[N] = {}, d[N] = {}, d2[N] = {}, ans = 1e18; 

void check(){
	ll res = 0, sm = 0, prv = 0;
	for(ll i = 0 ; i < n ; i ++){
		prv += d2[i]; sm += prv;
		res += (n + 1) * prv * prv;
	}
	res -= sm * sm;
	ans = min(ans, res);
}

int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 0 ; i < n ; i ++) scanf("%lld", &a[i]);
	n --;
	for(ll i = 0 ; i < n ; i ++) d[i] = a[i + 1] - a[i];
	sort(d, d + n); m = 1 << n;
	for(ll i = 0 ; i < m ; i ++){
		ll p = 0;
		for(ll j = n - 1 ; j >= 0 ; j --) if((i >> j) & 1) d2[p ++] = d[j];
		for(ll j = 0 ; j < n ; j ++) if(!((i >> j) & 1)) d2[p ++] = d[j];
		check();
	}
	printf("%lld", ans);
	return 0;
}

