#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
inline int read()
{
	int x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*y;
}
int n,m,k,a[105],ans,s[35],c[35][35];
void dfs(int now,int u,int sum,int cnt,int tot)
{				
	sum=sum%mod;
	tot=tot%mod;
	if(now==n) 
	{	
		int tmp=0;
		while(cnt)
		{
			if(cnt%2==1) tmp++;
			cnt/=2;
		}		
		if(tmp==k)
		{
			ans+=sum%mod*tot%mod;
			ans%=mod;
		}
		return;
	}
	int i=u+1;
	if(i>m) return;	
		for(int j=0;j<=n-now;j++)
		{		
			int tmp=1;
			for(int k=1;k<=j;k++) tmp=(tmp%mod*a[i]%mod)%mod;
			dfs(now+j,i,(sum%mod*tmp)%mod,cnt+(j<<i),(tot%mod*c[now+j][j])%mod);
		}
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++)
		a[i]=read();
	c[0][0]=c[1][1]=c[1][0]=1;
	for(int i=2;i<=30;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=30;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	if(n<=8&&m<=9)
	{
		dfs(0,-1,1,0,1);
		printf("%lld",ans%mod);
		return 0;
	}
}
