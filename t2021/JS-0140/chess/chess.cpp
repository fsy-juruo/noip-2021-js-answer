#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 10;
vector<PII> node[MAXN];
int n, m;
int c[MAXN];
struct Chess
{
    int co;
    int lv;
} tmpc;
vector<Chess> chess;
int cnt;
int h[MAXN];
int ans;
bool vis[MAXN];
int tra(int x, int y)
{
    return (x - 1) * m + y;
}
void dfs(int x, int y, int co, int lv, int r, int st)
{
    if (r == 1)
    {
        return;
    }
    for (auto i : node[tra(x, y)])
    {
        int tmp = i.second;
        int yy = tmp % m;
        if (yy == 0)
        {
            yy = m;
        }
        int xx = (tmp - yy) / m + 1;
        int nr = i.first;
        if (vis[tra(xx, yy)])
        {
            continue;
        }
        if (r != 0 && nr != r)
        {
            continue;
        }
        if (nr == 2)
        {
            if (st == 1)
            {
                if (xx != x)
                {
                    continue;
                }
            }
            else if (st == 2)
            {
                if (yy != y)
                {
                    continue;
                }
            }
            else
            {
                if (xx == x)
                {
                    st = 1;
                }
                else
                {
                    st = 2;
                }
            }
        }
        vis[tra(xx, yy)] = true;
        if (h[tra(xx, yy)])
        {
            int tmp = h[tra(xx, yy)] - 1;
            // cout << "!" << xx << " " << yy << " " << co << " " << chess[tmp].co << " " << lv << " " << chess[tmp].lv << endl;
            if (co != chess[tmp].co && lv >= chess[tmp].lv)
            {
                // cout << xx << " " << yy << endl;
                ans++;
            }
            continue;
        }
        // cout << xx << " " << yy << endl;
        ans++;
        dfs(xx, yy, co, lv, nr, st);
        if (r != 2)
        {
            st = 0;
        }
    }
}
int main()
{
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    // scanf("%d", &t);
    cin >> t;
    while (t--)
    {
        int q;
        // scanf("%d%d%d", &n, &m, &q);
        cin >> n >> m >> q;
        for (int i = 0; i < n; i++)
        {
            string s;
            // scanf("%s", s);
            cin >> s;
            for (int j = 0; j < s.length(); j++)
            {
                int now = s[j] - '0';
                if (!now)
                {
                    continue;
                }
                node[tra(i + 1, j + 1)].push_back(make_pair(now, tra(i + 1, j + 2)));
                node[tra(i + 1, j + 2)].push_back(make_pair(now, tra(i + 1, j + 1)));
            }
        }
        for (int i = 1; i < n; i++)
        {
            string s;
            // scanf("%s", s);
            cin >> s;
            for (int j = 0; j < s.length(); j++)
            {
                int now = s[j] - '0';
                if (!now)
                {
                    continue;
                }
                node[tra(i, j + 1)].push_back(make_pair(now, tra(i + 1, j + 1)));
                node[tra(i + 1, j + 1)].push_back(make_pair(now, tra(i, j + 1)));
            }
        }
        while (q--)
        {
            int co;
            int lv;
            int x;
            int y;
            // scanf("%d%d%d%d", &co, &lv, &x, &y);
            cin >> co >> lv >> x >> y;
            ans = 0;
            memset(vis, 0, sizeof(vis));
            vis[tra(x, y)] = true;
            dfs(x, y, co, lv, 0, 0);
            // printf("%d\n", ans);
            cout << ans << endl;
            tmpc.co = co;
            tmpc.lv = lv;
            chess.push_back(tmpc);
            h[tra(x, y)] = chess.size();
        }
        for (int i = 1; i <= n * m; i++)
        {
            node[i].clear();
        }
        memset(h, 0, sizeof(h));
    }
    return 0;
}