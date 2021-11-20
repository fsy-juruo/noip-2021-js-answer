#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int T,n,m,q,game[4002][4002],vis[4002][4002];
string gheng[100005],gzong[100005];
struct Chess{
	int x,y,col,lv;
}chess[100005];
int read(){
	char c=' ';
	int num=0;
	c=getchar();
	while (c!='\n'&&c!=' '){
		num=num*10+c-'0';
		c=getchar();
	}
	return num;
}
string read2(){
	char c;
	string ans="";
	while (c!='\n'){
		ans+=c;
		c=getchar();
	}
	return ans;
}
int find(int csx,int csy,int rstate,int prex,int prey,int cc){ 
	vis[prex][prey]=1;
	int nx=prex+csx,ny=prey+csy;
	if (nx<1||nx>n||ny<1||ny>m)return 0;
	if (vis[nx][ny]){
		return 0;
	}
	if (csy==-1){
		if (rstate!=gheng[prex][prey]||rstate==-1)return 0;
	}else if (csx==1){
		if (rstate!=gzong[nx][ny]||rstate==-1)return 0;
	}else if(csy==1){
		if (rstate!=gheng[nx][ny]||rstate==-1)return 0;
	}else if (csx==-1){
		if (rstate!=gzong[prex][prey]||rstate==-1)return 0;
	}
	if (rstate==1){
		vis[nx][ny]=1;
		return 1;
	}
	if (game[nx][ny]!=0){
		if (chess[game[nx][ny]].col==chess[cc].col)return 0;
		else{
			if (chess[game[nx][ny]].lv>chess[cc].lv)return 0;
			else{
				vis[nx][ny]=1;
				return 1;
			}
		}
	}
	if (rstate==2){
		return find(csx,csy,rstate,nx,ny,cc)+1;
	}else if (rstate==3||rstate==-1){
		return find(-1,0,3,nx,ny,cc)+find(0,1,3,nx,ny,cc)+find(1,0,3,nx,ny,cc)+find(0,-1,3,nx,ny,cc)+1;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while (T--){
		memset(game,0,sizeof(game));
		n=read();
		m=read();
		q=read();
		for (int i=1;i<=n;++i){
			gheng[i]=read2();
		}
		for (int i=2;i<=n;++i){
			gzong[i]=read2();
		}
		for (int i=1;i<=q;++i){
			chess[i].col=read();
			chess[i].lv=read();
			chess[i].x=read();
			chess[i].y=read();
			memset(vis,0,sizeof(vis));
			game[chess[i].x][chess[i].y]=i;
			int x=chess[i].x,y=chess[i].y,cc=i;
			int ans=find(-1,0,-1,x,y,cc)+find(0,1,-1,x,y,cc)+find(1,0,-1,x,y,cc)+find(0,-1,-1,x,y,cc);
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
