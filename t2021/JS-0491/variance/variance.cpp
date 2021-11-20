#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;
int perm[MAXN], A[MAXN], B[MAXN]; 

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N-2; i++) perm[i] = i;
	int ans = 23333333;
	do {
		for (int i = 1; i <= N; i++) B[i] = A[i]; 
		int sum = 0;
		double tmp = 0;
		for (int i = 1; i <= N; i++) {
			int p = perm[i]+1;
			B[p] = B[p-1]+B[p+1]-B[p];
//			for (int j = 1; j <= N; j++) cerr << B[j] << " ";
//			cerr << '\n';
			for (int j = 1; j <= N; j++) sum += B[j]; 
			double a = 1.0*sum/N;
			for (int j = 1; j <= N; j++) tmp += (B[j]-a)*(B[j]-a); 
			ans = min(ans, int(tmp*N+0.5));
		}
	} while (next_permutation(perm+1, perm+N+1));
	cout << ans << '\n';
	return 0;
}
