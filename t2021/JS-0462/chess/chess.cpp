#include<bits/stdc++.h>
using namespace std;
int n,m,q,cl[202020],lv[202020],vis[202020],vis3[202020];
vector<vector<int> >to;
vector<pair<int,pair<int,int> > >v[202020];
string s1[202020],s2[202020];
void add(int a1,int b1,int a2,int b2,int e,int ee)
{
	int x=to[a1][b1];
	int y=to[a2][b2];
	if(e>0)
	{
		v[x].push_back(make_pair(y,make_pair(e,ee)));
		v[y].push_back(make_pair(x,make_pair(e,ee+1)));
	}
}
void dfs2(int cc,int ll,int nm,int fx)
{
	for(int i=0;i<v[nm].size();i++)
	{
		int x=v[nm][i].first;
		if(v[nm][i].second!=make_pair(2,fx) || cc==cl[x] || ll<lv[x])
		{
			continue;
		}
		vis[x]=1;
		if(cl[x]==-1)
		{
			dfs2(cc,ll,x,fx);
		}
	}
}
void dfs3(int cc,int ll,int nm)
{
	for(int i=0;i<v[nm].size();i++)
	{
		int x=v[nm][i].first;
		if(v[nm][i].second.first!=3 || vis3[x] || cc==cl[x] || ll<lv[x])
		{
			continue;
		}
		vis3[x]=1;
		if(cl[x]==-1)
		{
			dfs3(cc,ll,x);
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;
		to.resize(n+1);
		memset(cl,-1,sizeof(cl));
		memset(lv,-1,sizeof(lv));
		for(int i=0;i<=n;i++)
		{
			to[i].resize(m+1);
		}
		int x=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				x++;
				to[i][j]=x;
				v[x].clear();
			}
		}
		bool hs1=false,hs2=false,hs3=false;
		for(int i=1;i<=n;i++)
		{
			cin>>s1[i];
			for(int j=2;j<=m;j++)
			{
				if(s1[i][j-2]=='1')
				{
					hs1=true;
				}
				if(s1[i][j-2]=='2')
				{
					hs2=true;
				}
				if(s1[i][j-2]=='3')
				{
					hs3=true;
				}
				add(i,j-1,i,j,s1[i][j-2]-'0',1);
			}
		}
		for(int i=2;i<=n;i++)
		{
			cin>>s2[i];
			for(int j=1;j<=m;j++)
			{
				if(s2[i][j-1]=='1')
				{
					hs1=true;
				}
				if(s2[i][j-1]=='2')
				{
					hs2=true;
				}
				if(s2[i][j-1]=='3')
				{
					hs3=true;
				}
				add(i-1,j,i,j,s2[i][j-1]-'0',3);
			}
		}
		while(q--)
		{
			int cc,ll,x,y;
			scanf("%d %d %d %d",&cc,&ll,&x,&y);
			int nm=to[x][y];
			cl[nm]=cc;
			lv[nm]=ll;
			int ans=0;
			for(int i=0;i<v[nm].size();i++)
			{
				int x=v[nm][i].first;
				if(v[nm][i].second.first==1 && cl[nm]!=cl[x] && lv[nm]>=lv[x])
				{
					ans++;
				}
			}
			if(!hs2 && !hs3)
			{
				printf("%d\n",ans);
				continue;
			}
			for(int i=0;i<n*m+5;i++)
			{
				vis[i]=0;
				vis3[i]=0;
			}
			for(int i=0;i<v[nm].size();i++)
			{
				int x=v[nm][i].first;
				if(v[nm][i].second.first==1 && cl[nm]!=cl[x] && lv[nm]>=lv[x])
				{
					vis[x]=1;
				}
			}
			ans=0;
			dfs2(cc,ll,nm,1);
			dfs2(cc,ll,nm,2);
			dfs2(cc,ll,nm,3);
			dfs2(cc,ll,nm,4);
			dfs3(cc,ll,nm);
			for(int i=1;i<=n*m;i++)
			{
				if(vis[i] || vis3[i])
				{
					ans++; 
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
