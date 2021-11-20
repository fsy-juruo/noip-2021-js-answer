#include<bits/stdc++.h>
using namespace std;

int T, X;
bool hah[11000110];
int val[5300010], a[5300010], num, cnt;

template <typename Tp>
void read(Tp &x) {
	x = 0; int f = 1; char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = - 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}

void get7(int x, int sum, int h7) {
	if (x > 7) {
		if (h7) val[++ cnt] = sum, hah[sum] = 1;
		return ;
	}
	for (int i = 0; i <= 9; ++ i) {
		if (i == 7) {
			get7(x + 1, sum * 10 + i, 1);
		}
		else {
			get7(x + 1, sum * 10 + i, h7);
		}
	}
}

void Euler() {
	for (int i = 1; i <= 10000100; ++ i) {
		if (!hah[i]) a[++ num] = i;
		for (int j = 1; j <= cnt && val[j] * i <= 10000100; ++ j) {
			int x = val[j] * i;
			hah[x] = 1;
			if (i % val[j] == 0) break;
		}
	}
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(T);
	get7(1, 0, 0);
	Euler();
	while (T --) {
		read(X);
		if (hah[X]) {
			printf("-1\n");
			continue;
		}
		int pos = lower_bound(a + 1, a + num + 1, X + 1) - a;
		printf("%d\n", a[pos]);
	}
	return 0;
}
