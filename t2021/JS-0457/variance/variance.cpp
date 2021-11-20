#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 5, MAXST = 170000;

int n, a[MAXN], ans;
bool vis[MAXST];

int sta() {
	int st = 0;
	for (int i = 1; i <= n; i++) {
		st = st * 11 + a[i];
	}
	return st;
}

void dfs() {
	int cur = sta();
	if (vis[cur]) return;
	vis[cur] = true;
	int s2 = 0, s = 0;
	for (int i = 1; i <= n; i++) {
		s2 += a[i] * a[i], s += a[i];
	}
	ans = min(ans, s2 * n - s * s);
	for (int i = 2; i < n; i++) {
		int nex = a[i - 1] + a[i + 1] - a[i];
		swap(nex, a[i]);
		dfs();
		swap(nex, a[i]);
	}
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	ans = 1e9;
	dfs();
	
	printf("%d\n", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
