#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, k;
bool bit[150];
int evry[30], v[150];
int ans;

int quickpow(int x, int y){
	long long now = x;
	long long ret = 1;
	while (y){
		if (y & 1){
			ret *= now;
			ret %= mod;
		}
		y >>= 1;
		now *= x;
		now %= mod;
	}
	return ret;
}

void dfs(int ind, int now, int cnt){
	return;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++){
		scanf("%d", &v[i]);
	}
	dfs(1, 0, 0);
	return 0;
}
