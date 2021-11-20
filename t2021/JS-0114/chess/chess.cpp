#include<bits/stdc++.h>
using namespace std;
const int MAXQ=200005;
int T,n,m,q;
string s;
int col[MAXQ],lv[MAXQ],x[MAXQ],y[MAXQ];
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
vector <string> L,C;
map <pair<int,int>,int> H,vis,bvis;
struct Node
{
	int x;
	int y;
};
queue <Node> Q;
void bfs(int p)
{
	bvis.clear();
	while(!Q.empty())
	{
		int cur_x=Q.front().x;
		int cur_y=Q.front().y;
		bvis[make_pair(cur_x,cur_y)]=1;
		Q.pop();
		for(int k=0;k<4;k++)
		{
			int nx=cur_x+dir[k][0];
			int ny=cur_y+dir[k][1];
			if(nx<1||nx>n||ny<1||ny>m)
				continue;
			if(bvis[make_pair(nx,ny)])
				continue;
			if(k==0)
				if(L[nx][cur_y-1]!='3')
					continue;
			if(k==1)
				if(L[nx][ny-1]!='3')
					continue;
			if(k==2)
				if(C[cur_x][cur_y-1]!='3')
					continue;
			if(k==3)
				if(C[nx][cur_y-1]!='3')
					continue;
			int id=H[make_pair(nx,ny)];
			if(id==0)
			{
				Node nn;
				nn.x=nx;
				nn.y=ny;
				Q.push(nn);
				vis[make_pair(nx,ny)]=1;
				continue;
			}
			if(col[id]!=col[p]&&lv[p]>=lv[id])
				vis[make_pair(nx,ny)]=1;
		}
	}
}
void BF()
{
	for(int i=1;i<=q;i++)
	{
		while(!Q.empty())
			Q.pop();
		vis.clear();
		cin>>col[i]>>lv[i]>>x[i]>>y[i];
		vis[make_pair(x[i],y[i])]=1;
		H[make_pair(x[i],y[i])]=q;
		for(int k=0;k<4;k++)
		{
			int nx=x[i]+dir[k][0];
			int ny=y[i]+dir[k][1];
			if(nx<1||nx>n||ny<1||ny>m)
				continue;
			int id=H[make_pair(nx,ny)];
			if((id==0)||(id==1&&col[id]!=col[i]&&lv[id]<=lv[i]))
			{
				if(k==0)
					if(L[nx][y[i]-1]=='1')
						vis[make_pair(nx,ny)]=1;
				if(k==1)
					if(L[nx][ny-1]=='1')
						vis[make_pair(nx,ny)]=1;
				if(k==2)
					if(C[x[i]][y[i]-1]=='1')
						vis[make_pair(nx,ny)]=1;
				if(k==3)
					if(C[nx][y[i]-1]=='1')
						vis[make_pair(nx,ny)]=1;
			}
		}
		int cur_x=x[i],cur_y=y[i];
		while(cur_x)
		{
			vis[make_pair(cur_x,cur_y)]=1;
			if(cur_x==1)
				break;
			if(C[cur_x-1][cur_y-1]!='2')
				break;
			int nx=cur_x-1,ny=cur_y;
			int id=H[make_pair(nx,ny)];
			if(id==0)
			{
				cur_x--;
				continue;
			}
			if(col[i]!=col[id]&&lv[i]>=lv[id])
				vis[make_pair(nx,ny)]=1;
			break;
		}
		while(cur_x<=n)
		{
			vis[make_pair(cur_x,cur_y)]=1;
			if(cur_x==n)
				break;
			if(C[cur_x][cur_y-1]!='2')
				break;
			int nx=cur_x+1,ny=cur_y;
			int id=H[make_pair(nx,ny)];
			if(id==0)
			{
				cur_x++;
				continue;
			}
			if(col[i]!=col[id]&&lv[i]>=lv[id])
				vis[make_pair(nx,ny)]=1;
			break;
		}
		while(cur_y)
		{
			vis[make_pair(cur_x,cur_y)]=1;
			if(cur_y==1)
				break;
			if(L[cur_x][cur_y-2]!='2')
				break;
			int nx=cur_x,ny=cur_y-1;
			int id=H[make_pair(nx,ny)];
			if(id==0)
			{
				cur_y--;
				continue;
			}
			if(col[i]!=col[id]&&lv[i]>=lv[id])
				vis[make_pair(nx,ny)]=1;
			break;
		}
		while(cur_y<=m)
		{
			vis[make_pair(cur_x,cur_y)]=1;
			if(cur_y==m)
				break;
			if(L[cur_x][cur_y-1]!='2')
				break;
			int nx=cur_x,ny=cur_y+1;
			int id=H[make_pair(nx,ny)];
			if(id==0)
			{
				cur_y++;
				continue;
			}
			if(col[i]!=col[id]&&lv[i]>=lv[id])
				vis[make_pair(nx,ny)]=1;
			break;
		}
		Node st;
		st.x=x[i];
		st.y=y[i];
		Q.push(st);
		bfs(i);
		cout<<vis.size()-1<<endl;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--)
	{
		H.clear();
		L.clear();
		C.clear();
		L.push_back("");
		C.push_back("");
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			L.push_back(s);
		}
		for(int j=1;j<n;j++)
		{
			cin>>s;
			C.push_back(s);
		}
		BF();
	}
	return 0;
}
