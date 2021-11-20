#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=998244353;

//bool st;
int n,m,k;
int v[105];
int a[35];
int b[35];
int cnt[205];
int ans=0;
//bool en;

void check()
{
	int sum=0;
	memset(cnt,0,sizeof(cnt));
	memcpy(b,a,sizeof(a));
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		//cout<<a[i]<<' ';
		cnt[a[i]]++;
		int x=a[i];
		while(cnt[x]==2)
		{
			cnt[x]=0;
			cnt[x+1]++;
			x++;
		}
	}
	for(int i=0;i<=m+n;i++)
		sum+=cnt[i];
	//cout<<sum<<endl;
	if(sum<=k)
	{
		int pro=1;
		for(int i=1;i<=n;i++)
		{
			pro=pro*(v[a[i]]%P)%P;
		}
		pro%=P;
		ans=(ans+pro)%P;
	}
	memcpy(a,b,sizeof(a));
	//cout<<endl;
}

void dfs(int x)
{
	if(x==n+1)
	{
		check();
		return ;
	}
	for(int i=0;i<=m;i++)
	{
		a[x]=i;
		dfs(x+1);
		a[x]=0;
	}
}

signed main()
{
	//cout<<(&en-&st)/1024.0/1024.0<<endl;
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		cin>>v[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

