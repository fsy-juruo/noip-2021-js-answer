#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define inf 1000000007
using namespace std;
const int mxn=100005;
const int mod=998244353;
typedef long long ll;
typedef pair<int,int> pi;
inline int read()
{
	char c=getchar();
	int f=1;
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	int x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int v[105];
int dp[33][33][2050];
int td[33];
inline ll ksm(int a,int m)
{
	if(m==0) return 1;
	if(m==1) return a;
	ll x=ksm(a,m/2);
	x=x*x%mod;
	if(m%2==1) x=x*a%mod;
	return x;
}
void exgcd(int a,int b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
	}
	else
	{
		exgcd(b,a%b,y,x);
		y-=x*(a/b);
	}
}
inline int cnt(int x)
{
	int c=0;
	while(x!=0)
	{
		c+=x%2;
		x/=2;
	}
	return c;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ll x,y;
	int n=read(),m=read(),k=read();
	for(int i=0;i<m;i++)
		v[i]=read();
	td[0]=1;
	td[1]=1;
	for(int i=2;i<=n;i++)
	{
		exgcd(mod,i,x,y);
		if(y<0) y+=mod;
		td[i]=(ll)td[i-1]*y%mod;
	}
	int mxs=ksm(2,n-1);
	for(int i=0;i<=n;i++)
		dp[i][i%2][i/2]=ksm(v[0],i)*td[i]%mod;
	//cout<<dp[5][1][2]<<endl;
	for(int p=0;p<m;p++)
	{
		for(int i=0;i<=n;i++)
			for(int j=0;j<=min(p+1,k);j++)
				for(int s=0;s<=mxs;s++)
				{
					if(dp[i][j][s]!=0)
					{
						//cout<<p<<" "<<i<<" "<<j<<endl;
						for(int k=0;i+k<=n;k++)
						{
							dp[i+k][j+(s%2+k)%2][(s+k)/2]=((ll)dp[i+k][j+(s%2+k)%2][(s+k)/2]+(ll)dp[i][j][s]*ksm(v[p+1],k)*td[k]%mod)%mod;
						}
					}
				}
	}
	ll ans=0;
	for(int j=0;j<=k;j++)
		for(int s=0;s<=mxs;s++)
		{
			if(cnt(s)+j<=k)
				ans=(ans+dp[n][j][s])%mod;
			
		}
	cout<<ans<<endl;
	return 0;
}


