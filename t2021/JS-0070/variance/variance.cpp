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

const int maxN = 1e4 + 10;
int n, a[maxN], sum = 0, q = 0;

LL ans;
int seq[15];
void dfs(int dep, int gp) {
	ans = std::min(ans, 1ll * n * q - 1ll * sum * sum);
	if(dep >= 12) return;
	_rep(i, 2, n - 1) {
		if(i == gp) continue;
		int g = a[i + 1] + a[i - 1] - a[i];
		sum = sum - a[i] + g; q = q - a[i] * a[i] + g * g, a[i] = g; seq[dep] = i;
		dfs(dep + 1, i);
		a[i] = a[i + 1] + a[i - 1] - g;
		sum = sum - g + a[i]; q = q - g * g + a[i] * a[i]; seq[dep] = 0;
	}
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	read(n);
	_rep(i, 1, n) read(a[i]), sum = sum + a[i], q = q + a[i] * a[i];
	
	if(n == 2) {
		writesp(1ll * n * q - 1ll * sum * sum, '\n');
		return 0;
	} else if(n == 3) {
		ans = 1ll * n * q - 1ll * sum * sum;
		int qq = a[1] + a[3] - a[2];
		ans = std::min(ans, 1ll * n * (q - a[2] * a[2] + qq * qq) - 1ll * (sum - a[2] + qq) * (sum - a[2] + qq));
		writesp(ans, '\n');
	} else if(n == 4) {
		ans = 1ll * n * q - 1ll * sum * sum;
//		std::cout << ans << "\n";
		int qq = a[1] + a[3] - a[2];
		ans = std::min(ans, 1ll * n * (q - a[2] * a[2] + qq * qq) - 1ll * (sum - a[2] + qq) * (sum - a[2] + qq));
//		std::cout << 1ll * n * (q - a[2] * a[2] + qq * qq) - 1ll * (sum - a[2] + qq) * (sum - a[2] + qq) << "\n";
		qq = a[2] + a[4] - a[3];
		ans = std::min(ans, 1ll * n * (q - a[3] * a[3] + qq * qq) - 1ll * (sum - a[3] + qq) * (sum - a[3] + qq));
		writesp(ans, '\n');
	} else if(n <= 10) {
		int ans = n * q - sum * sum;
		dfs(1, 0);
		writesp(ans, '\n');
	} else {
		while(1) {
			int flg = 1, maxL = 0, maxpos = 0;
			_rep(i, 2, n - 1) {
				LL lambda = 1ll * n * (a[i + 1] + a[i - 1]) * (a[i + 1] + a[i - 1]) - 2ll * n * a[i] * (a[i + 1] + a[i - 1]) - 1ll * (a[i + 1] + a[i - 1] - 2 * a[i]) * (a[i + 1] + a[i - 1] - 2 * a[i]) - 2ll * sum * (a[i + 1] + a[i - 1] - 2 * a[i]);
	//			std::cout << 1ll * n * (a[i + 1] + a[i - 1]) * (a[i + 1] + a[i - 1]) - 2ll * n * a[i] * (a[i + 1] + a[i - 1]) - 1ll * (a[i + 1] + a[i - 1] - 2 * a[i]) * (a[i + 1] + a[i - 1] - 2 * a[i]) + 2ll * sum * (a[i + 1] + a[i - 1] - 2 * a[i]) << "\n"; 
				if(lambda < 0) {
					if(lambda < maxL) maxL = lambda, maxpos = i;
					flg = 0; 
				}
			}
			if(flg) break;
			int g = a[maxpos + 1] + a[maxpos - 1] - a[maxpos];
			sum = sum - a[maxpos] + g; a[maxpos] = g;
		}	
		_rep(i, 1, n) q = q + a[i] * a[i];
		writesp(1ll * n * q - 1ll * sum * sum, '\n');
	}	
	return 0;
}


