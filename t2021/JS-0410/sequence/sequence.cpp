#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long v[110];
long long f[110][31][31][31];
int popcnt[110];
long long C[110][110];

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int n, m, K;
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 0; i <= m; i++){
		scanf("%lld", &v[i]);
	}
	for (int i = 0; i <= n; i++){
		int t = i;
		while (t){
			if (t & 1) popcnt[i]++;
			t >>= 1;
		}
	}
	C[0][0] = 1;
	for (int i = 1; i <= 30; i++){
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	f[0][0][0][0] = 1;
	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++){
			for (int k = 0; k <= n; k++){
				for (int l = 0; l <= K; l++){
					long long qaq = 1;
					for (int chen = 0; chen <= n; chen++){
						if (j == 0){
							f[i + 1][chen][chen >> 1][chen & 1] += (f[i][j][k][l] * qaq % MOD) * C[n][chen];
							f[i + 1][chen][chen >> 1][chen & 1] %= MOD;
						}
						else{
							if (j + chen > n) break;
							int ran = k;
							ran += chen;
							if (l + (ran & 1) <= K){
								f[i + 1][j + chen][ran >> 1][l + (ran & 1)] += (f[i][j][k][l] * qaq % MOD) * C[n - j][chen];
								f[i + 1][j + chen][ran >> 1][l + (ran & 1)] %= MOD;	
							}
						}
						qaq = (qaq * v[i]) % MOD;
					}	
				}
			}
		}
	}
//	for (int i = 0; i <= m + 1; i++){
//		for (int j = 0; j <= n; j++){
//			for (int k = 0; k <= n; k++){
//				for (int l = 0; l <= K; l++){
//					cout << i << " " << j << " " << k << " " << l << " *" << f[i][j][k][l] << endl;	
//				}
//			}
//		}
//	}
	long long ans = 0;
	for (int k = 0; k <= n; k++){
		for (int l = 0; l <= K; l++){
			if (popcnt[k] + l <= K) ans += f[m + 1][n][k][l];
			ans %= MOD;
		}
	}
	printf("%lld", ans);
	return 0;
}
/*
5 1 1
2 1
ans: 40

8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699
ans: 642171527
*/
