#include<bits/stdc++.h>
using namespace std;
#define signed unsigned long long
signed v[10000+5];
const signed mod=998244353;

signed n,m,k;

signed fp[10000+5];

bool check()
{
	signed t=0;
	for(signed i=0;i<=m;++i)
	{
		t+=(1ull<<i)*fp[i];
	}
	signed tot=0;
	for(signed i=0;i<=19;++i)
	{
		if(t&(1ull<<i))
		{
			++tot;
		}
	}
	if(tot<=k)return true;
	return false;
}

signed ksm(signed a,signed b)
{
	if(b==0)
	{
		return 1;
	}
	signed t=ksm(a,b/2ull);
	if(b%2ull)
	{
		return (((t*t)%mod)*a)%mod;
	}
	return (t*t)%mod;
}


signed lo[1000+5];

signed ans=0;

void force(signed rt,signed sum)
{
	//cout<<"force "<<rt<<" "<<last<<" "<<sum<<endl;
	if(rt==m)
	{
		fp[m]=sum;
		//cout<<" ";for(signed i=0;i<=m;++i) cout<<fp[i]<<" ";cout<<endl;
		if(check())
		{
			
			signed t=lo[n];
			//cout<<lo[n]<<endl;
			for(signed i=0;i<=m;++i)
			{
				t*=ksm(lo[fp[i]],mod-2);
				t%=mod;
				//cout<<"r "<<t<<endl;
				t*=ksm(v[i],fp[i]);
				t%=mod;
			}
			//cout<<"t "<<t<<endl;
			ans+=t;
			ans%=mod;
		}
		return;
	}
	for(signed i=0;i<=sum;++i)
	{
		fp[rt]=i;
		force(rt+1,sum-i);
		fp[rt]=0;
	}
}


int main()
{
	lo[0]=1;
	lo[1]=1;
	for(signed i=2;i<=55;++i)
	{
		lo[i]=(lo[i-1]*i)%mod;
	}
	//998244353 is a prime
	
	
	ios::sync_with_stdio(0);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	
	cin>>n>>m>>k;
	
	for(signed i=0;i<=m;++i)
	{
		cin>>v[i];
	}
	force(0,n);
	cout<<ans<<endl;
	
	return 0;
}
