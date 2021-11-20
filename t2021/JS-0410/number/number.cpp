#include <bits/stdc++.h>
using namespace std;

int can[10000010];
int ans[10000010];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= 10000001; i++) can[i] = 1;
	for (int i = 1; i <= 10000001; i++){
		if (can[i] == 0) continue;
		int t = i;
		can[i] = 1;
		while (t){
			if (t % 10 == 7) can[i] = 0;
			t /= 10;
		}
		if (!can[i]){
			for (int j = i; j <= 10000001; j += i) can[j] = 0;
		}
	}
	int now = 10000001;
	for (int i = 10000000; i >= 1; i--){
		ans[i] = now;
		if (can[i]) now = i;
	}
	int t;
	scanf("%d", &t);
	while (t--){
		int q;
		scanf("%d", &q);
		if (can[q]) printf("%d\n", ans[q]);
		else printf("-1\n");
	} 
	return 0;
}

