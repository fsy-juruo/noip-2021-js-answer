#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e4 + 10;

int n;
int a[N] , b[N];
LL ans , sumh , sump;

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

int main() {

	freopen("variance.in" , "r" , stdin);
	freopen("variance.out" , "w" , stdout);

	read(n);
	
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		sump += 1ll * a[i] * a[i];
		sumh += a[i];
	}
	ans = (1ll * n * sump) - sumh * sumh;
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) b[i] = a[i];
		sump = 1ll * a[1] * a[1] + 1ll * a[n] * a[n];
		sumh = a[1] + a[n];
		for (int j = i; j >= 2; j--) {
			if (b[j + 1] + b[j - 1] - b[j] > b[j]) {
				b[j] = b[j + 1] + b[j - 1] - b[j];
			}
			sump += 1ll * b[j] * b[j];
			sumh += b[j];
		}
		for (int j = i + 1; j < n; j++) {
			if (b[j + 1] + b[j - 1] - b[j] < b[j]) {
				b[j] = b[j + 1] + b[j - 1] - b[j];
			}
			sump += 1ll * b[j] * b[j];
			sumh += b[j];
		}
		chkmin(ans , 1ll * n * sump - sumh * sumh);
		sump = 1ll * a[1] * a[1] + 1ll * a[n] * a[n];
		sumh = a[1] + a[n];
		for (int j = 1; j <= n; j++) b[i] = a[i];
		for (int j = i + 1; j < n; j++) {
			if (b[j + 1] + b[j - 1] - b[j] < b[j]) {
				b[j] = b[j + 1] + b[j - 1] - b[j];
			}
			sump += 1ll * b[j] * b[j];
			sumh += b[j];
		}
		for (int j = i; j >= 2; j--) {
			if (b[j + 1] + b[j - 1] - b[j] > b[j]) {
				b[j] = b[j + 1] + b[j - 1] - b[j];
			}
			sump += 1ll * b[j] * b[j];
			sumh += b[j];
		}
		chkmin(ans , 1ll * n * sump - sumh * sumh);
	}
	
	write(ans , '\n');

	return 0;

}

