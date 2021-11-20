#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=b;a<=c;++a)
#define per(a,b,c) for(register a=b;a>=c;--a)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int Mod=998244353;

ll Pas[200][200];

int n,m,k;
int a[200];
ll v[200];
ll ans=0;
ll tt=0;
inline ll qpow(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1)res=res*a%Mod;
		b>>=1;
		a=a*a%Mod;
	}
	return res;
}

inline void cal()
{
	int s=0,tmp=0;
	ll cnt=1,p=n,mul=1;
	rep(i,0,m){
		if(i!=m)cnt=cnt*Pas[p][a[i]]%Mod;
		mul=mul*qpow(v[i],a[i])%Mod;
		p-=a[i];
	}	
	ans+=cnt*mul%Mod;
	ans%=Mod;
}

inline void dfs(int dep,int s,int sum,int tmp)
{	
	if(sum>k)return;
	if(dep>m)
	{		
		while(tmp)
		{
			sum+=tmp&1;
			tmp>>=1;
		}
		if(sum<=k)cal();
		return;	
	}
	if(dep==m)
	{
		a[dep]=n-s;
		dfs(dep+1,n,sum+((tmp+n-s)&1),(tmp+n-s)>>1);
	}
	else
	{
		rep(i,0,n-s)
		{
			a[dep]=i;
			dfs(dep+1,s+i,sum+((tmp+i)&1),(tmp+i)>>1);
		}
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	Pas[0][0]=1;
	rep(i,1,150)Pas[i][0]=1,Pas[i][i]=1;
	rep(i,2,150)
		rep(j,1,150)Pas[i][j]=(Pas[i-1][j]+Pas[i-1][j-1])%Mod;
	
	scanf("%d%d%d",&n,&m,&k);

	rep(i,0,m)scanf("%lld",&v[i]);
	
	dfs(0,0,0,0);
	printf("%lld\n",ans);
	return 0;
}
/*
30 7 12
1 2 3 4 5 6 7 8
*/
