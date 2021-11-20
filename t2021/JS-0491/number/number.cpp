#include <bits/stdc++.h>
using namespace std;

bool chk(int x) {
	while (x) { if (x%10 == 7) return true; x /= 10; }
	return false;
}

const int MAXN = 11000010;
bool vis[MAXN];
int nums[1000010], cnt = 0;
void sieve(int N = MAXN-10) {
	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		if (chk(i)) {
			for (int j = i; j <= N; j+=i)
				vis[j] = 1;
		}
	}
	for (int i = 1; i <= N; i++) if (!vis[i])
		nums[++cnt] = i;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	sieve();
//	cerr << cnt << '\n';
//	cerr << nums[cnt] << '\n';
//	for (int i = 1; i <= 50; i++) cout << nums[i] << '\n';
	int T; cin>> T;
	while (T--) {
		int x; cin >> x;
		if (vis[x]) cout << "-1\n";
		else {
			int p = upper_bound(nums+1, nums+cnt+1, x)-nums;
			cout << nums[p] << '\n';		
		}
	}
	return 0;
}
