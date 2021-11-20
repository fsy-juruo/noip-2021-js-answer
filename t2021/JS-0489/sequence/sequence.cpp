#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+5;
const long long mod=998244353;
const long long inf=0x3f3f3f3f;
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
long long n,m,k;
long long v[maxn],hfs[maxn],nm,mf[maxn];
set<long long> st;
long long quick_pow(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1)
			res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
long long ans=0;
void dfs(long long stp,long long nw,long long qz)
{
	if(stp==n+1)
	{
		if(st.count(nw)!=0)
		{
			ans+=qz;
			if(ans>=mod)
				ans-=mod;
//			cout<<ans<<endl;
		}
		return ;
	}
	for(long long i=0;i<=m;i++)
	{
		long long dq=nw+mf[i];
		if(dq>=mod)
			dq-=mod;
		long long nq=qz*v[i]%mod;
		dfs(stp+1,dq,nq);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=0;i<=m;i++)
		cin>>v[i];
	for(long long i=0;i<=m;i++)
		mf[i]=quick_pow(2,i);
	for(long long s=n;s<=n*quick_pow(2,m);s++)
	{
		long long cnt=0,x=s;
		for(long long j=0;j<=20;j++)
		{
			if((x&(1<<j))) 
			{
				cnt++;
				x-=(1<<j);
			}
		}
		if(cnt<=k)
		{
			hfs[++nm]=s;
			st.insert(s);
		}
//		cout<<s<<" "<<cnt<<endl;
	}
//	for(long long i=1;i<=nm;i++)
//		cout<<hfs[i]<<" ";
//	cout<<endl; 
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}

