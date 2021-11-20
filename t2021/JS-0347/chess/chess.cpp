#include<bits/stdc++.h>

using namespace std;

const int N=110;

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int T;
int n,mm,q,ans;
char h[N][N],z[N][N];
struct Node{
	int col,lv;
}m[N][N];
bool st[N][N];

void op(int xx,int y,int pt,int fx,int lv,int col){
	if(fx==1)
	for(int j=xx;j<n;j++)
		if(z[j][y]==0||m[xx][y].lv>lv||m[xx][y].col==col)break;
		else if(z[j][y]==1){
			if(pt==1)break;
			else ans++;
		}
		else if(z[j][y]==2)op(j,y,pt,fx,lv,col);
		else if(z[j][y]==3)ans++;
	if(fx==2)
		for(int j=y;j<mm;j++)
		if(h[xx][j]==0||m[xx][y].lv>lv||m[xx][y].col==col)break;
		else if(h[xx][j]==1){
			if(pt==1)break;
			else ans++;
		}
		else if(h[xx][j]==2)op(j,y,pt,fx,lv,col);
		else if(h[xx][j]==3)ans++;
	if(fx==3)
		for(int j=y-1;j>=1;j--)
		if(h[xx][j]==0||m[xx][y].lv>lv||m[xx][y].col==col)break;
		else if(h[xx][j]==1){
			if(pt==1)break;
			else ans++;
		}
		else if(h[xx][j]==2)op(j,y,pt,fx,lv,col);
		else if(h[xx][j]==3)ans++;
	if(fx==4)
		for(int j=xx-1;j>=1;j--)
		if(z[j][y]==0||m[xx][y].lv>lv||m[xx][y].col==col)break;
		else if(z[j][y]==1){
			if(pt==1)break;
			else ans++;
		}
		else if(z[j][y]==2)op(j,y,pt,fx,lv,col);
		else if(z[j][y]==3)ans++;
}

void dfs(int x,int y,int color,int pt){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(st[xx][yy])continue;
		if(xx==x&&yy>y){
			if(m[xx][yy].lv==0){
				if(h[xx][y]==0)continue;
				if(h[xx][y]==1){
					if(pt==1)continue;
					else{
						ans++;
						dfs(xx,yy,color,pt+1);
					}
				}
				if(h[xx][y]==2)
					op(xx,y,pt,2,m[x][y].lv,color);
				if(h[xx][y]==3)
					ans++;
			}
			else if(m[xx][yy].lv<m[x][y].lv&&m[xx][yy].col==1-color){
				ans++;
				break;
			}
			else continue;
		}
		if(xx==x&&yy<y){
			if(m[xx][yy].lv==0){
				if(h[xx][yy]==0)continue;
				if(h[xx][yy]==1){
					if(pt==1)continue;
					else{
						ans++;
						dfs(xx,yy,color,pt+1);
					}
				}
				if(h[xx][y]==2)
					op(xx,y,pt,3,m[x][y].lv,color);
				if(h[xx][y]==3)
					ans++;
			}
			else if(m[xx][yy].lv<m[x][y].lv&&m[xx][yy].col==1-color){
				ans++;
				break;
			}
			else continue;
		}
		if(xx>x&&yy==y){
			if(m[xx][yy].lv==0){
				if(z[x][yy]==0)continue;
				if(z[x][yy]==1){
					if(pt==1)continue;
					else{
						ans++;
						dfs(xx,yy,color,pt+1);
					}
				}
				if(z[x][y]==2)
					op(x,y,pt,3,m[x][y].lv,color);
				if(z[x][y]==3)
					ans++;
			}
			else if(m[xx][yy].lv<m[x][y].lv&&m[xx][yy].col==1-color){
				ans++;
				break;
			}
			else continue;
		}
		if(xx<x&&yy==y){
			if(m[xx][yy].lv==0){
				if(z[xx][yy]==0)continue;
				if(z[xx][yy]==1){
					if(pt==1)continue;
					else{
						ans++;
						dfs(xx,yy,color,pt+1);
					}
				}
				if(z[xx][y]==2)
					op(x,y,pt,3,m[x][y].lv,color);
				if(z[xx][y]==3)
					ans++;
			}
			else if(m[xx][yy].lv<m[x][y].lv&&m[xx][yy].col==1-color){
				ans++;
				break;
			}
			else continue;
		}
	}
}

int main(){
	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	memset(h,-1,sizeof h);
	T=read();
	while(T--){
		ans=0;
		n=read(),mm=read(),q=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<mm;j++)
				cin>>h[i][j];
		for(int i=1;i<n;i++)
			for(int j=1;j<=mm;j++)
				cin>>z[i][j];
		for(int i=1;i<=q;i++){
			int col=read(),lv=read(),x=read(),y=read();
			m[x][y]={col,lv};
			dfs(x,y,col,0);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}

