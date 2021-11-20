#include<bits/stdc++.h>
using namespace std;

int readint(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}

int readc(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	return ch^48;
}

struct qda{
	int col,lev,rx,ry;
	qda():col(0),lev(0),rx(0),ry(0){};
	qda(int col,int lev,int rx,int ry):col(col),lev(lev),rx(rx),ry(ry){};
	void read(){
		col=readint();
		lev=readint();
		rx=readint();
		ry=readint();
	}
};

typedef pair<int,int> pii;
const int N=2e5+5;
int T,n,m,q,rc,atp;
int used[N],typ[N*2],col[N],lev[N],dir[4][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char ss[105];
qda qry[N];
queue<pii> que;

inline bool ok(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}

inline int ID(int x,int y){
	return (x-1)*m+y;
}

void solve1(){
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n*m;j++) used[j]=0;
		while(!que.empty()) que.pop();
		int cl=qry[i].col;
		int lv=qry[i].lev;
		int x=qry[i].rx;
		int y=qry[i].ry;
		que.push(pii(x,y));
		used[ID(x,y)]=1;
		while(!que.empty()){
			int rx=que.front().first;
			int ry=que.front().second;
			que.pop();
			for(int k=0;k<4;k++){
				int nx=rx+dx[k];
				int ny=ry+dy[k];
				if(ok(nx,ny)&&!used[ID(nx,ny)]&&typ[dir[k][ID(rx,ry)]]==3){
					int nlv=lev[ID(nx,ny)];
					if(!~nlv){
						used[ID(nx,ny)]=1;
						que.push(pii(nx,ny));
					}else if(cl!=col[ID(nx,ny)]&&nlv<=lv) used[ID(nx,ny)]=1;
				}
			}
		}
		for(int k=0;k<4;k++){
			int rx=x;
			int ry=y;
			while(true){
				int nx=rx+dx[k];
				int ny=ry+dy[k];
				if(ok(nx,ny)&&typ[dir[k][ID(rx,ry)]]==2){
					int nlv=lev[ID(nx,ny)];
					if(!~nlv) used[ID(nx,ny)]=1;
					else{
						if(cl!=col[ID(nx,ny)]&&nlv<=lv) used[ID(nx,ny)]=1;
						break;
					}
				}else break;
				rx=nx;
				ry=ny;
			}
		}
		for(int k=0;k<4;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(ok(nx,ny)&&typ[dir[k][ID(x,y)]]==1){
				int nlv=lev[ID(nx,ny)];
				if(!~nlv) used[ID(nx,ny)]=1;
				else if(cl!=col[ID(nx,ny)]&&nlv<=lv) used[ID(nx,ny)]=1;
			}
		}
		for(int j=1;j<=n*m;j++) if(used[j]) ans++;
		printf("%d\n",ans-1);
		lev[ID(x,y)]=lv;
		col[ID(x,y)]=cl;
	}
}

void solve2(){
	for(int i=1;i<=q;i++){
		int ans=0;
		while(!que.empty()) que.pop();
		int cl=qry[i].col;
		int lv=qry[i].lev;
		int x=qry[i].rx;
		int y=qry[i].ry;
		for(int k=0;k<4;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(ok(nx,ny)&&typ[dir[k][ID(x,y)]]==1){
				int nlv=lev[ID(nx,ny)];
				if(!~nlv) ans++;
				else if(cl!=col[ID(nx,ny)]&&nlv<=lv) ans++;
			}
		}
		printf("%d\n",ans);
		lev[ID(x,y)]=lv;
		col[ID(x,y)]=cl;
	}
}

void solve(){
	rc=atp=0;
	memset(typ,-1,sizeof(typ));
	memset(col,-1,sizeof(col));
	memset(lev,-1,sizeof(lev));
	memset(dir,-1,sizeof(dir));
	n=readint();m=readint();q=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<m;j++){
		typ[++rc]=readc();
		atp|=1<<typ[rc];
		dir[0][ID(i,j)]=rc;
		dir[2][ID(i,j+1)]=rc;
	}
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++){
		typ[++rc]=readc();
		atp|=1<<typ[rc];
		dir[1][ID(i,j)]=rc;
		dir[3][ID(i+1,j)]=rc;
	}
	for(int i=1;i<=q;i++) qry[i].read();
	if(~atp&12) solve2();
	else if(n*m<=200000&&q<=2000) solve1();
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=readint();
	while(T--) solve();
	return 0;
}
