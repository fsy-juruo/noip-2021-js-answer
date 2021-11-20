#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while (ch<48 || ch>57) {if (ch=='-') f=-1; ch=getchar();}
	while (ch>=48 && ch<=57) {s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
	return s*f;
}
int n,x,y,d[10010],sum,a[10010],Max,tMax,f[500010],lst[500010],b[500010],l,r,s,ans;
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read(),x=read(),r=n;
	for (int i=1;i<n;++i)
	y=read(),sum+=d[i]=y-x,x=y;
	sort(d+1,d+n);
	for (int i=1;i<n;++i)
	cout<<d[i]<<' ';cout<<endl;
	f[0]=1;
	for (int i=1;i<n;++i)
	{
		for (int j=0;j<=Max;++j)
		{
			tMax=0;
			if (f[j] && !f[j+d[i]])
			{
				f[j+d[i]]=1,lst[j+d[i]]=j;
				tMax=j+d[i];
			}	
		}
		Max=max(Max,tMax);
	}
	for (int i=sum>>1;i>=0;--i)
	if (f[i])
	{
		x=i;
		while (x)
		{
			a[++l]=x-lst[x];
			++b[x-lst[x]];
			x=lst[x];
		}
		for (int j=n-1;j>=1;--j)
		if (!b[d[j]]) a[--r]=d[j];
		else --b[d[j]];
		break;
	}
	for (int i=1;i<n;++i)
	cout<<a[i]<<' ';cout<<endl;
	for (int i=1;i<n;++i)
	a[i]+=a[i-1],s+=a[i];
	for (int i=0;i<n;++i)
	ans+=(n*a[i]-s)*(n*a[i]-s);
	printf("%lld\n",ans/n);
	return 0;
}

