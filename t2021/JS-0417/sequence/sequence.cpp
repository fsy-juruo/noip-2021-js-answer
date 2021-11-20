#include<bits/stdc++.h>
#define int long long
#define N 35
#define M 105
using namespace std;
const int mo=998244353;
int n,m,K,ans;
int v[M],p[M][N],C[N][N];
int dp[M][N][N][N];
void add(int &x,int y){
	x=(x+y)%mo;
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>K;m++;
	for(int i=1;i<=m;i++){
		cin>>v[i];
		p[i][0]=1;
		for(int j=1;j<=n;j++) p[i][j]=p[i][j-1]*v[i]%mo;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++){
			if(j==0) C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
		}
	dp[0][0][0][0]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<=K;j++)
			for(int k=0;k<=n;k++)
				for(int l=0;l<=k;l++) if(dp[i][j][k][l]){
					for(int cnt=0;cnt<=n-k;cnt++){
						//choose cnt values on the (i+1) position
						if(j+(l+cnt)%2<=K)
							add(dp[i+1][j+(l+cnt)%2][k+cnt][(l+cnt)/2],dp[i][j][k][l]*p[i+1][cnt]%mo*C[cnt+k][cnt]);
					}
				}
	for(int i=0;i<=K;i++)
		for(int j=0;j<=n;j++){
			if(i+__builtin_popcount(j)<=K) add(ans,dp[m][i][n][j]); 
		}
	cout<<ans<<endl;
	return 0;
}
