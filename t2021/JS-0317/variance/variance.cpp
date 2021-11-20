#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
int n;
ll minn;
ll a[N], sum, sum2;
void dfs(int pre) {
	for(int i = 2; i < n; i++) {
		if(i == pre) continue;
		int t = a[i];
		a[i] = a[i - 1] + a[i + 1] - a[i];
		if(a[i] != t) {
			sum = sum - t + a[i];
			sum2 = sum2 - n * t * t + n * a[i] * a[i];
			if(sum2 - sum * sum < minn) minn = sum2 - sum * sum;
			dfs(i);
			sum = sum + t - a[i];
			sum2 = sum2 - n * a[i] * a[i] + n * t * t;
			a[i] = t;
		} 
	}
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
		sum2 += n * a[i] * a[i];
	}
	minn = sum2 - sum * sum;
	dfs(-1);
	printf("%lld", minn);
	return 0;
}
