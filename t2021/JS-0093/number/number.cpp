#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf = 1e7+10;

template < typename _T >

inline void read( _T &x ) {
	int t = 1; x = 0;
	char c = getchar();
	while( !isdigit(c) && c != '-' ) c = getchar();
	if( c == '-' ) { t = -1; c = getchar(); }
	while( isdigit(c) ) { x = (x<<3)+(x<<1)+c-'0'; c = getchar(); }
	x *= t;
	return ;
}

int vis[inf], ans[inf];

bool check( int x ) {
	while(x) {
		if( x%10 == 7 ) return true;
		x /= 10;
	}
	return false;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for( int i = 1; i <= inf; i++ ) {
		if( vis[i] ) continue;
		if( check(i) ) {
			for( int j = i; j <= inf; j += i ) vis[j] = 1;
		}
	}
	int tans = inf;
	for( int i = inf-1; i > 0; i-- ) {
		if( vis[i] ) ans[i] = -1;
		else { ans[i] = tans; tans = i; }
	}
	int T, n;
	read(T);
	while( T-- ) {
		read(n);
		printf("%d\n",ans[n]);
	}
	return 0;
} 
