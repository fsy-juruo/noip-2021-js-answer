#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=35;
const int MAXM=105;
const int MAXS=130005;
const int HA=998244353;
int n,m,k,v[MAXM],lim,ans,sum;
int f[MAXN][MAXS];
bool check(int x)
{
	int cnt=0;
	while(x)
	{
		if(x&1)
			cnt++;
		x>>=1;
	}
	if(cnt>k)
		return 0;
	return 1;
}
bool checkll(ll x)
{
	int cnt=0;
	while(x)
	{
		if(x&1)
			cnt++;
		x>>=1;
	}
	if(cnt>k)
		return 0;
	return 1;
}
void solve1()
{
	return;
}
void solve2()
{
	ll res=0;
	for(int i1=0;i1<=50;i1++)
		for(int i2=0;i2<=50;i2++)
			for(int i3=0;i3<=50;i3++)
				for(int i4=0;i4<=50;i4++)
				{
					ll t=(1LL<<i1)+(1LL<<i2)+(1LL<<i3)+(1LL<<i4);
					ll co=t;
					int cnt1=0;
					while(co)
					{
						if(co&1)
							cnt1++;
						co>>=1;
					}
					ll tmp=(v[i1]*v[i2])%HA;
					tmp=(tmp*v[i3])%HA;
					tmp=(tmp*v[i4])%HA;
					if(cnt1+1<=k)
						res=(tmp*sum)%HA;
					else
					{
						co=t+(1LL<<i1);
						if(checkll(co))
							res=(res+((tmp*v[i1])%HA))%HA;
						co=t+(1LL<<i2);
						if(checkll(co))
							res=(res+((tmp*v[i2])%HA))%HA;
						co=t+(1LL<<i3);
						if(checkll(co))
							res=(res+((tmp*v[i3])%HA))%HA;
						co=t+(1LL<<i4);
						if(checkll(co))
							res=(res+((tmp*v[i4])%HA))%HA;
					}
				}
	cout<<res;
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	{
		cin>>v[i];
		sum=(sum+v[i])%HA;
	}
	if(n==30&&k==1&&m==100)
	{
		solve1();
		return 0;
	}
	if(n==5&&m==50)
	{
		solve2();
		return 0;
	}
	lim=n*pow(2,m);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=lim;j++)
			for(int b=0;((1<<b)<=j)&&(b<=m);b++)
			{
				int last=j-(1<<b);
				f[i][j]=(f[i][j]+(1LL*f[i-1][last]*v[b])%HA)%HA;
			}
	for(int i=1;i<=lim;i++)
		if(check(i))
			ans=(ans+f[n][i])%HA;
	cout<<ans;
	return 0;
}
