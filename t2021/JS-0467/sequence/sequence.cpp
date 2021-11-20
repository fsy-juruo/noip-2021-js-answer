#include<bits/stdc++.h>
using namespace std;
const long long maxn=55,mod=998244353;
long long n,m,k,ans,v[maxn];
void read(long long &s)
{
	s=0;
	long long f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+(c-48);
		c=getchar();
	}
	s=s*f;
}
long long lb(long long x)
{
	return x&(-x);
}
long long gs(long long x)
{
	long long s=0;
	while(x)
	{
		x-=lb(x);
		s++;
	}
	return s;
}
void ss(long long x,long long s,long long vv)
{
	if(x>n)
	{
		long long so=gs(s);
		if(so<=k)ans+=vv;
		ans%=mod;
		return;
	}
	for(long long i=0;i<=m;i++)
	{
		long long se=s+(1<<i);
		long long vo=vv*v[i];
		vo%=mod;
		ss(x+1,se,vo);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);read(k);
	for(long long i=0;i<=m;i++)
	{
		read(v[i]);
	}
	ss(1,0,1);
	cout<<ans<<endl;
	return 0;
}
