#include <bits/stdc++.h>
using namespace std;

const int maxn = 21,mod = 998244353;
int n,m,k;
int v[maxn],a[maxn],j;
long long ans = 0;

inline int pwr2(int x){
	int ret[] = {1,2,4,8,16,32,64,128,256,512,1024};
	return ret[x];
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	cin>>n>>m>>k;
	for (int i=0;i<=m;i++) cin>>v[i];
	
	while (!a[0]){
		int tmp = 0;
		for (int i=1;i<=n;i++) tmp += pwr2(a[i]);
		if (__builtin_popcount(tmp) <= k){
			long long tt = 1;
			for (int i=1;i<=n;i++) tt = (tt*(v[a[i]]%mod))%mod;
			ans = (ans + tt) % mod;
		}
		
		j = n;
		while (a[j] == m){
			a[j] = 0;j--;
		}
		a[j] ++;
	}
	
	cout<<ans<<endl;
	return 0;
}
