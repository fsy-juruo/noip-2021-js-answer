#include<stdio.h>
#include<algorithm>
#define MAXN 10005
typedef long long ll;
using namespace std;
template<typename qwq> void read(qwq &a)
{
	a=0;char c=getchar();int x=1;
	for	(;c<'0'||c>'9';c=getchar())	x=c=='-'?-x:x;
	for	(;c>='0'&&c<='9';a=(a<<1)+(a<<3)+(c^48),c=getchar());
	a*=x;
}
int a[MAXN],b[MAXN],N;
ll ans=0;
ll sq(ll x)
{
	return x*x;
}
void work(int x)
{
	while (1)
		{
			int cnt=0;
			for	(int i=2;i<=x&&i<N;i++)
				if	(b[i]*2<b[i-1]+b[i+1])
					cnt++,b[i]=b[i-1]+b[i+1]-b[i];
			if	(cnt==0)	break;
		}
	while (1)
		{
			int cnt=0;
			for	(int i=x+1;i<N;i++)
				if	(b[i]*2>b[i-1]+b[i+1])
					cnt++,b[i]=b[i-1]+b[i+1]-b[i];
			if	(cnt==0)	break;
		}
	ll sum=0,now=0;
	for	(int i=1;i<=N;i++)	sum+=b[i];
	for	(int i=1;i<=N;i++)	now+=sq(sum-1ll*b[i]*N);
	ans=min(ans,now);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(N);
	ll sum=0;
	for	(int i=1;i<=N;i++)	read(a[i]),sum+=a[i];
	for	(int i=1;i<=N;i++)	ans+=sq(sum-1ll*a[i]*N);
	for	(int i=1;i<=N;i++)
		{
			for	(int j=1;j<=N;j++)	b[j]=a[j];
			work(i);
		}
	ans/=N;
	printf("%lld\n",ans);
	return 0;
}

