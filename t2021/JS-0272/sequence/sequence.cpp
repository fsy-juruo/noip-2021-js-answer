#include <bits/stdc++.h>
using namespace std;

#define N (int) 1e5+10
#define MOD 998244353
#define ll long long

int input () {
    int x = 0, f = 0;
    char c = getchar ();
    while (c < '0' || c > '9') f = c == '-', c = getchar ();
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar ();
    return f ? - x : x;
}

int n, m, k;
int v[N];

int ksm (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return ret;
}

int inv (int x) {
    return ksm (x, MOD-2);
}

int frac[N], inv_frac[N];
void getfrac (int x) {
    frac[0] = 1;
    for (int i = 1; i <= x; i ++) {
        frac[i] = 1ll * frac[i-1] * i % MOD;
    }
    inv_frac[x] = inv (frac[x]);
    for (int i = x-1; i >= 0; i --) {
        inv_frac[i] = 1ll * inv_frac[i+1] * (i+1) % MOD;
    }
}

int cnt[N];
int sum = 0;
bool check (int * cnt) {
    int x = 0;
    for (int i = 0; i <= m; i ++) {
        x += cnt[i] % 2;
        cnt[i+1] += cnt[i] / 2;
    }
    return x <= k;
}
int C (int x, int y) {
    return 1ll * ((1ll * frac[x] * inv_frac[y]) % MOD) * inv_frac[x-y] % MOD;
}
int calc (int * cnt) {
    int x = n, ret = 1;
    for (int i = 0; i <= m; i ++) {
        ret = 1ll * ret * C (x, cnt[i]) % MOD;
        x -= cnt[i];
    }
    return ret;
}
void dfs (int id, int * cnt, int num, int ans) {
    if (id == m) {
        cnt[m] = n - num;
        if (check (cnt)) {
            ans = 1ll * ans * calc (cnt) % MOD;
            sum = (sum + ans) % MOD;
        }
        return ;
    }

    for (int i = 0; i <= n - num; i ++) {
        cnt[id] = i;
        dfs (id+1, cnt, num-i, ans * ksm (v[id], i));
    }
}

int main () {
    freopen ("sequence.in", "r", stdin);
    freopen ("sequence.out", "w", stdout);

    n = input (), m = input (), k = input ();
    for (int i = 0; i <= m; i ++) {
        v[i] = input ();
    }

    getfrac (n);
    
    dfs (0, cnt, 0, 1);

    cout << sum << endl;
    
    return 0;
}
