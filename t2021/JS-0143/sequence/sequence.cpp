#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define mod 998244353
int n,m,k,a[105];
ll v[105],ans;
inline int calc(int cont){
	int x = 0;
	while(cont){
		cont = cont - (cont & (-cont));
		x++;
	}
	return x;
}
void dfs(int step,int cont){
//	cout << step << ' ' << cont << endl;
	if(step > n){
		int x = 0;
		while(cont){
			cont = cont - (cont & (-cont));
			x++;
		}
		ll tmp = 1;
		if(x <= k){
			for(re int i = 1;i <= n;i++){
				tmp *= v[a[i]];
				tmp %= mod;
			}
			ans += tmp;
			ans %= mod;
		}
		return;
	}
	for(int i = 0;i <= m;i++){
		a[step] = i;
		dfs(step + 1,cont + (1 << i));
	}
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0;i <= m;i++){
		scanf("%lld",&v[i]);
		v[i] %= mod;
	}
	dfs(1,0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
