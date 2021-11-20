#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
bool vis[N];
int nt[N];
int T, x, t, pos = 200002;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &T);
	for(int i = 1; i <= N - 5; i++) {
		if(vis[i]) continue;
		t = i;
		while(t > 0) {
			if(t % 10 == 7) {
				vis[i] = true;
				break;
			}
			t /= 10;
		}
		if(vis[i]) {
			for(int j = 2; j * i <= N - 5; j++) {
				vis[i * j] = true;
			}
		}
	}
	for(int i = N - 5; i >= 1; i--) {
		nt[i] = pos;
		if(vis[i] == false) pos = i;
	}
	while(T--) {
		scanf("%d", &x);
		if(vis[x] == 1) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", nt[x]);
	}
	return 0;
}
