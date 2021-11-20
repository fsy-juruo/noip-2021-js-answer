#include<bits/stdc++.h>
#define RE return
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define P pair
#define F first
#define S second
#define ALL(a) a.begin(),a.end()
#define FILL(a,b) memset(a,b,sizeof(a))
#define gmin(a,b) a=min(a,b)
#define gmax(a,b) a=max(a,b)
using namespace std;
void read(int &x){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	x=0;
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-'0',c=getchar();
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void up(int &x,int y){
	if(x==-1||x>y)x=y;
}
int n,a[10005],p[10005];
int dp[2][605][1805];
int num[1205],S=600;
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	int maxi=0;
	FOR(i,1,n)read(a[i]),gmax(maxi,a[i]);
	rep(i,1,n)p[i]=a[i+1]-a[i];
	FOR(i,1,1200)num[i]=(i-S)*(i-S);
	sort(p+1,p+n);
	FILL(dp,-1);
	dp[0][0][0]=0;
	int sum=0;
	int T=0;
	rep(i,1,n){
		T^=1;
		FOR(j,0,sum+p[i])FOR(k,0,maxi*3)dp[T][j][k]=-1;
		FOR(j,0,sum){
			FOR(k,0,maxi*3)if(dp[T^1][j][k]!=-1){
				int to=k-(j+p[i]);
				if(to<0){
					if(-to<=maxi*3)up(dp[T][sum-j][-to],dp[T^1][j][k]+num[S+j+p[i]]);
				}else if(to<=maxi*3)up(dp[T][j+p[i]][to],dp[T^1][j][k]+num[S+j+p[i]]);
				int tj=j;
				j=sum-j;
				to=-k-(j+p[i]);
				if(to<0){
					if(-to<=maxi*3)up(dp[T][sum-j][-to],dp[T^1][tj][k]+num[S+j+p[i]]);
				}else if(to<=maxi*3)up(dp[T][j+p[i]][to],dp[T^1][tj][k]+num[S+j+p[i]]);
				j=sum-j;
			}
		}
		sum+=p[i];
	}
	int ans=2e9;
	FOR(j,0,sum){
		FOR(k,0,maxi*3)if(dp[T][j][k]!=-1){
			gmin(ans,dp[T][j][k]*n-k*k);
		}
	}
	write(ans);
	RE 0;
}

