#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<vector<int>> C;
void solve(int n, int m, int k)
{
    vector<int> v(m + 1), cnt(m + 1);
    for (int i = 0; i <= m; i++)
        cin >> v[i];
    int ans = 0;
    function<void(int, int, int, int)> dfs = [&](int step, int sum, int mul, int last)
    {
        if (step == n)
        {
            if (__builtin_popcount(sum) <= k)
            {
                int nn = n;
                for (int i = 0; i <= m; nn -= cnt[i], i++)
                    mul = 1ll * mul * C[nn][cnt[i]] % mod;
                ans = (ans + mul) % mod;
            }
            return;
        }
        for (int i = last; i <= m; i++)
        {
            cnt[i]++;
            dfs(step + 1, sum + (1 << i), 1ll * mul * v[i] % mod, i);
            cnt[i]--;
        }
    };
    dfs(0, 0, 1, 0);
    cout << ans;
}
int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    C.resize(n + 1, vector<int>(n + 1));
    C[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    solve(n, m, k);
    return 0;
}