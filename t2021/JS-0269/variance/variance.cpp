#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define fi first
#define sc second
typedef long long ll;
using namespace std;

int rdi(){
	int cur=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		cur*=10;
		cur+=((int)ch-'0');
		ch=getchar();
	}
	return cur;
}
int n;
ll sum,a[10010],b[10010];
ll calc(int l,int r){
	forn(i,n){
		b[i]=a[i];
	}
	for(int i=r;i<n;i++){
		int to=b[i+1]+b[i-1]-b[i];
		if(to<b[i]){
			b[i]=to;
		}
	}
	for(int i=l;i>1;i--){
		int to=b[i+1]+b[i-1]-b[i];
		if(to>b[i]){
			b[i]=to;
		}
	}
	ll va=0ll;
	forn(i,n){
		//cout<<b[i]<<" ";
		va+=(b[i]*b[i]);
	}
	//cout<<endl;
	va*=((ll)n);
	ll cur=0ll;
	forn(i,n){
		cur+=b[i];
	}
	cur*=cur;
	va-=cur;
	
	forn(i,n){
		b[i]=a[i];
	}
	for(int i=l;i>1;i--){
		int to=b[i+1]+b[i-1]-b[i];
		if(to>b[i]){
			b[i]=to;
		}
	}
	for(int i=r;i<n;i++){
		int to=b[i+1]+b[i-1]-b[i];
		if(to<b[i]){
			b[i]=to;
		}
	}
	ll vb=0ll;
	forn(i,n){
		vb+=(b[i]*b[i]);
	}
	vb*=((ll)n);
	cur=0ll;
	forn(i,n){
		cur+=b[i];
	}
	cur*=cur;
	vb-=cur;
	va=min(va,vb);
	return va;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=rdi();
	forn(i,n){
		a[i]=rdi();
		//cout<<a[i]<<endl;
		//sum+=a[i];
	}
	ll ans=1e18;
	for(int l=1;l<n;l++){
		for(int r=l;r<=n;r++){
			ans=min(ans,calc(l,r));
		}
		//ans=min(ans,calc(l,l+1));
	}
	for(int l=1;l<=n;l++){
		ans=min(ans,calc(l,l));
		int bef=a[l];
		a[l]=a[l-1]+a[l+1]-a[l];
		ans=min(ans,calc(l,l));
		a[l]=bef;
	}
	cout<<ans<<endl;
	return 0;
}
