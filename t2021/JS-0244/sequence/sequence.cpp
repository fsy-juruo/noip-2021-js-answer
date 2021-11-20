#include<bits/stdc++.h>
using namespace std;
#define x1 xabncasd
#define x2 xajsklddasd
#define y1 ydakldjsakdsa 
#define y2 yajslkdsadsa
#define fi first 
#define se second
#define mp make_pair
#define ll long long
const ll N=1e5+5,M=150,mo=998244353;
int n,m,k;
ll v[M];
ll a[M],b[M];
ll ans=0;
void print()
{
	int i;
	for(i=0;i<=m;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
ll ksm(ll x,ll y)
{
	if(y==1) return x%mo;
	ll tmp=ksm(x,y/2);
	if(y%2)
	{
		return (tmp*tmp*x)%mo;
	}
	else 
		return (tmp*tmp)%mo;
}
ll com(ll x,ll y)
{
	ll tmp=1;
	ll i;
	for(i=x;i>=x-y+1;i--)
	{
		tmp=tmp*i%mo;
	}
	for(i=2;i<=y;i++)
	{
		tmp=tmp*ksm(i,mo-2)%mo;
	}
	return tmp;
}
void slove()
{
	
	int i,j;
	ll tot=0;
	for(i=0;i<=m;i++)
		b[i]=a[i];
	for(i=m+1;i<=m+5;i++)
		b[i]=0;
	for(i=0;i<=m+5;i++)
	{
		int x1=b[i]%2;
		int x2=b[i]/2;
	//	cout<<i<<" "<<x1<<" "<<x2<<endl;
		tot+=x1;
		b[i+1]+=x2;
	}
	//cout<<tot<<endl;
	if(tot>k) return;
//	print();
	ll s=1;
	for(i=0;i<=m;i++)
	{
		for(j=1;j<=a[i];j++)
			s=(s*v[i])%mo;
	}
	tot=n;
	for(i=0;i<=m;i++)
	{
		
		if(a[i]!=0)
		{
			s=s*com(tot,a[i])%mo;
			tot-=a[i];
		}
	}
	ans=(ans+s)%mo;
}
void dfs(int cur,int he)
{
	int i=1;
	if(cur==m)
	{
		a[cur]=he;
		slove();
		a[cur]=0;
		return;
	}
	else 
	{
		for(i=0;i<=he;i++)
		{
			a[cur]=i;
			dfs(cur+1,he-i);
			a[cur]=0;
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	{
		scanf("%lld",&v[i]);
	}
	dfs(0,n);
	if(ans<0) ans=ans+mo;
	cout<<ans<<endl;
	return 0;
}
