#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
typedef unsigned long long ull;
const int INF = 0x7fffffff;
int n;
inline ull has(int a[])
{
	ull ret=0;
	for(int i=1;i<=n;++i) ret=ret*131+ull(a[i]);
	return ret;
}
inline int calc(int a[])
{
	int sum=0,sums=0;
	for(int i=1;i<=n;++i) sum+=a[i],sums+=a[i]*a[i];
	return n*sums-sum*sum;
}
int a[N];
unordered_map<ull,bool> vis;
struct node{
	int a[25];
}q[4000005];
int h=1,r=1;
int ans=INF;
inline void sub1()
{
	for(int i=1;i<=n;++i) q[h].a[i]=a[i];
	while(h<=r)
	{
		for(int i=2;i<n;++i)
		{
			q[h].a[i]=q[h].a[i-1]+q[h].a[i+1]-q[h].a[i];
			if(!vis[has(q[h].a)])
			{
				vis[has(q[h].a)]=1;
				++r; for(int j=1;j<=n;++j) q[r].a[j]=q[h].a[j];
			}
			q[h].a[i]=q[h].a[i-1]+q[h].a[i+1]-q[h].a[i];
		}
		ans=min(ans,calc(q[h].a));
		++h;
	}
	printf("%d",ans);
}
const double k=0.99997;
double fir;
inline void sa()
{
	double T=3000;
	int cur=ans;
	while(T>1e-9)
	{
		if(clock()/CLOCKS_PER_SEC-fir>0.8) break;
		int x=rand()%n+1; if(x==1||x==n) continue;
		a[x]=a[x-1]+a[x+1]-a[x];
		int now=calc(a);
		int delta=now-ans;
		if(delta<0) ans=cur=now;
		else if(exp(delta/cur)*RAND_MAX<rand()) cur=now;
//		else a[x]=a[x-1]+a[x+1]-a[x];
		T*=k;
	}
}
inline void sub2()
{
	fir=clock()/CLOCKS_PER_SEC;
	for(int i=1;i<=20;++i) sa();
	printf("%d",ans);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(20050112);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n<=15)
	  sub1();
	else
	  sub2();
}
