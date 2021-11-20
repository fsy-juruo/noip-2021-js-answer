#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define mp make_pair
#define pb push_back
#define ppb pop_back
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {
	if (x > y) x = y;
}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {
	if (x < y) x = y;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
template<typename T> void read(T &x) {
	x = 0; char c = getchar(); bool neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return; recursive_print(x / 10);
	putchar('0' + x % 10);
}
template<typename T> void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x == 0) putchar('0');
	recursive_print(x);
}
template<typename T> void print(T x, char c) {
	print(x); putchar(c);
}
const int MAXV = 1e7 + 100;
bool has7(int x) {
	while (x) {
		if (x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
bool ban[MAXV + 5];
int nxt[MAXV + 5];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= MAXV; i++) if (has7(i)) {
		for (int j = i; j <= MAXV; j += i) ban[j] = 1;
	}
	int lst = MAXV + 1;
	for (int j = MAXV; j; j--) {
		nxt[j] = lst;
		if (!ban[j]) lst = j;
	}
	int qu; read(qu);
	while (qu--) {
		int x; read(x);
		print((ban[x] ? -1 : nxt[x]), '\n');
	}
	return 0;
}
