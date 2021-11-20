#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define N 5003
#define PII pair<int,int>
#define col first
#define lv second
int t,n,m,q,w[N][N],l[N][N];
PII h[N][N];
bool vis[N][N][4],canto[N][N];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void dfs(int col,int lv,int x,int y,int dv,int tp){
	if(tp){
		if(!h[x][y].lv) canto[x][y]=true;
		else{
			if(h[x][y].lv<=lv&&h[x][y].col!=col)
				canto[x][y]=true;
			return;
		}
		if(tp==1) return;
	}
	for(int d=0;d<4;++d){
		int xx=x+dx[d],yy=y+dy[d],rd=0;
		if(xx<1||xx>n||yy<1||yy>m) continue;
		if(d==0) rd=l[x-1][y];
		else if(d==1) rd=w[x][y];
		else if(d==2) rd=l[x][y];
		else rd=w[x][y-1];
		if(!tp){
			if(rd){
				vis[xx][yy][rd]=true;
				dfs(col,lv,xx,yy,d,rd);
				vis[xx][yy][rd]=false;
			}
		}else if(tp==2&&!vis[xx][yy][2]){
			if(d==dv&&rd==tp){
				vis[xx][yy][2]=true;
				dfs(col,lv,xx,yy,dv,tp);
				vis[xx][yy][2]=false;
			}
		}else if(tp==3&&rd==tp&&!vis[xx][yy][3]){
			vis[xx][yy][3]=true;
			dfs(col,lv,xx,yy,d,tp);
			vis[xx][yy][3]=false;
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&q);
		memset(h,0,sizeof h);
		for(int i=1;i<=n;++i)
			for(int j=1;j<m;++j)
				scanf("%1d",&w[i][j]);
		for(int i=1;i<n;++i)
			for(int j=1;j<=m;++j)
				scanf("%1d",&l[i][j]);
		int a,b,u,v;
		while(q--){
			scanf("%d%d%d%d",&a,&b,&u,&v);
			if(n*m<=5000){
				memset(vis,0,sizeof vis);
				memset(vis[u][v],true,4);
				memset(canto,0,sizeof canto);
				dfs(a,b,u,v,0,0);
				int cnt=0;
				for(int i=1;i<=n;++i)
					for(int j=1;j<=m;++j)
						cnt+=canto[i][j];
				printf("%d\n",cnt);
			}
			else{
				int cnt=0;
				for(int d=0;d<4;++d){
					int x=u+dx[d],y=v+dy[d];
					if(x<1||x>n||y<1||y>m) continue;
					if(!h[x][y].lv) cnt++;
					else if(h[x][y].lv<=b&&h[x][y].col!=a)
						cnt++;
				}
				printf("%d\n",cnt);
			}
			h[u][v]={a,b};
		}
	}
	return 0;
}
