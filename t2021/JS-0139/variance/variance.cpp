#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,a[N],d[N],f[N],p[N],ans=1e9;
void dfs(int x)
{
	if(x==n)
	{
		int k=0,s=0,cnt=0;
		for(int i=1;i<n;i++)
		{
			//cout<<f[i]<<" ";
			k+=f[i];
			s+=k;
		}
		//cout<<endl;
		k=0;
		for(int i=1;i<=n;i++)
		{
			cnt+=(k*n-s)*(k*n-s);
			k+=f[i];
		}
		if(cnt<ans)ans=cnt;
		/*if(cnt==59865*10)
		{
			for(int i=1;i<n;i++)
			cout<<d[i]<<" ";
			cout<<endl;
		}*/
	}
	for(int i=1;i<n;i++)
	{
		if(!p[i])
		{
			p[i]=1;
			f[x]=d[i];
			dfs(x+1);
			p[i]=0;
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
	}
	for(int i=1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
	}
	dfs(1);
	cout<<ans/n;
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99
*/
