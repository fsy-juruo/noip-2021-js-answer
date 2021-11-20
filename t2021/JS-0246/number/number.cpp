#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e7 + 10;

bool h[N] , f[N];
int sum[N];
int nxt[N];

int T;

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

int t;
inline void dfs(int dep , int sum) {
	if (dep > 7) {
		h[sum] = 1;
		return;
	}
	if (dep == t) {
		dfs(dep + 1 , sum * 10 + 7);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		dfs(dep + 1 , sum * 10 + i);
	}
}

int main() {

	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);

	for (int i = 1; i <= 7; i++) {
		t = i;
		dfs(1 , 0);
	}
	for (int i = 1; i <= 10000000; i++) {
		if (i % 7 == 0) {
			f[i] = 1;
			sum[i] = sum[i - 1] + 1;
			continue;
		}
		if (f[i]) {
			sum[i] = sum[i - 1] + 1;
			continue;
		}
		if (!h[i]) {
			sum[i] = sum[i - 1];
			continue;
		}
		for (int j = 1; j * i <= 10000000; j++) {
			f[j * i] = 1;
		}
		sum[i] = sum[i - 1] + 1;
	}
		
	nxt[10000000] = 10000001;
	nxt[10000001] = 10000001;
	for (int i = 10000000 - 1; i >= 0; i--) {
		if (f[i]) {
			nxt[i] = nxt[i + 1];
		}
		else nxt[i] = i;
	}
	
	read(T);
	
	while(T--) {
		int x;
		read(x);
		if (nxt[x] != x) {
			write(-1 , '\n');
		}
		else {
			write(nxt[x + 1] , '\n');
		}
	}

	return 0;

}

