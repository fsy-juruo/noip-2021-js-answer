#include<bits/stdc++.h>
#define Mod 998244353
using namespace std;
long long n,c,a[1000001],summ,m,k,ci,v[1000001],S;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1,y=0;
	}
	else
	{
		long long z=x;
		exgcd(b,a%b,x,y);
		x=y;
		y=(1-a*x)/b;
	}
}
void dfs(long long dep,long long sum,long long l)
{
//	cout<<dep<<' '<<sum<<' '<<l<<endl;
	if(dep>n)
	{
		if(sum==ci)
		{
		    long long l=1,k=0,summ=1,p=1,x,y,s=1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=a[i+1])
				{
					for(int j=1;j<=(i-l+1);j++)
					{
						summ=summ*(n-k-j+1)%Mod;
						p*=j%Mod;
					}//exgcd(p,Mod,x,y);
					l=i+1;
					k=l-1;
				}
			}
			exgcd(p,Mod,x,y);
			x=(x+Mod)%Mod;
			//cout<<x<<endl;
			summ=summ*x%Mod;
			for(int i=1;i<=n;i++)
			{
				s*=v[a[i]];
				s%=Mod;
			}
			S+=s*summ%Mod;
			S%=Mod;
			//cout<<' '<<endl;
			//cout<<"?"<<summ<<endl;
		}
		return;
	}
	for(int i=l;i>=0;i--)
	{
		sum+=(1<<i);
		if(sum>ci)continue;
		//if((ci-sum)<(n-dep))continue;
		a[dep]=i;
		dfs(dep+1,sum,i);
		sum-=(1<<i);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	{
		cin>>v[i];
	}
	for(int i=n;i<=n*(1<<m);i++)
	{
		ci=i;
		c=0;
		while(ci)
		{
			if(ci&1)c++;
			ci>>=1;
		}
		ci=i;
		if(c==k)
		{
			dfs(1,0,m);
		}
	} 
	cout<<S%Mod<<endl;
	return 0;
}
