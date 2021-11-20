#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

bool good[12000000];
int ans[12000000],t,x;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	repn(i,11000000) good[i]=true;
	repn(i,11000000) if(good[i])
	{
		bool bad=false;
		int tmp=i;
		while(tmp>0)
		{
			if(tmp%10==7)
			{
				bad=true;
				break;
			}
			tmp/=10;
		}
		if(!bad) continue;
		good[i]=false;
		for(int j=i+i;j<=11000000;j+=i) good[j]=false;
	}
	int nxt=-1;
	for(int i=11000000;i>=0;--i)
	{
		if(!good[i]) ans[i]=-1;
		else
		{
			ans[i]=nxt;
			nxt=i;
		}
	}
	cin>>t;
	rep(tn,t)
	{
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}
