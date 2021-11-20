#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3fll;

int n; ll ans = llINF;
vector<int> a;
map<vector<int>, bool> mp;

void dfs(const vector<int> &vec) {
    if (mp.count(vec)) return;
    mp[vec] = 1; ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) s1 += vec[i] * vec[i], s2 += vec[i];
    ans = min(ans, s1 * n - s2 * s2);
    for (int i = 1; i < n - 1; i++) {
        vector<int> v = vec;
        v[i] = v[i - 1] + v[i + 1] - v[i];
        dfs(v);
    }
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w",stdout);
    scanf("%d", &n); for (int i = 0, x; i < n; i++) scanf("%d", &x), a.push_back(x);
    dfs(a); printf("%lld\n", ans);
	return 0;
} 
