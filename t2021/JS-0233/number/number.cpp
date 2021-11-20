#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath> 
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 2e5 + 5, M = 1e5 + 5;

int n, p[N], cnt;
bool st[N];

void init() {
	for (int i = 7; i < N; i++) {
		if (i % 10 == 7) {
			for (int j = 1; j * i < N; j *= 10) {
				int m = i * j;
				for (int k = 0; k < j; k++) st[k + m] = 1, p[++cnt] = k + m;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
		for (int j = 2; p[i] * j < N; j++)
			st[p[i] * j] = 1;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	init();
	scanf("%d", &n);
	int x;
	while (n--) {
		scanf("%d", &x);
		if (st[x]) {
			puts("-1");
			continue;
		}
		int j = x + 1;
		while (st[j]) j++;
		cout << j << endl;
	}
	return 0;
} 
