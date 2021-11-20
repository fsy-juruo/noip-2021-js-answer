#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int sum=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+ch-48;ch=getchar();}
	return sum*f;
}
const int Mod=998244353;
int a[105];
int gs[500005];
int f[35][500005];
int ans=0;
inline int cont(int x)
{
	int gs=0;
	while(x)
	{
		if(x&1)gs++;
		x>>=1;
	}
	return gs;
}
int n,m,k;
int v;
int yy;
int tong[65];
int tnng[65];
bool pd()
{
	int GS=0;
	for(int i=0;i<=m+5;i++)tnng[i]=tong[i];
	for(int i=0;i<=m+5;i++)
	{
		if(tong[i]&1) GS++;
		tong[i+1]+=(tong[i]>>1);
	}
	for(int i=0;i<=m+5;i++)tong[i]=tnng[i];
	if(GS<=k)return 1;
	return 0;
}
void Dfs(int now,int nw)
{
//	cout<<now<<" "<<nw<<endl;
	if(now>n)
	{
		if(pd())
		{
			ans+=nw;
			ans%=Mod;
		}
		return;
	}
	for(int i=0;i<=m;i++)
	{
		tong[i]++;
		Dfs(now+1,nw*a[i]%Mod);
		tong[i]--;
	}
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=500000;i++)gs[i]=cont(i);
	for(int i=0;i<=m;i++)a[i]=read();
	if(n==5&&m==50)
	{
		Dfs(1,1);
		cout<<ans<<endl;
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n*(1<<m);j++)
		{
			for(int k=0;k<=m;k++)
			{
				if((1<<k)>j)continue;
				f[i][j]+=f[i-1][j-(1<<k)]*a[k];
				f[i][j]%=Mod;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n*(1<<m);i++)
	{
		if(cont(i)<=k)
		{
			ans+=f[n][i];
			ans%=Mod;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
/*
5 1 1
2 1
*/
