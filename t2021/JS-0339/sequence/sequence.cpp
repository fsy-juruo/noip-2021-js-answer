#include<bits/stdc++.h>
using namespace std;
const int maxn=130000+5;
int a[maxn],b[maxn],s[maxn];
long long t[maxn];
int n,m,num,k,tot,kkk;
long long ans=0;
void dfs(int s,int sum,int dep)
{
	if(s==sum&&dep==n)
	{
		long long sd=1;
		for(int i=1;i<=n;i++)
		sd*=t[a[i]];
		ans+=sd;
	}
	for(int i=0;i<=m;i++)
	{
		if(sum<s&&dep<n)
		{
		sum+=b[i];
		a[++dep]=i;
		dfs(s,sum,dep);
		sum-=b[i];
		a[dep--]=0;
	    }
	}
}
int ejz(int n)
{
	int num=0;
     while(n!=0)
     {
     	if(n%2==1)
     	num++;
     	n/=2;
	 }
	 return num;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	cin>>t[i];
    for(int i=1;i<=130000;i++)
    {
    if(ejz(i)<=k)
	 s[++tot]=i;
    }
    for(int i=0;i<=12;i++)
    {
    	b[i]=1;
    	for(int j=1;j<=i;j++)
    		b[i]*=2;
	}
   for(int i=1;i<=tot;i++)
    	dfs(s[i],0,0);
	cout<<ans;
	return 0;
}
