#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
void update(ll &a, ll b){
	a += b;
	if(a >= Mod)
		a -= Mod;
}

int n, m, k;
ll v[111];
ll C[33][33];
ll dp[111][33][33][33];

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	rep(i, n + 1)
		C[0][i] = 0, C[i][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
	rep(i, m + 1)
		cin >> v[i];
	dp[0][0][0][0] = 1;
	for(int val = 0; val <= m + 5; val++) for(int cnt = 0; cnt <= n; cnt++) for(int lastcnt = 0; lastcnt <= cnt; lastcnt++) for(int cntsum = 0; cntsum <= k; cntsum++){
		if(!dp[val][cnt][lastcnt][cntsum])
			continue;
		ll nowval = 1;
//		cout << val << " " << cnt << " " << lastcnt << " " << cntsum << ": " << dp[val][cnt][lastcnt][cntsum] << endl; 
		for(int nxtcnt = 0; nxtcnt <= n - cnt; nxtcnt++){
			if(nxtcnt > 0 && val > m)
				break; 
			int nowcnt = lastcnt + nxtcnt;
			if(cntsum + (nowcnt & 1) > k)
				continue;
			update(dp[val + 1][cnt + nxtcnt][nowcnt >> 1][cntsum + (nowcnt & 1)], dp[val][cnt][lastcnt][cntsum] * nowval % Mod * C[n - cnt][nxtcnt] % Mod);
			nowval = nowval * v[val] % Mod;
		}
	}
	ll ans = 0;
	rep(cntsum, k + 1)
		update(ans, dp[m + 6][n][0][cntsum]);
	cout << ans << endl;
	return 0;
}
