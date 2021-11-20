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
int n,a[N],p[N],b[N],q[N],l=1,r=n;
ll ls=0,rs=0;
inline ll calc(ll s){
	ll ans=0;
	for(int i=0;i<=n;++i){
		ans+=(s-(n+1)*b[i])*(s-(n+1)*b[i]);
	}
	return ans/(n+1);
}
inline ll cl(int x){
	ll nls=x*x;
	for(int i=l-1;i;--i){
		x+=b[i];
		nls+=x*x;
	}
	return nls;
}
inline ll cr(int x){
	ll nrs=x*x;
	for(int i=r+1;i<=n;++i){
		x+=b[i];
		nrs+=x*x;
	}
	return nrs;
}
int main(){
	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		p[i]=i;
	}
	sort(a+1,a+n+1);
	l=1;r=n;
	ll mn=LINF,s=0,ans=0,nls,nrs;
	for(int i=n;i;--i){
		nls=cl(a[i]);nrs=cr(a[i]);
		printf("%d\n",a[i]);
		printf("%lld %lld %lld %lld\n",nls,ls,nrs,rs);
		if(nls-ls<nrs-rs){
			ls=nls;
			b[l++]=a[i];
		}else{
			rs=nrs;
			b[r--]=a[i];
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",b[i]);puts("");
	return 0;
}
