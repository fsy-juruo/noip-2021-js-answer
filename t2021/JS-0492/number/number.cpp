#include<bits/stdc++.h>
using namespace std;
const int maxt=2e5+10,maxn=2e7+10;
int t,q[maxt];
vector<int> v;
bool f[maxn];
bool check(int x)
{
	while(x)
	{
		if(x%10==7)
		{
			return true;
		}
		x/=10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	int mx=0;
	for(int i=1;i<=t;i++)
	{
		scanf("%d",q+i);
		mx=max(mx,q[i]);
	}
	for(int i=0;i<=mx+mx;i++)
	{
		if(check(i))
		{
			f[i]=1;
			for(int j=i;j<=mx+mx;j+=i)
			{
				f[j]=1;
			}
		}
	}
	for(int i=0;i<=mx+mx;i++)
	{
		if(!f[i])
		{
			v.push_back(i);
		}
	}
	for(int i=1;i<=t;i++)
	{
		if(f[q[i]])
		{
			printf("-1\n");
		}
		else
		{
			int nxt=*upper_bound(v.begin(),v.end(),q[i]);
			printf("%d\n",nxt);
		}
	}
	return 0;
}
/*
1. copy the names of the problems
2. freopen
3. int, long long overflow
4. memory overflow
5. delete debug sentences
6. list the main ideas
7. special cases
*/
