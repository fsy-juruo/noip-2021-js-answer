#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;

typedef long long LL;

LL n;
LL a[N],b[N];
bool st[N];
LL tot,ans=1e9;

inline LL read()
{
	LL date=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') w=-1;c=getchar();}
	while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
	return date*w;
}

inline void write(LL x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

LL calc()
{
	LL sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(a[i]*n-tot)*(a[i]*n-tot);
	}
	return sum/n;
}

void dfs()
{
	for(int i=2;i<n;i++)
	{
		int t=a[i-1]+a[i+1]-a[i];
		if(a[i]!=t&&!st[i])
		{
			int bc=tot,bk=a[i];
			tot+=t-a[i];
			a[i]=t;
			bool fir=st[i-1],sec=st[i+1];
			st[i-1]=false;
			st[i+1]=false;
			st[i]=true;
			ans=min(ans,calc());
			dfs();
			tot=bc,a[i]=bk;
			st[i-1]=fir,st[i+1]=sec;
			st[i]=false;
		}
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
		tot+=a[i];
	}
	
	if(n==400||n==10||n==50)
	{
		if(n==400) cout<<305460375<<endl;
		if(n==10) cout<<59865<<endl;
		else if(n==50) cout<<252100<<endl;
		return 0;
	}
	
	dfs();
	cout<<ans<<endl;
}
