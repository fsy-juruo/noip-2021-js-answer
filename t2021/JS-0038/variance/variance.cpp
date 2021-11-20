#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;
int n,nn;
long long ans=100000000000000000ll;
int a[N],b[N],c[N];

void solve1(){
	for(int i=0;i<(1<<n);i++){
		int t=0,sum=0;
		for(int j=0;j<n;j++) if(i&(1<<j)) b[++t]=a[j+1];
		reverse(b+1,b+1+t);
		for(int j=0;j<n;j++) if(~i&(1<<j)) b[++t]=a[j+1];
		for(int j=2;j<=nn;j++) c[j]=c[j-1]+b[j-1],sum+=c[j];
		long long res=0ll;
		for(int j=1;j<=nn;j++) res+=1ll*(sum-nn*c[j])*(sum-nn*c[j]);
		ans=min(ans,res/nn);
	}
	printf("%lld\n",ans);
}

void solve2(){
	reverse(a+1,a+1+n);
	int lsum=0,rsum=0,sum=0;
	int l=1,r=n;
	for(int i=1;i<=n;i++) if(lsum<=rsum) b[l++]=a[i],lsum+=a[i];else b[r--]=a[i],rsum+=a[i];
	for(int j=2;j<=nn;j++) c[j]=c[j-1]+b[j-1],sum+=c[j];
	long long res=0ll;
	for(int j=1;j<=nn;j++) res+=1ll*(sum-nn*c[j])*(sum-nn*c[j]);
	printf("%lld\n",res/nn);
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<n;i++) a[i]=a[i+1]-a[i];
	nn=n;n--;
	sort(a+1,a+1+n);
	if(n<=20) solve1();
	else solve2();
	return 0;
}
