#include <bits/stdc++.h>
using namespace std;
void readin(int &x) {
	x = 0;
	char ch = getchar();
	for (; ch > '9' || ch < '0'; ch = getchar());
	for (; ch <= '9' && ch >= '0'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
}
void writeln(int x) {
	if (x > 9) writeln(x / 10);
	putchar(x % 10 + 48);
}
const int N = 1e7 + 500, Lim = 1e7 + 10;
int rec[N], len;
bool del[N], vis[N];
int nex[N];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= Lim; i ++) {
		if (vis[i / 10] || i % 10 == 7) {
			vis[i] = true;
			rec[++ len] = i;
		}
	}
	int tmp;
	for (int i = 1; i <= len; i ++) {
		tmp = Lim / rec[i];
		for (int j = rec[i]; j <= Lim; j += rec[i]) {
			del[j] = true;
		}
	}
	int las = 0;
	for (int i = 1; i <= Lim; i ++) {
		if (!del[i]) {
			nex[las] = i;
			las = i;
		}
	}
	int T, x;
	readin(T);
	while (T --) {
		readin(x);
		if (del[x]) printf("-1\n");
		else {
			writeln(nex[x]);
			putchar('\n');
		}
	}
	return 0;
}
