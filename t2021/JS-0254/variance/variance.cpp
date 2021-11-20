#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

template <typename T>
void input(T &num) {
    num = 0;
    T sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') sign = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    num *= sign;
}

using arr = vector<i64>;
int n;
i64 ans = 0x3f3f3f3f3f3f3f3f;
arr a;
unordered_set<string> s;

string ha() {
    string str = "";
    for (int i : a) str += to_string(i) + " ";
    return str;
}

void dfs() {
    for (int i = 2; i < n; ++i) {
        if (a[i + 1] + a[i - 1] - a[i] != a[i]) {
            int tmp = a[i];
            a[i] = a[i + 1] + a[i - 1] - a[i];
            string h = ha();
            if (!s.count(h)) {
                s.insert(h);
                i64 x = 0, y = 0;
                for (int i = 1; i <= n; ++i) x += a[i] * a[i], y += a[i];
                ans = min(ans, x * n - y * y);
                dfs();
            }
            a[i] = tmp;
        }
    }
}

int main() {
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    input(n);
    a.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) input(a[i]);
    dfs();
    cout << ans << endl;
    return 0;
}
