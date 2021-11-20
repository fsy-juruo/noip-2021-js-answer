#include <bits/stdc++.h>
#define N 10005
#define mod 10000007
using namespace std;
int n, s, s2, a[N], ans = INT_MAX, fg[mod];
void dfs(){
	long long f = 0;
	for(int i = 1; i <= n; ++i) f = (f * 131 + a[i] * 233) % mod;
	if(fg[f]) return;
	fg[f] = 1;
	s = 0; s2 = 0;
	for(int i = 1; i <= n; ++i) s2 += a[i] * a[i], s += a[i];
	ans = min(ans, s2 * n - s * s);
	for(int i = 2; i < n; ++i){
		int x = a[i];
		a[i] = a[i - 1] + a[i + 1] - a[i];
		dfs();
		a[i] = x;
	}
}
int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), s += a[i]; 
	if(n <= 15){
		dfs();
		printf("%d", ans);
	}
	else{
		while(1){
			int pd = 0;
			for(int i = 2; i < n; ++i){
				int p = a[i - 1] + a[i + 1] - a[i];
				if(n * (p * p - a[i] * a[i]) - ((s + p - a[i]) * (s + p - a[i]) - s * s) < 0){
					s += p - a[i];
					a[i] = a[i - 1] + a[i + 1] - a[i];
					pd = 1;
				}
			}
			if(!pd) break;
		}
		for(int i = 1; i <= n; ++i) s2 += a[i] * a[i];
		printf("%d", s2 * n - s * s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

