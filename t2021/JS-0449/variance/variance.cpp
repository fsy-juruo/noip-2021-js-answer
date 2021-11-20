#include<bits/stdc++.h>
using namespace std;
int n, ans = 0x3f3f3f3f, s[10];
void dfs(int u){
	if (u > 10) return;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; ++i)
		sum1 += s[i] * s[i], sum2 += s[i];
	ans = min(ans, n * sum1 - sum2 * sum2);
	
	int tmp;
	for (int i = 2; i < n; ++i){
		tmp = s[i];
		s[i] = s[i - 1] + s[i + 1] - s[i];
		dfs(u + 1);
		s[i] = tmp;
	}
}
int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", s + i);
	
	if (n <= 4){
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}

