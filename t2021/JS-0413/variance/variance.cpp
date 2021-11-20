#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef pair<int,int> pi;
template <class T> void chmax(T &x,T y) {x=x>y?x:y;}
template <class T> void chmin(T &x,T y) {x=x<y?x:y;}
const int inf=1000000000;
const int mod=1000000007;

const int maxn=10005;
int n;
ll ans;
ll a[maxn];

ll clc() {
	double s,d;
	for(int i=1;i<=n;i++) {
		s+=(double)a[i];
	}
	s/=(double)(n);
	for(int i=1;i<=n;i++) {
		d+=(double)(a[i]-s)*(double)(a[i]-s);
	}
	d*=n;
	return (ll)(d);
}

const ll K=13000;
map<vector<ll>,bool> vc;

void dfs() {
	vector<ll> vec(a+1,a+n+1);
	if(vc[vec]) return;
	vc[vec]=1;
	ll nxt=clc();
	if(nxt>ans+K) return;
	ans=min(ans,nxt);
	for(int i=2;i<=n-1;i++) {
		int prei=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		dfs();
		a[i]=prei;
	}
	return;
}

int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	ans=clc();
	dfs();
	printf("%lld\n",ans);
	return 0;
}
