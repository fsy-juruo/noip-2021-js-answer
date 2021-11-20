#include<bits/stdc++.h>

using namespace std;
string s[100005];
string t[100005];
int n,m,Q;

int col[200005],lv[200005];
bool vis[200005];
bool d[200005];

queue<pair<int,int> >q;

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(col,0,sizeof col);
		memset(lv,0,sizeof lv);
		scanf("%d%d%d",&n,&m,&Q);
		for(int i=1;i<=n;++i)
		{
			cin>>s[i];
			s[i]=" "+s[i];
		}
		for(int i=1;i<n;++i)
		{
			cin>>t[i];
			t[i]=" "+t[i];
		}
		while(Q--)
		{
			int x,y,c,v;
			scanf("%d%d%d%d",&c,&v,&x,&y);
			col[(x-1)*m+y]=c,lv[(x-1)*m+y]=v;
			
			if(t[x-1][y]=='1'&&(!lv[(x-2)*m+y]||lv[(x-2)*m+y]<=v&&col[(x-2)*m+y]!=c)) vis[(x-2)*m+y]=1;
			if(t[x][y]=='1'&&(!lv[x*m+y]||lv[x*m+y]<=v&&col[x*m+y]!=c)) vis[x*m+y]=1;
			if(s[x][y-1]=='1'&&(!lv[(x-1)*m+y-1]||lv[(x-1)*m+y-1]<=v&&col[(x-1)*m+y-1]!=c)) vis[(x-1)*m+y-1]=1;
			if(s[x][y]=='1'&&(!lv[(x-1)*m+y+1]||lv[(x-1)*m+y+1]<=v&&col[(x-1)*m+y+1]!=c)) vis[(x-1)*m+y+1]=1;
			
			if(t[x-1][y]=='2')
			{
				int k=x;
				while(t[k-1][y]=='2'&&!lv[(k-2)*m+y]) --k;
				for(int i=k;i<x;++i) vis[(i-1)*m+y]=1;
				if(t[k-1][y]=='2'&&col[(k-2)*m+y]!=c&&lv[(k-2)*m+y]<=v) vis[(k-2)*m+y]=1;
			}
			if(t[x][y]=='2')
			{
				int k=x;
				while(t[k][y]=='2'&&!lv[k*m+y]) ++k;
				for(int i=x+1;i<=k;++i) vis[(i-1)*m+y]=1;
				if(t[k][y]=='2'&&col[k*m+y]!=c&&lv[k*m+y]<=v) vis[k*m+y]=1;
			}
			if(s[x][y-1]=='2')
			{
				int k=y;
				while(s[x][k-1]=='2'&&!lv[(x-1)*m+k-1]) --k;
				for(int i=k;i<y;++i) vis[(x-1)*m+i]=1;
				if(s[x][k-1]=='2'&&col[(x-1)*m+k-1]!=c&&lv[(x-1)*m+k-1]<=v) vis[(x-1)*m+k-1]=1;
			}
			if(s[x][y]=='2')
			{
				int k=y;
				while(s[x][k]=='2'&&!lv[(x-1)*m+k+1]) ++k;
				for(int i=y+1;i<=k;++i) vis[(x-1)*m+i]=1;
				if(s[x][k]=='2'&&col[(x-1)*m+k+1]!=c&&lv[(x-1)*m+k+1]<=v) vis[(x-1)*m+k+1]=1;
			}
			
			q.push(make_pair(x,y));
			while(!q.empty())
			{
				int u=q.front().first;
				int w=q.front().second;
				q.pop();
				if(d[(u-1)*m+w]) continue;
				d[(u-1)*m+w]=1;
				if(t[u-1][w]=='3')
				{
					if(!lv[(u-2)*m+w])
					{
						vis[(u-2)*m+w]=1;
						q.push(make_pair(u-1,w));
					}
					else if(col[(u-2)*m+w]!=c&&lv[(u-2)*m+w]<=v)
					{
						vis[(u-2)*m+w]=1;
					}
				}
				if(t[u][w]=='3')
				{
					if(!lv[u*m+w])
					{
						vis[u*m+w]=1;
						q.push(make_pair(u+1,w));
					}
					else if(col[u*m+w]!=c&&lv[u*m+w]<=v)
					{
						vis[u*m+w]=1;
					}
				}
				if(s[u][w-1]=='3')
				{
					if(!lv[(u-1)*m+w-1])
					{
						vis[(u-1)*m+w-1]=1;
						q.push(make_pair(u,w-1));
					}
					else if(col[(u-1)*m+w-1]!=c&&lv[(u-1)*m+w-1]<=v)
					{
						vis[(u-1)*m+w-1]=1;
					}
				}
				if(s[u][w]=='3')
				{
					if(!lv[(u-1)*m+w+1])
					{
						vis[(u-1)*m+w+1]=1;
						q.push(make_pair(u,w+1));
					}
					else if(col[(u-1)*m+w+1]!=c&&lv[(u-1)*m+w+1]<=v)
					{
						vis[(u-1)*m+w+1]=1;
					}
				}
			}
			
			int cnt=0;
			for(int i=1;i<=n*m;++i)
			{
				if(vis[i]) ++cnt,vis[i]=0;
				d[i]=0;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
