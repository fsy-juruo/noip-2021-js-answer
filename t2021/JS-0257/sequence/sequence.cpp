#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
template<typename tn>void read(tn &n) {
	tn x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	n=x*f;
}
int n,m,k;
int add;
int lg[101];
int v[101];
int f[41][31];
int dp[41][41][31][31];
void log(int x) {
	lg[0]=-1;
	for(int i=1; i<=m; ++i)
		lg[i]=lg[i/2]+1;
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=0; i<=m; ++i)
		read(v[i]);
	log(m);
	for(int i=0; i<=n; ++i)
		f[i][1]=1;
	for(int i=1; i<=n+lg[m]; ++i)
		for(int j=2; j<=n; ++j)
			for(int num=1; num<=j/2; ++num)
				f[i][j]=(f[i][j]+f[i-1][num]*f[i-1][j-num])%mod;
	for(int i=0; i<=n+lg[m]; ++i)
		for(int j=1; j<=n; ++j)
			dp[i][i][1][j]=f[i][j];
	for(int i=0;i<=n+lg[m];++i)
		for(int j=0;j<=n+lg[m];++j)
			dp[i][j][0][0]=1;
	for(int l=0; l<=n+lg[m]; ++l)
		for(int r=l+1; r<=n+lg[m]; ++r)
			for(int num=0; num<=k; ++num) {
				if(num>r-l+1)
					break;
				for(int tot=1; tot<=n; ++tot)
					for(int i=1; i<=tot; ++i)
						dp[l][r][num][tot]=(dp[l][r][num][tot]+(ll)(l-1<0?0:dp[l-1][r][num-1][i])*(tot-i==0?1:f[l][tot-i])+(ll)dp[l][r-1][num-1][i]*(tot-i==0?1:f[r][tot-i]))%mod;
			}
	int ans=0;
	for(int i=0;i<=k;++i)
		ans=(ans+dp[0][n+lg[m]][i][n])%mod;
	printf("%d\n",ans);
	return 0;
}
