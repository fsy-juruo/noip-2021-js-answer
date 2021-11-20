#include <bits/stdc++.h>
#define N 5005
#define M make_pair
using namespace std;
int t, n, m, q, ftt, co[N][N], l[N][N], vis[N][N], fr[N][N], o[N], e[N], top;
string a[N], b[N];
struct node{
	int z, x, y, fx, lx, ly, cz;
};
int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		memset(l, 0, sizeof(l)); memset(co, 0, sizeof(co)); 
		memset(vis, 0, sizeof(vis)); memset(fr, 0, sizeof(fr));
		scanf("%d%d%d", &n, &m, &q);
		for(int i = 1; i <= m; ++i) vis[0][i] = vis[n + 1][i] = 1;
		for(int i = 1; i <= n; ++i) vis[i][0] = vis[i][m + 1] = 1;
		for(int i = 1; i <= n; ++i) cin >> a[i], a[i] = " " + a[i];
		for(int i = 1; i < n; ++i) cin >> b[i], b[i] = " " + b[i];
		for(int i = 1; i <= q; ++i){
			int col, lv, nx, ny;
			scanf("%d%d%d%d", &col, &lv, &nx, &ny);
			co[nx][ny] = col; l[nx][ny] = lv;
			queue<node> q; top = 0; vis[nx][ny] = 1; 
			q.push(node{0, nx, ny, 0, 0, 0, 0}); int ans = 0;
			while(q.size()){
				int bh = q.front().z, x = q.front().x, y = q.front().y, fx = q.front().fx; 
				int lx = q.front().lx, ly = q.front().y, cz = q.front().cz;  
				o[++top] = x; e[top] = y;
				q.pop();
				if(bh == 1 || cz == 1) continue; 
				int pg = 0, ld = 0;
				if(a[x][y] - '0' == bh || !bh){
					if(a[x][y] == '3' && vis[x][y + 1] && !fr[x][y + 1] && y + 1 <= m){
						fr[x][y + 1] = 1;
						q.push(node{3, x, y + 1, fx, x, y, 0});
					} 
					else{
						if(a[x][y] == '0') pg = 1; if(vis[x][y + 1]) pg = 1;
						if(a[x][y] == '2' && bh == 2 && fx == 2) pg = 1;
						if(pg) ++ld;
						else if(l[x][y + 1]){
							if(co[x][y + 1] != col && lv >= l[x][y + 1]) 
								ans++, vis[x][y + 1] = 1, q.push(node{a[x][y] - '0', x, y + 1, 1, x, y, 1});
						}
						else if(!bh && a[x][y] == '2') vis[x][y + 1] = 1, ans++, q.push(node{2, x, y + 1, 1, x, y, 0});
						else{
							if(a[x][y] == '3') fr[x][y + 1] = 1;
							vis[x][y + 1] = 1, ans++, q.push(node{a[x][y] - '0', x, y + 1, fx, x, y, 0});
						}	
					}
				}pg = 0;
				if(a[x][y - 1] - '0' == bh || !bh){
					if(a[x][y - 1] == '3' && vis[x][y - 1] && !fr[x][y - 1] && y - 1 >= 1){
						fr[x][y - 1] = 1;
						q.push(node{3, x, y - 1, fx, x, y, 0});
					} 
					else{
						if(a[x][y - 1] == '0') pg = 1; if(vis[x][y - 1]) pg = 1;
						if(a[x][y - 1] == '2' && bh == 2 && fx == 2) pg = 1;
						if(pg) ++ld; 
						else if(l[x][y - 1]){
							if(co[x][y - 1] != col && lv >= l[x][y - 1])
								ans++, vis[x][y - 1] = 1, q.push(node{a[x][y - 1] - '0', x, y - 1, 1, x, y, 1});
						}
						else if(!bh && a[x][y - 1] == '2') ans++, vis[x][y - 1] = 1, q.push(node{2, x, y - 1, 1, x, y, 0});
						else{
							if(a[x][y - 1] == '3') fr[x][y - 1] = 1;
							ans++, vis[x][y - 1] = 1, q.push(node{a[x][y - 1] - '0', x, y - 1, fx, x, y, 0});
						}
					}
				}pg = 0;
				if(b[x][y] - '0' == bh || !bh){
					if(b[x][y] == '3' && vis[x + 1][y] && !fr[x + 1][y] && x + 1 <= n){
						fr[x + 1][y] = 1;
						q.push(node{3, x + 1, y, fx, x, y, 0});
					} 
					else{
						if(b[x][y] == '0') pg = 1; if(vis[x + 1][y]) pg = 1;
						if(b[x][y] == '2' && bh == 2 && fx == 1) pg = 1; 
						if(pg)++ld;
						else if(l[x + 1][y]){
							if(co[x + 1][y] != col && lv >= l[x + 1][y]) 
								ans++, vis[x + 1][y] = 1, q.push(node{b[x][y] - '0', x + 1, y, 1, x, y, 1});
						}
						else if(!bh && b[x][y] == '2') ans++, vis[x + 1][y] = 1, q.push(node{2, x + 1, y, 2, x, y, 0});
						else{
							if(b[x][y] == '3') fr[x + 1][y] = 1;
							ans++, vis[x + 1][y] = 1, q.push(node{b[x][y] - '0', x + 1, y, fx, x, y, 0});
						}
					}
				}pg = 0;
				if(b[x - 1][y] - '0' == bh || !bh){
					if(b[x - 1][y] == '3' && vis[x - 1][y] && !fr[x - 1][y] && x - 1 >= 1){
						fr[x - 1][y] = 1; 
						q.push(node{3, x - 1, y, fx, x, y, 0});
					} 
					else{
						if(b[x - 1][y] == '0') pg = 1; if(vis[x - 1][y]) pg = 1;
						if(b[x - 1][y] == '2' && bh == 2 && fx == 1) pg = 1; 
						if(pg) ++ld; 
						else if(l[x - 1][y]){
							if(co[x - 1][y] != col && lv >= l[x - 1][y]) 
								ans++, vis[x - 1][y] = 1, q.push(node{b[x - 1][y] - '0', x - 1, y, 1, x, y, 1});
						} 
						else if(!bh && b[x - 1][y] == '2') ans++, vis[x - 1][y] = 1, q.push(node{2, x - 1, y, 2, x, y, 0});
						else{
							if(b[x - 1][y] == '3') fr[x - 1][y] = 1;
							ans++, vis[x - 1][y] = 1, q.push(node{b[x - 1][y] - '0', x - 1, y, fx, x, y, 0});
						}
					}
				}
			}
			printf("%d\n", ans);
			for(int j = 1; j <= top; ++j) vis[o[j]][e[j]] = fr[o[j]][e[j]] = 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

