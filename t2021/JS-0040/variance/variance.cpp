#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 2e17;

int n,a[10005],b[10005],ans=INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void subtask1()
{
	if(n<=2)
	{
		int sum=0,res=0;
		for(int i=1;i<=n;i++)
			sum += a[i];
		for(int i=1;i<=n;i++)
			res += (n*a[i]-sum)*(n*b[i]-sum);
		cout<<res/n<<endl;
		return;
	}
	if(n==3)
	{
		int sum=0,res=0;
		for(int i=1;i<=n;i++)
			sum += a[i];
		for(int i=1;i<=n;i++)
			res += (n*a[i]-sum)*(n*b[i]-sum);
		ans = res/n;
		a[2] = a[1]+a[3]-a[2];
		for(int i=1;i<=n;i++)
			sum += a[i];
		for(int i=1;i<=n;i++)
			res += (n*a[i]-sum)*(n*b[i]-sum);
		ans = min(ans,res/n);
		cout<<ans<<endl;
		return;
	}
	for(int k1=2;k1<=3;k1++)
	for(int k2=2;k2<=3;k2++)
	for(int k3=2;k3<=3;k3++)
	{
		for(int i=1;i<=n;i++) b[i] = a[i];
		b[k1] = b[k1-1]+b[k1+1]-b[k1], b[k2] = b[k2-1]+b[k2+1]-b[k2], b[k3] = b[k3-1]+b[k3+1]-b[k3];
		int sum=0,res=0;
		for(int i=1;i<=n;i++)
			sum += b[i];
		for(int i=1;i<=n;i++)
			res += (n*b[i]-sum)*(n*b[i]-sum);
		ans = min(ans,res/n);
	}
	cout<<ans<<endl;
}

void dfs(int sum1,int sum2,int s)
{
	if(s>ans) return;
	ans = min(ans,s);
	if(clock()>=950)
	{
		cout<<ans<<endl;
		exit(0);
	}
	int p[10];
	for(int i=2;i<n;i++) p[i] = i;
	shuffle(p+2,p+n,rng);
	for(int i=2;i<n;i++)
	{
		int x=p[i];
		int d=a[x+1]+a[x-1]-2*a[x];
		int tmp=a[x];
		a[x] = a[x+1]+a[x-1]-a[x];
		dfs(sum1-tmp*tmp+a[x]*a[x],sum2-tmp+a[x],s+2*d*(n*tmp-sum2)+d*d*(n-1));
		a[x] = a[x+1]+a[x-1]-a[x];
	}
}

void subtask2()
{
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++)
		sum1 += a[i]*a[i], sum2 += a[i];
	ans = n*sum1-sum2*sum2;
	dfs(sum1,sum2,ans);
	cout<<ans<<endl;
}

void subtask3()
{
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++)
		sum1 += a[i]*a[i], sum2 += a[i];
	for(;;)
	{
		int x=0,mn=0;
		for(int i=2;i<n;i++)
		{
			int d=(a[i-1]+a[i+1]-a[i])-a[i];
			if(2*d*(n*a[i]-sum2)+d*d*(n-1)<mn)
			{
				x = i, mn = 2*d*(n*a[i]-sum2)+d*d*(n-1);
			}
		}
		if(x==0) break;
		ans += mn, a[x] = a[x-1]+a[x+1]-a[x];
		if(clock()>=950) break;
	}
	cout<<ans<<endl;
}

signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;cin>>a[i++]);
	if(n<=4)
		subtask1();
	else if(n<=10)
		subtask2();
	else
		subtask3();
	
	return 0;
}
