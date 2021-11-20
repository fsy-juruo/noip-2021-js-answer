#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std; 
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=10005;
int B=1600;
int dp[2][305][3205];
int n,a[Maxn],b[Maxn],A,N;
void Ckmin(int &x,int y){
	if (y<x) x=y;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	A=(a[n]+1)/2;
	for (int i=1;i<n;i++){
		if (a[i]!=a[i+1]) b[++N]=a[i+1]-a[i];
	}
	sort(b+1,b+N+1);
	
	int tot=0;
	for (int i=0;i<=A;i++){
		for (int j=0;j<=(B+B);j++){
			dp[0][i][j]=2e9;
		}
	}
	dp[0][0][B]=0;
	for (int ii=1;ii<=N;ii++){
		tot+=b[ii];
		int i=ii&1;
		for (int j=0;j<=A;j++){
			for (int k=0;k<=B+B;k++){
				dp[i][j][k]=1e9;
			}
		}
		
		for (int j=0;j<=A;j++){
			for (int k=0;k<=B+B;k++){
				if (dp[i^1][j][k]!=1e9){
					if (k-(tot-j)>=0) Ckmin(dp[i][j][k-(tot-j)],dp[i^1][j][k]+(tot-j)*(tot-j));
					
					if (j+b[ii]<=A && k+j+b[ii]<=B+B) Ckmin(dp[i][j+b[ii]][k+(j+b[ii])],dp[i^1][j][k]+(j+b[ii])*(j+b[ii]));
				}
			}
		}
	}
	LL res=1e18;
	for (int j=0;j<=A;j++){
		for (int k=0;k<=B+B;k++){
			if (dp[(n-1)&1][j][k]==1e9) continue;
			LL ans=1ll*dp[(N)&1][j][k]*n-1ll*(k-B)*(k-B);
			
			res=min(res,ans);
		}
	}
	printf("%lld\n",res);
	return 0;
}
