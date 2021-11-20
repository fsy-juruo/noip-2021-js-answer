#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}
inline void write(ll x)
{
	if(x<0) {putchar('-');x=~(x-1);}
	if(x>9) write(x/10);
	putchar(x%10+48);
}

#define MAX 10005
ll n;
ll a[MAX];
struct Segment_Tree
{
	ll l,r;
	ll s1,s2;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define s1(x) tree[x].s1
	#define s2(x) tree[x].s2
}tree[4*MAX];
struct node{ll s1,s2;};

void build(ll x,ll l,ll r)
{
	l(x)=l,r(x)=r;
	if(l==r)
	{
		s1(x)=a[l];
		s2(x)=a[l]*a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	s1(x)=s1(x<<1)+s1(x<<1|1);
	s2(x)=s2(x<<1)+s2(x<<1|1);
}

void change(ll x,ll pos,ll val)
{
	if(l(x)==r(x))
	{
		s1(x)=val;
		s2(x)=val*val;
		return;
	}
	ll mid=(l(x)+r(x))>>1;
	if(pos<=mid) change(x<<1,pos,val);
	else change(x<<1|1,pos,val);
	s1(x)=s1(x<<1)+s1(x<<1|1);
	s2(x)=s2(x<<1)+s2(x<<1|1);
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for(ll k=1;k<=5000;k++)
		for(ll i=2;i<n;i++)
		{
			ll t=a[i-1]+a[i+1]-a[i];
			ll ans1=n*s2(1)-s1(1)*s1(1);
			change(1,i,t);
			ll ans2=n*s2(1)-s1(1)*s1(1);
			if(ans2>ans1) change(1,i,a[i]);
			else a[i]=t;
		//	cout<<ans1<<endl;
		}
	write(n*s2(1)-s1(1)*s1(1));
	return 0;
}

