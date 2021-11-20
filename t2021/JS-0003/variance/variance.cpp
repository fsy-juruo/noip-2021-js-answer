#include<bits/stdc++.h>
#define fz0g(i,n) for((i)=0;(i)<=(n);(i)++)
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for((i)=(n);(i)>=1;(i)--)
using namespace std;
void read(int &x)
{
	int s=0,f=1;char c;
	while((c=getchar())>'9'||c<'0') if(c=='-') f=-1;
	s=(c&15);
	while((c=getchar())>='0'&&c<='9') s=s*10+(c&15);
	x=s*f;
}
int n,m,i,j,a[10005],sum[10005];
long long ans=0x3f3f3f3f3f3f3f3fll;
long long dp[2][500005];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);fz1(i,n)read(a[i]);
	if(n==1){puts("0");return 0;}
	fz1(i,n-1) a[i]=a[i+1]-a[i];a[n]=0;
	sort(a+1,a+n);
	fz1(i,n-1) sum[i]=sum[i-1]+a[i];
	memset(dp,0x3f,sizeof(dp));
	int t=1;while(t+1<n&&a[t+1]==0) t++;
	fz0g(i,sum[n-1]*n) dp[t&1][i]=1ll*i*i+1ll*(a[1]*n-i)*(a[1]*n-i)+1ll*min(i,a[1]*n-i)*min(i,a[1]*n-i)*(t-1);
	for(i=t+1;i<=n-1;i++){
		fz0g(j,sum[n-1]*n){
			dp[i&1][j]=dp[(i-1)&1][j]+1ll*(sum[i]*n-j)*(sum[i]*n-j);
			if(j>=a[i]*n) dp[i&1][j]=min(dp[i&1][j],dp[(i-1)&1][j-a[i]*n]+1ll*j*j);
			dp[i&1][j]=min(dp[i&1][j],0x3f3f3f3f3f3f3f3fll);
		}
	}
	fz0g(i,sum[n-1]*n){
		ans=min(ans,dp[(n-1)&1][i]);
	}
	cout<<ans/n<<endl;
	return 0;
}
