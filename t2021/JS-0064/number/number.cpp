#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MN = 1e7 + 500 , maxn = 1e7 + 250;

int f[MN] , nxt[MN];

template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
}
template <typename T> inline void write(T x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> inline void writeln(T x) {
	write(x);
	putchar('\n');
}

int main() {
	
	#ifndef evenbao
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	#endif
	
	for (int i = 1; i < maxn; ++i) {
		int yes = 0 , t = i;
		if (f[i]) continue;
		while (t != 0) {
			if (t % 10 == 7) yes = 1;
			t /= 10;
		}
		if (yes)
			for (int j = i; j < maxn; j += i)
				f[j] = 1;
	}
	for (int i = maxn - 1; i >= 0; --i)
		if (!f[i]) nxt[i] = i;
		else nxt[i] = nxt[i + 1];
	int T; read(T);
	while (T--) {
		int x; read(x);
		if (f[x]) puts("-1");
		else writeln(nxt[x + 1]);
	}
	return 0;
}
