#include <bits/stdc++.h>
#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define per(i, a, b) for (int i(a); i >= b; --i)
#define mem(a, b) memset(a, b, sizeof(a))
#define pqueue priority_queue
#define umap unordered_map
#define pb push_back
#define mp make_pair
//#define int long long

using namespace std;
bool vis[10000055];
int pos, tot, nxt[10000055];

template <typename _T>
void rd(_T &x) {
	int f = 1; x = 0;
	char s = getchar();
	while (s < '0' || s > '9') {if (s == '-') f = -1; s = getchar();}
	while (s >= '0' && s <= '9') x = (x<<1)+(x<<3)+(s^48), s = getchar();
	x *= f;
}

bool check(int x) {
	while (x) {
		if (x%10 == 7) return false;
		x /= 10;
	}
	return true;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	rep(i, 1, 10000050) {
		if (!vis[i] && check(i)) {
			nxt[pos] = i;
			pos = i;
		}
		if (!check(i)) for (register int j = i; j <= 10000050; j += i) vis[j] = 1;
	}
	int _;
	for (rd(_); _; _--) {
		int x; rd(x);
		if (vis[x]) puts("-1");
		else printf("%d\n", nxt[x]);
	}
	return 0;
}

