#include <bits/stdc++.h>
#define pb push_back
#define P pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 110;
const int INF = 0x3f3f3f3f;
const int Mod = 998244353;
inline int rd() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
ll n, m, k, v[N];
ll ans;
ll jc1(ll x, ll c) {
	ll mul = 1;
	for (ll i = x; i >= x - c + 1; i--) mul = mul * x % Mod;
	return mul;
}
ll jc2(ll x) {
	ll mul = 1;
	for (ll i = 1; i <= x; i++) mul = mul * x % Mod;
	return mul;
}
void dfs(ll p, ll l, ll sum, ll to, ll a[]) {
	if (p == n + 1) {
		if (sum == to) {
			ll cnt = 1;
			for (int i = 0; i <= m; i++) cnt = cnt * ((ll)pow(v[i], a[i]) % Mod) % Mod;
			sort(a, a + m + 1);
			ll num = 1, now = a[0] + 1;
			for (int i = 1; i <= m; i++) {
				num = num * (jc1(now, a[i]) / jc2(a[i])) % Mod;
			}
			ans = (ans + num * cnt % Mod) % Mod;
		}
		return;
	}
	for (ll i = l; i <= m; i++) {
		if (sum + pow(2, i) * (n - p + 1) > to) break;
		a[i]++;
		dfs(p + 1, i, sum + (ll)pow(2, i), to, a);
		a[i]--;
	}
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = rd(); m = rd(); k = rd();
	for (int i = 0; i <= m; i++) cin >> v[i];
	for (int i = n; i <= n * pow(2, k); i++) {
		int t = i, cnt = 0;
		while (t) {
			int a = t % 2;
			cnt += a;
			t /= 2;
		}
		if (cnt > k) continue;
		ll a[m + 1] = {0};
		dfs(1, 0, 0, i, a);
	}
	cout << ans << endl;
	return 0;
}

