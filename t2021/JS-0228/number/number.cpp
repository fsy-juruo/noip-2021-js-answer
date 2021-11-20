// 70
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define mp make_pair
typedef long long ll;
template <class T>
T read(T& x) {
	x = 0; T sign = 1, ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') { sign = -1, ch = getchar(); }
	while(isdigit(ch)) {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	x *= sign;
	return x;
}
const int N = 12000020;
bool have_7[N], ill_7[N];
int num7[N], from[N], len = 0;
bool check(int x) {
	if(x % 7 == 0) return false;
	while(x) {
		if(x % 10 == 7) return false;
		x /= 10;
	}
	return true;
}
void init() {
	for(int i = 1; i <= 1.01e7 + 5; i ++ ) {
		have_7[i] = !check(i);
		if(have_7[i]) {
			len ++ ; num7[len] = i;
		}
	}
	for(int i = 1; i <= len; i ++ ) {
		if(num7[i] % 7 == 0) {
			ill_7[num7[i]] = true;
			continue;
		}
		for(int j = 1; num7[i] * j <= 1.01e7 + 10; j ++ )
			ill_7[num7[i] * j] = true;
	}
	len = 0;
	for(int i = 1; i <= 1.01e7 + 5; i ++ )
		if(!ill_7[i]) { len ++ ; num7[len] = i; }
}
int T, x;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init();
	read(T);
	while(T -- ) {
		read(x);
		if(ill_7[x]) { puts("-1"); continue; }
		int* p = upper_bound(num7 + 1, num7 + 1 + len, x);
		if(*p == x) p ++ ;
		printf("%d\n", *p);
	}
	return 0;
}

