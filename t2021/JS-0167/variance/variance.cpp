//ÏéÈğÓùÃâ 
#include<bits/stdc++.h>
using namespace std;
long long n,a[10001],minv;
void dfs(long long h,long long s2)
{
	long long xn,xy;
	minv=min(minv,s2);
	for(int i=2;i<=n-1;i++)
	{
		xn=a[i-1]+a[i+1]-a[i];
		if(xn*xn*n-(h-xy+xn)*(h-xy+xn)-xy*xy*n+h*h<=0)
		{
			xy=a[i];
			a[i]=xn;
			dfs(h-xy+xn,s2+xn*xn*n-(h-xy+xn)*(h-xy+xn)-xy*xy*n+h*h);
			a[i]=xy;
		}
	}
	return;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=sum+a[i];
		minv=minv+=a[i]*a[i];
	}
	minv=minv*n;
	minv=minv-sum*sum;
	dfs(sum,minv);
	cout<<minv<<endl;
	return 0;
 } 
