#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> inline void read(T &F) {
	F = 0; int R = 1; char CH = getchar();
	for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;
	for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;
	F = F * R;
}
inline void file(string str) {
	freopen((str + ".in").c_str(), "r", stdin);
	freopen((str + ".out").c_str(), "w", stdout);
}
const int N = 2e6 + 10;
int now, fst[N], nxt[N], num[N], wi[N], n, m, q, flag[N], ci[N], li[N];
int id(int x, int y) {
	return (x - 1) * n + y;
}
void add(int u, int v, int w) {
	nxt[++now] = fst[u], fst[u] = now, num[now] = v, wi[now] = w;
	nxt[++now] = fst[v], fst[v] = now, num[now] = u, wi[now] = w;
}
void zero() {
	now = 0;
	memset(fst, 0, sizeof(fst));
	memset(ci, 0, sizeof(ci));
	memset(li, 0, sizeof(li));
}
int main() {
	file("chess");
	int T; read(T);
	while(T--) {
		read(n), read(m), read(q);
		for(int i = 1; i <= n; i++) {
			string s; cin >> s;
			for(int j = 0; j < s.size(); j++)
				if(s[j] == '1') add(id(i, j + 1), id(i, j + 2), 0);
		}
		for(int i = 1; i <= n - 1; i++) {
			string s; cin >> s;
			for(int j = 0; j < s.size(); j++)
				if(s[j] == '1') add(id(i, j + 1), id(i + 1, j + 1), 0);
		}
		for(int i = 1; i <= q; i++) {
			int c, l, x, y; read(c), read(l), read(x), read(y); c++;
			x = id(x, y); int res = 0;ci[x] = c, li[x] = l;
			for(int i = fst[x]; i; i = nxt[i])
				if(ci[num[i]] != ci[x] && li[num[i]] <= li[x]) res++;
			
			printf("%d\n", res);
		}
		zero();
	}
	return 0;
}

