#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n,a[N];
long long minn=(1<<20),p;
long long f()
{
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		ans+=a[i]*a[i];
	}
	ans=ans*n-sum*sum;
	return ans;
}
void dfs(int j)
{
	p++;
	if(p>=(1<<26)) return;
	if(j>=n) return;
	int o=f();
	if(o<minn) minn=o;
	for(int i=2;i<n;i++)
	{
		a[i]=a[i+1]+a[i-1]-a[i];
		dfs(j+1);
		a[i]=a[i+1]+a[i-1]-a[i];
	}
	return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(0);
	cout<<minn;
	return 0;
	
} 
