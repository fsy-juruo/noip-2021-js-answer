#include <bits/stdc++.h>
using namespace std;
template <typename T>
void ri(T& x)
{
    x = 0;
    int flg = 1;
    char c = getchar();
    for (; !isdigit(c) && c != '-'; c = getchar())
        ;
    if (c == '-') {
        flg = -1;
        c = getchar();
    }
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - 48;
    x *= flg;
}
template <typename T, typename... Args>
void ri(T& x, Args&... args)
{
    ri(x), ri(args...);
}
#define FILEIO(x)                        \
    do {                                 \
        freopen(#x ".in", "r", stdin);   \
        freopen(#x ".out", "w", stdout); \
    } while (0)
#define ALL(x) (x).begin(), (x).end()
const int MAXN = 1.5e7;
int isVaild[MAXN];
vector<int> vailds;
void solve()
{
    int n;
    ri(n);
    if (!isVaild[n]) {
        cout << -1 << "\n";
        return;
    }
    cout << *upper_bound(ALL(vailds), n) << "\n";
}
int main()
{
    FILEIO(number);
    int n = 1e7 + 500;
    memset(isVaild, -1, sizeof(isVaild));
    for (int i = 1; i <= n; i++) {
        if (!isVaild[i])
            continue;
        bool has7 = 0;
        int x = i;
        while (x)
            has7 |= x % 10 == 7, x /= 10;
        if (has7) {
            for (int j = i; j <= n; j += i)
                isVaild[j] = 0;
        } else {
            vailds.push_back(i);
        }
    }
    int T;
    ri(T);
    while (T--) {
        solve();
    }
    return 0;
}