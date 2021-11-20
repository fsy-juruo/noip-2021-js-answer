#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3fll;
const int n = 1e7;
const int MAXN = n + 5;

bool flag[MAXN + 5];
int tot, a[MAXN], nxt[MAXN];

void Solve() {
    int x; scanf("%d", &x);
    if (flag[x]) printf("-1\n");
    else printf("%d\n", nxt[x]);
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w",stdout);
    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t) {
            if (t % 10 == 7) {a[++tot] = i; break;}
            else t /= 10;
        }
    }
    for (int i = 1; i <= tot; i++)
        for (int j = a[i]; j <= n + 5; j += a[i])
            flag[j] = true;
    for (int i = n + 5, x; i >= 1; i--) {
        if (i <= n) nxt[i] = x;
        if (!flag[i]) x = i;
    }
    int T; scanf("%d", &T); while (T--) Solve();
	return 0;
} 
