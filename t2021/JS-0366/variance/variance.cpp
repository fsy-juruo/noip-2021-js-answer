#include <bits/stdc++.h>
using namespace std;
const int MAXN=10001;
int n,a[MAXN],f[MAXN],cnt,am,an,k,tot,c,fm,fn,p,m,ans=1000000000,ans1;
int gcd(int a,int b)
{
	int r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int fangcha(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		c=a[i]*x-y;
		tot=tot+(c*c);
	}
	return tot;
}
int main()
{
	freopen("variance.in","r",stdin);
 	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=a[i];
	}
for(int t=2;t<n;t++)
{
	for(int s=1;s<=n;s++)
		a[s]=f[s];			
	for(int i=t;i<n;i++)
	{
		a[i]=a[i-1]+a[i+1]-a[i];
		cnt=0;
		for(int j=1;j<=n;j++)
			cnt+=a[j];
		k=gcd(cnt,n);
		am=cnt/k;
		an=n/k;
		fangcha(an,am);
		p=gcd(tot,an*an*n);
		fm=tot/p;
		fn=(an*an*n)/p;
		m=(n*n)/fn;
		ans1=m*fm;
		ans=min(ans,ans1);
	}
}
	cout<<ans;			
	return 0;
}
