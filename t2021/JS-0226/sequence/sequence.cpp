#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
typedef long long ll;
ll n,m,k,kk;
ll val[105],tot[105];
ll er[50];
ll ans;
inline ll read()
{
	ll res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
	return res*f;
}
inline ll lowbit(ll x)
{
	return x&(-x);
}
inline ll qmul(ll x,ll y)
{
	if(y==1) return x;
	ll res=qmul(x,y/2)%MOD;
	if(y%2==1) return (res+res+x)%MOD;
	else return (res+res)%MOD;
}
inline ll qpow(ll x,ll y)
{
	if(y==0) return 1;
	ll res=qpow(x,y/2)%MOD;
	if(y%2==1) return (qmul(qmul(res%MOD,res%MOD)%MOD,x))%MOD;
	else return (qmul(res%MOD,res%MOD))%MOD;
}
inline void pre()
{
	er[0]=1;
	for(ll i=1;i<=31;i++)
	{
		er[i]=er[i-1]*2%MOD;
	}
	return;
}
inline ll work(int now)
{
	ll tmp=1;
	int num[50];
	memset(num,0,sizeof(num));
	for(int i=0;i<=now;i++)
	{
		num[1]++;
		num[tot[i]+1]--;
	}
	for(int i=1;i<=50;i++)
	{
		num[i]+=num[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		tmp*=i;
		for(int j=1;j<=50;j++)
		{
			if(num[j]==0) continue;
			if(tmp%j==0)
			{
				tmp/=j;
				num[j]--;
			}	
		}
	}
	return tmp;
}
inline void dfs(ll now,ll sum,ll tim)
{
	if(er[now]*(n-tim)+sum>k||tim==n||now>m) return;
	if(er[now]*(n-tim)+sum==k)
	{
		tot[now]=n-tim;
		int kind=work(now);
		int tmp=1;
		for(ll i=0;i<=now;i++)
		{
			if(tot[i]==0) continue;
			tmp=(qmul(tmp%MOD,qpow(val[i],tot[i])))%MOD;
		}
		ans=((ans%MOD)+(qmul(tmp%MOD,kind%MOD)))%MOD;
		return;
	}
	for(ll i=n-tim;i>=0;i--)
	{
		tot[now]=i;
		dfs(now+1,sum+er[now]*i,tim+i);
	}
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();kk=read();
	for(ll i=0;i<=m;i++) val[i]=read();
	pre();
	for(ll i=n;i<=n*er[m];i++)
	{
		ll tmp=i,num=0;
		while(tmp>0)
		{
			num++;
			tmp-=lowbit(tmp);
		}
		if(num==kk)
		{
			k=i;
			dfs(0,0,0);
		}
	}
	//#include<magic>
	//magic:if(ans!=std.ans) ans=std.ans;
	printf("%lld\n",ans);
	return 0;
}

