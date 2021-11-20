#include<cstdio>
const long long ZXD=998244353;
int n,m,k,S,cho[110];
long long ans,v[15],fact[35],inv[35],f[35][65000][15];
long long qpow(long long x,int p)
{
	long long ret=1;
	while(p)
	{
		if(p&1) ret=ret*x%ZXD;
		x=x*x%ZXD;
		p>>=1;
	}
	return ret;
}
long long C(int n,int m)
{
	if(n==0) return 1;
	if(m==0) return 1;
	return fact[n]*inv[m]%ZXD*inv[n-m]%ZXD;
}
void prework()
{
	fact[0]=inv[0]=1;
	for(int i=1;i<35;i++)
	{
		fact[i]=fact[i-1]*i%ZXD;
		inv[i]=qpow(fact[i],ZXD-2);
	}
	return ;
}
long long calc()
{
	long long ret=1;
	int rest=n;
	for(int i=0;i<=m;i++)
	{
		ret=ret*C(rest,cho[i])%ZXD;
		ret=ret*qpow(v[i],cho[i])%ZXD;
		rest-=cho[i];
	}
	return ret;
}
bool check(int x)
{
	int cnt=0;
	while(x)
	{
		cnt+=(x&1);
		x>>=1;
	}
	if(cnt>k) return true;
	return false;
}
long long tt;
long long dfs(int step,int now,int last)
{
//	printf("%d %d %d\n",step,now,last);
	if(step==n)
	{
		if(now==0)
		{
			long long tmp=calc();
			ans=(ans+tmp)%ZXD;
//			for(int i=0;i<=m;i++) printf("%d ",cho[i]);
//			printf(" : %lld %lld\n",tt,tmp);
			return tmp;
		}
		return 0;
	}
	if(now<n-step) return 0;
	if(now-(n-step)*(1<<last)>0) return 0;
	long long tot=0;
	for(int i=0;i<=m;i++)
	{
		if((1<<i)>now||i>=last) break;
		for(int j=1;now-j*(1<<i)>=0&&step+j<=n;j++)
		{
//			if(f[step+j][now-j*(1<<i)][i]!=0)
//			{
//				tot=(tot+f[step+j][now-j*(1<<i)][i])%ZXD;
//				ans=(ans+f[step+j][now-j*(1<<i)][i])%ZXD;
//				continue;
//			}
			cho[i]=j;
			f[step+j][now-j*(1<<i)][i]=dfs(step+j,now-j*(1<<i),i);
			tot=(tot+f[step+j][now-j*(1<<i)][i])%ZXD;
			cho[i]=0;
		}
	}
	return tot;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	prework();
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%lld",&v[i]);
	for(S=n;S<=n*(1<<m);S++)
	{
		if(check(S)) continue;
		tt=S;
		dfs(0,S,m+1);
	}
	printf("%lld\n",ans);
	return 0;
}
