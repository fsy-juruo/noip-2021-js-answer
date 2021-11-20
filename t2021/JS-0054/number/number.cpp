//pts: 100
#include <cstdio>

#define _N 10000010

int T;

bool vis[_N];
bool con[_N];
int nxt[_N];

void pre() {
	for (int i = 1; i < _N; i++) {
		con[i] = (i % 10 == 7) || con[i / 10];
		if (!vis[i] && con[i]) {
			for (int j = 1; i * j < _N; j++) {
				vis[i * j] = true;
			}
		}
	}
	int last = -1;
	for (int i = _N - 1; i >= 0; i--) {
		if (!vis[i]) {
			last = i;
			break;
		}
	}
	for (int i = last - 1; i >= 1; i--) {
		nxt[i] = last;
		if (!vis[i]) {
			last = i;
		}
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	pre();
	scanf("%d", &T);
	while(T--) {
		int x;
		scanf("%d", &x);
		printf("%d\n", vis[x] ? -1 : nxt[x]);
	}
	return 0;
}
