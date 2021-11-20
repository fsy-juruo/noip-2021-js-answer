#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
int n,a[10005],ans = 2147483647;
bool vis[171051];
void dfs(int t){
	int tmp = 0,sum = 0,res = 0;
	while(t){
		tmp++;
		a[n - tmp + 1] = t % 11;
		sum += (t % 11);
		t /= 11;
	}
	for(int i = 1;i <= n;i++){
		res += (n * a[i] - sum) * (n * a[i] - sum);
	}
	ans = min(ans,res / n);
	for(int i = 2;i < n;i++){
		int x = a[i],c = 0;
		a[i] = a[i - 1] + a[i + 1] - a[i];
		for(int i = 1;i <= n;i++){
			c = c * 11 + a[i];
		}
		if(!vis[c]){vis[c] = true;dfs(c);}
		a[i] = x;
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		cnt = cnt * 11 + a[i];
	}
	vis[cnt] = true;
	dfs(cnt);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
