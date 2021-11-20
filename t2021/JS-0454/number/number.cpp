#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second

using namespace std;
const int N=1e7+200;
bool vis[N];
int ans[N];
bool check(int x)
{
	while(x)
	{
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
void init()
{
	for(int i=1;i<=10000100;i++)
	{
		if(!vis[i]&&check(i))
		{
			vis[i]=true;
			for(int j=i+i;j<=10000100;j+=i)
				vis[j]=true;
		}
	}
	int qwq=0;
	for(int i=10000100;i>=1;i--)
	{
		ans[i]=qwq;
		if(!vis[i])qwq=i;
	}
	return;
}
int T;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	scanf("%d",&T);
	while(T--)
	{
		int x;
		scanf("%d",&x);
		if(vis[x])printf("-1\n");
		else printf("%d\n",ans[x]);
	}
	return 0;
}
