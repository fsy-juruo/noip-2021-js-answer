#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 998244353;
#define rep(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(int (i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(int (i)=(j);(i)>=(k);(i)--)
#define sit set<int>::iterator
#define mit map<int,int>::iterator
#define pb push_back
#define pii pair<int,int>
#define mpr make_pair
#define check(x) if(x>=mod) x-=mod
typedef long long ll;
int n,m,v[110],k;
int dp[110][20][35][35],C[35][35],pw[110][35];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	C[0][0] = 1;
	rep(i,1,30) rep(j,0,i) {
		C[i][j] = C[i - 1][j];
		if(j) {
		C[i][j] += C[i - 1][j - 1];check(C[i][j]);} 
	}
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,m) scanf("%d",v+i);
	rep(i,0,m) {
		pw[i][0] = 1;
		rep(j,1,n) pw[i][j] = (ll)pw[i][j - 1] * v[i] % mod;
	}
	rep(i,m+1,m+7) pw[i][0] = 1;
	dp[0][0][0][0] = 1;
	rap(i,0,m+7) {
		rep(j,0,n/2) {
			rep(o,0,k) {
				rep(l,0,n) {
					//if(dp[i][j][o][l]) printf("%d %d %d %d %d\n",i,j,o,l,dp[i][j][o][l]);
					int lim = (i > m) ? 0 : n - l;
					rep(ch,0,lim) {
						int &res = dp[i + 1][(j + ch) / 2][o + (j + ch) % 2][l + ch];
						res += (ll)dp[i][j][o][l] * C[n - l][ch] % mod * pw[i][ch] % mod;
						check(res);
					}
				}
			}
		}
	}
	int ans = 0;
	rep(i,0,k) {
		ans += dp[m + 7][0][i][n];
		check(ans);
	}
	printf("%d\n",ans);
	return 0;
}
