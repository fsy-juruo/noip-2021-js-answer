#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int) (n); ++ i)
#define rep1(i, n) for (int i = 1; i <= (int) (n); ++ i)

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

bool found(int x)
{
	bool ret = false;
	while (x) {
		if (x % 10 == 7) ret = true;
		x /= 10;
	}
	return ret;
}

int T;
bool vis[10000017];
int nxt[10000017];

void solve()
{
	int x; scanf("%d", &x);
	if (vis[x]) {
		printf("-1\n"); return ;
	}
	printf("%d\n", nxt[x]);
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	for (int i = 1; i <= 10000007; ++ i) if (!vis[i]) {
		if (!found(i)) continue;
		vis[i] = true;
		for (int j = i; j <= 10000007; j += i) {
			vis[j] = true;
		}
	}
	
	int mi = 10000001;
	for (int i = 10000000; i > 0; -- i) {
		nxt[i] = mi;
		if (!vis[i]) mi = i;
	}
	
	scanf("%d", &T);
	while (T --) solve();
	
	return 0;
}
