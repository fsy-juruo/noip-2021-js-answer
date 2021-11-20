#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define rep(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(int (i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(int (i)=(j);(i)>=(k);(i)--)
#define sit set<int>::iterator
#define mit map<int,int>::iterator
#define pb push_back
#define pii pair<int,int>
#define mpr make_pair
int n,a[100005],d[100005],sum[100005];
vector<ll> dp[405][405];
void chmin(ll &x,ll y){if(x > y) x = y;
}
void expand(int x,int y,int len){
	fflush(stdout);
	if(dp[x][y].size() > len) return;
	int u = dp[x][y].size();
	dp[x][y].resize(len + 1);
	rep(i,u,len) dp[x][y][i] = inf;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	//vector<int> v;v.pb(1);v.pb(2);v.resize(4);
	//rap(i,0,v.size()) printf("%d ",v[i]);puts("");
	//v.resize(1);rap(i,0,v.size()) printf("%d ",v[i]);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,1,n-1) d[i] = a[i + 1] - a[i];
	sort(d+1,d+n);
	//rep(i,1,n-1) printf("%d ",d[i]);puts("");
	rep(i,1,n-1) sum[i] = sum[i - 1] + d[i];
	n--;
	rep(i,1,n) {
		expand(i,i,d[1] * i);
		dp[i][i][d[1] * i] = (ll)d[1] * d[1] * i * (n + 1 - i);
	}
	rep(len,1,n) rep(l,1,n-len+1) {
		int r = l + len - 1;
		rap(s,0,dp[l][r].size()){
			int sum1 = sum[len];
			if(dp[l][r][s] == inf) continue;
			//printf("%d %d %d %lld\n",l,r,s,dp[l][r][s]);
			if(l > 1) {
				ll cost = ll(l - 1) * (n - l + 2) * d[len + 1] * d[len + 1];
				expand(l - 1, r, s + d[len + 1] * (l - 1));
				chmin(dp[l - 1][r][s + d[len + 1] * (l - 1)], dp[l][r][s] + cost + ((ll)sum1 * 2ll * (l - 1) * (n + 1) - 2ll * (l - 1) * s) * d[len + 1]);
			}
			if(r < n) {
				ll cost = ll(r + 1) * (n - r) * d[len + 1]  *d[len + 1];
				expand(l, r + 1, s + d[len + 1] * (r + 1));
				chmin(dp[l][r + 1][s + d[len + 1] * (r + 1)], dp[l][r][s] + cost + 2ll * (n - r) * s * d[len + 1]);
			}
		}
	}
	ll ans = inf;
	rap(i,0,dp[1][n].size()) ans = min(ans, dp[1][n][i]);
	printf("%lld\n",ans);
	return 0;
}
