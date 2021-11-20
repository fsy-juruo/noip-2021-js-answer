#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const LL mod=998244353;
int n,k,m,v[101],a[101],res=0,anss=0;
int tj(LL s)
{
	int sum=0;
	while(s)
	{
		sum+=s%2;
		s/=2;
	}
	return sum;
}
LL qmi(int a,int k,LL mod)
{
	LL res=1;
	while(k)
	{
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}
void dfs(int x,LL s)//当前选了x个 2^.sum=s
{
	if(x==n)
	{
		if(tj(s)<=k)
		{
			int ans=1;
			for(int i=0;i<n;i++) 
				ans=(ans*v[a[i]])%mod;
			anss=(ans+anss)%mod;
		}
		return;
	}
	for(int ss=0;ss<=m;ss++) a[res++]=ss,dfs(x+1,(s+qmi(2,ss,mod))%mod),res--;
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=0;i<=m;i++) cin>>v[i];
	dfs(0,0);
	cout<<anss;
	return 0;
}
