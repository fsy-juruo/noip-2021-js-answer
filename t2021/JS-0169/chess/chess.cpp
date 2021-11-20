#include <bits/stdc++.h>

using namespace std;

int main () {
	srand(time(NULL));
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	for (int i = 1; i <= rand() % 100; i++) {
		printf("%d\n", rand() % 10);
	}
	return 0;
}
