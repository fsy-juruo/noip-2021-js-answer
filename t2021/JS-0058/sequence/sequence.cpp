#include<bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define int long long
const int MAXN = 30 + 10;
const int mod = 998244353;
const int MAXM =  + 10;

inline int fread(void){
	char ch = getchar(); int ret = 0, op = 1;
	for(; !isdigit(ch) && ch != '-'; ch = getchar());
	if(ch == '-') op = -1;
	else ret = ch - '0';
	ch = getchar();
	for(; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return ret * op;
}
int fac[MAXN], ifac[MAXN];
inline int fpow(int base, int top){
	int ret = 1;
	for(; top; top >>= 1){
		if(top & 1) ret = 1ll * ret * base % mod;
		base = 1ll * base * base % mod; 
	} return ret;
}
int n, m, T, v[MAXN];
inline void init(void){
	n = fread(), m = fread(), T = fread();
	fac[0] = 1; for(int i = 1; i <= n; ++ i) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[n] = fpow(fac[n], mod - 2); 
	for(int i = n - 1; i >= 0; -- i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
	
	for(int i = 0; i <= m; ++ i) v[i] = fread();
	
}
int lowbit(int x){ return x & (-x); }
inline int Count(int x){
	int ret = 0; 
	while(x != 0){
		ret ++; x -= lowbit(x); 
	} return ret;
}
/*
int num[MAXN];
inline int figure(int s){
	s -= n;
	for(int i = m; i >= 1; -- i){
		int val = (1 << i) - 1; 
		int now = s / val; 
		num[i] = now; s -= now * val; 
	}
	num[0] = n;
	for(int i = 1; i <= m; ++ i) num[0] -= num[i];
	int k = fac[n], c = 1;
	for(int i = 0; i <= m; ++ i){
		k = 1ll * k * ifac[num[i]] % mod;
		c = 1ll * c * fpow(v[i], num[i]) % mod;
	}
	return 1ll * k * c % mod; 
}*/
int p[MAXN], num[MAXN];
int Ans;
inline int getVal(void){
	int k = fac[n], c = 1;
	for(int i = 0; i <= m; ++ i){
		k = 1ll * k * ifac[num[i]] % mod;
		c = 1ll * c * fpow(v[i], num[i]) % mod;
	}
	return 1ll * k * c % mod; 
}
void dfs(int step, int pre, int sum){
	if(step == n + 1){
		if(Count(sum) <= T)
			Ans = (Ans + getVal()) % mod;
		return; 
	}
	for(int i = pre; i <= m; ++ i){
		num[i] ++;
		dfs(step + 1, i, sum + p[i]);
		num[i] --;
	} 
}
inline void work(void){
	/*
	for(int S = n; S <= n * (1 << m); ++ S){
		if(Count(S) > T) continue;
		Ans = (Ans + figure(S)) % mod;
	}
	printf("%d", Ans);*/
	p[0] = 1;for(int i = 1; i <= m; ++ i) p[i] = (p[i - 1] << 1);
	dfs(1, 0, 0);
	printf("%lld", Ans);
}
#undef int
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	init(); work();
	fclose(stdin); fclose(stdout);
	return 0;
}

