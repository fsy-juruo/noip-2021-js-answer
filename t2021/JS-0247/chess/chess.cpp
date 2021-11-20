#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,q;
char way[102][102][102][102];
int col[105][105],lv[105][105];
bool vis[105][105];
int c,l,x,y;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch==45)f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return (f==1)?x:-x;
}
inline char readchar(){
	char ch=getchar();
	while(ch==10||ch==32)ch=getchar();
	return ch;
}
int dfs(int x,int y,int fx,int fy){
	if(vis[x][y])return 0;
	vis[x][y]=true;
	if(fx==0&&fy==0)return dfs(x,y-1,fx,fy)+dfs(x+1,y,fx,fy)+dfs(x,y+1,fx,fy)+dfs(x-1,y,fx,fy);
	int ans=1;
	x=fx+1,y=fy;
	if((way[fx][fy][x][y]==51&&col[x][y]==-1)||(col[x][y]!=col[fx][fy]&&lv[x][y]<=lv[fx][fy]))ans+=dfs(x,y,fx,fy);
	x=fx-1,y=fy;
	if((way[fx][fy][x][y]==51&&col[x][y]==-1)||(col[x][y]!=col[fx][fy]&&lv[x][y]<=lv[fx][fy]))ans+=dfs(x,y,fx,fy);
	x=fx,y=fy-1;
	if((way[fx][fy][x][y]==51&&col[x][y]==-1)||(col[x][y]!=col[fx][fy]&&lv[x][y]<=lv[fx][fy]))ans+=dfs(x,y,fx,fy);
	x=fx,y=fy+1;
	if((way[fx][fy][x][y]==51&&col[x][y]==-1)||(col[x][y]!=col[fx][fy]&&lv[x][y]<=lv[fx][fy]))ans+=dfs(x,y,fx,fy);
	return ans;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	while(t--){
		n=read(),m=read(),q=read();
		memset(way,'0',sizeof(way));
		memset(col,-1,sizeof(col));
		memset(lv,0,sizeof(lv));
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m-1;++j)
				way[i][j][i][j+1]=readchar();
		for(int i=1;i<=n-1;++i)
			for(int j=1;j<=m;++j)
				way[i][j][i+1][j]=readchar();
		int ans=0;
		for(int i=1;i<=q;++i){
			c=read(),l=read(),x=read(),y=read();
			lv[x][y]=l;
			col[x][y]=c;
			if(way[x][y][x-1][y]==49)ans+=(col[x-1][y]==-1||(col[x-1][y]!=col[x][y]&&lv[x-1][y]<=lv[x][y]));
			if(way[x][y][x-1][y]==50){
				int t=x;
				while((way[t][y][t-1][y]==50&&col[t-1][y]==-1)||(col[t-1][y]!=col[t][y]&&lv[t-1][y]<=lv[t][y])){
					++ans;
					--t;
				}
			}
			if(way[x][y][x+1][y]==49)ans+=(col[x+1][y]==-1||(col[x+1][y]!=col[x][y]&&lv[x+1][y]<=lv[x][y]));
			if(way[x][y][x+1][y]==50){
				int t=x;
				while((way[t][y][t+1][y]==50&&col[t+1][y]==-1)||(col[t+1][y]!=col[t][y]&&lv[t+1][y]<=lv[t][y])){
					++ans;
					++t;
				}
			}
			if(way[x][y][x][y-1]==49)ans+=(col[x][y-1]==-1||(col[x][y]-1!=col[x][y]&&lv[x][y-1]<=lv[x][y]));
			if(way[x][y][x][y-1]==50){
				int t=y;
				while((way[x][t][x][t-1]==50&&col[x][t-1]==-1)||(col[x][t-1]!=col[x][t]&&lv[x][t]<=lv[x][t-1])){
					++ans;
					--t;
				}
			}
			if(way[x][y][x-1][y]==49)ans+=(col[x-1][y]==-1||(col[x-1][y]!=col[x][y]&&lv[x-1][y]<=lv[x][y]));
			if(way[x][y][x][y+1]==50){
				int t=y;
				while((way[x][t][x][t+1]==50&&col[x][t+1]==-1)||(col[x][t+1]!=col[x][t]&&lv[x][t]<=lv[x][t+1])){
					++ans;
					++t;
				}
			}
			ans+=dfs(x,y,0,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
