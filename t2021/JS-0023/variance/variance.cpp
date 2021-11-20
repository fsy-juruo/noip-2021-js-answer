#include <bits/stdc++.h>
using namespace std;
vector <int> v, w;
int n;
int cal(vector <int> v) {
	int sum = 0;
	for (int i = 0; i < n; i ++) sum += v[i];
	int res = 0;
	for (int i = 0; i < n; i ++) {
		res += (n * v[i] - sum) * (n * v[i] - sum);
	} 
	return res;
}
stack <vector <int> > s;
stack <int> t;
map <vector <int>, bool> m;
int ans = 1e9;
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}
	s.push(v);
	t.push(1);
	m[v] = true;
	int hd, tmp;
	while (!s.empty()) {
		v = s.top(); hd = t.top();
		t.pop();
		if (hd == n - 1) {
			s.pop();
			ans = min(ans, cal(v));
			continue;
		}
		t.push(hd + 1);
		tmp = v[hd + 1] + v[hd - 1] - v[hd];
		swap(v[hd], tmp);
		if (!m[v]) {
			m[v] = true;
			s.push(v);
			t.push(1);
		}
	}
	cout << ans / n << endl;
	return 0;
}
