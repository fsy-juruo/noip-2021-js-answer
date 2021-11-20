#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1 << 17;
const int P = 998244353;

int n , m , k;
int a[N] , v[N];
LL ans;

template <typename T> inline void read(T &x) {
	T f = 1; char c = getchar(); x = 0;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

template <typename T> inline void print(T x) {
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> inline void write(T x , char c) {
	if (x < 0) {x = -x; putchar('-'); }
	print(x);
	putchar(c);
}

inline int ksm(int x , int y) {
	int s = 1;
	while(y) {
		if (y & 1) s = 1ll * s * x % P;
		x = 1ll * x * x % P;
		y >>= 1;
	}
	return s;
}

inline bool chck(int x) {
	int cnt = 0;
	while(x) {
		cnt += x % 2;
		x >>= 1;
	}
	if (cnt <= k) return 1;
	return 0;
}

inline void dfs(int dep , int sum , LL s) {
	if (dep > n) {
		if (chck(sum)) {
			ans = (ans + s) % P;
		}
		return;
	}	
	for (int i = 0; i <= m; i++) {
		dfs(dep + 1 , sum + (1 << i) , s * v[i] % P);
	}
}

int main() {

	freopen("sequence.in" , "r" , stdin);
	freopen("sequence.out" , "w" , stdout);

	read(n); read(m); read(k);
	
	for (int i = 0; i <= m; i++) read(v[i]);
	
	dfs(1 , 0 , 1);
	
	write(ans , '\n');

	return 0;

}

