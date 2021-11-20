#include <bits/stdc++.h>
using namespace std;
const int N = 10000001;
bool vis[N + 5];
int nxt[N + 5];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= N; i++) if (!vis[i]) {
		if (i % 10 == 7 || i / 10 % 10 == 7 || i / 100 % 10 == 7 || i / 1000 % 10 == 7 || i / 10000 % 10 == 7 ||
		i / 100000 % 10 == 7 || i / 1000000 % 10 == 7 || i / 10000000 == 7) {
			for (int j = i; j <= N; j += i) vis[j] = true;
		}
	}
	for (int i = 10000000, lst = 10000001; i >= 1; i--) {
		nxt[i] = lst;
		if (!vis[i]) lst = i;
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", vis[n] ? -1 : nxt[n]);
	}
	return 0;
}
