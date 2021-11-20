#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
const int MOD = 998244353;

il ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
} 

ll n, m, k;
ll ans = 0;
ll pow_2[65], f[110], v[105];

bool sapar(int x, int k){
	while(x > 0){
		int m = 1;
		while(m <= x) m *= 2;
		m /= 2;
		x -= m;
		k--;
	}
	if(k >= 0) return 1;
	else return 0;
}

ll c(int r, int m){
	double res = 1;
	for(int i = r; i > 0; i--){
		res *= 1.0 * (m - r + i) / i;
	}
	return (ll) res;
}

void dfs(ll cap, ll x, ll sum){
	//±ß½çÅÐ¶¨
	if(x > m) return;
	if(sum > pow_2[m] * n) return;
	
	for(int i = 0; i <= cap; i++){
		//if(x == 1) cout << i << " " << sum << endl;
		f[x] = i; sum += pow_2[x]*i;
		//if(x == 0) cout << i << " " << pow_2[x]*i << endl;
		if(cap - i == 0){
			if(sum < n) return;
			if(sapar(sum, k)){	
				//cout << sum << " " << x << endl;//cout << sum << endl;		
				ll cnt = 0, tot = 1, weight = 1;
				for(int i = 0; i <= x; i++){
					tot *= c(f[i], n - cnt); tot %= MOD;
					cnt += f[i];
					weight *= pow(v[i], f[i]); weight %= MOD;
					//cout << v[x] << " " << f[i] << endl;
				}
				ans += tot * weight;
				ans %= MOD;
			}
			return;
		}
		dfs(cap - i, x + 1, sum);
		f[x] = 0;
		sum -= pow_2[x]*i;
	}
}

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	pow_2[0] = 1; pow_2[1] = 2;
	for(ll i = 2; i <= 55; i++) pow_2[i] = pow_2[i-1] * 2;
	
	n = read(); m = read(); k = read();
	for(int i = 0; i <= m; i++) v[i] = read();	
	dfs(n, 0, 0);
	//if(sapar(8, 1)) cout << "ok" << endl;
	//int x = c(2, 5);
		
	printf("%lld\n", (ans % MOD + MOD) % MOD);

	return 0;
}
