#include<bits/stdc++.h>
#include<map>
using namespace std;

typedef long long ll;
const int maxn = 1e4+5;

int a[maxn],b[maxn],n;
ll ans;
map<ll,int> vis;

ll qpow(ll s,ll t) {
	ll anss = 1,p=1;
	while(t) {
		p *= s;
		if(t&1) anss *= p;
		t >>= 1;
	}
	return anss;
}

ll Do(ll squ,ll sum) {
	return n*squ-qpow(sum,2);	
}

ll gao(ll squ,ll sum) {
	return (squ+1)/2*(sum-1)*(squ+4)/3;
}

void dfs(int pos,ll squ,ll sum) {
	if(pos == 1 || pos == n) return;
	//if(vis[gao(squ,sum)]) return;
	
	ll t = b[pos-1] + b[pos+1] - b[pos];
	if(t == b[pos]) return;
	a[pos] = b[pos];
	b[pos] = t;
	ll x = squ-qpow(a[pos],2)+qpow(t,2);
	ll y = sum-a[pos]+t;
	ans = min(ans,Do(x,y));
	if(vis[gao(x,y)]) return;
	else vis[gao(x,y)] = 1;
	
	dfs(pos+1,x,y);
	dfs(pos-1,x,y);
	b[pos] = a[pos];
	return;
}

int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	cin >> n;
	ll squ=0,sum=0;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		b[i] = a[i];
		squ += qpow(a[i],2);
		sum += a[i];
	}
	ans = Do(squ,sum);
	vis[gao(squ,sum)] = 1;
	for(int i=2;i<n;i++) {
		dfs(i,squ,sum);
	}
	cout << ans << endl;
	return 0;
}
