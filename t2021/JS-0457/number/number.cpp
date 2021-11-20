#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXX = 1e7 + 5, MAXT = 2e5 + 5;

struct node {
	int x, l, r;
	bool vis;
	node(int _x = 0, int _l = 0, int _r = 0) {
		vis = false;
		x = _x, l = _l, r = _r;
	}
} a[MAXX];

int t, x, inp[MAXT], maxx;
bool flag = false;

bool check(int x) {
	while (x > 0) {
		if (x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}

void del(int x) {
	a[x].vis = true;
	a[a[x].l].r = a[x].r;
	a[a[x].r].l = a[x].l;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &inp[i]);
		maxx = max(maxx, inp[i]);
	}
	
	for (int i = 1; i < MAXX; i++) {
		a[i].x = i;
		a[i].l = i - 1; a[i].r = i + 1;
	}
	for (int i = 1; i < MAXX && !flag; i = a[i].r) {
		if (a[i].vis) continue;
		if (check(i) && (i % 10)) {
			del(i);
			for (int j = 2 * i; j < MAXX; j += i) {
				if (a[j].vis) continue;
				del(j);
			}
		}
		if (i > maxx && !a[i].vis) flag = true;
	}
	
	for (int i = 1; i <= t; i++) {
		if (a[inp[i]].vis) printf("-1\n");
		else printf("%d\n", a[inp[i]].r);
	}
	
	fclose(stdin); fclose(stdout);
	return 0;
}
	
	
