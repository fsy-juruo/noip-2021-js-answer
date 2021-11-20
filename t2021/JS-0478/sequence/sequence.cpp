#include<bits/stdc++.h>
#define int long long
using namespace std;
int MOD=998244353;
int n, m, k, v[101], s[101], x[201], opt;
int C(int x, int y){
	int a=1, b=1;
	for (int i=1; i<=y; i++) a*=(x-i+1), b*=i;
	return (a/b)%MOD;
}
int ksm(int x, int y){
	if (y==0) return 1;
	if (y==1) return x;
	if (y%2==0){
		int f=ksm(x, y/2);
		return (f*f)%MOD;
	}
	else{
		int f=ksm(x, y/2);
		return (((f*f)%MOD)*x)%MOD;
	}
}
void check(){
	for (int p=0; p<=199; p++){
		x[p+1]+=x[p]/2;
		x[p]%=2;
	}
	int sum=0;
	for (int i=0; i<=200; i++)
		if (x[i]==1) sum++, x[i]=s[i];
	if (sum>k) return;
	int ans=1, mul=1, q=n;
	for (int i=0; i<=m; i++){ans*=ksm(v[i], s[i]); ans%=MOD;}
	for (int i=0; i<=m; i++){mul*=C(q, s[i]);mul%=MOD;q-=s[i];}
	opt+=(ans*mul)%MOD;
	opt%=MOD;
}
void dfs(int num, int t, int left){
	s[num]=t;
	x[num]=t;
	if (num==m){
		check();
		return;
	}
	if (num==m-1){
		dfs(num+1, left, 0);
		return;
	}
	for (int i=0; i<=left; i++)
		dfs(num+1, i, left-i);
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i=0; i<=m; i++) scanf("%lld", &v[i]);
	for (int i=0; i<=n; i++)
		dfs(0, i, n-i);
	cout << opt << endl;
	return 0;
}
