
//1~6 24pts

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=5005;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)){
		x=x*10+(c^48);
		c=getchar();
	}
	return x;
}

void putint(int x){
	if(x>9) putint(x/10);
	putchar(x%10+'0');
}

int T,n,m,query;
bool st[N][N];
char col1[N][N],col2[N][N];
int col[N][N],lv[N][N];

inline int getcol(int xa,int ya,int xb,int yb){
	if(yb==ya+1) return col1[xa][ya]-'0';
	if(ya==yb+1) return col1[xb][yb]-'0';
	if(xa==xb+1) return col2[xb][yb]-'0';
	if(xb==xa+1) return col2[xa][ya]-'0';
	return 0;
}

struct chess{
	int col,lv,x,y;
}q[N*N];

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=getint();
	while(T--){
		n=getint(),m=getint(),query=getint();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				col1[i][j]=col2[i][j]=col[i][j]=lv[i][j]=0;
		for(int i=1;i<=n;++i) scanf("%s",col1[i]+1);
		for(int i=1;i< n;++i) scanf("%s",col2[i]+1);
		while(query--){
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					st[i][j]=false;
			chess t={getint(),getint(),getint(),getint()};
			st[t.x][t.y]=true;
			for(int k=0;k<4;++k){
				int x=t.x+dx[k],y=t.y+dy[k];
				if(x<1||x>n||y<1||y>m) continue;
				int c=getcol(t.x,t.y,x,y);
				if(c==3){
					int hh=0,tt=0;
					q[0]=t;
					while(hh<=tt){
						chess now=q[hh++];
						for(int kk=0;kk<4;++kk){
							x=now.x+dx[kk],y=now.y+dy[kk];
							if(x<1||x>n||y<1||y>m||st[x][y]) continue;
							if(getcol(x,y,now.x,now.y)!=3) continue;
							if(lv[x][y]){
								if(t.col!=col[x][y]&&t.lv>=lv[x][y]) st[x][y]=true;
								continue;
							}
							st[x][y]=true;
							q[++tt]={now.col,now.lv,x,y};
						}
					}
				}
			}
			
			for(int k=0;k<4;++k){
				int x=t.x+dx[k],y=t.y+dy[k];
				if(x<1||x>n||y<1||y>m) continue;
				int c=getcol(t.x,t.y,x,y);
				if(c==1){
					if(lv[x][y]){
						if(t.col!=col[x][y]&&t.lv>=lv[x][y]) st[x][y]=true;
						continue;
					}
					st[x][y]=true;
				}else if(c==2){
					int lx=t.x,ly=t.y;
					do{
						if(lv[x][y]){
							if(t.col!=col[x][y]&&t.lv>=lv[x][y])
								st[x][y]=true;
							break;
						}
						st[x][y]=true;
						lx=x,ly=y;
						x=lx+dx[k],y=ly+dy[k];
					}while(x<=n&&x>0&&y<=m&&y>0&&getcol(x,y,lx,ly)==2);
				}
			}
			
			int res=-1;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					if(st[i][j]) ++res;
			putint(res),putchar('\n');
			col[t.x][t.y]=t.col,lv[t.x][t.y]=t.lv;
		}
	}
	return 0;
}
