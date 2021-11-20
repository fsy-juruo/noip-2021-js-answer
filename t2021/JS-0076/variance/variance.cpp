#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
double a[N], ans;
double A;

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

int main() {
	freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; ++ i) scanf("%lf", &a[i]);
	for (int i = 1; i <= n; ++ i) A += a[i];
	A /= n;
	for (int i = 1; i <= n; ++ i) ans += n * (a[i] - A) * (a[i] - A);
	printf("%.0f", ans);
	return 0;
}

