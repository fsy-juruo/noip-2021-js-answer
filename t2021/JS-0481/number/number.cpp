#include <bits/stdc++.h>
using namespace std;
// 莫看嚣雨扰江尘，鉴镜富明，三五花笑 

const int N = 11000010;
const int XGJDXJ = 11000000;
bool f[N];
int nxt[N];

inline bool valid(int x) {
	while (x) {
		if (x % 10 == 7) 
			return 1;
		x /= 10;
	}
	return 0;
}

void tryd(int n) {
	for (int i = 1; i <= n; i++) if (!f[i] && valid(i))
		for (int j = i; j <= n; j += i)	f[j] = 1;
	int la = 1;
	for (int i = 2; i <= n; i++) 
		if (!f[i]) nxt[la] = i, la = i;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	tryd(XGJDXJ);
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		int x;
		scanf("%d", &x);
		if (!f[x]) printf("%d\n", nxt[x]);
		else printf("-1\n");
	}

	return 0;
}


