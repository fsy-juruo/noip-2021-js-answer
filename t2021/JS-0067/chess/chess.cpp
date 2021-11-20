#include <bits/stdc++.h>
using namespace std;
const int N = 2050;
int T;
int n,m,t,ans;
int p[2][N][N],lv[N][N],col[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[N][N][4];
char c;
struct node{
	int x,y;
}q[N*N],now;
void bfs1(int color,int level,int x,int y) {
	int nx,ny;
	vis[x][y][1]=1;
	for (int j=0;j<4;j++) {
		nx=x+dx[j];
		ny=y+dy[j];
		if (nx<1||nx>n||ny<1||ny>m)  continue;
		if (!vis[nx][ny][1]&&p[abs(dx[j])][min(now.x,nx)][min(now.y,ny)]==1&&(lv[nx][ny]==0||(lv[nx][ny]<=level&&col[nx][ny]!=color))) {
			vis[nx][ny][1]=1;
		}
	}
}
void bfs3(int color,int level,int x,int y) {
	int l=0, r=1,nx,ny;
	q[1].x=x, q[1].y=y;
	vis[x][y][3]=1;
	while(l<r) {
		now=q[++l];
		if (lv[now.x][now.y])  continue;
		for (int j=0;j<4;j++) {
			nx=now.x+dx[j];
			ny=now.y+dy[j];
			if (nx<1||nx>n||ny<1||ny>m)  continue;
			if (!vis[nx][ny][3]&&p[abs(dx[j])][min(now.x,nx)][min(now.y,ny)]==3&&(lv[nx][ny]==0||(lv[nx][ny]<=level&&col[nx][ny]!=color))) {
				q[++r].x=nx;
				q[r].y=ny;
				vis[nx][ny][3]=1;
			}
		}
	}
}
void bfs2(int color,int level,int x,int y) {
	int nx,ny;
	for (int i=0;i<4;i++) {
		nx=x+dx[i], ny=y+dy[i];
		while (!vis[nx][ny][2] && p[abs(dx[i])][min(now.x,nx)][min(now.y,ny)]==2&&(lv[nx][ny]==0||(lv[nx][ny]<=level&&col[nx][ny]!=color))) {
			vis[nx][ny][2]=1;
			nx+=dx[i];
			ny+=dy[i];
			if (nx<1||nx>n||ny<1||ny>m)  break;
		}
	}
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j,tmp1,tmp2,x,y;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&n,&m,&t);
		c=getchar();
		for (i=1;i<=n;i++) {
			while (c<'0'||c>'3')  c=getchar();
			for (j=1;j<m;j++) {
				p[0][i][j]=(c-'0');
				c=getchar();
			}
		}	
		for (i=1;i<n;i++)
			for (j=1;j<=m;j++) {
				while (c<'0'||c>'3')  c=getchar();
				p[1][i][j]=c-'0';
				c=getchar();
			}
		while (t--) {
			scanf("%d%d%d%d",&tmp1,&tmp2,&x,&y);
			ans=0;
			memset(vis,0,sizeof(vis));
			bfs1(tmp1,tmp2,x,y);
			bfs3(tmp1,tmp2,x,y);
			bfs2(tmp1,tmp2,x,y);
			for (i=1;i<=n;i++)
				for (j=1;j<=m;j++)
					if (vis[i][j][1]||vis[i][j][2]||vis[i][j][3])  cout<<i<<" "<<j<<endl;//ans++;
			lv[x][y]=tmp1;
			col[x][y]=tmp2;
			cout<<ans-1<<endl;
		}
	}
	return 0;
}
