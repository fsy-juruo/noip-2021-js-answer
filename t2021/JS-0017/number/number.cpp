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
const int MAXN = 1e7 + 100;
int v[MAXN + 10], n, flag[MAXN + 10];
int check(int x) {
	while(x) {
		if(x % 10 == 7) return 1;
		x /= 10; 
	}
	return 0;
}
void pre_solve() {
	for(int i = 1; i <= MAXN; i++) {
		if(check(i) && !v[i])
			for(int j = 1; j * i <= MAXN; j++) v[i * j] = 1;
	}
	for(int i = 1; i <= MAXN; i++)
		flag[i] = flag[i - 1] + v[i];
}
int main() {
	file("number");
	pre_solve(); int m; read(m);
	for(int i = 1; i <= m; i++) {
		int x; read(x); if(v[x]) {
			puts("-1"); continue;
		}
		int l = x + 1, r = MAXN, res = 0;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(flag[mid] - flag[x] != mid - x) res = mid, r = mid - 1;
			else l = mid + 1; 
		}
		printf("%d\n", res);
	}
	return 0;
}

