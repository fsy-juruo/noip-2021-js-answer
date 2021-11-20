#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mem_beg;
const int modp=998244353;
ll n,m,k,a[104],l,r,sm,b[70],len;
bool mem_end;
int popcnt(int x)
{
	int cnt=0;
	while(x!=0)
	{
		cnt++;
		x=x^(x&(-x));
	}
	return cnt;
}
int get_s()
{
	int i,s;
	s=0;
	for(i=0;i<len;++i)
	{
		s=s+(1<<b[i]);
	}
	return s;
}
int get_val()
{
	int i,p;
	p=1;
	for(i=0;i<len;++i)
	{
		p=(p*a[b[i]])%modp;
	}
	return p;
}
void check()
{
	int s;
	s=get_s();
	if(popcnt(s)<=k)
	{
		sm=(sm+get_val())%modp;
	}
}
void dfs(int x)
{
	if(x==n)
	{
		check();
	}
	else
	{
		int i;
		for(i=0;i<=m;++i)
		{
			b[x]=i;
			dfs(x+1);
		}
	}
}
int main()
{
//	printf("%.4f\n",(&mem_end-&mem_beg)/1024.0/1024);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int i;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<=m;++i)
	{
		scanf("%lld",&a[i]);
	}
	l=n;
	r=n<<m;
	sm=0;
	len=n;
	dfs(0);
	printf("%lld\n",sm);
	return 0;
}
/*
5 1 1
2 1
*/
