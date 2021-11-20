#include<bits/stdc++.h>
using namespace std;
int T,n,m,q,c,x,y,l,ans,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
char s1[5005][5005],s2[5005][5005];
bool vis[5005][5005];
struct node{
	int col,lv;
}opt[5005][5005];
bool check(int a,int b,int c,int d){
	if(opt[c][d].col==-1)return 1;
	if(opt[c][d].col==opt[a][b].col)return 0;
	if(opt[c][d].lv>opt[a][b].lv)return 0;
	return 1;
}
void dfs(int x,int y,int _x,int _y){
	ans+=!vis[x][y];
	vis[x][y]=1;
	int nx,ny;
	nx=x,ny=y+1;
	if(vis[nx][ny]||nx>n||nx<1||ny>m||ny<1||s1[x][y]!='3'||opt[nx][ny].col!=-1){
		if(vis[nx][ny]||nx>n||nx<1||ny>m||ny<1||s1[x][y]!='3');
		else ans+=check(_x,_y,nx,ny),vis[nx][ny]=1;
	}
	else dfs(nx,ny,_x,_y);
	nx=x+1,ny=y;
	if(vis[nx][ny]||nx>n||nx<1||ny>m||ny<1||s2[x][y]!='3'||opt[nx][ny].col!=-1){
		if(vis[nx][ny]||nx>n||nx<1||ny>m||ny<1||s2[x][y]!='3');
		else ans+=check(_x,_y,nx,ny),vis[nx][ny]=1;
	}
	else dfs(nx,ny,_x,_y);
	nx=x,ny=y-1;
	if(vis[nx][ny]||nx>n||nx<1||ny>m||ny<1||s1[x][y-1]!='3'||opt[nx][ny].col!=-1){
		if(vis[nx][ny]||nx>n||nx<1||ny>m||ny<1||s1[x][y-1]!='3');
		else ans+=check(_x,_y,nx,ny),vis[nx][ny]=1;
	}
	else dfs(nx,ny,_x,_y);
	nx=x-1,ny=y;
	if(vis[nx][ny]||nx>n||nx<1||ny>m||ny<1||s2[x-1][y]!='3'||opt[nx][ny].col!=-1){
		if(vis[nx][ny]||nx>n||nx<1||ny>m||ny<1||s2[x-1][y]!='3');
		else ans+=check(_x,_y,nx,ny),vis[nx][ny]=1;
	}
	else dfs(nx,ny,_x,_y);
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)opt[i][j].lv=0,opt[i][j].col=-1;
		for(int i=1;i<=n;i++)scanf("%s",s1[i]+1);
		for(int i=1;i<n;i++)scanf("%s",s2[i]+1);
		while(q--){
			scanf("%d%d%d%d",&c,&l,&x,&y);
			ans=0;
			vis[x][y]=1;
			opt[x][y].col=c,opt[x][y].lv=l;
			dfs(x,y,x,y);
			if(y<m&&s1[x][y]=='1'&&check(x,y,x,y+1)&&!vis[x][y+1])ans++,vis[x][y+1]=1;
			if(y>=2&&s1[x][y-1]=='1'&&check(x,y,x,y-1)&&!vis[x][y-1])ans++,vis[x][y-1]=1;
			if(x<n&&s2[x][y]=='1'&&check(x,y,x+1,y)&&!vis[x+1][y])ans++,vis[x+1][y]=1;
			if(x>=2&&s2[x-1][y]=='1'&&check(x,y,x-1,y)&&!vis[x-1][y])ans++,vis[x-1][y]=1;
			int nx=x,ny=y;
			while(s1[nx][ny]=='2'&&ny<m){
				ny++;
				ans+=!vis[nx][ny];
				if(opt[nx][ny].col!=-1){
					if(!check(x,y,nx,ny))ans-=!vis[nx][ny];
					break;
				}
			}
			nx=x,ny=y;
			while(s1[nx][ny-1]=='2'&&ny>1){
				ny--;
				ans+=!vis[nx][ny];
				if(opt[nx][ny].col!=-1){
					if(!check(x,y,nx,ny))ans-=!vis[nx][ny];
					break;
				}
			}
			nx=x,ny=y;
			while(s2[nx][ny]=='2'&&nx<n){
				nx++;
				ans+=!vis[nx][ny];
				if(opt[nx][ny].col!=-1){
					if(!check(x,y,nx,ny))ans-=!vis[nx][ny];
					break;
				}
			}
			nx=x,ny=y;
			while(s2[nx-1][ny]=='2'&&nx>1){
				nx--;
				ans+=!vis[nx][ny];
				if(opt[nx][ny].col!=-1){
					if(!check(x,y,nx,ny))ans-=!vis[nx][ny];
					break;
				}
			}
			cout<<ans<<endl;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)vis[i][j]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
