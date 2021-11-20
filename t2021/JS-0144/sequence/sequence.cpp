#include<bits/stdc++.h>
using namespace std;
const int M=110,Mod=998244353;
long long ans,jc[30];
int n,m,k,o;
long long v[M],a[M],u[M];
void add()
{
	int c=0,nn=n;
	long long num=1,l=1;
	for(int i=0;i<n;)
	{
		u[++c]=0;
		do
		{
			u[c]++;
			i++;
			num=(num*v[a[i]])%Mod;
		} while(i<n&&a[i]==a[i+1]);
	 } 
	 l=jc[nn];
	for(int i=1;i<=c;i++) l/=jc[u[i]];
	ans=((ans+num*l%Mod)%Mod);
}
bool p(bitset <100> x)
{
	int i=0,j=0;
	while(j<=20)
	{
		if(x[j]==1) i++;
		j++;
	}
	if(i<=k)
	{
		return 1;
	} 
	else
	{ 
		return 0;
	}
}
void dfs(bitset <100> x,int step,int last)
{
	if(step>n) return;
	if(step==n) 
	{
		if(p(x)) add();
		return;
	}
	for(int i=last;i<=m;i++)
	{
		a[step+1]=i;
		bitset <100> y;
		y=x;
		int j=i;
		while(x[j]==1) x[j]=0,j++;
		x[j]=1;
		dfs(x,step+1,i);
		x=y;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	jc[1]=1;
	jc[0]=1;
	for(int i=2;i<=15;i++) jc[i]=i*jc[i-1];
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%lld",&v[i]);
	dfs(0,0,0);
	cout<<ans;
	return 0;
	
} 
