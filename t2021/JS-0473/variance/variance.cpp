#include <bits/stdc++.h>
using namespace std;
int n;
int a[10010];
long long sum, squ_sum;
long long ans;

void dfs(int last){
	ans = min(ans, n * squ_sum - sum * sum);
	for (int i = 2; i < n; i++){
		if (i != last && a[i - 1] + a[i + 1] != 2 * a[i]){
			int tmp = a[i];
			long long tmp1 = sum, tmp2 = squ_sum;
			sum -= a[i];
			squ_sum -= a[i] * a[i];
			a[i] = a[i - 1] + a[i + 1] - a[i];
			sum += a[i];
			squ_sum += a[i] * a[i];
			dfs(i);
			a[i] = tmp;
			sum = tmp1;
			squ_sum = tmp2;
		}
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
		squ_sum += a[i] * a[i];
	}
	ans = n * squ_sum - sum * sum;
	dfs(-1);
	printf("%d\n", ans);
	return 0;
}
