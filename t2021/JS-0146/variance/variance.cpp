#include<bits/stdc++.h>
#define ll long long
#define ge getchar()
using namespace std;
inline void read(ll &x){
	x=0;ll f=0,c=ge;
	for(;c<48||c>57;c=ge)if(c==45)f=1;
	for(;48<=c&&c<=57;c=ge)x=(x<<3)+(x<<1)+(c^48);
	if(f)x=-x;
}
ll n,a[10005],np=0,ns=0,ans=0,c,tp,ts;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		ns+=a[i];
		np+=n*a[i]*a[i];
	}
	ans=np-ns*ns;
	for(int d=2;d<n;++d)
	for(int l=1;l<n;++l){
		int i=d,fl=1;
		while(fl||i!=d){
			c=a[i-1]+a[i+1]-a[i];
			tp=np+n*(c*c-a[i]*a[i]);
			ts=ns+c-a[i];
			if(ans>=tp-ts*ts){
				ans=tp-ts*ts;
				a[i]=c;np=tp;ns=ts;
			}
			fl=0;++i;if(i==n)i=2;
		}
	}
	printf("%lld",ans);
	return 0;
}
