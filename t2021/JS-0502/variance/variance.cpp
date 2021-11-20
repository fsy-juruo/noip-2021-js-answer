#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[10010];
LL d[10010];
LL f[10010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
		f[i]=i;
	}
	LL mi=LLONG_MAX;
	do{
		LL s=0;
		for(LL i=2;i<=n;i++){
			a[i]=a[i-1]+d[f[i-1]+1];
			s+=a[i];
		}
		s+=a[1];
		LL ans=0;
		for(LL i=1;i<=n;i++){
			ans+=(a[i]*n-s)*(a[i]*n-s);
		}
		ans/=n;
		mi=min(mi,ans);
	}while(next_permutation(f+1,f+n));
	cout<<mi<<endl;
	return 0;
}

