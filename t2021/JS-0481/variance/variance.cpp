#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
typedef long long ll;

const int N = 1000010;
__gnu_pbds::cc_hash_table<int, bool> hs;

inline int vhash(vector<int> v) {
	int res = 0, n = v.size() - 1;
	for (int i = 1; i <= n; i++)
		res = (res << 3) + (res << 1) + v[i];
	return res;
}

inline vector<int> operate(vector<int> a, int i) {
	a[i] = a[i + 1] + a[i - 1] - a[i];
	return a;
}
queue<vector<int> > q;

inline ll sigma(vector<int> a) {
	int n = a.size() - 1;
	ll res = 0;
	for (int i = 1; i <= n; i++) 
		res += a[i];
	long long sigma = 0.;
	for (int i = 1; i <= n; i++)		
		sigma += (1ll * n * a[i] - res) * (1ll * n * a[i] - res);
	return sigma;
}
ll minimum = 531163989215212115;

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);

	int n; scanf("%d", &n);
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	q.push(v);
	while (!q.empty()) {
		vector<int> v = q.front(); q.pop();
		int val = vhash(v);
		if (hs[val]) continue;
		else {
			hs[val] = 1;
			ll vival = sigma(v);
	
			if (vival < minimum) 
				minimum = vival;
		}
		for (int i = 2; i <= n - 1; i++)
			q.push(operate(v, i));
	}
//	for (int i = 1; i <= n; i++)
//		cout << ans[i] << " ";
//	cout << endl;
	cout << minimum / n << endl;

	return 0;
}


