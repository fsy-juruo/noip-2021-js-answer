#include <bits/stdc++.h>
using namespace std;
const int MAXN = 310;
const int MAXQ = 10010;
const int dx[5] = {0,-1,1,0,0};
const int dy[5] = {0,0,0,-1,1};

struct Chess{
	int x,y;
	int col,lv;
}qz[MAXQ];
int n,m,q,ans,T;
int M[MAXN][MAXN][5];//1 up 2 down 3 left 4 right
int tkup[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool des[MAXN][MAXN];

void rusH(int dr, int x, int y, int num){
	for(int i = 1; ; i++){
		int tx = x + (dx[dr] * i), ty = y + (dy[dr] * i);
		if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && M[tx-dx[dr]][ty-dy[dr]][dr] == 2){
			if(tkup[tx][ty] != 0){
				if(qz[tkup[tx][ty]].lv <= qz[num].lv && qz[tkup[tx][ty]].col != qz[num].col){
					ans++;
					des[tx][ty] = true;
					vis[tx][ty] = true;
				}
				break;
			}
			ans++;
			des[tx][ty] = true;
			vis[tx][ty] = true;
		}
		else
			break;
	}
}

void predfs(int x, int y, int num){
	for(int i = 1; i <= 4; i++){
		int tx = x + dx[i], ty = y + dy[i];
		if(tx >= 1 && tx <= n && ty >= 1 && ty <= m){
			if(M[x][y][i] == 1){
				if(tkup[tx][ty] != 0){
					if(qz[tkup[tx][ty]].lv <= qz[num].lv && qz[tkup[tx][ty]].col != qz[num].col){
						ans++;
						des[tx][ty] = true;
					}
				}
				else{
					ans++;
					des[tx][ty] = true;
				}	
				
			}
			else if(M[x][y][i] == 2){
				rusH(i, x, y, num);
			}
		}
	}
}

void dfs(int x, int y, int num){
	if(!des[x][y]){
		des[x][y] = true;
		ans++;
	}
	for(int i = 1; i <= 4; i++){
		int tx = x + dx[i], ty = y + dy[i];
		if(!vis[tx][ty] && tx >= 1 && tx <= n && ty >= 1 && ty <= m && M[x][y][i] == 3){
			if(tkup[tx][ty] != 0){
				if(qz[tkup[tx][ty]].lv <= qz[num].lv && qz[tkup[tx][ty]].col != qz[num].col){
					ans++;
					des[tx][ty] = true;
					vis[tx][ty] = true;
				}
			}
			else{
				vis[x][y] = true;
				dfs(tx, ty, num);
				vis[x][y] = false;
			}
		}
			
	}
}

int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				tkup[i][j] = 0;
		scanf("%d%d%d", &n, &m, &q);
		for(int i = 1; i <= n; i++){
			getchar();
			for(int j = 1; j <= m-1; j++){
				char c = getchar();
				int x = c - '0';			
				M[i][j][4] = x;
				M[i][j+1][3] = x;
			}
		}
			
		for(int i = 1; i <= n - 1; i++){
			getchar();
			for(int j = 1; j <= m; j++){
				char c = getchar();
				int x = c - '0';
				M[i][j][2] = x;
				M[i+1][j][1] = x;
			}
		}
			
		for(int i = 1; i <= q; i++){
			ans = 0;
			scanf("%d%d%d%d",&qz[i].col,&qz[i].lv,&qz[i].x,&qz[i].y);
			des[qz[i].x][qz[i].y] = true;
			predfs(qz[i].x, qz[i].y, i);
			dfs(qz[i].x, qz[i].y, i);
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= m; j++)
					des[i][j] = vis[i][j] = false;
			tkup[qz[i].x][qz[i].y] = i;
			printf("%d\n", ans);
		}
	}
	return 0;
}
