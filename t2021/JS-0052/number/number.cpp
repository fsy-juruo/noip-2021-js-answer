#include<bits/stdc++.h>
using namespace std;
#define xh(i,a,b) for(int i=(a);i<(b);++i)
#define ll long long
template <typename T>
inline T rd(T& a) {
	a = 0;
	bool f = 1;
	char c = getchar();
	while(c > '9' || c < '0') {
		f = c - '-';
		c = getchar();
	}
	while(c <= '9' && c >= '0') {
		a = a * 10 + c - '0';
		c = getchar();
	}
	a = f ? a : -a;
	return a;
}
int t, q;
char c[10000100];
bool cc(ll a) {
	if(c[a] != 0) {
		return c[a] - 1;
	}
	for(int i = a; i; i /= 10)
		if(i % 10 == 7) {
			c[a] = 2;
			return 1;
		}
	return 0;
}
bool check(int a) {
	if(cc(a)) {
		c[a] = 2;
		return 1;
	}
	for(int i = 2; i <= (a >> 1); ++i) {
		if(a % i == 0 && cc(i) == 1) {
			c[a] = 2;
			return 1;
		}
	}
	c[a] = 1;
	return 0;
}
inline void hbh(int& a) {
	int m = 0, tm = 1;
	for(int i = 0, j = a; j; ++i, j /= 10)
		if(j % 10 == 7)m = i;
	for(int i = 0; i < m; ++i, tm *= 10);
	if(m >= 1) {
		a = a + tm - (a % tm);
	} else ++a;
	return;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	rd(t);
	xh(i, 0, t) {
		rd(q);
		if(check(q)) {
			puts("-1");
			continue;
		}
		++q;
		while(check(q))
			hbh(q);
		printf("%d\n", q);
	}
	return 0;
}



