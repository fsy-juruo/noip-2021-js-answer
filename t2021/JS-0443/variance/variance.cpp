#include <bits/stdc++.h>
#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define per(i, a, b) for (int i(a); i >= b; --i)
#define mem(a, b) memset(a, b, sizeof(a))
#define pqueue priority_queue
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
int n, a[10005];
map <multiset <int>, bool> h;
multiset <int> tmp;
int ans = 9e18;

template <typename _T>
void rd(_T &x) {
	int f = 1; x = 0;
	char s = getchar();
	while (s < '0' || s > '9') {if (s == '-') f = -1; s = getchar();}
	while (s >= '0' && s <= '9') x = (x<<1)+(x<<3)+(s^48), s = getchar();
	x *= f;
}

void dfs(int step) {
	if (n > 4 && step > 20) return ;
	int s = 0, sum = 0;
	rep(i, 1, n) sum += a[i];
//	printf("%lld:", step);
//	rep(i, 1, n) printf("%lld ", a[i]); puts("");
	rep(i, 1, n) s = s+((n*a[i])-sum)*((n*a[i])-sum);//, printf("%lld\n", s);
//	printf("%lld\n", s);
	s /= n;
	ans = min(ans, s);
	rep(i, 2, n-1) {
		tmp.clear();
		rep(j, 1, n) {
			if (i == j) tmp.insert(a[j-1]+a[j+1]-a[j]);
			else tmp.insert(a[j]);
		}
		if (h[tmp] == 1) continue;
//		for (auto y : tmp) printf("%d ", y); puts("hh");
		h[tmp] = 1;
		int ttmp = a[i];
		a[i] = a[i-1]+a[i+1]-a[i];
		dfs(step+1);
		a[i] = ttmp;
	}
	return ;
}

signed main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	rd(n);
	rep(i, 1, n) rd(a[i]);
	dfs(0);
	printf("%lld", ans);
	return 0;
}

