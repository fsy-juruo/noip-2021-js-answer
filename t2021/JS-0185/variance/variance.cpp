#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int n;
struct Node {
	vector<int> a;
	int s, q; // s: 加和 q: 平方和  d:方差 
	long long d;
	bool operator < (const Node &b) const {
		if (s != b.s) return s < b.s;
		if (q != b.q) return q < b.q;
		if (d != b.d) return d < b.d;
		return a < b.a;
	}
};
set<Node> st;
queue<Node> q;
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	Node s;
	s.d = s.s = s.q = 0;
	int x;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		s.a.push_back(x);
		s.s += x;
		s.q += x * x;
	}
	long long ans = s.d = (long long)s.q * (long long)n - (long long)s.s * (long long)s.s;
	q.push(s);
	st.insert(s);
	for (; !q.empty(); ) {
		Node x = q.front();
		q.pop();
		ans = min(ans, x.d);
		for (int i = 1; i < n - 1; ++i) {
			Node y;
			y.a = x.a;
			y.s = x.s - x.a[i];
			y.q = x.q - x.a[i] * x.a[i];
			y.a[i] = y.a[i - 1] + y.a[i + 1] - y.a[i];
			y.s += y.a[i];
			y.q += y.a[i] * y.a[i];
			y.d = (long long)y.q * (long long)n - (long long)y.s * (long long)y.s;
			if (st.count(y)) continue;
			st.insert(y);
			q.push(y);
		}
	}
	/*
	for (Node x : st) {
		for (int i = 0; i < n; ++i) printf("%d,", x.a[i]);
		printf("   %d %d %lld\n", x.s, x.q, x.d);
	}
	
	*/
	printf("%lld", ans);
	return 0;
}

