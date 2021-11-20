#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
//#include <cstdlib>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline int read() {
	int val = 0, neg = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0') {
		if (ch == '-') neg = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		val = val * 10 + ch - 48;
		ch = getchar();
	}
	return val * neg;
}

const int X = 1e7 + 10, N = 8e5;
bool nop[X];
int li[N], cnt = 0;

bool c7(int val) {
	while (val) {
		if (val % 10 == 7) return true;
		val /= 10;
	}
	return false;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	cout << (double)(X / 1024.0 / 1024.0) << endl;
	for (int i = 1; i < X; i++) {
		if (nop[i]) continue;
		if (c7(i)) {
			nop[i] = 1;
			for (ll j = 2; 1ll * i * j <= X; j++) {
				nop[i * j] = 1;
			}
		} else {
			li[++cnt] = i;
		}
	}
//	cout << X - 9 << ' ' << nop[X - 9] << endl;return 0;
	int T = read();
	while (T--) {
		int x = read();
		if (nop[x]) printf("-1\n");
		else {
			int pos = lower_bound(li + 1, li + 1 + cnt, x) - li;
			printf("%d\n", li[pos + 1]);
		}
	}
	return 0;
}

