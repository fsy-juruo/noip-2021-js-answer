#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e4 + 10;
int a[MAXN];
int n;
int t[MAXN];
string ns;
LL sqr;
LL sum;
LL ans;
int cnt;
int st, ed;
LL cl()
{
    LL res = sqr * n;
    res -= sum * sum;
    return res;
}
void dfs(int pos)
{
    cnt++;
    if (cnt >= 1000000)
    {
        cout << ans << endl;
        exit(0);
    }
    int org = t[pos];
    t[pos] = t[pos + 1] + t[pos - 1] - t[pos];
    if (t[pos] == a[pos])
    {
        t[pos] = org;
        return;
    }
    sqr -= org * org;
    sqr += t[pos] * t[pos];
    sum = sum - org + t[pos];
    ans = min(ans, cl());
    for (int i = 2; i < n; i++)
    {
        if (i == pos)
        {
            continue;
        }
        dfs(i);
    }
    sqr -= t[pos] * t[pos];
    sqr += org * org;
    sum = sum - t[pos] + org;
    t[pos] = org;
}
int main()
{
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[i] = a[i];
        sqr += (a[i] * a[i]);
        sum += a[i];
        ns += (char)(a[i] + '0');
    }
    ans = cl();
    dfs(2);
    cout << ans << endl;
    return 0;
}