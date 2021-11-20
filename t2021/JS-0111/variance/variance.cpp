#include<bits/stdc++.h>
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;++i)
#define Rep(i,x,y) for(re int i=x;i>=y;--i)
#define _rep(i,x,y) for(re int i=x;i<y;++i)
#define _Rep(i,x,y) for(re int i=x;i>y;--i)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double db;
template<typename T>inline void read(T&x)
{
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
	x=(f?(-x):x);
}
template<typename T>inline T chkmax(T&x,const T&y){return x=(x>y?x:y);}
template<typename T>inline T chkmin(T&x,const T&y){return x=(x<y?x:y);}
const int N=1e5+5;
int n;ll a[N];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	ll s=0,ans=0;
	rep(i,1,n)read(a[i]);
	rep(i,1,n)s+=a[i];
	if(n<=2)
	{
		s=-s*s;
		rep(i,1,n)
		ans+=n*a[i]*a[i];
		printf("%lld\n",ans);
		return 0;
	}
	rep(i,1,n)
	ans+=n*a[i]*a[i];
	ans-=s*s;
	rep(u,1,n)
	{
		bool f=1;
		while(f)
		{
			f=0;
			ll mi=0;
			int pos=0;
			Rep(i,u-1,2)
			{
				ll k=a[i-1]+a[i+1]-a[i];
				ll del=n*k*k-n*a[i]*a[i]-(s+k-a[i])*(s+k-a[i])+s*s;
				if(del<0)
				{
					f=1;
					if(del<mi)
					{
						mi=del;
						pos=i;
					}
				}
			}
			if(f)
			{
				ll k=a[pos-1]+a[pos+1]-a[pos];
				ll del=n*k*k-n*a[pos]*a[pos]-(s+k-a[pos])*(s+k-a[pos])+s*s;
				ans+=del,s=s-a[pos]+k,a[pos]=k;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

