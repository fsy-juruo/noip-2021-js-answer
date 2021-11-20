#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename tn>void read(tn &n) {
	tn x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	n=x*f;
}
int n;
int a[10001];
double k;
double standard[10001];
bool flag=true;
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
		read(a[i]);
	k=(double)(a[n]-a[1])/(n-1);
	for(int i=2; i<n; ++i)
		standard[i]=(double)a[1]+k*(i-1);
	while(flag) {
		flag=false;
		for(int i=n-1; i>1; --i) 
			if(abs((double)a[i-1]+a[i+1]-a[i]-standard[i])<abs((double)a[i]-standard[i])){
				a[i]=a[i+1]+a[i-1]-a[i];
				flag=true;
			}
	}
	int average=0;
	ll ans=0;
	for(int i=1;i<=n;++i)
		average+=a[i];
	for(int i=1;i<=n;++i)
		ans+=(n*a[i]-average)*(n*a[i]-average);
	printf("%lld\n",ans/n);
	return 0;
}

