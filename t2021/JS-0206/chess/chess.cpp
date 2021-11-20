#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline int read() {
	int val = 0, neg = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0') {
		if (ch == '-') neg = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		val = val * 10 + ch - 48;
		ch = getchar();
	}
	return val * neg;
}

const int N = 2e5 + 10, Q = 1e5 + 10;
int n, m, q, ver[N << 4], nxt[N << 4], head[N], cnt = 0, lv[N], cv = 0, ans = 0;
bool col[N], vis[N], vis2[N], u[N];
short opt[N << 4];
char s[N];

int cal(int x, int y) {
	return (x - 1) * m + y;
}

void add(int x, int y, short z) {
	ver[++cnt] = y, nxt[cnt] = head[x], opt[cnt] = z, head[x] = cnt;
}

void dfs(int now, int ini, int tmp) {
//	cout << ini << ' ' << now << ' ' << tmp << endl;
	vis[now] = 1, ans++;
	if (u[now] && now != ini) return;
	for (int i = head[now]; i; i = nxt[i]) {
		int to = ver[i];
		if (vis[to] || (u[to] && (col[to] == col[ini] || lv[to] > lv[ini]))) continue;
//		cout << "//" << to << endl;
		if (opt[i] == 1 && tmp == 0) dfs(to, ini, 1);
		if (opt[i] == 2) {
			if (tmp == 0) {
				if (to == now + 1) dfs(to, ini, 2);
				else if (to == now - 1) dfs(to, ini, 3);
				else if (to < now) dfs(to, ini, 4);
				else if (to > now) dfs(to, ini, 5);
			} else if (tmp == 2 && to == now + 1) dfs(to, ini, 2);
			else if (tmp == 3 && to == now - 1) dfs(to, ini, 3);
			else if (tmp == 4 && to < now && to != now - 1) dfs(to, ini, 4);
			else if (tmp == 5 && to > now && to != now + 1) dfs(to, ini, 5);
		}
	}
}

void dfs2(int now, int ini) {
//	cout << ini << ' ' << now << endl;
	if (!vis[now]) ans++;
	vis2[now] = vis[now] = 1;
	if (u[now] && now != ini) return;
	for (int i = head[now]; i; i = nxt[i]) {
		int to = ver[i];
//		cout << "/" << now << ' ' << to << ' ' << vis2[to] << endl;
		if (vis2[to] || (u[to] && (col[to] == col[ini] || lv[to] > lv[ini]))) continue;
		if (opt[i] != 3) continue;
		dfs2(ver[i], ini);
	}
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int T = read();
	while (T--) {
		memset(ver, 0, sizeof ver);
		memset(nxt, 0, sizeof nxt);
		memset(head, 0, sizeof head);
		memset(lv, 0, sizeof lv);
		memset(col, 0, sizeof col);
		memset(u, 0, sizeof u);
		memset(opt, 0, sizeof opt);
		cnt = 0;
		n = read(), m = read(), q = read();
//		cout << n << ' ' << m << ' ' << q << endl;
		cv = cal(n, m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", s + 1);
			for (int j = 1; j <= m - 1; j++) {
				int now = cal(i, j), to = cal(i, j + 1);
				if (s[j] == '0') continue;
				else add(now, to, s[j] - '0'), add(to, now, s[j] - '0');
			}
		}
		for (int i = 1; i <= n - 1; i++) {
			scanf("%s", s + 1);
			for (int j = 1; j <= m; j++) {
				int now = cal(i, j), to = cal(i + 1, j);
				if (s[j] == '0') continue;
				else add(now, to, s[j] - '0'), add(to, now, s[j] - '0');
			}
		}
		while (q--) {
//			cout << q << endl;
			int s1 = read(), s2 = read(), s3 = read(), s4 = read();
			int now = cal(s3, s4); col[now] = s1, lv[now] = s2;
			u[now] = 1;
			memset(vis, 0, sizeof(bool) * (cv + 1)); ans = 0; memset(vis2, 0, sizeof(bool) * (cv + 1));
			dfs(now, now, 0);
			dfs2(now, now);
			printf("%d\n", ans - 1);
		}
//		for (int i = head[8];i;i = nxt[i]) cout << ver[i] << ' '; cout << endl;
	}
	return 0;
}

