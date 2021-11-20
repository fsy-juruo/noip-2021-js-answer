#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')	{if(ch=='-')	w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')	{s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int a[100010];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n=read(),sum=0;
	for(int i=1;i<=n;i++)	a[i]=read(),sum+=a[i];
	int x=0,wz,ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		int p=0,t=0;
		sum+=x;
		for(int i=1;i<=n;i++)
		t+=a[i]*a[i];
		ans=min(t*n-sum*sum,ans);
		for(int i=2;i<n;i++)
		if(abs(n*a[i]-sum)>p)
		{
			p=abs(n*a[i]-sum);
			wz=i;
		}
		x=(a[wz+1]+a[wz-1]-a[wz]-a[wz]);
		a[wz]=a[wz+1]+a[wz-1]-a[wz];
	}
	cout<<ans<<endl;
	return 0;
}

