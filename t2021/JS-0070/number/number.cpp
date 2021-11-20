#include <bits/stdc++.h>
#define LL long long
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)

template <typename T>
inline void read(T &x) {
	x = 0; T f = (T) 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = ' ') {
	write(x); putchar(sp);
}

const int maxN = 1e7 + 4, mT = 2e5 + 2;
int T, n, sm = 0, g[919045], gd[maxN], qqq[maxN], tot1 = 0, tot2 = 0;
//void _sieve(int nn) {
//	_rep(i, 2, nn) {
//		if(!d[i]) d[i] = i, prs[++tot1] = i;
//		for(int j = 1; j <= tot1; j++) {
//			if(prs[j] > d[i] || prs[j] > nn / i) break;
//			d[i * prs[j]] = prs[j];
//			gd[i * prs[j]] = (gd[i * prs[j]] & gd[i] & gd[prs[j]]);
//		}
//	}
//}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	read(T);
//	time_t st, en;
//	st = clock();
	int Lim = 1e7 + 2;
	gd[0] = 1;
	_rep(i, 1, Lim) gd[i] = (gd[i / 10] & (i % 10 != 7)), qqq[i] = gd[i];  
	_rep(i, 1, Lim) {
		if(qqq[i]) continue;
		_rep(j, 2, Lim / i) gd[i * j] = 0;
	}
	_rep(i, 1, Lim) if(gd[i]) g[++tot2] = i;
//	en = clock();
//	printf("%.2f ms.\n", (en - st) * 1000.0 / CLOCKS_PER_SEC);
//	_sieve(Lim);
//	_rep(i, 1e7, Lim) writesp(gd[i]);
//	_rep(i, 1, Lim) if(gd[i]) g[++tot2] = i;
	while(T--) {
		read(n);
		if(gd[n] == 0) {
			puts("-1");
		} else {
			int x = std::upper_bound(g + 1, g + tot2 + 1, n) - g;
			writesp(g[x], '\n'); 
		}
	}
//	writesp(tot1, '\n');
//	_rep(i, 1, T) read(n[i]), sm = std::max(sm, n[i]);
//	
//	
//	_rep(i, 1, T) {
//		if(gd[n[i]] == 0) {
//			puts("-1");
//		} else {
//			int x = std::upper_bound(g + 1, g + tot2 + 1, n[i]) - g;
//			writesp(g[x], '\n');
//		}
//	}
//	_rep(i, 1, sm) if(gd[i] == 0) writesp(i);
//	puts("");
	return 0;
}


