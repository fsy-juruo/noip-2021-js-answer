#include <bits/stdc++.h>
using namespace std;
const int maxx = 1000010;
int t;

int nxt[maxx];

bool p(int x){
	while (x){
		if (x % 10 == 7){
			return 0;
		}
		x /= 10;
	}
	return 1;
}

void init(){
	for (int i = 1; i < maxx; i++){
		nxt[i] = 1;
	}
	for (int i = 1; i < maxx; i++){
		if (nxt[i] && !p(i)){
			for (int j = i; j < maxx; j += i){
				nxt[j] = 0;
			}
		}
	}
	int last = 1;
	for (int i = 2; i <= maxx; i++){
		if (nxt[i]){
			nxt[last] += i << 1;
			last = i;
		}else{
			nxt[i] = -2;
		}
	}
	return;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	scanf("%d", &t);
	while (t--){
		int x;
		scanf("%d", &x);
		printf("%d\n", nxt[x] >> 1);
	}
	return 0;
}
