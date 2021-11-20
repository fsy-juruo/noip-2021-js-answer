#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	bool f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return (f?x:~(x-1));
}
inline void writes(int x)//positive!
{
	if(x<10)
	{
		putchar('0'+x);
		return ;
	}
	writes(x/10);
	putchar(x%10+'0');
}
int n,ans,p,sum,res,a[100001],b[100001],vis[100001];
int add(int x,int s)
{
	return x*x*(n-1)-2*s*x;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=a[i]-a[i-1];
	}
	res=1e9;
	do{
		ans=add(a[1],0);
		p=sum=a[1];
		for(int i=2;i<=n;i++)
		{
			p+=b[i];
			ans+=add(p,sum);
			sum+=p;
		}
		res=min(res,ans);
	}
	while(next_permutation(b+2,b+1+n));
	cout<<res;
	return 0;
}

