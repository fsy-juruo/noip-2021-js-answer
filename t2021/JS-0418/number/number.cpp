#include <bits/stdc++.h>

using namespace std;

template<typename T> void read(T &x) {
	x = 0; bool f = false; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) f ^= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x= -x;
}
template<typename T> void write(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar((x % 10) ^ 48);
}

const int maxn = 1e7 + 1, maxnum = 1e7 + 10;

int T, cnt;
int a[maxnum], nxt[maxn + 10];
bool is7[maxn + 10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= maxn; i++) {
		int t = i;
		while (t) {
			if (t % 10 == 7) {
				a[++cnt] = i;
				break;
			}
			t /= 10;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= maxn / a[i]; j++) is7[a[i] * j] = true;
	}
	int pre = 0;
	for (int i = 1; i <= maxn; i++) {
		if (is7[i]) continue;
		nxt[pre] = i;
		pre = i;
	}
	read(T);
	while (T--) {
		int x;
		read(x);
		if (is7[x]) {
			puts("-1");
		} else {
			write(nxt[x]);
			putchar('\n');
		}
	}
	return 0;
} 
