#include <bits/stdc++.h>
using namespace std;

int has[10001000];
int bad[10001000];
int nxt[10001000];

void PreCalc(int n) {
	for (int i = 1; i <= n; i++) {
		has[i] = has[i / 10] | (i % 10 == 7);
	}
	for (int i = 1; i <= n; i++) {
		if (has[i] && !bad[i]) {
			for (int j = i; j <= n; j += i) {
				bad[j] = 1;
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		nxt[i] = bad[i] ? nxt[i + 1] : i;
	}
}

void read(int &x) {
	char c = getchar(); while (c < '0' || c > '9') c = getchar();
	x = c - '0', c = getchar(); while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}

char st[100];

void print(int x) {
	int tp = 0;
	if (!x) st[tp++] = '0';
	while (x) st[tp++] = x % 10 + '0', x /= 10;
	while (tp--) putchar(st[tp]);
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	PreCalc(10000100);
	int T; read(T);
	while (T--) {
		int x; read(x);
		if (bad[x]) putchar('-'), print(1);
		else print(nxt[x + 1]);
		putchar('\n');
	}
	return 0;
}

