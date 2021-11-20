#include<bits/stdc++.h>

using namespace std;

const int MAXN=2*1e5+7;

struct Edge{
	int v,nxt,opt;
}edge[MAXN*4];

int n,m,q,p,cnt,ans;
int head[MAXN];
bool vis[MAXN],vis1[MAXN];
int col[MAXN],lv[MAXN];

void add_edge(int u,int v,int opt)
{
	edge[++cnt].v=v;
	edge[cnt].opt=opt;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}

inline int read()
{
	int x=0,sign=0;char ch=getchar();
	while(ch>'9'||ch<'0') sign|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return sign?-x:x;
}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int lastd=-1;
void dfs(int u,int c,int nowopt)
{
	
	int nx=(u-1)/m+1,ny=((u-1)%m)+1;
//	cout<<nx<<' '<<ny<<endl;
//	cout<<lastd<<endl;
	if(!vis1[u]) ++ans;
	if(vis[u]) return ;
	vis1[u]=vis[u]=true;
	
	if(nowopt==1) 
	{
		vis[u]=false;
		return ;
	}
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int v=edge[i].v,opt=edge[i].opt;
		if(vis[v]) continue;
		int tx=(v-1)/m+1,ty=((v-1)%m)+1;
		if(nowopt==-1)
		{
			if(opt==0) continue;
			if(opt==1)
			{
				if(col[v]!=c) 
				{
					if(!vis1[v])
					{
						++ans;
						vis1[v]=true;
					}
				}
			}
			
			if(opt==2)
			{
				if(col[v]!=-1) 
				{
					if(col[v]!=c&&lv[p]>=lv[v]&&!vis1[v]) 
					{
						++ans;
						vis1[v]=true;
					}
					continue;
				}
				
				for(int i=0;i<4;++i)
				{
					if(nx+dx[i]==tx&&ny+dy[i]==tx) 
					{
						lastd=i;
						break;
					}
				}
				dfs(v,c,opt);
				lastd=-1;
				
			}
			
			if(opt==3)
			{
				if(col[v]!=-1) 
				{
					if(col[v]!=c&&lv[p]>=lv[v]&&!vis1[v]) 
					{
						++ans;
						vis1[v]=true;
					}
					continue;
				}
				dfs(v,c,opt);
			}
		}
		else 
		{
			if(opt==0) continue;
			if(opt!=nowopt) continue;
			
			if(opt==1)
			{
				continue;
			}
			
			if(opt==2)
			{
				int nowd;
				for(int i=0;i<4;++i)
				{
					if(nx+dx[i]==tx&&ny+dy[i]==ty)
					{
						nowd=i;
						break;
					}
				}
				//cout<<tx<<' '<<ty<<endl;
				if(nowd!=lastd)
				{
					continue;
				}
				
				if(col[v]!=-1)
				{
					if(col[v]!=c&&lv[p]>=lv[v]&&!vis1[v]) 
					{
						++ans; 
						vis1[v]=true;
					}
					continue;
				}
				dfs(v,c,opt);
			}
			
			if(opt==3)
			{
				if(col[v]!=-1)
				{
					if(col[v]!=c&&lv[p]>=lv[v]&&!vis1[v]) 
					{
						++ans; 
						vis1[v]=true;
					}
					continue;
				}
				dfs(v,c,opt);
			}
		}
		
	}
	vis[u]=false;
	
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	T=read();
	while(T--)
	{
		n=read();m=read();q=read();
		
		cnt=0;
		for(int i=1;i<=n*m;++i) 
		{
			head[i]=0;col[i]=-1;lv[i]=0;
		}
		
		int opt;
		string s;
		for(int i=1;i<=n;++i)
		{
			cin>>s;
			for(int j=1;j<m;++j)
			{
				opt=s[j-1]-'0';
				add_edge(m*(i-1)+j,m*(i-1)+j+1,opt);
				add_edge(m*(i-1)+j+1,m*(i-1)+j,opt);
			}
		}
		for(int i=1;i<n;++i)
		{
			cin>>s;
			for(int j=1;j<=m;++j)
			{
				
				opt=s[j-1]-'0';
				add_edge((i-1)*m+j,i*m+j,opt);
				add_edge(i*m+j,(i-1)*m+j,opt);
			}
		}
		
		for(int i=1;i<=q;++i)
		{
			int c=read(),lev=read(),x=read(),y=read();
			p=m*(x-1)+y;
			ans=-1;
			col[p]=c;
			lv[p]=lev;
			dfs(p,c,-1);
			for(int i=1;i<=n*m;++i)
			{
				vis1[i]=false;
			}
			cout<<ans<<endl;
		}
		
	}
	
	return 0;
}
/*

1 
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
*/


