#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const long long P = 998244353;

long long v[MAXN], a[MAXN];
int n,m,k;
long long ans;
int bit[MAXN];
int cpbit[MAXN];

bool check(){
	int cnt = 0;
	memset(cpbit, 0, sizeof(cpbit));	
	for(int i = 0; i <= m; i++)
		cpbit[i] = bit[i];
	for(int i = 0; i <= 100; i++){
		cpbit[i + 1] += cpbit[i] / 2;
		cpbit[i] %= 2;
		if(cpbit[i] == 1)
			cnt++;
		if(cnt > k)
			return false;
	}
	return true;
}


void dfs(int k){
	if(k == n + 1){
		if(check()){
			long long tot = 1;
			for(int i = 1; i <= n; i++)
				tot = (tot * v[a[i]]) % P;
			ans = (ans + tot) % P;
		}
	}
	else{
		for(int i = 0; i <= m; i++){
			bit[i]++;
			a[k] = i;
			dfs(k+1);
			bit[i]--;
		}
	}
}

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i <= m; i++)
		scanf("%lld", v+i);
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
