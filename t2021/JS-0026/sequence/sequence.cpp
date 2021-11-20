#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int n,m,K,v[110],C[33][33];
int f[110][33][33][33];
int pw[33];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=0;i<33;C[i][0]=1,i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	scanf("%d%d%d",&n,&m,&K),m++;
	for(int i=1;i<=m;i++)scanf("%d",&v[i]);
	f[0][0][0][0]=1;
	for(int i=1;i<=m+6;i++){
		pw[0]=1;
		for(int j=1;j<=n;j++)pw[j]=(ll)pw[j-1]*v[i]%M;
		for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)
			for(int l=0;l<=K;l++)if(f[i-1][j][k][l])
				for(int p=0;k+p<=n;p++){
					if(i>m&&p>0)break;
					(f[i][(j+p)/2][k+p][(j+p)%2+l]+=(ll)f[i-1][j][k][l]*pw[p]%M*C[n-k][p]%M)%=M;
				}
	}
	int ans=0;
	for(int i=0;i<=K;i++)(ans+=f[m+6][0][n][i])%=M;
	printf("%d",ans);
	return 0;
}
