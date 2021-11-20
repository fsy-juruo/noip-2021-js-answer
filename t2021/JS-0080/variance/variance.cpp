#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<vector<int>> vis;
    function<int()> get = [&]()
    {
        int ave = 0, res = 0;
        for (int i = 0; i < n; i++)
            ave += a[i];
        for (int i = 0; i < n; i++)
            res += (n * a[i] - ave) * (n * a[i] - ave);
        return res;
    };
    function<void()> dfs = [&]()
    {
        for (int i = 1; i < n - 1; i++)
        {
            a[i] = a[i - 1] + a[i + 1] - a[i];
            if (vis.find(a) == vis.end())
            {
                vis.insert(a);
                ans = min(ans, get());
                dfs();
            }
            a[i] = a[i - 1] + a[i + 1] - a[i];
        }
    };
    vis.insert(a);
    ans = get();
    dfs();
    cout << ans / n << '\n';
    return 0;
}