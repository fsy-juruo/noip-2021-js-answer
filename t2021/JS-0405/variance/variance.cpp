#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
void update(int &a, int b){
	if(b < a)
		a = b;
}

int n;
int dp[32777][444];
int a[22];
int diff[22];

int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n)
		cin >> a[i];
	rep(i, n - 1)
		diff[i] = a[i + 1] - a[i];
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	rep(i, n - 1){
		rep(mask, 1 << (n - 1)){
			if(__builtin_popcount(mask) != i)
				continue;
			int val = 0;
			rep(j, n - 1)
				if(mask & (1 << j))
					val += diff[j];
			rep(sum, 401){
				if(dp[mask][sum] >= 0x3f3f3f3f)
					continue;
//				cout << mask << " " << val << " " << sum << ": " << dp[mask][val][sum] << endl; 
				rep(nxt, n - 1){
					if(!((mask >> nxt) & 1)){
						update(dp[mask | (1 << nxt)][sum + val + diff[nxt]], dp[mask][sum] + (val + diff[nxt]) * (val + diff[nxt]));
					}
				}
			}
		}
	}
	int S = (1 << (n - 1)) - 1;
	int ans = 0x3f3f3f3f;
	rep(sum, 401){
		if(dp[S][sum] < 0x3f3f3f3f) 
			update(ans, n * dp[S][sum] - sum * sum);
	}
	cout << ans << endl;
	return 0;
}
