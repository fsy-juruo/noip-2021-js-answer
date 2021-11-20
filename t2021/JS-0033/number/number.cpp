#include <bits/stdc++.h>
using namespace std;

#define mk make_pair
#define fi first
#define se second
#define lob lower_bound
#define upb upper_bound
#define SZ(a) ((int)((a).size()))

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;


const int MAXN = 1e7;

bool f[MAXN + 5], g[MAXN + 5];
int ans[MAXN + 5];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	for (int i = 1; i <= MAXN; ++i) {
		int x = i;
		while (x) {
			if (x % 10 == 7) {
				f[i] = 1; // have 7
				break;
			}
			x /= 10;
		}
	}
	for (int i = 1; i <= MAXN; ++i) {
		if (f[i]) {
			for (int j = i + i; j <= MAXN; j += i) {
				g[j] = 1;
			}
		}
	}
	
	int nxt = MAXN + 1; // nxt number without 7
	for (int i = MAXN; i >= 1; --i) {
		if (!f[i] && !g[i]) { // no 7
			ans[i] = nxt;
			nxt = i;
		} else {
			ans[i] = -1;
		}
	}
	
	int T, x;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
	return 0;
}
