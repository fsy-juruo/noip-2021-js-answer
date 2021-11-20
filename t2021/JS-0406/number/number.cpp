#include <bits/stdc++.h>

using namespace std;

const int N = 1.1e7 + 8;

int nex[N], m;
bool vis[N], ban[N];

void getnext(int n) {
	for (int i = 1; i <= n; ++i) {
		ban[i] = (ban[i / 10] || i % 10 == 7);
		if (ban[i] && !vis[i])
			for (int j = i; j <= n; j += i)
				vis[j] = 1;
	}
	for (int i = n; i >= 1; --i) {
		if (vis[i + 1]) nex[i] = nex[i + 1];
		else nex[i] = i + 1;
	}
}

int T, x;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getnext(1.1e7);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &x);
		if (vis[x]) puts("-1");
		else printf("%d\n", nex[x]);
	}
	return 0;
}
