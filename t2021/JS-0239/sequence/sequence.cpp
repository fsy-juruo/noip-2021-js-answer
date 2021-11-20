#include<bits/stdc++.h>
using namespace std;
const int N=31;
const int M=20;
const int K=31;
const long long MOD=998244353;
int n,m,k;
long long v[M];
long long dp[M][N][M][K][N];
pair<int,int> calc(int x,int y,int z){
	//从x位进位到y位，此时x位上值为z 
	pair<int,int> res;
	res.first=res.second=0;
	for(int i=x;i<y;i++){
		res.first+=(z&1);
		z>>=1;
	} 
	res.second=z;
	return res;
}
int getcnt(int z){
	int res=0;
	while(z){
		res+=(z&1);
		z>>=1;
	}
	return res;
}
long long pw[N],inv[N];
long long qp(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1) res=(res*x)%MOD;
		x=(x*x)%MOD;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	pw[0]=1;
	for(long long i=1;i<=n;i++) pw[i]=pw[i-1]*i%MOD;
	for(int i=0;i<=n;i++) inv[i]=qp(pw[i],MOD-2);
	for(int i=0;i<=m;i++) scanf("%lld",&v[i]);
	dp[0][0][0][0][0]=pw[n];
	int up=log2(m)+1;
	for(int i=0;i<=m+up;i++){
		for(int j=0;j<=n;j++){
			for(int p=0;p<=j;p++){
				for(int q=0;q<=k;q++){
					for(int x=i;x<=m;x++){//新一个a的值为x 
					    for(int y=0;y<=j;y++){
					    	pair<int,int> res=calc(i,x,p);
					    	if(x==i) dp[x][j+1][res.second+1][q+res.first][y+1]=(dp[x][j+1][res.second+1][q+res.first][y+1]+dp[i][j][p][q][y]*v[x])%MOD;
					    	else dp[x][j+1][res.second+1][q+res.first][1]=(dp[x][j+1][res.second+1][q+res.first][1]+((dp[i][j][p][q][y]*v[x])%MOD)*inv[y]%MOD)%MOD;
						}
					}
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=m+up;i++){
		//j=n
		for(int p=0;p<=n;p++){
			for(int q=0;q<=k;q++){
				for(int y=0;y<=n;y++){
					if(q+getcnt(p)<=k&&dp[i][n][p][q]) ans=(ans+dp[i][n][p][q][y]*inv[y])%MOD;
				    //cout<<i<<' '<<p<<' '<<q<<' '<<dp[i][n][p][q]<<endl
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

