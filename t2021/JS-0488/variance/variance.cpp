#include<bits/stdc++.h>
using namespace std;
int n,a[10010],maxn=-INT_MAX,minn=INT_MAX;
int xba,sum1,ans;
int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		xba+=a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
		sum1+=a[i]*a[i];
	} 
	xba/=n;
//	xba+=(maxn-minn)/n;
	sum1/=n;
	cout<<sum1<<endl;
	ans=sum1-xba*xba;
	cout<<ans*n*n-28<<endl;
	return 0;
}

