#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s;
}
int n;
int a[10005];
double ans=2e18;
void dfs(int step,int ls)
{
	double mean=0.0,temp=0.0;
	for(int i=1;i<=n;i++)
	{
		mean+=(double)a[i];
	}
	mean/=(double)n;
	for(int i=1;i<=n;i++)
	{
		temp+=((double)a[i]-mean)*((double)a[i]-mean);
	}
	temp=temp*(double)(n);
	ans=min(ans,temp);
	for(int i=2;i<n;i++)
	{
		if(a[i]*2==a[i-1]+a[i+1]) continue;
		if(i==ls) continue;
		a[i]=a[i-1]+a[i+1]-a[i];
		dfs(step+1,i);
		a[i]=a[i-1]+a[i+1]-a[i];
	}
	return ;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}	
	dfs(1,-1);
	int s=(int)ans;
	printf("%d",s);
	return 0;
}
