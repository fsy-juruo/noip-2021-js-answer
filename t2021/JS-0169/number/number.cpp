#include <bits/stdc++.h>

using namespace std;

const int N = 20000010;

int n, maxn = 0;
int a[N];
bool st[N];

void find (int lar) {
	memset(st, 0, sizeof st);
	for (int i = 1;; i++) {
		if(st[i - 1] == false && i - 1 > lar) {
			break;
		}
		if(st[i] == true) continue;
		bool endd = false;
		int j = i;
		while(j) {
			if(j % 10 == 7) {
				endd = true;
				break;
			} else {
				j /= 10;
			}
		}
		if(endd == true) {
			int k = i;
			while(k - i < lar) {
				st[k] = true;
				k += i;
			}
		}
	}
}

int main () {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		maxn = max(maxn, a[i]);
	}
	find(maxn);
	for (int i = 1; i <= n; i++) {
		if(st[a[i]] == true) {
			printf("-1\n");
		} else {
			int j = a[i] + 1;
			while(st[j] == true) {
				j++;
			}
			printf("%d\n", j);
		}
	}
	return 0;
}
