#include<bits/stdc++.h>
using namespace std;

const int N=200005,M=5005;
int t,n,m,q;
int xy[4][2]={1,0,0,1,-1,0,0,-1};
int vis[N],cc[N],lc[N];
char tem[N];
queue<int> p;
vector<vector<int> > g1,g2;
vector<int> tt;

int getid(int x,int y,int i)
{
	if(i==0) return g2[x-1][y-1];
	if(i==1) return g1[x-1][y-1];
	if(i==2) return g2[x-2][y-1];
	return g1[x-1][y-2];
}

void bfs(int sx,int sy,int id,int cl,int ll)
{
	vis[sx*m-m+sy]=1,p.push(sx*m-m+sy);
//	cout<<sx<<' '<<sy<<' '<<sx*m-m+sy<<endl;
	while(!p.empty())
	{
		int u=p.front();
		p.pop();
		int ux=(u-1)/m+1,uy=(u-1)%m+1;
//		cout<<u<<' '<<ux<<' '<<uy<<endl;
		for(int i=0;i<4;i++)
		{
			int vx=ux+xy[i][0],vy=uy+xy[i][1];
			int v=vx*m-m+vy;
//			cout<<' '<<vx<<' '<<vy<<' '<<v<<' '<<getid(ux,uy,i)<<endl;
			if(vx<1||vx>n||vy<1||vy>m) continue;
			if(getid(ux,uy,i)!=id||vis[v]) continue;
			if(cc[v]==cl||cc[v]==3-cl&&lc[v]>ll) continue;
			vis[v]=1;
			if(cc[v]!=3-cl) p.push(v);
		}
	}
}

void solva()
{
	while(q--)
	{
		int x,y,z,w,ux,uy,res=0;
		scanf("%d%d%d%d",&z,&w,&x,&y),z++;
		memset(vis,0,sizeof(vis));
//		cout<<x<<' '<<y<<endl;
		bfs(x,y,3,z,w);
		for(int i=0;i<4;i++)
		{
			ux=x,uy=y;
			int vx=ux+xy[i][0],vy=uy+xy[i][1];
			int v=vx*m-m+vy;
//			cout<<' '<<vx<<' '<<vy<<endl;
			if(vx<1||vx>n||vy<1||vy>m) continue;
			if(getid(ux,uy,i)!=1) continue;
			if(cc[v]==z||cc[v]==3-z&&lc[v]>w) continue;
			vis[v]=1;
		}
//		cout<<1<<endl;
		for(int i=0;i<4;i++)
		{
			ux=x,uy=y;
			while(1)
			{
				int vx=ux+xy[i][0],vy=uy+xy[i][1];
				int v=vx*m-m+vy;
				if(vx<1||vx>n||vy<1||vy>m) break;
				if(getid(ux,uy,i)!=2) break;
				if(cc[v]==z||cc[v]==3-z&&lc[v]>w) break;
				vis[v]=1;
				if(cc[v]==3-z) break;
				ux=vx,uy=vy;
			}
		}
		for(int i=1;i<=n*m;i++) if(vis[i]) res++;
		printf("%d\n",res-1);
		cc[x*m-m+y]=z,lc[x*m-m+y]=w;
	}
}

void solvb()
{
	while(q--)
	{
		int x,y,z,w,ux,uy,res=0;
		scanf("%d%d%d%d",&z,&w,&x,&y),z++;
		for(int i=0;i<4;i++)
		{
			ux=x,uy=y;
			int vx=ux+xy[i][0],vy=uy+xy[i][1];
			int v=vx*m-m+vy;
//			cout<<' '<<vx<<' '<<vy<<endl;
			if(vx<1||vx>n||vy<1||vy>m) continue;
			if(getid(ux,uy,i)!=1) continue;
			if(cc[v]==z||cc[v]==3-z&&lc[v]>w) continue;
			res++;
		}
		for(int i=0;i<4;i++)
		{
			ux=x,uy=y;
			while(1)
			{
				int vx=ux+xy[i][0],vy=uy+xy[i][1];
				int v=vx*m-m+vy;
				if(vx<1||vx>n||vy<1||vy>m) break;
				if(getid(ux,uy,i)!=2) break;
				if(cc[v]==z||cc[v]==3-z&&lc[v]>w) break;
				res++;
				if(cc[v]==3-z) break;
				ux=vx,uy=vy;
			}
		}
		printf("%d\n",res);
		cc[x*m-m+y]=z,lc[x*m-m+y]=w;
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&q),g1.clear(),g2.clear();
		memset(cc,-1,sizeof(cc)),memset(lc,-1,sizeof(lc));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tem),tt.clear();
			for(int j=0;j<m-1;j++) tt.push_back(tem[j]-'0');
			g1.push_back(tt);
		}
		for(int i=1;i<n;i++)
		{
			scanf("%s",tem),tt.clear();
			for(int j=0;j<m;j++) tt.push_back(tem[j]-'0');
			g2.push_back(tt);
		}
//		solvb();
		if(n*m<=5000) solva();
		else solvb();
	}
} 
