#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,qs,head[N],to[N*2],nxt[N*2],lev[N],num[4],cnt,c[N];
bool flag[N][4],f2[N][4],vis[N],vi[N],col[N];
queue<int> q;
int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void add(int u,int v)
{
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void sol1()
{
	while(qs--)
	{
		memset(vis,false,sizeof(vis));
		memset(vi,false,sizeof(vi));
		for(int i=1; i<=n*m; i++)
			c[i]=1;
		int ans=0;
		int a=read(),b=read(),x=read()-1,y=read();
		int pos=x*m+y;
		lev[pos]=b;
		col[pos]=a;
		c[pos]=0;
		for(int i=0; i<4; i++)
		{
			int v=pos+num[i];
			if(flag[pos][i])
			{
				if(!lev[v])
				{
					ans++;
					vi[v]=true;
				}
				else if(lev[v]<=lev[pos]&&col[pos]!=col[v])
				{
					ans++;
					vi[v]=true;
				}
			}
		}
//		printf("%d ",ans);
//		printf("%d\n",ans);
		for(int i=0; i<4; i++)
		{
			int u=pos;
			while(1<2)
			{
				vi[u]=true;
				if(!f2[u][i]) break;
				int v=u+num[i];
//				printf("%d %d ",u,v);
//				printf("%d\n",po);
				if(lev[v])
				{
					if(lev[v]<=lev[pos]&&col[v]!=col[pos])
					{
						ans++;
						vi[v]=true;
					}
					break;
				}
				ans++;
				u=v;
			}
		}
//		printf("%d ",ans);
		q.push(pos);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			vis[u]=true;
			for(int i=head[u]; i; i=nxt[i])
			{
				int v=to[i];
				if(vis[v]) continue;
				if(lev[v]&&lev[v]<=lev[pos]&&col[v]!=col[pos]&&!vi[v])
				{
					ans++;
				}
				if(!lev[v])
				{
					q.push(v);
					if(!vi[v])
						ans++;
//					printf("%d ",vi[v]);
				}
			}
		}
		printf("%d\n",ans);
	}
}
void sol2()
{
	int ans=0;
	int a=read(),b=read(),x=read()-1,y=read();
	int pos=x*m+y;
	lev[pos]=b;
	col[pos]=a;
	for(int i=0; i<4; i++)
	{
		int v=pos+num[i];
		if(flag[pos][i])
		{
			if(!lev[v])
			{
				ans++;
			}
			else if(lev[v]<=lev[pos]&&col[pos]!=col[v])
			{
				ans++;
			}
		}
	}
		printf("%d\n",ans);
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int tt=read();
	while(tt--)
	{
		n=read(),m=read(),qs=read();
		num[0]=1,num[1]=-1,num[2]=m,num[3]=-m;
		int cn2=0,cn3=0;
		memset(head,0,sizeof(head));
		memset(to,0,sizeof(to));
		memset(nxt,0,sizeof(nxt));
		memset(flag,0,sizeof(flag));
		memset(f2,0,sizeof(f2));
		memset(lev,0,sizeof(lev));
		memset(col,0,sizeof(col));
		cnt=0;
		for(int i=0; i<n; i++)
		{
			int j=1;
			while(j<m)
			{
				char ch=getchar();
				while(ch<'0'||ch>'3') ch=getchar();
				int u=i*m+j,v=i*m+j+1;
				if(ch=='1')
				{
					flag[u][0]=true;
					flag[v][1]=true;
				}
				if(ch=='2')
				{
					f2[u][0]=true;
					f2[v][1]=true;
					cn2++;
				}
				if(ch=='3')
				{
					add(u,v);
					add(v,u);
					cn3++;
				}
				j++;
			}
		}
		for(int i=0; i<n-1; i++)
		{
			int j=1;
			while(j<=m)
			{
				char ch=getchar();
				while(ch<'0'||ch>'3') ch=getchar();
				int u=i*m+j,v=(i+1)*m+j;
				if(ch=='1')
				{
					flag[u][2]=true;
					flag[v][3]=true;
				}
				if(ch=='2')
				{
					f2[u][2]=true;
					f2[v][3]=true;
					cn2++;
				}
				if(ch=='3')
				{
					add(u,v);
					add(v,u);
					cn3++;
				}
				j++;
			}
		}
		if(cn2==0&&cn3==0)
		{
			sol2();
		}
		else
		{
			sol1();
		}
	}
//	for(int i=0; i<n; i++)
//	{
//		for(int j=1; j<=m; j++)
//		{
//			printf("%d ",flag[i*m+j][0]);
//		}
//		puts("");
//	}
	return 0;
}

