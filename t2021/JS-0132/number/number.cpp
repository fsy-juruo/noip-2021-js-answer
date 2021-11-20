#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5, M = 8e5 + 5;
int T, z, n, m, ADD, d[N], num[M];
bool seven (int x) {
	while (x) {
		if (x % 10 == 7)
			return true;
		x /= 10;
	}
	return false;
}
int read () {
	char ch = getchar ();
	int ret = 0;
	while (ch < '0' || ch > '9')
		ch = getchar ();
	while (ch >= '0' && ch <= '9') {
		ret = ret * 10 + (int)(ch) - (int)('0');
		ch = getchar ();
	}
	return ret;
}
void print (int x) {
	if (x < 10)
		putchar ((char)(x + (int)('0')));
	else {
		print ((int)(x / 10));
		putchar ((char)((int)(x % 10) + (int)('0')));
	}
	return ;
}
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	for (int i = 1; i <= N - 5; i ++)
		if (seven (i) && !d[i])
			for (int j = i; j <= N - 5; j += i)
				d[j] = 1;
	for (int i = 1; i <= N - 5; i ++)
		if (!d[i])
			num[++ ADD] = i;
	num[++ ADD] = (1e7) + 1;
	T = read ();
	for (int i = 1; i <= T; i ++) {
		z = read ();
		if (d[z]) {
			puts ("-1");
			continue ;
		}
		int l = 1, r = ADD, mid = (2 + ADD) >> 1;
		while (!(num[mid] <= z && z < num[mid + 1])) {
			if (num[mid] <= z)
				l = mid;
			else
				r = mid - 1;
			mid = (l + r + 1) >> 1;
		}
		print (num[mid + 1]);
		puts ("");
	}
	return 0;
}

