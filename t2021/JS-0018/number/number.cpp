#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
using namespace std;
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int maxn = 10000500;
bool sh[maxn + 5];

int main() {
	freopen("number.in", "r", stdin);
	#ifndef Acetyl
	freopen("number.out", "w", stdout);
	#endif
	for (int i = 7; i <= maxn; ++i) {
		bool hv7 = 0;
		int tmp = i;
		while (tmp) {
			if (tmp % 10 == 7) hv7 = 1;
			tmp /= 10;
		}
		if (!hv7) continue;
		for (int j = i; j <= maxn; j += i) sh[j] = 1;
	}
	int T; scanf("%d", &T);
	while (T--) {
		int x; scanf("%d", &x);
		if (sh[x]) puts("-1");
		else {
			++x;
			bool *p = sh + x;
			while (*p) ++p;
			printf("%d\n", p - sh);
		}
	}
	return 0;
}
