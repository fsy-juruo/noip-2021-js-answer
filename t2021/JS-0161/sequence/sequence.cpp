#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T&x) {
	x = 0;
	char ch = getchar();
	T flg = 1;
	while ((!isdigit(ch)) && ch != '-') ch = getchar();
	if (ch == '-') ch = getchar(), flg = -1;
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= flg;
}
long long v[1110];
int a[110];
bitset<110> vis;
const long long Mod = 998244353;
int n,m,k;
long long ans = 0;
inline void dfs (int dep, long long ret) {
	if (dep == n) {
		if (vis.count() <= k) {
			ans = (ans + ret) % Mod;
		}
		return;
	}
	for (register int i = 0; i <= m; i++) {
		a[dep] = i;
		int t = i;
		while (vis[t] == 1) vis[t] = 0,t++;
		vis[t] = 1;
		dfs(dep + 1, ret * v[i] % Mod);
		vis[t] = 0;
		for (register int j = t - 1; j >= i; j--) vis[j] = 1;
	}
}
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	read(n),read(m),read(k);
	for (int i = 0; i <= m; i++) {
		read(v[i]);
	}
//	for (int len = 1; len <= m + 1; len++) {
//		for (int i = 1; i + len - 1 <= m + 1; i++) {
//			int j = i + len - 1;
//			for (int x = 0; x <= min(len,k); x++) {
//				for (int s = x; s <= min(len,k); s++) {
//					for (int mid = i; mid <= j; mid++) {
//						if (mid < i + x) {
//							f[i][j][x][s] += f[i][mid-1][mid-i][mid-i] * v[mid] * f[mid+1][j][x-(mid-i+1)][s-(mid-i+1)];
//						} 
//						else f[i][j][x][s] += f[i][mid-1][x][s] * 
//					}
//				}
//			}
//		}
//	}
	dfs(0, 1);
	
	printf("%lld\n", ans);
	return 0;
}
