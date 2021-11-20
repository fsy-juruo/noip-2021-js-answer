#include<bits/stdc++.h>
using namespace std;
#define N 22
int n,b[10005],a[10005];
long long s1,s2,ans;
bool used[1005][605];
void dfs(int i,long long s1,long long s2) {
	ans = min(ans,n * s2 - s1 * s1);
	if(i == n) return;
	dfs(i + 1,s1,s2);
	s1 = s1 - 2 * b[i] + b[i + 1] + b[i - 1];
	s2 = s2 - b[i] * b[i] + (b[i + 1] + b[i - 1] - b[i]) * (b[i + 1] + b[i - 1] - b[i]);
	b[i] = b[i + 1] + b[i - 1] - b[i];
	if(i > 2 && !used[i][b[i]]) {
		used[i][b[i]] = 1;
		int c[N];
		for(int j = 2; j < n; ++j) c[j] = b[j];
		dfs(i - 1,s1,s2);
		for(int j = 2; j < n; ++j) b[j] = c[j];
	}
	dfs(i + 1,s1,s2);
	for(int j = i; j < n; ++j)
		b[j] = a[j];
}
int main() {
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s1 += a[i];
		s2 += a[i] * a[i];
		b[i] = a[i];
	}
	ans = n * s2 - s1 * s1;
	dfs(2,s1,s2);
	cout << ans;
	return 0;
}
