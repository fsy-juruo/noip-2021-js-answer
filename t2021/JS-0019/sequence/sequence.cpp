#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define N 33
#define M 110
#define ll long long
#define mod 998244353
using namespace std;

int n, m, K;
ll v[M], mul[M][N];
ll dp[N][M][N][N], fact[N], inv[N];

ll qpow(ll a, int b){
	ll ret = 1;
	for(; b; b >>= 1){ if(b&1) (ret *= a) %= mod; (a *= a) %= mod; }
	return ret;
}

void prework(){
	fact[0] = 1;
	rep(i,1,n) fact[i] = fact[i-1] * i % mod;
	inv[n] = qpow(fact[n], mod-2);
	per(i,n-1,0) inv[i] = (inv[i+1] * (i+1)) % mod;
	rep(i,m+2,m+6) mul[i][0] = 1;
	rep(i,1,m+1){
		mul[i][0] = 1;
		rep(j,1,n) mul[i][j] = (mul[i][j-1] * v[i]) % mod;
	}
}

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin>>n>>m>>K;
	rep(i,1,m+1) cin>>v[i];
	
	prework();
	dp[0][0][0][0] = 1;
	rep(num,0,n) rep(i,0,m+5) rep(j,0,n) rep(k,0,K){
		if(dp[num][i][j][k]) rep(l,0,n-num){
			int tk = k + (l+j)%2, tj = (l+j)/2;
			(dp[num+l][i+1][tj][tk] += dp[num][i][j][k] * mul[i+1][l] % mod * inv[l]) %= mod;
		}
	}
	ll ans = 0;
	rep(k,0,K) (ans += dp[n][m+5][0][k]) %= mod;
	(ans *= fact[n]) %= mod;
	cout<< ans <<endl;
	return 0;
}
/*
5 1 1
2 1
*/













