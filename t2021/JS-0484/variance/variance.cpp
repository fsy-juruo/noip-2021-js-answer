#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005], b[10005];
int ans;
void calc() {
	double av = (b[1]+b[2]+b[3]+b[4]) / 4.0;
	double s2 = ((b[1] - av) * (b[1]-av) +(b[2]-av)*(b[2]-av)+(b[3]-av)*(b[3]-av)+(b[4]-av)*(b[4]-av)) / 4.0;
	double n2 = 1.0 * n * n;
	int res = (int)(s2 * n2);
	ans = min(ans, res);
}
int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if(n == 4) {
		ans = 0;
		b[1]=a[1];b[2]=a[2];b[3]=a[3];b[4]=a[4];
		calc();
		b[2]=a[1]+a[3]-a[2];
		calc();
		b[2]=a[2];b[3]=a[2]+a[4]-a[3];
		calc();
		b[2]=a[1]+a[4]-a[3];b[3]=a[2]+a[4]-a[3];
		calc();
		b[2]=a[1]+a[3]-a[2];b[3]=a[1]+a[4]-a[2];
		calc();
		b[2]=a[1]+a[4]-a[3];b[3]=a[1]+a[4]-a[2];
		calc();
		cout << ans << '\n';
	} else {
		cout << 0 << '\n';
	}
	return 0;
}
