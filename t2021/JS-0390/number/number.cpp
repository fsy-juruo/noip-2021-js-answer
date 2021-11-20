#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned LL
#define open(name) freopen(#name".in", "r", stdin),\
				   freopen(#name".out", "w", stdout)
using namespace std;

const int N = 1e7 + 5; 

template < typename T >
inline void readin(T &x) {
	x = 0;
	register int f = 1;
	register char ch = getchar ();
	while (!isdigit (ch) && ch != '-')
		ch = getchar ();
	if (ch == '-')
		f = -1, ch = getchar();
	do {
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	while (isdigit (ch));
	x *= f;
}

bool P[N];

inline bool HasSeven (int x) {
	while (x) {
		if (x % 10 == 7)
			return true;
		x /= 10;
	}
	return false;
}

void init () {
	for (register int i = 1; i <= N; ++i)
		if (HasSeven (i) && !P[i])
			for (register int j = 1; j * i <= N; ++j) {
				P[i * j] = true;
			}
}

int main () {
	open(number);
	int T;
	readin (T);
	init ();
	while (T--) {
		int a;
		readin (a);
		if (P[a])
			printf ("-1\n");
		else {
			for (int i = a + 1; i <= N; ++i) {
				if (!P[i]) {
					printf ("%d\n", i);
					break;
				}
			} 
		}
	}/*
	for (int i = 1; i <= T; ++i) {
		if (!P[i])
			printf ("%d\n", i);
	}*/
	return 0;
}


