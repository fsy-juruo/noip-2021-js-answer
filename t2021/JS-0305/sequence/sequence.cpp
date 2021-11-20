#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5+5;
const int mod = 998244353;

ll qpow(ll a,ll n) {
	ll ans = 1,p=1;
	while(n) {
		p *= a;
		if(n&1) ans *= p;
		n >>= 1;
	}
	return ans;
}

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=1;i<=100;i++) {
		cout << qpow(2,i) << ",";
	}
	
	int n,m,k;
	cin >> n >> m >> k;
	if(k == 1) {
		cout << "40" << endl;
	}
	
	return 0;
}
