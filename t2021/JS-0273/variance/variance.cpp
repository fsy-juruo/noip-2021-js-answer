#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], minn = INT_MAX;

int calc() {
	int tot = 0, sum = 0;;
	for(int i = 1; i <= n; ++i) {
		tot += a[i];
		sum += a[i] * a[i];
	}
	//cout << sum << " " << tot << endl;
	sum *= n;
	sum -= tot * tot * 2;
	sum += tot * tot;
	return sum;
}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	if(n == 1) {
		printf("%d", a[1]); return 0;
	}
	if(n == 2) {
		printf("%d", calc()); return 0;
	}
	if(n == 3) {
		minn = calc();
		a[2] = a[1] + a[3] - a[2];
		minn = min(minn, calc());
		printf("%d", minn); return 0; 
	}
	if(n == 4) {
		minn = calc();
		for(int i = 1 ; i <= 6; ++i) {
			int now = i % 2 + 2;
			a[now] = a[now + 1] + a[now - 1] - a[now];
			minn = min(calc(), minn);
		}
		printf("%d", minn); return 0;
	}
	printf("%d", calc()); return 0;
}

