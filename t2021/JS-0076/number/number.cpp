#include <bits/stdc++.h>

using namespace std;

const int MN = 10000005;

int n, sn[MN];
bool isn[MN];

#define de(x) cerr << (#x) << ":" << x << endl
#define deb(x, y) cerr << (#x) << "[" << y << "]:" << x[y] << endl

void read(int &x) {
	x = 0; int op = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') op = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= op;
}

bool check(int x) {
	while (x) {
		if (x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}

void init() {
	for (int i = 1; i <= n; ++ i) {
		if (i % 7 == 0) isn[i] = 1;
		else if (check(i)) for (int j = i; j <= n; j += i) isn[j] = 1;
	}
	int now = 0;
	for (int i = n; i; -- i) {
		sn[i] = now;
		if (!isn[i]) now = i;
	}
}

void write(int x) {
	if (x == 0) {
		puts("0");
		return;
	}
	char s[10]; int len = 0;
	while (x) {
		s[++ len] = char(x % 10 + 48);
		x /= 10;
	}
	for (int i = len; i; -- i) putchar(s[i]); putchar('\n');
}

int main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	n = 10000002;
	init();
	int T; read(T);
	while (T --) {
		int x; read(x);
		if (isn[x]) puts("-1");
		else write(sn[x]);
	}
	return 0;
}

