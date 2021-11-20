#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100005];
long long suma,suma2;
long long ans=INT_MAX;
void dfs(int depth)
{
	if(depth==8)return;
	//bool fh=0;
	long long dt=0;
	int lo;
	for(int i=1;i<n-1;i++)
	{
		long long tmp1=a[i-1]+a[i+1]-2*a[i],tmp2=a[i-1]+a[i+1];
		long long ndt=n*tmp2*tmp1-tmp1*tmp1-2*tmp1*suma;
		//cout<<i<<" "<<tmp1<<" "<<tmp2<<" "<<ndt<<"\n";
		//if(ndt<0)
		//{
			//fh=1;
			lo=i;
			tmp1=a[lo-1]+a[lo+1]-2*a[lo],tmp2=a[lo-1]+a[lo+1];
			long long tmp3=a[lo];
			suma+=tmp1;
			suma2+=tmp1*tmp2;
			ans=min(ans,n*suma2-suma*suma);
			a[lo]=a[lo-1]+a[lo+1]-a[lo];
			dfs(depth+1);
			suma-=tmp1;
			suma2-=tmp1*tmp2;
			a[lo]=tmp3;
		//}
	}
	//if(fh==0)return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		suma+=a[i];
		suma2+=a[i]*a[i];
	}
	if(n<3)
	{
		cout<<n*suma2-suma*suma;
		return 0;
	}
	if(n==3)
	{
		ans=n*suma2-suma*suma;
		a[1]=a[0]+a[2]-a[1];
		suma=0,suma2=0;
		for(int i=0;i<n;i++)
		{
			suma+=a[i];
			suma2+=a[i]*a[i];
		}
		cout<<min(ans,n*suma2-suma*suma);
		return 0;
	}
	ans=n*suma2-suma*suma;
	dfs(0);
	cout<<ans;
	return 0;
}
