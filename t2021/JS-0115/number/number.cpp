#include<bits/stdc++.h>
using namespace std;

const int maxn=10001000;

bool vis[11000010],chk[11000010];
int nxt[10010010],pr[2000010],flag[10010010];
int t,x,cnt;

bool check(int x)
{
	while(x)
	{
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}

void prework()
{
	for(int i=1;i<=maxn;i++) vis[i]=check(i);
	for(int i=2;i<=maxn;i++)
	{
		if(!chk[i]) 
		{
			pr[++cnt]=i;
			flag[i]=i;
		}
		for(int j=1;i*pr[j]<=maxn;j++)
		{
			chk[i*pr[j]]=1;
			flag[i*pr[j]]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
//	for(int i=1;i<=10;i++) cout<<pr[i]<<endl;
	for(int i=2;i<=maxn;i++) if(!vis[i]) vis[i]=((vis[flag[i]])|(vis[i/flag[i]]));
	
	int now=1;
	for(int i=2;i<=maxn;i++) 
	{
		if(!vis[i])
		{
			nxt[now]=i;
			now=i;
		}
	} 
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	prework();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		if(vis[x]) printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
