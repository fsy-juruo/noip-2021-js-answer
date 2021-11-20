#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

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

const int N = 105;
const int Mod = 998244353;

int cnt[N];
ull v[N];

int num1( int x ) {
	int tcnt = 0;
	while(x) {
		tcnt += (x&1);
		x >>= 1;
	}
	return tcnt;
} 

ull qpow( int a, int b, int p ) {
	if( b == 0 ) return 1ll;
	if( b == 1 ) return 1ll*a%p;
	ull base = 1ll*a, tans = 1ll;
	while(b) {
		if(b&1) tans *= base;
		base *= base;
		tans %= p;
		b >>= 1;
	}
	return tans;
}

int n, m, k;
ull ans;

void DFS( int sum, int pos, int aim ) {
	if( sum + (n-pos+1) > aim || sum + (n-pos+1)*(1<<m) < aim ) return ;
	if( pos > n ) {
		if( sum != aim ) return ;
		ull t = 1;
		for( int i = 0; i <= m; i++ ) {
			t = t*qpow(v[i],cnt[i],Mod)%Mod;
		} 
		ans = (ans + 1ll*t)%Mod;
		return ;
	}
	for( int i = 0; i <= m; i++ ) {
		cnt[i]++; 
		DFS( sum + (1<<i), pos+1, aim );
		cnt[i]--;
	}
}

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n); read(m); read(k);
	for( int i = 0; i <= m; i++ ) {
		read(v[i]);
	}
	for( int i = n; i <= n*(1<<m); i++ ) {
		if( num1(i) <= k ) {
			DFS( 0, 1, i );
		}
	}
	printf("%llu\n",ans);
	return 0;
} 
