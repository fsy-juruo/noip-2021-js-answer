#include<bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define pb push_back
#define lson k<<1
#define rson k<<1|1
//#define getchar nc

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll INF64 = 1e18;
const double eps = 1e-8;

const int maxn = 35;
const int maxm = 105;
const int MOD = 998244353;

inline char nc(){
	static char buf[100005],*p1 = buf,*p2 = buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
}

inline int read(){
	char ch = getchar(); int sum = 0; int f = 0;
	while(!isdigit(ch)) f |= (ch=='-'), ch = getchar();
	while(isdigit(ch)) sum = (sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
	return f ? -sum : sum; 
}

int n,m,K;
int v[maxm];
int con[maxm];
int power2[maxm];
int fac[maxm];
int ifac[maxm];
int ret;

inline int calc(ll x){
	int res = 0;
	for(int j=6;j>=0;j--)
		if(x >= power2[j]) x -= power2[j], res ++;
	return res;
}

inline int ksm(int x,int y){
	int res = 1;
	while(y){
		if(y&1) res = 1ll * res * x % MOD;
		x = 1ll * x * x % MOD; y >>= 1;
	}
	return res;
}

inline int C(int x,int y){
	return 1ll * fac[x] * ifac[y] % MOD * ifac[x-y] % MOD;
}

struct Node{
	int res;
	int cur;
};

int a[maxm];

inline void dfs(int x){
	if(x > n){
		ll tmp = 0; int ans = 1;
		for(int i=1;i<=n;i++) tmp += pow(2,a[i]);
		if(calc(tmp) <= K){
			int last = 1;
//			for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//			cout<<endl;
			for(int i=2;i<=n;i++)
				if(a[i] != a[i-1]){
					ans = 1ll * ans * ksm(v[a[i-1]],i-1-last+1) %MOD * ifac[i-1-last+1] % MOD;
					last = i;
//					cout<<ksm(v[a[i]],i-1-last+1)<<endl;
//					cout<<last<<endl;
				}
			ans = 1ll * ans * ksm(v[a[n]],n-last+1) % MOD * ifac[n-last+1] % MOD;
			ret = (ret + ans) % MOD;
		}
		return;
	}
	for(int i=a[x-1];i<=m;i++){
		a[x] = i;
		dfs(x+1);
		a[x] = 0;
	}
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	power2[0] = 1; power2[1] = 2; power2[2] = 4;
	power2[3] = 8; power2[4] = 16; power2[5] = 32;
	power2[6] = 64;
	n = read(); m = read(); K = read();
	for(int i=0;i<=m;i++) v[i] = read();
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for(int i=2;i<=n;i++) fac[i] = 1ll * fac[i-1] * i % MOD;
	ifac[n] = ksm(fac[n], MOD-2);
	for(int i=n-1;i>=1;i--) ifac[i] = 1ll* ifac[i+1] * (i+1) % MOD;
//	puts("FUCK");
	dfs(1);
	printf("%lld\n",1ll * fac[n] * ret % MOD);
	return 0;
}

