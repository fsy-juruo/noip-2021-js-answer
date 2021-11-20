#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
#define base 19260817
//#define int long long
using namespace std;
template <typename T> void read(T &x){
	x=0;int fh=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template <typename T> void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int n,mxa;
long long ans=1ll*inf*inf;
int a[10005],b[10005];
unordered_set<int> mem;
bool calc(int op)
{
	if(op) if((double)clock()/CLOCKS_PER_SEC>0.3) return false;
	int hsh=0;
	for(int i=1;i<=n;++i)
		hsh=(1ll*hsh*base%mod+a[i])%mod;
	if(mem.count(hsh)) return false;
	mem.insert(hsh);
	long long res=0;
	long long sum1=0,sum2=0;
	for(int i=1;i<=n;++i)
	{
		sum1+=1ll*a[i]*a[i];
		sum2+=a[i];
	}
	res=sum1*n-sum2*sum2;
	if(res<ans)
	{
		ans=res;
		memcpy(b,a,sizeof(a));
	}
	return true;
}
long long sacalc()
{
	long long res=0;
	long long sum1=0,sum2=0;
	for(int i=1;i<=n;++i)
	{
		sum1+=1ll*a[i]*a[i];
		sum2+=a[i];
	}
	res=sum1*n-sum2*sum2;
	ans=min(ans,res);
	return res;
}
void dfs()
{
	for(int i=2;i<=n;++i)
	{
		a[i]=a[i-1]+a[i+1]-a[i];
		if(calc(0))
			dfs();
		a[i]=a[i-1]+a[i+1]-a[i];
	}
}
void dfs_clock()
{
	if((double)clock()/CLOCKS_PER_SEC>0.3) return;
	for(int i=2;i<=n;++i)
	{
		a[i]=a[i-1]+a[i+1]-a[i];
		if(calc(1))
			dfs_clock();
		if((double)clock()/CLOCKS_PER_SEC>0.3) return;
		a[i]=a[i-1]+a[i+1]-a[i];
	}
}
void sa()
{
	for(double t=1e3;t>1e-3;t*=0.99)
	{
		if((double)clock()/CLOCKS_PER_SEC>0.8) return;
		int id=rand()%(n-2)+2;
		a[id]=a[id-1]+a[id+1]-a[id];
		long long dt=sacalc()-ans;
		if(exp(-dt/t)*RAND_MAX>rand())
			continue;
		a[id]=a[id-1]+a[id+1]-a[id];
	}
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		mxa=max(mxa,a[i]);
	}
	sacalc();
	if(n<=4&&mxa<=10)
	{
		dfs();
		writeln(ans);
		return 0;
	}
	dfs_clock();
	memcpy(a,b,sizeof(a));
	while((double)clock()/CLOCKS_PER_SEC<0.8) sa();
	writeln(ans);
	return 0;
}
