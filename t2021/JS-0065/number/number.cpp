#include<bits/stdc++.h>
#define ll long long
#define N 10005007
using namespace std;
bool hx[N];
bool check(int x)
{
	while(x)
	{
		if (x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int prime[800005],cnt;
int T,q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i=1;i<=10005000;++i)
	{
		if (!hx[i])
		{
			if (check(i))
			{
				for (int j=i;j<=10005000;j+=i)
				hx[j]=1;
			}
		}
		if (!hx[i])prime[++cnt]=i;
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&q);
		if (hx[q])printf("-1\n");
		else{
			int x=lower_bound(prime+1,prime+cnt+1,q)-prime;
			printf("%d\n",prime[x+1]);
		}
	}
	return 0;
}

