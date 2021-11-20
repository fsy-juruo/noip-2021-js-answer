#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

template <typename T>
void input(T &num) {
    num = 0;
    T sign = 1;
    char ch = cin.get();
    while (ch < '0' || ch > '9') {
        if (ch == '-') sign = -1;
        ch = cin.get();
    }
    while (ch >= '0' && ch <= '9') {
        num = num * 10 + ch - '0';
        ch = cin.get();
    }
    num *= sign;
}

const int maxn = 10000001;
bool vis[maxn + 5];
int nxt[maxn + 5];

inline int getbit(int x, int base) { return x / base % 10; }

void init() {
    for (int i = 1; i <= maxn; ++i) {
        if (vis[i]) continue;
        for (int j = 1; j <= maxn; j *= 10) {
            if (getbit(i, j) == 7) {
                vis[i] = true;
                for (int j = i * 2; j <= maxn; j += i) vis[j] = true;
            }
        }
    }
    int now = maxn;
    for (int i = maxn; i >= 1; --i) {
        nxt[i] = now;
        if (!vis[i]) now = i;
    }
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    input(t);
    while (t--) {
        int x;
        input(x);
        if (vis[x])
            cout << "-1\n";
        else
            cout << nxt[x] << "\n";
    }
    return 0;
}
