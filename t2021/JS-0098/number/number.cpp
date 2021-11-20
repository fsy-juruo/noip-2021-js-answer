#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
	return x; }
int top, s[32];
void write(int x) {
	top = 0; while (x) s[++top] = x % 10, x /= 10;
	while (top) putchar(s[top--] + '0'); 
	putchar('\n');
}
const int N = 1e7 + 10;
const int M = 6e6 + 10;
const int M2 = 1e6 + 10;
const int maxn = 1e7;
bool f[N];
int c1, c2;
int a[M], b[M2];
void dfs(int dep, int v, int cnt) {
	if (dep == 7) { if(cnt) a[++c1] = v; return; }
	for (int i = 0; i <= 9; ++i) {
		if (i == 7) dfs(dep + 1, v * 10 + i, cnt + 1);
		else dfs(dep + 1, v * 10 + i, cnt); } }
int main() {
	freopen("number.in", "r", stdin);
 	freopen("number.out", "w", stdout);
	dfs(0, 0, 0);
	for (int i = 1; i <= c1; ++i) { if (f[a[i]]) continue; 
		for (int j = 1; j * a[i] <= maxn; ++j) f[j * a[i]] = 1; }
	for (int i = 1; i <= maxn + 1; ++i) if (!f[i]) b[++c2] = i;
	int T = read(); while (T--) {
		int x = read();
		if (f[x]) puts("-1");
		else {
			int w = upper_bound(b + 1, b + c2 + 1, x) - b;write(b[w]);
		 } }
	return 0; }
