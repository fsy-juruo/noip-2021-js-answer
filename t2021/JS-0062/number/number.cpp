#include<bits/stdc++.h>
using namespace std;

#define U(x, y, z) for (int x = y; x <= z; ++x)
#define D(x, y, z) for (int x = y; x >= z; --x)

const int N = 1e7 + 10;

template <typename T> inline void read(T &n) {
    n = 0; char ch; bool f = 1;
    for (ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
    for (; isdigit(ch); ch = getchar()) n = (n << 1) + (n << 3) + (ch ^ 48);
    if (f == 0) n = -n;
}

template <typename T> inline void chkmin(T &x, T y) {
	if (x > y) x = y;
}

template <typename T> inline void chkmax(T &x, T y) {
	if (x < y) x = y;
}

template <typename T> inline void writeln(T n) {
	static char ch[30]; static int len = 0;
	while (n) {
		ch[++len] = (n % 10) ^ 48;
		n /= 10;
	}
	while (len) putchar(ch[len--]);
	putchar('\n');
}

inline void file(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int Is[N];
int nxt[N];
inline void init() {
	int lst = 0;
	U(i, 1, N - 9) {
		if (Is[i] == 1) continue ;
		int x = i;
		while (x) {
			if (x % 10 == 7) {
				Is[i] = 2;
				break ;
			}
			x /= 10;
		}
		if (Is[i]){
			U(j, 2, N - 10) {
				int tmp = i * j;
				if (tmp > N - 10) break ;
				Is[tmp] = 1;
 			}
		}
		else {
			nxt[lst] = i;
			lst = i;
		}
	}
	
}


int main() {
	file("number");
	init();
	int T;
	read(T);
	while (T--) {
		int x;
		read(x);
		if (!nxt[x]) puts("-1");
		else writeln(nxt[x]);
	}
    return 0;
}

