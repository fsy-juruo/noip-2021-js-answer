#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;

int n,m,a[110],d[110];

signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	m=a[n]-a[1];
	for(int i=1;i<=n-1;i++) d[i]=a[i+1]-a[i];
	sort(d+1,d+n);reverse(d+1,d+n);
	vector<vector<vector<int> > > dp;
	dp.resize(n+1,vector<vector<int> >(m+1,vector<int>(n*m+1,INF)));
	dp[0][0][0]=0;
	int sum=0;
	for(int i=1;i<=n-1;i++){
		sum+=d[i];
		for(int j=0;j<=sum;j++){
			int l=sum-j;
			for(int k=0;k<=n*m;k++){
				if(j>=d[i]&&k>=j) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-d[i]][k-j]+j*j*n);
				if(k>=m-l+d[i]) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k-(m-l+d[i])]+(m-l+d[i])*(m-l+d[i])*n);
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n*m;j++){
			ans=min(ans,dp[n-1][i][j]-j*j);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
