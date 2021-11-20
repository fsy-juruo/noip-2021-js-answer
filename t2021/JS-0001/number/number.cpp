#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000015;
const int maxq = 200005;
int q, n, lst;
bool bad[maxn], del[maxn];
int a[maxq], nxt[maxn];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d", &a[i]);
		n = max(n, a[i]);
	}
	if (n <= 2e5) n = 2e5 + 10;
	else n = 1e7 + 10;
	for (int i = 1; i <= n; i++) {
		bad[i] = bad[i / 10] || (i % 10 == 7);
		if (bad[i] && !del[i]) {
			for (int j = i; j <= n; j += i)
				del[j] = true;
		}
		if (!del[i])
			nxt[lst] = i, lst = i;
	}
	for (int i = 1; i <= q; i++) {
		if (del[a[i]]) puts("-1");
		else printf("%d\n", nxt[a[i]]);
	}
	return 0;
}
