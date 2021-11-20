#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int) (n); ++ i)
#define rep1(i, n) for (int i = 1; i <= (int) (n); ++ i)

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = (LL) 1e17 + 7;

int N, a[10004];
int b[10004];

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	
	scanf("%d", &N);
	rep1(i, N) scanf("%d", &a[i]);
	rep1(i, N - 1) b[i] = a[i + 1] - a[i];
	
	sort(b + 1, b + N);
	
	LL ret = INF;
	do {
		for (int i = 2; i <= N; ++ i) {
			a[i] = a[i - 1] + b[i - 1];
		}
		LL cd = 0, sum = 0;
		for (int i = 1; i <= N; ++ i) {
			cd += 1ll * a[i] * a[i];
			sum += a[i];
		}
		cd *= N;
		cd -= 1ll * sum * sum;
		ret = min(ret, cd);
	} while (next_permutation(b + 1, b + N));
	
	printf("%lld\n", ret);
	
	return 0;
}
