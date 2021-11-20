#include<bits/stdc++.h>
using namespace std;
struct point{
    bool col;
    int lv = 0;
    short d[4] = {0, 0, 0, 0};
};
int d[4][2] = {
    -1, 0,
    0, 1,
    1, 0,
    0, -1};
point mp[1010][1010];
bool vis[1010][1010];
void dfs(int col, int lv, int x, int y){
    vis[x][y] = true;
    if (mp[x][y].lv != 0){
        if (mp[x][y].col == col || mp[x][y].lv > lv){
            vis[x][y] = false;
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (mp[x][y].d[i] == 3){
            int nx = x + d[i][0], ny = y + d[i][1];
            if (!vis[nx][ny]){
                dfs(col, lv, nx, ny);
            }
        }
    }
}
int main(){
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int T;
    cin >> T;
    while (T--){
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                mp[i][j].lv = 0;
            }
        }
        getchar();
        for (int i = 1; i <= n; i++){
            for (int j = 1; j < m; j++){
                char c = getchar();
                mp[i][j].d[1] = (c - '0');
                mp[i][j + 1].d[3] = (c - '0');
            }
            getchar();
        }
        for (int i = 1; i < n; i++){
            for (int j = 1; j <= m; j++){
                char c = getchar();
                mp[i][j].d[2] = (c - '0');
                mp[i + 1][j].d[0] = (c - '0');
            }
            getchar();
        }
        for (int i = 0; i < q; i++){
            memset(vis, 0, sizeof(vis));
            int col, lv, x, y;
            scanf("%d%d%d%d", &col, &lv, &x, &y);
            mp[x][y].col = col;
            mp[x][y].lv = lv;
            for (int j = 0; j < 4; j++){
                if (mp[x][y].d[j] == 3){
                    int nx = x + d[j][0], ny = y + d[j][1];
                    if (!vis[nx][ny]){
                        dfs(col, lv, nx, ny);
                    }
                }
            }
            for (int j = 0; j < 4; j++){
                if (mp[x][y].d[j] == 2){
                    int nx = x, ny = y;
                    while(true){
                        nx += d[j][0];
                        ny += d[j][1];
                        if (!vis[nx][ny]){
                            vis[nx][ny] = true;
                            if (mp[nx][ny].lv != 0){
                                if (mp[nx][ny].col == col || mp[nx][ny].lv > lv){
                                    vis[nx][ny] = false;
                                }
                                break;
                            }
                        }
                        if (mp[nx][ny].d[j] != 2){
                            break;
                        }
                    }
                }
            }
            for (int j = 0; j < 4; j++){
                if (mp[x][y].d[j] == 1){
                    int nx = x + d[j][0], ny = y + d[j][1];
                    if (!vis[nx][ny]){
                        vis[nx][ny] = true;
                        if (mp[nx][ny].lv != 0){
                            if (mp[nx][ny].col == col || mp[nx][ny].lv > lv){
                                vis[nx][ny] = false;
                            }
                            break;
                        }
                    }
                }
            }
            int c = 0;
            for (int j = 1; j <= n; j++){
                for (int k = 1; k <= m; k++){
                    if (vis[j][k]){
                        c++;
                    }
                }
            }
            cout << c << '\n';
        }
    }
    return 0;
}