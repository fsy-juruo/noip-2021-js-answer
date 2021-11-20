#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int maxm=100+1;
const int maxs=524288;
const int maxn=30+1;
int f[maxm][maxs];
int v[maxn];
int n,m,k;
int ans;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++) scanf("%d",&v[i]);
	for(int add=0;add<=m;add++) f[1][1<<add]=v[add];
	for(int c=2;c<=n;c++) 
	{
		for(int s=c;s<=c*(1<<m);s++)
		{
			//c&s confirmed
			for(int add=0;(1<<add)<=s;add++)
			{
				f[c][s]=(f[c][s]+f[c-1][s-(1<<add)]*v[add])%MOD;
			}
		}
	}
	bitset<30> b;
	for(int i=m;i<=n*(1<<m);i++)
	{
		b=i;
		if(b.count()<=k)
		{
			ans=(ans+f[n][i])%MOD;
		}
	}
	printf("%d",ans);
	return 0;
}
