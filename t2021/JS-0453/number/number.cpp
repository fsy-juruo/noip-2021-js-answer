#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void file() {
	freopen("number.in", "r", stdin);
	freopen("number.out","w",stdout);
}

const int maxn = 1e7;
const int MAXN = 1e7 + 100;
int nxt[maxn + 100];

void prepare() {
	int multiply = 1, number, standard;
	for (register int digit = 0; digit != 7; ++digit) {
		int mul = 10 * multiply;
		for (register int i = 7 * multiply; i <= MAXN; i += mul) {
			for (int n = 0; n != multiply; ++n) {
				number = i + n;
				if (nxt[number] == -1) continue;
				standard = MAXN / number;
				for (int j = 1; j <= standard; ++j) {
					nxt[number * j] = -1;
				}
			}
		}
		multiply *= 10;
	}
	int left = 1;
	for (register int i = 2; i <= maxn; ++i) {
		if (nxt[i] != -1) {
			nxt[left] = i;
			left = i;
		}
	}
}

int main() {
	file();
	int times, x;
	scanf("%d", &times);
	prepare();
	while (times--) {
		scanf("%d", &x);
		printf("%d\n", nxt[x]);
	}
	return 0;
}
