#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 123000, mod = 998244353;
int n,m,k,maxn;
int i,j,h;
int cnt[N],b[10],c[10];
ll a[35],dp[35][N],ans,d[N];
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	maxn=(1<<m)*n+1;
	for (i=0;i<=m;i++)
		scanf("%lld",a+i);
	dp[0][0]=1;
	for (i=0;i<maxn;i++)
		cnt[i]=cnt[i>>1]+(i&1);
	for (i=1;i<=n;i++)
		for (j=i-1;j<maxn;j++) {
			if (dp[i-1][j]==0)  continue;
			for (h=0;h<=m;h++)
				if (j+(1<<h)<maxn)  dp[i][j+(1<<h)]+=dp[i-1][j]*a[h]%mod, dp[i][j+(1<<h)]%=mod;
		}	
	for (i=n;i<maxn;i++)
		if (cnt[i]<=k)  ans=(ans+dp[n][i])%mod;
	cout<<ans<<endl;
	return 0;
}
