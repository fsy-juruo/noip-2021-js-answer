#include <bits/stdc++.h>
#define pb push_back
#define P pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1e7 + 10;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
inline int rd() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int a[N];
bool f[N];
map<int, int> mp;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    memset(f, true, sizeof(f));
	int T;
	T = rd();
    int cnt = 0;
    for (int i = 7; i <= 1e7; i += 7) f[i] = 0; 
	for (int i = 1; i <= 1e7; i++) {
        int t = i;
        bool ok = false;
        while (t) {
            if (t % 10 == 7) {
                ok = true;
                break;
            } 
            t /= 10;
        }
        if (ok) {
            for (int j = i; j <= 1e7; j += i) f[j] = 0;
        }
        if (f[i]) {
            a[++cnt] = i;
			mp[i] = cnt;
        }
	}
	while (T--) {
		int x = rd();
        if (!f[x]) printf("%d\n", -1);
        else printf("%d\n", a[mp[x] + 1]);
	}
	return 0;
} 
