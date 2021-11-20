#include <bits/stdc++.h>
using namespace std;
int n, m, q, col, lv, x, y;
int getn(int x, int y) { return (x-1) * n + (y-1); }
int getx(int N) { return N / n + 1; }
int gety(int N) { return N % n + 1; }
struct Edge{
    int t, opt;
};
vector<Edge> e[200010];
struct Chess{
    int col, lv, x, y;
} c[200010];
int read() {
    int t = 0; char c;
    while(!isdigit(c = getchar())); t = c - '0';
    while( isdigit(c = getchar())) t = t * 10 + (c - '0');
    return t;
}
int main() {
    //freopen("chess.in",  "r", stdin);
    //freopen("chess.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q); char ch;
    for(int i = 1; i <= n; i++) {
        while(!isdigit(ch = getchar())); ungetc(1, stdin);
        for(int j = 1; j <= m-1; j++) {
            int opt = getchar() - '0';
            if(!opt) continue;
            e[getn(i, j)]  .push_back((Edge){getn(i, j+1), opt});
            e[getn(i, j+1)].push_back((Edge){getn(i, j),   opt});
        }
    }
    for(int i = 1; i <= n-1; i++) {
        while(!isdigit(ch = getchar())); ungetc(1, stdin);
        for(int j = 1; j <= m; j++) {
            int opt = getchar() - '0';
            if(!opt) continue;
            e[getn(i, j)]  .push_back((Edge){getn(i+1, j), opt});
            e[getn(i+1, j)].push_back((Edge){getn(i, j),   opt});
        }
    }
    while(q--) {
        col = read(), lv = read(), x = read(), y = read(); int ans = 0, N = getn(x, y);
        for(int i = 0; i < e[N].size(); i++) {
            switch(e[N][i].opt) {
                case 1:
                    ans++;
                    break;
                case 2:

                case 3:
                    ans++;
                    queue<int> q; q.push(getn(x, y));
                    bool vis[n*m+10]; memset(vis, 0, sizeof(vis));
                    while(!q.empty()) {
                        int t = q.front(); q.pop();
                        for(int i = 0; i < e[t].size(); i++)
                            if(e[t][i].opt == 3) {
                                if(c[e[t][i].t].x){
                                if(col != c[e[t][i].t].col) ans++;}
                                else {ans++, q.push(e[t][i].t);}
                            }
                    }
                    break;
            }
        }
        printf("%d\n", ans);
        c[getn(x, y)] = (Chess){col, lv, x, y};
        
    }
}