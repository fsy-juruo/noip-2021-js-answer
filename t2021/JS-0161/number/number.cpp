#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T&x) {
	x = 0;
	char ch = getchar();
	T flg = 1;
	while ((!isdigit(ch)) && ch != '-') ch = getchar();
	if (ch == '-') ch = getchar(), flg = -1;
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= flg;
}
const int MN = 2e7 + 10;
bool f[MN];
int a[MN], cnt = 0;
bool check (int x) {
	while (x) {
		if (x % 10 == 7) return false;
		x /= 10;
	}
	return true;
}
inline int sfind(int x) {
	int l = 1, r = cnt + 1;
	while (l + 1 < r) {
		int mid = l + r; mid >>= 1;
		if (a[mid] <= x) l = mid;
		else r = mid;
	}
	return a[l + 1];
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= 2e7; i++) {
		if (f[i] == 1) continue;
		if (check(i)) a[++cnt] = i;
		else {
			f[i] = 1;
			for (int j = 2; j * i <= 2e7; j++) {
				f[i * j] = 1;
			}
		}
	}
	int T;
	read(T);
//system("pause");
	while (T--) {
		int x;
		read(x);
		if (f[x]) {
			printf("-1\n");
		}else {
			printf("%d\n", sfind(x));
		}
	}
//	cout<< (sizeof a + sizeof f) / 8 / 1024 / 1024;
	return 0;
}
