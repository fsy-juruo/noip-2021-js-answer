#include<bits/stdc++.h>
#define lyx 998244353
using namespace std;
long long n,m,k,a[20],f[50][500005],ans;
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	memset(f,0,sizeof(f));
	for(int i=0;i<=m;i++)cin>>a[i];
	for(int i=0;i<=m;i++)
		f[1][(1<<i)]=a[i];
	for(int i=2;i<=n;i++)
		for(int j=1;j<=(1<<(m+5));j++)
			for(int k=0;k<=m;k++)
				f[i][j]=(f[i][j]+f[i-1][j-(1<<k)]*a[k]%lyx)%lyx;
	ans=0;
	for(int i=1;i<=(1<<(m+5));i++) {
		int t=i,cnt=0;
		while(t!=0) {
			cnt+=(t&1);
			t=t>>1;
		}
		if(cnt<=k)ans=(ans+f[n][i])%lyx;
	}
	cout<<ans%lyx<<endl;
}
