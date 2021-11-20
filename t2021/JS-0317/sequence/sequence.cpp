#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
const int N = 200;
const int M = 105;
ll v[M], ans = 0;
int a[N], t[N], aa[40]; //选2^i的个数 
int n, m, k;
void dfs(int u) { //已处理几个序列
	if(u == n) {
		int cnt = 0;
		ll sum = 1;
		memset(t, 0, sizeof(t));
		int i;
		for(i = 0; i <= m; i++) {
			t[i] += a[i];
			t[i + 1] += t[i] / 2;
			t[i] %= 2;
			cnt += t[i];
		}
		while(t[i]) {
			t[i + 1] += t[i] / 2;
			t[i] %= 2;
			cnt += t[i];
			i++;
		}
		if(cnt <= k) {
			for(int i = 0; i < n; i++) {
				sum = (sum * v[aa[i]]) % mod;
			}
			ans += sum;
			ans = ans % mod;
		}
		return;
	}  
	for(int i = 0; i <= m; i++) { //枚举第u位的数值 
		aa[u] = i;
		a[i]++; //数值计数器++ 
		dfs(u + 1); //搜索下一位 
		a[i]--; //回溯 
	}
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i <= m; i++) {
		scanf("%lld", &v[i]); //m个v 
	}
	dfs(0);
	printf("%lld", ans);
	return 0;
}
