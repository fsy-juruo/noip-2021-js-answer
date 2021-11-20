#include <bits/stdc++.h>
using namespace std;

#define N (int) 1e5+10
#define ll long long

int input () {
    int x = 0, f = 0;
    char c = getchar ();
    while (c < '0' || c > '9') f = c == '-', c = getchar ();
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar ();
    return f ? - x : x;
}


int n;
int a[N];

int vis[(int) 2e7+10];
int Hash (int * a) {
    int ret = 0;
    for (int i = 1; i <= n; i ++) {
        ret = (1ll * ret * 114514 + a[i]) % 19260817;
    }
    return ret;
}
ll calc (int * a) {
    ll sum = 0;
    for (int i = 1; i <= n; i ++) sum += a[i];
    ll ret = sum * sum;
    for (int i = 1; i <= n; i ++) {
        ret += 1ll * a[i] * (1ll * n * a[i] - 2 * sum);
    }
    // for (int i = 1; i <= n; i ++) cout << a[i] << " ";
    // cout << endl << ret << endl;
    return ret;
}
ll ans = 1e18;
void dfs (int * a) {
    int h = Hash (a);
    if (vis[h]) return ;
    vis[h] = 1;
    ans = min (ans, calc (a));  
    for (int i = 2; i < n; i ++) {
        if (a[i] != a[i-1] + a[i+1] - a[i]) {
            int t = a[i];
            a[i] = a[i-1] + a[i+1] - a[i];
            dfs (a);
            a[i] = t;
        }
    }
}

void Subtask1 () {
    for (int i = 1; i <= n; i ++) a[i] = input ();

    dfs (a);

    printf ("%lld\n", ans);
}

int main () {
    freopen ("variance.in", "r", stdin);
	freopen ("variance.out", "w", stdout);
        
    n = input ();
    Subtask1 ();
    
    return 0;
}
