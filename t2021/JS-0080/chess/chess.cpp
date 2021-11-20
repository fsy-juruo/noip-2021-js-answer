#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, Q, ans;
        cin >> n >> m >> Q;
        vector<vector<int>> path0(n, vector<int>(m - 1)), path1(n - 1, vector<int>(m));
        vector<vector<pair<int, int>>> board(n, vector<pair<int, int>>(m, {-1, -1}));
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m - 1; j++)
                path0[i][j] = s[j] - '0';
        }
        for (int i = 0; i < n - 1; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                path1[i][j] = s[j] - '0';
        }
        pair<int, int> now;
        function<void(int, int)> dfs = [&](int x, int y)
        {
            vis[x][y] = 1;
            ans++;
            if (y < m - 1 && path0[x][y] == 1 && !vis[x][y + 1] && (board[x][y + 1] == make_pair(-1, -1) || board[x][y + 1].first != now.first && board[x][y + 1].second <= now.second))
                dfs(x, y + 1);
            if (y > 0 && path0[x][y - 1] == 1 && !vis[x][y - 1] && (board[x][y - 1] == make_pair(-1, -1) || board[x][y - 1].first != now.first && board[x][y - 1].second <= now.second))
                dfs(x, y + 1);
            if (x < n - 1 && path1[x][y] == 1 && !vis[x + 1][y] && (board[x + 1][y] == make_pair(-1, -1) || board[x + 1][y].first != now.first && board[x + 1][y].second <= now.second))
                dfs(x + 1, y);
            if (x > 0 && path1[x - 1][y] == 1 && !vis[x - 1][y] && (board[x - 1][y] == make_pair(-1, -1) || board[x - 1][y].first != now.first && board[x - 1][y].second <= now.second))
                dfs(x + 1, y);
            if (y < m - 1 && path0[x][y] == 2)
                for (int i = y + 1; i < m && path0[x][i - 1] == 2; i++)
                    if (!vis[x][i] && (board[x][i] == make_pair(-1, -1) || board[x][i].first != now.first && board[x][i].second <= now.second))
                        dfs(x, i);
            if (y > 0 && path0[x][y - 1] == 2)
                for (int i = y - 1; i >= 0 && path0[x][i] == 2; i--)
                    if (!vis[x][i] && (board[x][i] == make_pair(-1, -1) || board[x][i].first != now.first && board[x][i].second <= now.second))
                        dfs(x, i);
            if (x < n - 1 && path1[x][y] == 2)
                for (int i = x + 1; i < n && path1[i - 1][y] == 2; i++)
                    if (!vis[i][y] && (board[i][y] == make_pair(-1, -1) || board[i][y].first != now.first && board[i][y].second <= now.second))
                        dfs(i, y);
            if (x > 0 && path1[x - 1][y] == 2)
                for (int i = x - 1; i >= 0 && path1[i][y] == 2; i--)
                    if (!vis[i][y] && (board[i][y] == make_pair(-1, -1) || board[i][y].first != now.first && board[i][y].second <= now.second))
                        dfs(i, y);
            if (y < m - 1 && path0[x][y] == 3)
            {
                queue<pair<int, int>> q;
                vector<vector<bool>> pass(n, vector<bool>(m));
                q.push({x, y});
                while (q.size())
                {
                    if (y < m - 1 && path0[x][y] == 3 && !pass[x][y + 1])
                    {
                        pass[x][y + 1] = 1;
                        if (!vis[x][y + 1])
                        {
                            vis[x][y + 1] = 1;
                            ans++;
                        }
                        q.push({x, y + 1});
                    }
                    if (y > 0 && path0[x][y - 1] == 3 && !pass[x][y - 1])
                    {
                        pass[x][y - 1] = 1;
                        if (!vis[x][y - 1])
                        {
                            vis[x][y - 1] = 1;
                            ans++;
                        }
                        q.push({x, y - 1});
                    }
                    if (x < n - 1 && path1[x][y] == 3 && !pass[x + 1][y])
                    {
                        pass[x + 1][y] = 1;
                        if (!vis[x + 1][y])
                        {
                            vis[x + 1][y] = 1;
                            ans++;
                        }
                        q.push(make_pair(x + 1, y));
                    }
                    if (x > 0 && path1[x - 1][y] == 3 && !pass[x - 1][y])
                    {
                        pass[x - 1][y] = 1;
                        if (!vis[x - 1][y])
                        {
                            vis[x - 1][y] = 1;
                            ans++;
                        }
                        q.push(make_pair(x - 1, y));
                    }
                }
            }
        };
        while (Q--)
        {
            ans = 0;
            vis.assign(n, vector<bool>(m, 0));
            int xx, yy;
            cin >> now.first >> now.second >> xx >> yy;
            dfs(xx, yy);
            board[xx][yy] = now;
            cout << ans << '\n';
        }
    }
    return 0;
}