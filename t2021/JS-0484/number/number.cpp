#include <bits/stdc++.h>
using namespace std;
bool bd[10000005];
int lst[10000005];
int x[200005];
void precalc() {
	memset(bd, 0, sizeof(bd));
	memset(lst, 0, sizeof(lst));
	for(int i = 2; i <= 200000; ++i) {
		int t = i;
		bool sv = false;
		while(t) {
			if(t % 10 == 7) {
				sv = true;
				break;
			}
			t /= 10;
		}
		if(sv) {
			for(int j = i; j <= 200000; j += i) {
				bd[j] = true;
			}
		}
	}
	int hd = 200002;
	for(int i = 200000; i >= 1; --i) {
		lst[i] = hd;
		if(!bd[i]) {
			hd = i;
		}
	}
}
void precalc2() {
	memset(bd, 0, sizeof(bd));
	memset(lst, 0, sizeof(lst));
	for(int i = 2; i <= 10000000; ++i) {
		int t = i;
		bool sv = false;
		while(t) {
			if(t % 10 == 7) {
				sv = true;
				break;
			}
			t /= 10;
		}
		if(sv) {
			for(int j = i; j <= 10000000; j += i) {
				bd[j] = true;
			}
		}
	}
	int hd = 10000001;
	for(int i = 10000000; i >= 1; --i) {
		lst[i] = hd;
		if(!bd[i]) {
			hd = i;
		}
	}
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int t;
	scanf("%d", &t);
	int mxv = 0;
	for(int i = 1; i <= t; ++i) {
		scanf("%d", &x[i]);
		mxv = max(mxv, x[i]);
	}
	if(mxv > 200000) {
		precalc2();
	} else {
		precalc();
	}
	for(int i = 1; i <= t; ++i) {
		if(bd[x[i]]) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", lst[x[i]]);
	}
	return 0;
}
