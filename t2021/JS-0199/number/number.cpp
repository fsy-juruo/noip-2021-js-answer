#include <bits/stdc++.h>
using namespace std;
int T, n;
const int N = 10000007;
const int x = 10000000;
int nxt[N];
bool p[N], s[N];
void read (int &x) {
	x = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
void init () {
	for (int i = 1; i <= x; i++) {
		int t = i;
		while (t) {
			if (t % 10 == 7) {
				p[i] = 1;
				break;
			}
			t = t / 10;
		}
	}
	for (int i = x; i >= 1; i--) if (p[i])
		for (int j = 2; j * i <= x; j++)
			p[i * j] = 1;
	int t = x + 1;
	for (int i = x; i >= 1; i--) {
		if (!p[i]) nxt[i] = t, t = i;
	}
}
int main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	read(T);
	init();
	while (T--) {
		read(n);
		if (p[n]) printf ("-1\n");
		else printf ("%d\n", nxt[n]);
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
