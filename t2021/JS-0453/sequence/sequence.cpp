#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void file() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out","w",stdout);
}

const int mod = 998244353;
int n, length, one_maximum;
int array[102];
int C[102][102];
int bit_sum[102];
long long sum = 0;

void prepare_C() {
	C[0][0] = 1;
	for (int i = 1; i <= 100; ++i) {
		C[i][0] = 1;
		for (int j = 1; j != i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
		C[i][i] = 1;
	}
}

inline void Add(int x) {
	++bit_sum[x];
	for (int i = x; i <= 100; ++i) {
		if (bit_sum[i] > 1) {
			bit_sum[i] &= 1;
			++bit_sum[i + 1];
		} else {
			break;
		}
	}
}

inline void Minus(int x) {
	--bit_sum[x];
	for (int i = x; i <= 100; ++i) {
		if (bit_sum[i] < 0) {
			bit_sum[i] += 2;
			--bit_sum[i + 1];
		} else {
			break;
		}
	}
}

inline int countbit() {
	int s = 0;
	for (int i = 0; i <= 100; ++i) {
		s += bit_sum[i];
	}
	return s;
}

void dfs(int fl, long long product) {
	if (fl == length) {
		if (countbit() <= one_maximum) {
			sum = (sum + product) % mod;
		}
		return;
	}
	for (int i = 0; i <= n; ++i) {
		Add(i);
		dfs(fl + 1, product * array[i] % mod);
		Minus(i);
	}
}

int main() {
	//file();
	prepare_C();
	scanf("%d %d %d", &length, &n, &one_maximum);
	for (int i = 0; i <= n; ++i) {
		scanf("%d", array + i);
	}
	dfs(0, 1);
	printf("%d\n", sum);
	return 0;
}
