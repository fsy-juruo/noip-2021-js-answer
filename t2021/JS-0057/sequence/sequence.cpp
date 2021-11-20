//start:10:06
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N=41,M=111;
int dp[M][N][N][41],val[M][32],c[M][M];
#define dp(a,b,c,d) dp[a][b][c][d]
const int mod=998244353;
void add(int &x,int y){
	x=(x+y)%mod;
} 
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=0;i<=m+6;i++){
		val[i][0]=1;
		if (i<=m) cin >> val[i][1]; else val[i][1]=1;
		for (int j=1;j<=40;j++) val[i][j]=val[i][j-1]*val[i][1]%mod;
	}
//	for (int i=0;i<=m;i++){
//		for (int j=0;j<=5;j++) cout << val[i][j] << ' ';cout << endl;
//	}
	c[0][0]=1;
	for (int i=1;i<=n;i++){
		c[i][0]=1;
		for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
//	for (int i=0;i<=n;i++){
//		for (int j=0;j<=n;j++) cout << c[i][j] << ' ';cout << endl;
//	}
	for (int j=0;j<=n;j++) dp(0,j,j%2,j)=val[0][j];
	for (int i=1;i<=m+6;i++) for (int j=0;j<=n;j++) for (int p=0;p<=(i>m?0:(n-j));p++) for (int t=0;t<=k;t++)
	for (int mask=0;mask<=31;mask++){
		int mask1=mask/2+p;
		add(dp(i,j+p,t+mask1%2,mask1),dp(i-1,j,t,mask)*c[j+p][p]%mod*val[i][p]%mod);
	}
//	for (int i=0;i<=m+6;i++) for (int j=0;j<=n;j++) for (int t=0;t<=k;t++) for (int mask=0;mask<=31;mask++){
//		if (dp(i,j,t,mask)) cout << i << ' ' << j << ' ' << t << ' ' << mask << ':' << dp(i,j,t,mask) << endl;
//	}
	int res=0;
	for (int i=1;i<=k;i++) add(res,dp(m+6,n,i,0));
	cout << res << endl;
	return 0;
}
