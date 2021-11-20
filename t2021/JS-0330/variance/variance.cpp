#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
using namespace std;
int n,a[MAXN],b[MAXN],sum;
ll ans;
bool flag;
ll fangcha() {
	ll summ=0;
	for(int i=1;i<=n;i++) summ+=((ll)a[i]*(ll)n-sum)*((ll)a[i]*(ll)n-sum);
	return summ;
}
void solve() {
	for(int i=1;i<=n-1;i++) {
		for(int j=2;j<=n-1;j++) {
			int t=a[j];
			a[j]=a[j-1]+a[j+1]-t;
			sum=sum-t+a[j];
			ans=min(ans,fangcha());
		}
	}
}
void solve2() {
	for(int i=1;i<=n-1;i++) {
		for(int j=2;j<=n-1;j++) {
			int t=a[j];
			a[j]=a[j-1]+a[j+1]-t;
			sum=sum-t+a[j];
			ans=min(ans,fangcha());
		}
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=(ll)a[i];
	for(int i=1;i<=n;i++) b[i]=a[i];
	ans=fangcha();
	if(n<=4) {
		solve();
		printf("%lld",ans/n);
		return 0;
	}
	flag=0;
	for(int i=2;i<=n-1;i++) {
		if(a[i]-a[i-1]!=a[i+1]-a[i]) flag=1;
	}
	if(!flag) {
		printf("%lld",ans/n);return 0;
	}
	for(int i=2;i<=n-1;i++) solve2();
	printf("%lld",ans/n);
	return 0;
}
