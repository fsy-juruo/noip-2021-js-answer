#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
void chkmn(int &x,int y){y<x&&(x=y);}
const int N=110,V=45;
int n;
int a[N],A[N];
int p[N];
int dp[2][N*N*V];
signed main(){
	freopen("variance.in","r",stdin);freopen("variance.out","w",stdout);
	cin>>n;
	if(n==1)return puts("0"),0;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=n;i;i--)a[i]-=a[i-1];
	for(int i=1;i<n;i++)a[i]=a[i+1];
	n--;
	sort(a+1,a+n+1);
	if(n<=10){
		for(int i=1;i<=n;i++)p[i]=i;
		int ans=1e18;
		do{
			int res=0;
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)res+=min(i,j)*(n-max(i,j)+1)*a[p[i]]*a[p[j]];
			ans=min(ans,res);
		}while(next_permutation(p+1,p+n+1));
		return cout<<ans<<"\n",0;
	}
	int mx=0;
	for(int i=1;i<=n;i++)A[i]=A[i-1]+a[i],mx=max(mx,a[i])/*,cout<<A[i]<<"?\n"*/;
//	for(int i=1;i<=n;i++)cerr<<a[i]<<" \n"[i==n]; 
	memset(dp,0x3f,sizeof(dp));
	if(n&1)dp[1][a[1]*(n/2+1)]=(n/2+1)*(n/2+1)*a[1]*a[1];
	else dp[1][a[1]*(n/2+1)+a[2]*(n/2)]=dp[1][a[2]*(n/2+1)+a[1]*(n/2)]=(n/2)*(n/2+1)*(a[1]*a[1]+a[2]*a[2])+2*a[1]*a[2]*(n/2)*(n/2);
	int cur=1;
	for(int i=1;i<n+1>>1;i++){
		int x=2*i+1-(n&1),y=2*i+2-(n&1),len=(n+1>>1)-i;
//		cout<<x<<" "<<y<<" "<<len<<":"<<cur<<"?\n";
		memset(dp[cur^1],0x3f,sizeof(dp[cur^1]));
		for(int j=0;j<=n*n*mx;j++)if(dp[cur][j]<inf){
//			cout<<cur<<","<<j<<"\n";
			chkmn(dp[cur^1][j+len*a[x]+(n-len+1)*a[y]],dp[cur][j]+(a[x]*a[x]+a[y]*a[y])*len*(n-len+1)+2*len*len*a[x]*a[y]+2*len*(a[x]*((n+1)*A[x-1]-j)+a[y]*j));
			chkmn(dp[cur^1][j+len*a[y]+(n-len+1)*a[x]],dp[cur][j]+(a[x]*a[x]+a[y]*a[y])*len*(n-len+1)+2*len*len*a[x]*a[y]+2*len*(a[y]*((n+1)*A[x-1]-j)+a[x]*j));
		}
		cur^=1;
//		for(int j=0;j<=n*n*mx;j++)cout<<dp[cur][j]<<" \n"[j==n*n*mx]; 
	}
	cout<<*min_element(dp[cur],dp[cur]+n*n*mx+1)<<"\n";
	return 0;
}
/*1
6 1 2 3 4 5 6
*/
