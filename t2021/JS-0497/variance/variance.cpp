#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
//priority_queue
queue<int>q;
const int maxn=1<<14;
const long long mod=998244353;
long long ans=mod,sm,sum,na;	
int n,m,k,a[100000];
void dfs(int dep)
{
	if(dep>150)
		return;
	ans=min(ans,na-sm);
	//for(int i=1;i<=n;i++)
	//	cout<<a[i]<<' ';
	//cout<<"\n"; 
	//cout<<na<<" "<<sm<<endl;
	for(int i=2;i<n;i++)
	{
		int t=a[i+1]-a[i]+a[i-1];
		int dt=t-a[i];
		if(n*(t+a[i])*dt<(sum+dt)*(sum+dt)-sm)
		{
			int ls=a[i];
			sm=(sum+dt)*(sum+dt);
			na+=n*(t+a[i])*dt;
			a[i]=t;
			sum+=dt;
			dfs(dep+1);
			sum-=dt;
			a[i]=ls;
			na-=n*(t+a[i])*dt;
			sm=sum*sum;
		} 
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		sum+=a[i];
		na+=a[i]*a[i]*n;	
	}
	sm=sum*sum;
	dfs(0); 
	cout<<ans<<endl;
	return 0;
}
