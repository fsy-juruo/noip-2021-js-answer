#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 50;
int n;
ll a[N],sum,sum2,ans;
bool work(int x) {
	ll tmp,ori,now;
	tmp=a[x-1]+a[x+1]-a[x];
	ori=n*sum2-sum*sum;
	now=n*(sum2+tmp*tmp-a[x]*a[x])-(sum+tmp-a[x])*(sum+tmp-a[x]);
	if (ori>now)  return 1;
	return 0;
}
void work2(int x) {
	ll tmp;
	tmp=a[x-1]+a[x+1]-a[x];
	sum2=sum2+tmp*tmp-a[x]*a[x];
	sum=sum+tmp-a[x];
	a[x]=tmp;
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%lld",a+i);
		sum+=a[i];
		sum2+=a[i]*a[i];
	}
	ans=n*sum2-sum*sum;
	for (i=1;i<=n;i++)
		for (j=2;j<n;j++)
			if (work(j))  work2(j);
	cout<<n*sum2-sum*sum<<endl;
	return 0;
}

