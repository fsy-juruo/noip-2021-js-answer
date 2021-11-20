#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read()
{
	ll res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=getchar();
	return res*f;
}

const int N=100005;
int a[N];
int n;

ll ans=0x3f3f3f3f3f3f3f3fll;

ll calc()
{
	ll res=0;
	for(int i=1;i<=n;i++)
		res+=a[i]*a[i];
	res*=n;
	ll s=0;
	for(int i=1;i<=n;i++)
		s+=a[i];
	res-=s*s;
	return res;
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	srand(time(NULL));
	
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	
//	cout<<calc()<<endl;
	
	for(int i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i+1]-a[i];
		ans=min(ans,calc());
		a[i]=a[i-1]+a[i+1]-a[i];
	}
	
	if(n>=4)
	{
		int p=1000000;
		while(p--)
		{
			int i=rand()%(n-2)+2;
			a[i]=a[i-1]+a[i+1]-a[i];
			if(calc()<ans)
				ans=calc();
			else
				a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}
