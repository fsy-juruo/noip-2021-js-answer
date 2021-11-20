#include<bits/stdc++.h>
#define N 200010
using namespace std;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1}; 
int T,n,m,q;
char str[N];
struct node{
	int to[4],col,lvl;
	bool fl;
	inline node(){memset(to,0,sizeof(to));fl=0;}
};
vector<node> a[N];
vector<bool> vis[N],u[N];
void place(int x,int y,int col,int lvl){
	a[x][y].fl=1;
	a[x][y].col=col;
	a[x][y].lvl=lvl;
}
bool ok(int x,int y,int d,int col,int lvl){
	int xx=x+dx[d],yy=y+dy[d];
	if(!a[xx][yy].fl) return 1;
	if(a[xx][yy].col!=col&&a[xx][yy].lvl<=lvl) return 1;
	return 0; 
}
void dfs2(int x,int y,int d,int col,int lvl){
	vis[x][y]=1;
	if(a[x][y].fl) return;
	if(ok(x,y,d,col,lvl)&&a[x][y].to[d]==2) dfs2(x+dx[d],y+dy[d],d,col,lvl);
}
void dfs3(int x,int y,int col,int lvl){
	vis[x][y]=1;u[x][y]=1;
	if(a[x][y].fl) return;
	for(int d=0;d<4;d++)
		if(ok(x,y,d,col,lvl)&&a[x][y].to[d]==3&&!u[x+dx[d]][y+dy[d]]) dfs3(x+dx[d],y+dy[d],col,lvl);
}
int getans(int x,int y){
	int col=a[x][y].col,lvl=a[x][y].lvl,tmp[4],ans=0;
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<4;i++) tmp[a[x][y].to[i]]++;
	if(!tmp[2]&&!tmp[3]){
		for(int i=0;i<4;i++)
			if(a[x][y].to[i]&&ok(x,y,i,col,lvl)) ans++;
	}else{
		for(int i=0;i<=n+5;i++){
			vis[i].clear();u[i].clear();
			for(int j=0;j<=m+5;j++) vis[i].push_back(0),u[i].push_back(0);
		}
		for(int i=0;i<4;i++){
			if(a[x][y].to[i]==1&&ok(x,y,i,col,lvl)) vis[x+dx[i]][y+dy[i]]=1;
			if(a[x][y].to[i]==2&&ok(x,y,i,col,lvl)) dfs2(x+dx[i],y+dy[i],i,col,lvl);
			if(a[x][y].to[i]==3&&ok(x,y,i,col,lvl)) dfs3(x+dx[i],y+dy[i],col,lvl);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(i==x&&j==y) continue;
				if(vis[i][j]) ans++;
			}
	}
	return ans;
}
void solve(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<=n+5;i++){
		a[i].clear();
		for(int j=0;j<=m+5;j++){
			node x;
			a[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<m;j++) a[i][j].to[1]=a[i][j+1].to[3]=str[j]-'0';
	}
	for(int i=1;i<n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=m;j++) a[i][j].to[2]=a[i+1][j].to[0]=str[j]-'0';
	}
	while(q--){
		int x,y,col,lvl;
		scanf("%d%d%d%d",&col,&lvl,&x,&y);
		place(x,y,col,lvl);
		printf("%d\n",getans(x,y));
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve(); 
	return 0;
}
