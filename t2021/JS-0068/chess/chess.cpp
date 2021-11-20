#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
const int maxn=2e5+10;
int T;	
int n,m,q;
bool chess[maxn];
int col[maxn];
int lv[maxn];
char a[maxn];
vector<pair<int,int> > g[maxn];
void init()
{
	for(int i=0;i<maxn;i++)
	{
		g[i].clear();
		chess[i]=0;
	}
}
int getpos(int x,int y)
{
	return (x-1)*m+y;
}
struct go
{
	int now,hen;
};
int bfs(int now,int lvv,int coll)
{
	int vis[maxn],ans=0,cnt[maxn];
	for(int i=0;i<maxn;i++)
	{
		vis[i]=0;
		cnt[i]=0;
	}
	queue<int> qq;//3 
	qq.push(now);
	vis[now]=true;
	while(qq.size())
	{
		int from=qq.front();
		qq.pop();
		for(int i=0;i<g[from].size();i++)
		{
			int to=g[from][i].first,r=g[from][i].second;
			//cout<<from<<" "<<to<<" "<<r<<endl;
			if(r!=3||vis[to])
			{
				continue;	
			}		
			if(chess[to])
			{
				if(lv[to]>lvv||col[to]==coll)
				{
					continue;
				}
				else 
				{
					cnt[to]=true;
					vis[to]=true;
					continue;
				}
			}	
			vis[to]=true;
			cnt[to]=true;
			qq.push(to);
		}
	}	
	//cout<<ans<<endl;
	//2
	for(int i=0;i<maxn;i++)
	{
		vis[i]=0;
	}	
	vis[now]=true;
	queue<go> qqq;
	qqq.push((go){now,0});
	while(qqq.size())
	{
		int from=qqq.front().now,hen=qqq.front().hen;
		qqq.pop();
		for(int i=0;i<g[from].size();i++)
		{
			
			int to=g[from][i].first,r=g[from][i].second;
			//cout<<from<<" "<<r<<endl;
			if(vis[to])
			{
				continue;
			}
			if(r!=2)
			{
				continue;
			}
			if(from==now)
			{
				goto A;
			}			
			if(hen)
			{
				if(abs(from-to)!=1)
				{
					continue;
				}
			}
			else
			{
				if(abs(from-to)!=n)
				{
					continue;
				}
			}
			A:			
			if(chess[to])
			{
				if(lv[to]>lvv||col[to]==coll)
				{
					continue;
				}
				else 
				{
					cnt[to]=true;
					vis[to]=true;
					continue;
				}
			}		
			if(from==now)
			{
				if(abs(from-to)==1)
				{
					hen=1;
				}
				else
				{
					hen=0;
				}						
			}
			vis[to]=true;
			cnt[to]=true;		
			qqq.push((go){to,hen});		
		}
	}
	//cout<<ans<<endl;	
	for(int i=0;i<g[now].size();i++)
	{
		int to=g[now][i].first,r=g[now][i].second;
		//cout<<to<<" "<<r<<endl;
		if(r!=1||cnt[to])
		{
			continue;
		}
		if(chess[to])
		{
			if(lv[to]>lvv||col[to]==coll)
			{
				continue;
			}
		}
		//cout<<to<<" "<<r<<endl;
		cnt[to]=true;
	}	
	for(int i=0;i<maxn;i++)
	{
		if(cnt[i])
		{
			//cout<<i<<endl;
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		init();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",a+1);
			for(int j=1;j<=m-1;j++)
			{
				if(a[j])
				{
					g[getpos(i,j)].push_back(make_pair(getpos(i,j+1),a[j]-'0'));
					g[getpos(i,j+1)].push_back(make_pair(getpos(i,j),a[j]-'0'));
	//				cout<<getpos(i,j)<<" "<<getpos(i,j+1)<<" "<<a[j]-'0'<<endl;
				}	
			}
		}		
		for(int i=1;i<=n-1;i++)
		{
			scanf("%s",a+1);
			for(int j=1;j<=m;j++)
			{
				if(a[j])
				{
					g[getpos(i,j)].push_back(make_pair(getpos(i+1,j),a[j]-'0'));
					g[getpos(i+1,j)].push_back(make_pair(getpos(i,j),a[j]-'0'));
				}	
			}
		}
		while(q--)
		{
			int coll,lvv,x,y,po;
			scanf("%d%d%d%d",&coll,&lvv,&x,&y);
			po=getpos(x,y);
			int t=bfs(po,lvv,coll);
			//cout<<po<<"dda"<<endl;
			printf("%d\n",t);
			chess[po]=true;
			col[po]=coll;
			lv[po]=lvv;
		}			
	}
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
