#include<bits/stdc++.h>
#define ALL(v) v.begin(),v.end()
#define srt(v) sort(ALL(v))
#define rALL(v) v.rbegin(),v.rend()
#define rsrt(v) sort(rALL(v))
#define rev(v) reverse(ALL(v))
#define sz(v) (int)(v.size())
#define inf 0x3f3f3f3f
#define eps 1e-9
#define pii pair<int,int>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int maxn=10001000;
bool valid[10001010];
int ans[10001010];
bool P(int x)
{
	while(x)
	{
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}
void init()
{
	memset(valid,1,sizeof(valid));
	vector<int> pnums;
	for(int i=1;i<=maxn;i++)
	{
		if(!valid[i]||P(i))
		{
			pnums.pb(i);
			for(register ll j=i;j<=maxn;j*=i)
			{
				valid[j]=0;
			}
			if(i>=(int)(sqrt(maxn)))
				for(register int j=i;j<=maxn;j+=i)
					valid[j]=0;
			else for(register int j=1;j<=i;j++)
				valid[j*i]=0;
		}
		for(register int j=0;j<sz(pnums);j++)
		{
			if(i%pnums[j]&&i<=maxn/pnums[j])
				valid[i*pnums[j]]=0;
			else break;
		}
	}
	int x=maxn+1;
	for(int i=maxn;i>=1;i--)
	{
		ans[i]=x;
		if(valid[i])
			x=i;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	scanf("%d",&t);
	if(t<=10000)
		maxn=200200;
	init();
	while(t--)
	{
		int x;
		scanf("%d",&x);
		if(!valid[x])
			puts("-1");
		else	printf("%d\n",ans[x]);
	}
	return 0;
}
