/*
my blog:
www.cnblogs.com/luoyj506
welcome to visit
*/
#include<bits/stdc++.h>
using namespace std;

inline long long read(){
	long long s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-')
			w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		s = s * 10 + ch - '0';
	return s * w;
}

inline void fre(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
}

const int mo = 998244353;
long long n, m, k;
long long v[233], a[233];
long long C[33][33];
long long ans;

inline void init (){
	C[0][0] = 1;
	for (int i = 1; i <= 30; i++){
		C[i][0] = 1, C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i-1][j-1] + C[i-1][j];
	}
}

bool check(){
	int cnt = 0;
	for (int i = 0, g = a[0]; i <= m || g; g += a[++i]){
		if (g % 2)
			cnt++;
		g = g / 2;
	}
	return cnt <= k;
}

long long power(long long x, long long y){
	long long res = 1;
	for (; y; y >>= 1){
		if (y & 1) res = (res * x) % mo;
		x = (x*x) % mo;
	}
	return res;
}

inline void dfs(int x, int step){
	if (step == n){
		if (check()){
			long long res = 1, tot = n;
			for (int i = 0; i <= m; i++){
				res = (res * power(v[i], a[i])) % mo;
				res = (res * C[tot][a[i]]) % mo;
				tot -= a[i];
			}
			ans += res;
			ans %= mo;
		}
		return;
	}
	for (int i = x; i <= m; i++){
		a[i]++;
		dfs(i, step+1);
		a[i]--;
	}
}

int main(){
	fre();
	n = read(), m = read(), k = read();
	for (int i = 0; i <= m; i++)
		v[i] = read();
	init();
	dfs(0, 0);
	printf("%lld\n", ans % mo);
	return 0;
}

