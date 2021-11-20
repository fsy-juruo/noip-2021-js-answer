#include <bits/stdc++.h>

using namespace std;

const int N = 11000, M = 90000000;

int n, all, ans = 0x3f3f3f3f;
int a[N];
bool st[M];

void dfs(int cnt, int u) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int k = a[i] * n - cnt;
		res += k * k;
	}
	res /= n;
	if(res < ans) {
		ans = res;
 	}
 	if(st[res] == true){
 		return;
	}
 	st[res] = true;
	for (int i = 2; i < n; i++) {
		if(i == u) continue;
		if(a[i] == a[i - 1] + a[i + 1] - a[i]) continue;
		cnt -= a[i];
		a[i] = a[i - 1] + a[i + 1] - a[i];
		cnt += a[i];
		dfs(cnt, i);
		cnt -= a[i];
		a[i] = a[i - 1] + a[i + 1] - a[i];
		cnt += a[i];
	}
}

int main () {
	
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		all += a[i];
	}
	memset(st, 0, sizeof st);
	dfs(all, 0);
	printf("%d\n", ans);
	return 0;
}
