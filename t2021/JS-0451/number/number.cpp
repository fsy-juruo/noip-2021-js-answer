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
const int N = 1e7 + 10;
bool flag[N + 5];
int ans[N + 5];
bool check(int x) {
	while(x) {
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for(int i = 1; i <= N; i++) {
		if(flag[i]) continue;
		if(check(i)) {
			for(int j = 1; j * i <= N; j++) {
				flag[i * j] = 1;
			}
		}
	}
	for(int i = N - 5; i >= 1; i--) {
		if(flag[i]) ans[i - 1] = ans[i];
		else ans[i - 1] = i;
	}
	int T;
	read(T);
	while(T--) {
		int x;
		read(x);
		if(flag[x]) puts("-1");
		else {
			write(ans[x]);
			puts("");
		}
	}
	return 0;
}

