#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10010;
ll n,a[N],b[N],sum,ans=1e9,c[N];
ll work1(){
	for(int i=2;i<n;i++){
		if(a[i]*n<sum&&a[i-1]+a[i+1]>a[i]*2||
		a[i]*n>sum&&a[i-1]+a[i+1]<a[i]*2){
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
	ll s=0,anss=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
	}
	for(int i=1;i<=n;i++){
		anss+=(a[i]*n-s)*(a[i]*n-s);
	}
	return anss/n;
}
ll work2(){
	for(int i=1;i<=n;i++)a[i]=b[i];
	for(int i=2;i<n;i++){
		if(a[i]*n<sum&&a[i-1]+a[i+1]>a[i]*2||
		a[i]*n>sum&&a[i-1]+a[i+1]<a[i]*2){
			a[i]=a[i-1]+a[i+1]-a[i];
			sum+=a[i-1]+a[i+1]-a[i]*2;
		}
	}
	ll anss=0;
	for(int i=1;i<=n;i++){
		anss+=(a[i]*n-sum)*(a[i]*n-sum);
	}
	return anss/n;
}
ll work4(){
	for(int i=1;i<=n;i++)a[i]=b[i];
	for(int i=n-1;i>1;i--){
		if(a[i]*n<sum&&a[i-1]+a[i+1]>a[i]*2||
		a[i]*n>sum&&a[i-1]+a[i+1]<a[i]*2){
			a[i]=a[i-1]+a[i+1]-a[i];
			sum+=a[i-1]+a[i+1]-a[i]*2;
		}
	}
	ll anss=0;
	for(int i=1;i<=n;i++){
		anss+=(a[i]*n-sum)*(a[i]*n-sum);
	}
	return anss/n;
}
ll work3(){
	for(int i=1;i<=n;i++)a[i]=b[i];
	for(int i=2;i<=n/2;i++){
		if(a[i-1]+a[i+1]>a[i]*2){
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
	for(int i=n/2+1;i<n;i++){
		if(a[i-1]+a[i+1]<a[i]*2){
			a[i]=a[i-1]+a[i+1]-a[i];
		}
	}
	ll s=0,anss=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
	}
	for(int i=1;i<=n;i++){
		anss+=(a[i]*n-s)*(a[i]*n-s);
	}
	return anss/n;
}
/*ll workstd(){
	for(int i=1;i<=n;i++)a[i]=b[i];
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n-1;i++)
	for(int j=1;j<=i;j++)
	if(c[i]>c[i])
}*/
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
		sum+=a[i];	
	}
	ans=work1();
	ans=min(ans,work1());
	ans=min(ans,work2());
	ans=min(ans,work1());
	ans=min(ans,work3());
	ans=min(ans,work1());
	ans=min(ans,work4());
	ans=min(ans,work1());
//	ans=min(ans,workstd());
	printf("%lld\n",ans);
	return 0;
}
