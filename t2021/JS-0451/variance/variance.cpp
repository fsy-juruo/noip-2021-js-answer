#include<bits/stdc++.h>
using namespace std;
inline void read(int &x) {
	int w = 1; char c = getchar(); x = 0;
	while(c < '0' || c > '9') w = (c == '-' ? -1 : 1), c = getchar();
	while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - 48, c = getchar();
	x *= w; return ;
}
inline void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) { putchar(x + 48); return ; }
	write(x / 10); putchar(x % 10 + 48); return ;
}
int n, a[10005], b[10005];
int sum() {
	int s = 0;
	for(int i = 1; i <= n; i++)
		s += a[i];
	int ss = 0;
	for(int i = 1; i <= n; i++)
		ss += (a[i] * n - s) * (a[i] * n - s);
	//cout << ss / n << endl;
	return ss / n;
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	int t = clock();
	srand(time(NULL));
	read(n);
	for(int i = 1; i <= n; i++) {
		read(a[i]);
		b[i] = a[i];
	}
	int ans = INT_MAX;
	for(int i = 1; i <= n; i++) {
		int s = 0;
		for(int j = 1; j <= n; j++) {
			s += a[j];
		}
		for(int j = 2; j < n; j++) {
			if(abs((a[j - 1] + a[j + 1] - a[j]) * n - s) < abs(a[j] * n - s)) {
				s -= a[j];
				a[j] = a[j - 1] + a[j + 1] - a[j];
				s += a[j];
			}
		}
		ans = min(ans, sum());
	}
	int x = 0;
	while(1) {
		int l = rand() % (n - 2) + 2;
		while(x == l) l = rand() % (n - 2) + 2;
		a[l] = a[l - 1] + a[l + 1] - a[l];
		ans = min(ans, sum());
		x = l;
		if(clock() - t >= 900) break;
	}
	cout << ans;
	return 0;
}

