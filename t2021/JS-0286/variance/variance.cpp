#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;

int n,a[MAXN];
int ans = 0x3f3f3f3f;

void dfs(int k){
	if(k == n)
		return;
	int tot = 0;
	for(int i = 1; i <= n; i++)
		tot += a[i];
	double avg = double(tot) / double(n);
	double x = 0.00;
	for(int i = 1; i <= n; i++)
		x += (a[i] - avg) * (a[i] - avg);
	x *= n;
	int y = int(x + 0.5);
	if(y < ans)
		ans = y;
	dfs(k+1);
	int tmp = a[k];
	a[k] = a[k-1] + a[k+1] - a[k];
	dfs(k+1);
	a[k] = tmp;
}

int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", a+i);
	dfs(2);
	printf("%d", ans);
	return 0;
}
