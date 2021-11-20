#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 10010
using namespace std;
ll n,a[N],d[N],dp[(1<<14)+5][305],sum[(1<<14)+5],bct[(1<<14)+5],ans=LINF;
map<pair<pair<ll,ll>,ll>,ll> mp1,mp2;
ll calc()
{
	ll csm=0,sq=0,i;
	for(i=0;i<n;i++)
	{
		csm+=a[i];
		sq+=n*a[i]*a[i];
	}
	return sq-csm*csm;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ll i,j,mask;
	scanf("%lld",&n);
	for(i=0;i<n;++i)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<n;++i)
	{
		d[i-1]=a[i]-a[i-1];
	}
	if(n<=10)
	{
		vector<ll> p;
		for(i=0;i<n-1;i++)
		{
			p.push_back(i);
		}
		do
		{
			for(i=0;i<(int)p.size();i++)
			{
				a[i+1]=a[i]+d[p[i]];
			}
			ans=min(ans,calc());
		}while(next_permutation(p.begin(),p.end()));
	}
	else if(n<=15)
	{
		for(mask=0;mask<(1<<(n-1));++mask)
		{
			sum[mask]=0;
			bct[mask]=0;
			for(i=0;i+1<n;++i)
			{
				if(mask&(1<<i))
				{
					++bct[mask];
					sum[mask]+=d[i];
				}
			}
			for(i=0;i<=300;++i)
			{
				dp[mask][i]=LINF;
			}
		}
		dp[0][0]=0;
		for(mask=0;mask<(1<<(n-1));++mask)
		{
			for(i=0;i<=20*bct[mask];++i)
			{
				if(dp[mask][i]<LINF)
				{
					for(j=0;j<n-1;++j)
					{
						if(!(mask&(1<<j)))
						{
							dp[mask|(1<<j)][i+sum[mask|(1<<j)]]=min(dp[mask|(1<<j)][i+sum[mask|(1<<j)]],dp[mask][i]+n*sum[mask|(1<<j)]*sum[mask|(1<<j)]);
						}
					}
				}
			}
		}
		for(i=0;i<=300;++i)
		{
			ans=min(ans,dp[(1<<(n-1))-1][i]-i*i);
		}
	}
	else if(n<=20)
	{
		vector<ll> v1,v2;
		for(mask=0;mask<(1<<(n-1));++mask)
		{
			v1.clear();
			v2.clear();
			for(i=0;i<n-1;++i)
			{
				if(mask&(1<<i))
				{
					v1.push_back(d[i]);
				}
				else
				{
					v2.push_back(d[i]);
				}
			}
			sort(v1.begin(),v1.end());
			reverse(v1.begin(),v1.end());
			sort(v2.begin(),v2.end());
			for(i=0;i<(int)v1.size();++i)
			{
				a[i+1]=a[i]+v1[i];
			}
			for(i=0;i<(int)v2.size();++i)
			{
				a[i+v1.size()+1]=a[i+v1.size()]+v2[i];
			}
			ans=min(ans,calc());
		}
	}
	else
	{
		sort(d,d+n-1);
		reverse(d,d+n-1);
		mp1[make_pair(make_pair(0,0),0)]=0;
		for(i=0;i<n-1;++i)
		{
			mp2.clear();
			for(map<pair<pair<ll,ll>,ll>,ll>::iterator it=mp1.begin();it!=mp1.end();it++)
			{
				ll s1=(it->F).F.F,s2=(it->F).F.S,s3=(it->F).S;
				ll ns=s1+d[i];
				if(!mp2.count(make_pair(make_pair(ns,s2),s3+ns)))
				{
					mp2[make_pair(make_pair(ns,s2),s3+ns)]=it->S+n*ns*ns;
				}
				else
				{
					mp2[make_pair(make_pair(ns,s2),s3+ns)]=min(mp2[make_pair(make_pair(ns,s2),s3+ns)],it->S+n*ns*ns);
				}
				ns=a[n-1]-a[0]-s2;
				if(!mp2.count(make_pair(make_pair(s1,s2+d[i]),s3+ns)))
				{
					mp2[make_pair(make_pair(s1,s2+d[i]),s3+ns)]=it->S+n*ns*ns;
				}
				else
				{
					mp2[make_pair(make_pair(s1,s2+d[i]),s3+ns)]=min(mp2[make_pair(make_pair(s1,s2+d[i]),s3+ns)],it->S+n*ns*ns);
				}
			}
			mp1=mp2;
		}
		for(map<pair<pair<ll,ll>,ll>,ll>::iterator it=mp1.begin();it!=mp1.end();it++)
		{
			ans=min(ans,it->S-(it->F).S*(it->F).S);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
