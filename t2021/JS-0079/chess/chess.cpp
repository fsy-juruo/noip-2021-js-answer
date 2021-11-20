#include <bits/stdc++.h>
#define N 5010
using namespace std;

int n, m, q, T, cnt, e1[N][N], e2[N][N];
string s;
struct nod{
	int c = -1, l;
}g[N][N];
int dx[5] = {0,0,1,-1};
int dy[5] = {1,-1,0,0};
bool vh[N][N], vh2[N][N];
void read(int &x){
	x = 0;
	char s = getchar();
	while(s < '0' || s > '9') s = getchar();
	while(s <= '9' && s >= '0'){
		x = x * 10 + s - '0';
		s = getchar();
	}
}
void reads(string &s){
	s = "";
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch <= '9' && ch >= '0'){
		s += ch;
		ch = getchar();
	}
}
void calc(int c, int l, int x, int y, int k, int dir){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if(g[nx][ny].c == c || g[nx][ny].l > l) continue;
		int p2;
		if(i == 0) p2 = e1[x][y];
		if(i == 1) p2 = e1[x][y-1];
		if(i == 2) p2 = e2[x][y];
		if(i == 3) p2 = e2[x-1][y];
		if(p2 == 0 || p2 == 3) continue;
		if(p2 == 1 && k == 5){
			vh[nx][ny] = true;
			continue;
		}
		if(p2 == 2 && (k == 5 || k == 2) && (dir == 4 || dir == i)){
			vh[nx][ny] = true;
			if(g[nx][ny].c == -1) calc(c,l,nx,ny,p2,i);
		}
	}
}
void calc2(int c, int l, int x, int y, int k, int dir){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if(g[nx][ny].c == c || g[nx][ny].l > l) continue;
		if(vh2[nx][ny]) continue;
		int p2;
		if(i == 0) p2 = e1[x][y];
		if(i == 1) p2 = e1[x][y-1];
		if(i == 2) p2 = e2[x][y];
		if(i == 3) p2 = e2[x-1][y];
		if(p2 != 3) continue;
		if(p2 == 3 && (k == 5 || k == 3)){
			vh2[nx][ny] = true;
			if(g[nx][ny].c == -1) calc2(c,l,nx,ny,p2,i);
		}
	}
}
void zreset(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			g[i][j].c = -1;
			g[i][j].l = 0;
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while(T--){
		read(n); read(m); read(q);
		for(int i = 1; i <= n; i++){
			reads(s);
			int ls = s.size(); 
			for(int j = 0; j < ls; j++)
				e1[i][j+1] = s[j] - '0';
		}
		for(int i = 1; i < n; i++){
			reads(s);
			int ls = s.size();
			for(int j = 0; j < ls; j++)
				e2[i][j+1] = s[j] - '0';
		}
		for(int i = 1, col, lv, x, y; i <= q; i++){
			read(col); read(lv); read(x); read(y);		
			memset(vh,0,sizeof(vh));
			memset(vh2,0,sizeof(vh2));
			vh[x][y] = true;
			vh2[x][y] = true;
			cnt = 0;
			calc(col,lv,x,y,5,4);
			calc2(col,lv,x,y,5,4);
			for(int j = 1; j <= n; j++){
				for(int k = 1; k <= m; k++){
					if(vh[j][k] || vh2[j][k]) cnt++;
				}
			}
			g[x][y].c = col;
			g[x][y].l = lv;
			printf("%d\n",cnt-1);
		}
		zreset();
	}
	return 0;
}
