#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define DF(i, a, b) for (int i = (a); i >= (b); --i)
#define SZ(x) (int)x.size() - 1
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long ll;

template <typename T> inline void read(T& x) {
	x = 0; int f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= f;
}
template <typename T> inline void chkmax(T& x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T& x, T y) { x = min(x, y); }

const int N = 1e4 + 10;
int n;
ll s, ans, a[N], b[N], o = LONG_LONG_MAX;
void work1(){
	s = ans = 0;
	F(i, 1, n) s += a[i], ans += n * (a[i] * a[i]);
	ans -= s * s;
	while (1) {
		ll q = 0; int num = 0;
		F(i, 2, n - 1) {
			ll k = a[i - 1] + a[i + 1] - a[i];
			ll z = n * (k * k - a[i] * a[i]) + s * s - (s - a[i] + k) * (s - a[i] + k);
//			cout << s * s - (s - a[i] + k) * (s - a[i] + k) << " " << s << endl;
//			cout << i << " " << z << endl;
			if (z < q) {
				q = z;
				num = i;
//				break;
			}
		}
		if (!num) break;
		ans += q;
		s = s - a[num];
		a[num] = a[num - 1] + a[num + 1] - a[num];
		s = s + a[num];
//		cout << ans << " " << num << " " << q << endl;
//		break;
		chkmin(o, ans);
	}
}
void work2() {
	srand(time(NULL));
	F(_, 1, 2000000) {
		int x = rand() % (n - 2) + 2;
		ll k = a[x - 1] + a[x + 1] - a[x];
		ll z = n * (k * k - a[x] * a[x]) + s * s - (s - a[x] + k) * (s - a[x] + k);
		ans += z;
		s = s - a[x];
		a[x] = a[x - 1] + a[x + 1] - a[x];
		s = s + a[x];
		chkmin(o, ans);
//		cout << ans << endl; 
//		if (o == 59865) {
//			F(i, 1, n) cout << a[i] << " ";
//			cout << endl;
//			return;
//		}
//		cout << ans << endl;
//		return;
//		if (++x == n) x = 2;
	}
}
void work3() {
//	for (ll k = -1000; k <= 1000000; k++) 
	F(i, 1, n) b[i] = a[i];
	F(i, 2, n - 1) {
		a[i] = a[i + 1] + a[i - 1] - a[i];
		DF(j, i - 1, 2) a[j] = a[j + 1] + a[j - 1] - a[j];
		F(j, i + 1, n - 1) a[j] = a[j + 1] + a[j - 1] - a[j];
		ll z = o;
		work1();
		if (o == z) {
			F(j, 1, n) a[j] = b[j];
		}
//		ll k = a[i + 1] + a[i - 1] - a[i] - a[i];
//		ll t = ans + n * (2 * k * (s - a[1] - a[n]) + k * k * (n - 2)) + s * s - (s + (n - 2) * k) * (s + (n - 2) * k);
//		if (t == 250525) {
//			cout << "->" << k << endl;
//		}
//		cout << i << " " << t << endl;
//		chkmin(o, t);
//		work1();
	}
//	F(i, 2, n - 1) {
//		ll k = a[i + 1] + a[i - 1] - a[i] - a[i];
//		ll t = ans + n * (2 * k * (s - a[1] - a[n]) + k * k * (n - 2)) + s * s - (s + (n - 2) * k) * (s + (n - 2) * k);
//		if (t == o) {
//			ans = t;
//			s += (n - 2) * k;
//			F(j, 2, n - 1) a[j] += k;
//			return;
//		}
//	}
}
//void work4() {
//	F(i, 1, n) b[i] = a[i];
//	F(i, 2, n - 1) {
//		ll k = a[i + 1] + a[i - 1] - a[i] - a[i];
//		F(j, 2, n - 1) a[j] += k;
////		F(j, 1, n) cout << a[j] << " "; cout << endl;
//		work1();
////		if (o < 0) {
////			F(j, 1, n) cout << a[j] << " "; cout << endl;
////			exit(0);
////		}
//		F(j, 1, n) a[j] = b[j];
//	}
//}

int main() {
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	read(n);
	F(i, 1, n) read(a[i]);
//	cout << ans << endl;
	work1();
//	F(i, 1, n) cout << a[i] << " "; cout << endl;
//	F(i, 2, n - 1) cout << a[i - 1] + a[i + 1] - a[i] << " "; cout << endl;
	while (1) {
		ll z = o;
		work3();
		if (o == z) break;
	}
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work3();
//	work4();
//	work1();
//	work3();
//	work1();
//	work3();
//	work1();
//	work3();
//	work1();
//	work3();
//	work1();
//	work3();
//	work1();
//	work3();
//	work1();
//	work3();
//	work1();
//	work3();
	work1();
//	F(i, 1, n) cout << a[i] << " "; cout << endl;
	work2();
//	F(i, 2, n - 2) {
//		a[i] = a[i - 1] + a[i + 1] - a[i];
//		work();
//	}
	cout << o;
	return 0;
}

