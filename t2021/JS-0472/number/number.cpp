#include<bits/stdc++.h>
using namespace std;
int T,n;
const int MAXN=10000000;
int a[MAXN+5]; //a[1]:不符合要求的数 a[0]:符合要求的 
int b[MAXN+5]; //b[i]:第i个数之后最小的符合要求的数 
bool check(int p)
{
	while (p>0)
	{
		if (p%10==7) return false;
		p/=10;
	}
	return true;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for (int i=7;i<=MAXN+5;i++)
	{
		if (a[i]==1) continue;
		else if (!(check(i)))
		{
			for (int j=i;j<=MAXN+5;j+=i)
			a[j]=1;
		}
	}
	b[MAXN]=10000001;
	for (int i=MAXN-1;i>=1;i--)
	{
		if (a[i+1]==0) b[i]=i+1;
		else b[i]=b[i+1];
	}
	/*for (int i=1;i<=MAXN;i++)
	printf("%d ",b[i]);
	for (int i=1;i<=MAXN+1005;i++)
	if (a[i]==1) printf("%d ",i);*/
	while (T--)
	{
		scanf("%d",&n);
		if (a[n]==1)
		{
			printf("-1\n");
			continue;
		}
		if (n==0)
		{
			printf("1\n");
			continue;
		}
		printf("%d\n",b[n]);
	}
	return 0;
}
