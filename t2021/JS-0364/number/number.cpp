#include <bits/stdc++.h>
#define N 12000005
using namespace std;
int p[N], n, x;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= N - 5; ++i){
		if(p[i]) continue;
		int x = i, pd = 0;
		while(x){
			if(x % 10 == 7){
				pd = 1;
				break;
			}
			x /= 10;
		}
		if(pd) for(int j = i; j <= N - 5; j += i) p[j] = 1;
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		if(p[x]) printf("-1\n");
		else for(int j = x + 1; j < N; ++j){
			if(!p[j]){
				printf("%d\n", j);
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

