#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int MAXN=10005;

int n;

set< vector<ll> > s;

ll a[MAXN];
vector<ll> v;
ll s1,s2,ans;
int cnt=0;
int maxd;

void dfs(int d)
{
	++cnt;
	if(d>maxd) return;
	ll tmp,os1=s1,os2=s2;
	for(int i=2;i<=n-1;++i)
	{
		tmp=v[i-1];
		v[i-1]=v[i-2]+v[i]-v[i-1];
	
		s1=s1-tmp+v[i-1];
		s2=s2-tmp*tmp+v[i-1]*v[i-1]; 
		if(s.find(v)==s.end())
		{
			s.insert(v);
			ans=min(ans,n*s2-s1*s1);
			dfs(d+1);
		}

		v[i-1]=tmp;
		s1=os1;
		s2=os2;
	}	
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		v.push_back(a[i]);
		s1+=a[i];
		s2+=a[i]*a[i];
	}
	ans=n*s2-s1*s1;
	for(maxd=1;cnt<=15000;++maxd)
	{
		s.clear();
		dfs(1);
	}
	cout<<ans<<endl;
	return 0;
}
