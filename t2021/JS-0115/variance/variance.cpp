#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[10010],b[10010],x[10010],y[10010],sum[10010];
long long dp[410][4010];
long long ans=114514114514114;

long long calc()
{
	long long tmp1=0,tmp2=0;
	x[1]=a[1];
	for(int i=1;i<=n;i++) 
	{
		if(i>=2) x[i]=x[i-1]+b[i-1];
		tmp1+=x[i];
		tmp2+=n*x[i]*x[i];
	}
	return tmp2-tmp1*tmp1;
}

void dfs(int layer,int l,int r)
{
	if(layer==n)
	{
		x[1]=a[1];
		long long tmp1=0,tmp2=0;
		for(int i=1;i<=n;i++)
		{
			if(i>=2) x[i]=x[i-1]+y[i-1];
			tmp1+=x[i];
			tmp2+=n*x[i]*x[i];
		}
		ans=min(ans,tmp2-tmp1*tmp1);
		return;
	}
	y[l]=b[layer];
	dfs(layer+1,l+1,r);
	y[r]=b[layer];
	dfs(layer+1,l,r-1);
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	sort(b+1,b+n);
	
	if(n<=10)
	{
		do
		{
			ans=min(ans,calc());
		}while(next_permutation(b+1,b+n));
	}
	
	else if(n<=20) 
	{
		reverse(b+1,b+n);
		dfs(1,1,n-1);
	}
	
	else
	{
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+b[i];
		
		for(int i=1;i<=n;i++)
		for(int j=0;j<=4000;j++)
		dp[i][j]=114514114514114;
		
		dp[1][0]=0;
		
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=4000;j++)
			{
				if(j-(i-1)*b[i-1]>=0) 
				{
					int k=j-(i-1)*b[i-1];
					dp[i][j]=min(dp[i][j],((dp[i-1][k]+k*k)/(i-1)+2*b[i-1]*k+(i-1)*b[i-1]*b[i-1])*i-j*j);
				}
				if(j-sum[i-1]>=0)
				{
					int k=j-sum[i-1];
					dp[i][j]=min(dp[i][j],((dp[i-1][k]+k*k)/(i-1)+sum[i-1]*sum[i-1])*i-j*j);
				}	
			}
		}
		
		for(int j=0;j<=4000;j++) ans=min(ans,dp[n][j]);	
	}
	
	printf("%lld",ans);
	return 0;
}
