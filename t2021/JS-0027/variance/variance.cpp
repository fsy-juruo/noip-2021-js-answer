#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define F first
#define S second
#define N 10005
#define mod 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
int n,a[N],b[N],c[N],d[N],p[N],l,r;
inline ll calc(ll s){
	ll ans=0;
	for(int i=0;i<n;++i){
		ans+=(s-n*d[i])*(s-n*d[i]);
	}
	return ans/n;
}
inline ll cl(int x){
	ll nls=x*x;
	for(int i=l-1;i;--i){
		x+=c[i];
		nls+=x*x;
	}
	return nls;
}
inline ll cr(int x){
	ll nrs=x*x;
	for(int i=r+1;i<n;++i){
		x+=c[i];
		nrs+=x*x;
	}
	return nrs;
}
void solve1(){
	ll mn=LINF,s=0,ans=0;
	p[1]=n-1;
	do{
		s=0;
		for(int i=1;i<n;++i){
			d[i]=d[i-1]+b[p[i]];
			s+=d[i];
			//printf("%d ",b[i]);
		}//puts("");
		ans=calc(s);
		if(ans<mn) mn=ans;
	}while(next_permutation(p+2,p+n-1));
	printf("%lld\n",mn);
}
int main(){
	
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	for(int i=1;i<n;++i){
		b[i]=a[i+1]-a[i];
		p[i]=i-1;
	}
	sort(b+1,b+n);
	if(n<=10){
		solve1();
		return 0;
	}
	l=1;r=n-1;
	ll nls=0,ls=0,nrs=0,rs=0;
	for(int i=n-1;i;--i){
		nls=cl(b[i]);nrs=cr(b[i]);
		if(nls-ls<nrs-rs){
			ls=nls;c[l++]=b[i];
		}else{
			rs=nrs;c[r--]=b[i];
		}
	}
	//for(int i=1;i<n;++i)printf("%d ",c[i]);puts("");
	ll s=0,ans=0;
	for(int i=1;i<n;++i){
		d[i]=d[i-1]+c[i];
		s+=d[i];
	}
	printf("%lld\n",calc(s));
	return 0;
}
