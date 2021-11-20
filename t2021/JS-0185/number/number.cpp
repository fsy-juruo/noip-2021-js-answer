#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 100;
bool nope[MAXN];

bool have7(int x) {
	for (; x; ) {
		if (x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}

vector<int> num;

int solve(int x) {
	int l = 0, r = num.size();
	for (; l < r - 2; ) {
		int m = (l + r) >> 1;
		if (num[m] == x) return num[m + 1];
		if (num[m] < x) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	for (int i = l; i < r; ++i) {
		if (num[i] == x) return num[i + 1];
	}
	return -1;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i < MAXN; ++i) {
		if (have7(i) && !nope[i]) {
			for (int j = 1; i * j < MAXN; ++j)
				nope[i * j] = true;
		}
		if (!nope[i]) num.push_back(i);
	}
	int T, x;
	scanf("%d", &T);
	for(; T--; ) {
		scanf("%d", &x);
		printf("%d\n", solve(x));
	}
	return 0;
}

