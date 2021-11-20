#include <bits/stdc++.h>
using namespace std;

const int N=5005;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
char c1[N][N],c2[N][N];
int T,ans,n,m,q;
int lv[N][N],col[N][N];
bool used[N][N];

void init(){
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			lv[i][j]=0;
			col[i][j]=0;
			used[i][j]=false;
		}
	}
}

void bfs(int x,int y,int Mode,int move1,int move2){
	for (int i=move1;i<move2;i++){
		for (int j=move1;j<move2;j++){
			int px=dx[i]+x,py=dy[i]+y;
			if(dx[i]==0){
				if(px>=0 && px<n && py>=0 && py<m && (c2[px][py]==Mode || Mode==-1)){
					if(c1[px][py]==0) continue;
				}
			}else{
				if(px>=0 && px<n && py>=0 && py<m && (c1[px][py]==Mode || Mode==-1)){
					if(c1[px][py]==0) continue;
					if(c1[px][py]==1) ans++;
					if(c1[px][py]==2){
						ans++;
					}
				}
			}
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		init();
		scanf("%d%d%d",&n,&m,&q);
		for (int j=0;j<n;j++){
			scanf("%s",&c1[i]);
		}
		for (int j=0;j<n-1;j++){
			scanf("%s",&c2[i]);
		}
		for (int i=0;i<q;i++){
			int x,y,COL,LV;
			scanf("%d%d%d%d",&COL,&LV,&x,&y);
			col[x][y]=COL;
			lv[x][y]=LV;
			x--;y--;
			ans=0;
			bfs(x,y,-1,0,4);
			printf("%d\n",ans);
		}
	}
	return 0;
}
