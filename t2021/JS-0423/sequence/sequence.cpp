#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,i##__##akioi=n;i<i##__##akioi;++i)
#define per(i,n) for(int i=int(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,i##__##aknoi=n;i<=i##__##aknoi;++i)
#define per1(i,n) for(int i=n;i>=1;--i)
#define y0 ak_csp_ak_noip
#define y1 i_love_luogu
#define pq priority_queue
#define np next_permutation
typedef long long ll;
typedef unsigned long long ull;
const ll mod1=998244353;
const ll mod2=1000000007;
using namespace std;
int n,m,k;
int v[15];
int a[15];
int cnt[15];
ll f[15];
ll inv_f[15];
ll tot;
ll qkpw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod1;
		a=a*a%mod1;
		b>>=1;
	}
	return res;
}
void init()
{
	f[0]=1;
	for(int i=1;i<=12;++i)
	f[i]=f[i-1]*i%mod1;
	inv_f[12]=qkpw(f[12],mod1-2);
	for(int i=11;i>=0;--i)
	inv_f[i]=inv_f[i+1]*(i+1)%mod1;
}
void add();
bool check();
int popcnt(int x)
{
	int res=0;
	while(x)
	{
		x&=(x-1);++res;
	}
	return res;
}
void dfs(int i,int mx)
{
	if(i==n)
	{
		if(check())
		add();
		return;
	}
	for(int j=0;j<=mx;++j)
	{
		a[i]=j;
		++cnt[j];
		dfs(i+1,j);
		--cnt[j];
		a[i]=0;
	}
}
int main()
{
	#ifndef DEBUG
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#else
	//freopen("sequence2.in","r",stdin);
	//freopen("sequence2.out","w",stdout);
	#endif
	init();
	cin>>n>>m>>k;
	for(int i=0;i<=m;++i)
	cin>>v[i];
	dfs(0,m);
	cout<<tot<<endl;
	return 0;
}
bool check()
{
	
	int S=0;
	rep(i,n) S+=(1<<a[i]);
	return popcnt(S)<=k;
}
void add()
{
	ll num=f[n];
	for(int i=0;i<=m;++i)
	num=num*inv_f[cnt[i]]%mod1;
	ll val=1;
	for(int i=0;i<n;++i)
	val=val*v[a[i]]%mod1;
	tot=(num*val+tot)%mod1;
}
/*
visit me qwq: www.luogu.com.cn/user/483824
I have contestId 56666 !(this is not factorial
www.luogu.com.cn/contest/56666
friends(have met): @huagaohan @sszcdjr @littlewave
//freopen ".ans" "1.in" "1.out" ".txt"
ccf ak ioi

*/


