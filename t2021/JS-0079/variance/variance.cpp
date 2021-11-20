#include <bits/stdc++.h>
#define ll long long
#define N 10010
using namespace std;

ll n, a[N], b[N], sum, ans2, ans = 1000000000, js, pa[N];
bool vh[N];
ll cnt(ll x){
	ll c = 0;
	while(x){
		if(x & 1) c++;
		x >>= 1;
	}
	return c;
}
void calc(){
	for(int i = 1; i <= n; i++)
		b[i] = a[i];
	for(int i = 1; i <= js; i++){
		b[pa[i]] = b[pa[i]-1] + b[pa[i]+1] - b[pa[i]];
	}
	ll squ = 0, sum = 0;
	for(int i = 1; i <= n; i++){
		sum += b[i];
		squ += b[i] * b[i];
	}
	if(n * squ - sum * sum < ans) ans = n * squ - sum*sum;
}
void dfs(ll k, ll x){
	if(k > js){
		calc();
		return ;
	}
	for(int i = 2; i < n; i++){
		if(((x >> (i-2)) & 1) == 0) continue;
		if(!vh[i]){
			vh[i] = true;
			pa[k] = i;
			dfs(k+1,x);
			vh[i] = false;
		}
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 0; i < (1 << (n-2)); i++){
		js = cnt(i);
		dfs(1,i);
	}
	for(int i = 1; i <= n; i++) sum += a[i];
	for(int i = 2; i < n; i++){
		if(2 * (sum - a[i]) > (n-1)*(a[i-1] + a[i+1])){
			sum = sum - 2*a[i] + a[i-1] + a[i+1];
			a[i] = a[i-1] + a[i+1] - a[i];
		}
	}
	for(int i = 1; i <= n; i++){
		ans2 += a[i] * a[i];
	}
	printf("%lld\n",min(ans,ans2));
	return 0;
}
