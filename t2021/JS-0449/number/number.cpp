#include<bits/stdc++.h>
using namespace std;
namespace base{
	template<class T>inline void read(T&n){
		n = 0; T f = 1; char ch = 0;
		for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
		for (; ch >= '0' && ch <= '9'; ch = getchar()) n = (n << 3) + (n << 1) + (ch ^ 48);
		n *= f;
	}
	template<class T>inline void write(T n, char ch){
		static char buf[233]; int tmp = 0;
		if (n == 0) putchar('0');
		if (n < 0) n = -n, putchar('-');
		for (; n; n /= 10) buf[++tmp] = n % 10;
		for (; tmp; --tmp) putchar(buf[tmp] + 48);
		putchar(ch);
	}
}
using namespace base;
const int N = 1e7 + 5;
const int pos[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int T, p[N], h[N], nxt[N], tot;
inline bool check(int x){
	for (int i = 1; i <= 4; ++i)
		if (x / pos[i] % 10 ==7 || x / pos[9 - i] % 10 == 7) return 1;
	return 0;
}
inline void init(){
	for (int i = 1; i <= N - 5; ++i){
		if (h[i]) continue;
		if (check(i)){
			h[i] = 1;
			for (int j = 2; j <= (N - 5) / i; ++j)
				h[i * j] = 1;
		}
	}
	int last = 1e7 + 1;
	for (int i = N - 5; i >= 1; --i){
		nxt[i] = last;
		if (h[i] == 0) last = i;
	}
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init();
	read(T);
	while (T--){
		int x; read(x);
		if (h[x] == 0) write(nxt[x], '\n');
		else puts("-1");
	}
	return 0;
}

