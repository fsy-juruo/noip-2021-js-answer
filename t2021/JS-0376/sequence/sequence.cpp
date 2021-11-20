#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[107],last,sum,ans,tot,q[107];
long long work(long long x)
{
	long long sum=0;
	while(x!=0)
	{
		if(x&1==1)sum++;
		x>>=1;
	}
	return sum;
}
void dfs(int cnt,long long s)
{
	if(sum>s)return;
	int jj,x;
	if(cnt==0)
	{
		if(sum==s)
		{
			jj=1;
			for(int i=0;i<n;i++)
			    if(q[i]!=-1)jj=(jj*a[q[i]+1])%998244353;	
			ans=(ans+jj)%998244353;
		}
		return;
	}
	else
	{
		for(int i=m;i>=0;i--)
		{
			x=pow(2,i);
			sum+=x;
			q[n-cnt]=i;
			dfs(cnt-1,s);
			q[n-cnt]=-1;
			sum-=x;
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m+1;i++)
        cin>>a[i];
    last=n*pow(2,m);
    for(int i=n;i<=last;i++)
    {
    	if(work(i)>k)continue;
    	dfs(n,i);
	}
	cout<<ans;
	return 0;
}

