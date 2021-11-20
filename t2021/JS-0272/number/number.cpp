#include <bits/stdc++.h>
using namespace std;

#define N (int) (1e7+10)
#define INF 0x3f3f3f3f
#define ll long long

int input () {
    int x = 0, f = 0;
    char c = getchar ();
    while (c < '0' || c > '9') f = c == '-', c = getchar ();
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar ();
    return f ? - x : x;
}

int cnt_primes, cnt_sevens;
int primes[N], sevens[N];
int notprime[N+110], minseven[N+110];
int nxt[N+110];
bool check (int x) {
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}
void findsevens (int n) {
    notprime[1] = 1;
    memset (minseven, INF, sizeof (minseven));
    for (int i = 1, pre = 1; i <= n; i ++) {
        if (! notprime[i]) primes[cnt_primes ++] = i;
        if (check (i)) {
            nxt[i] = -1;
            minseven[i] = min(minseven[i], i);
            sevens[cnt_sevens ++] = i;
        }
        if (nxt[i] != -1) nxt[pre] = i, pre = i;
        
        for (int j = 0; j < cnt_primes && 1ll * i * primes[j] <= n; j ++) {
            notprime[i*primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }

        for (int j = 0; j < cnt_sevens && 1ll * i * sevens[j] <= n; j ++) {
            nxt[i*sevens[j]] = -1;
            minseven[i*sevens[j]] = min (minseven[i*sevens[j]], sevens[j]);
            if (i % sevens[j] == 0) {
				break;
			}
        }

        if (nxt[i] == -1) {
            for (int j = 0; j < cnt_primes && 1ll * i * primes[j] <= n; j ++) {
                nxt[i*primes[j]] = -1;
                minseven[i*primes[j]] = min (minseven[i*primes[j]], minseven[i]);
                if ((i / minseven[i]) % primes[j] == 0) break;
            }
        }
    }
}

int main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);

    int t = input ();
    if (t <= 10000) findsevens (200100);
    else findsevens (N+100);

    while (t --) {
        int x = input ();
        printf ("%d\n", nxt[x]);
    }

    return 0;
}
