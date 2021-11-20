#include <bits/stdc++.h>
#define pb push_back
#define P pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
inline ll rd() {
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
ll n, a[N], ans = 1e16;
map<pair<ll, pair<ll, ll> >, bool> mp;
void dfs(ll a[], ll sum, ll sum2, ll sum3) {
	for (int i = 2; i < n; i++) {
    	ll now = a[i - 1] + a[i + 1] - a[i];
		ll now_sum = sum - a[i] + now;
		ll now_sum3 = sum3 - a[i] * a[i] + now * now;
		ll now_sum2 = now_sum3 * n * n - 2 * now_sum * n * now_sum + now_sum * now_sum * n;
		ll t = a[i];
		a[i] = now;
		if (mp[make_pair(now_sum, make_pair(now_sum2, now_sum3))]) continue;
		mp[make_pair(now_sum, make_pair(now_sum2, now_sum3))] = 1;
		ans = min(ans, now_sum2);
		dfs(a, now_sum, now_sum2, now_sum3);
		a[i] = t;
    }
}
ll sum, sum2, sum3;
int main() {
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        sum3 += a[i] * a[i]; 
    }
    for (int i = 1; i <= n; i++) sum2 += (sum - n * a[i]) * (sum - n * a[i]);
    if (n >= 5) {
		while (true) {
	        bool f = 0;
		    for (int i = 2; i < n; i++) {
	        	ll now = a[i - 1] + a[i + 1] - a[i];
				ll now_sum = sum - a[i] + now;
				ll now_sum3 = sum3 - a[i] * a[i] + now * now;
				ll now_sum2 = now_sum3 * n * n - 2 * now_sum * n * now_sum + now_sum * now_sum * n;
				if (now_sum2 < sum2) {
	                f = 1;
	            	sum = now_sum;
	            	sum2 = now_sum2;
	            	sum3 = now_sum3;
	            	a[i] = a[i - 1] + a[i + 1] - a[i];
					break;
				}
	        }
			ans = min(ans, sum2);
	        if (!f) break;
		}
	}
	else {
	    ans = sum2;
		mp[make_pair(sum, make_pair(sum2, sum3))] = 1;
		dfs(a, sum, sum2, sum3);
	}
    cout << ans / n << endl;
    return 0;
}
