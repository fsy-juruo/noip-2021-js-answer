#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c,d,S;
ll ans=1e9+7;
ll f(int x){
	return 1ll*(n*x-S)*(n*x-S);
}
ll ff(int q,int w,int e,int r){
	return (f(q)+f(w)+f(e)+f(r))/n;
}
int main(){
//	freopen("variance.in","r",stdin);
//	freopen("varience.out","w",stdout);
	scanf("%d",&n);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int b1=a+c-b,b2=a+d-c,
		c1=b+d-c,c2=a-b+d;
	S=a+b+c+d;
	ans=min(ans,ff(a,b,c,d));
	S=a+b1+c+d;
	ans=min(ans,ff(a,b1,c,d));
	S=a+b2+c1+d;
	ans=min(ans,ff(a,b2,c1,d));
	S=a+b+c1+d;
	ans=min(ans,ff(a,b,c1,d));
	S=a+b1+c2+d;
	ans=min(ans,ff(a,b1,c2,d));
	S=a+b2+c2+d;
	ans=min(ans,ff(a,b2,c2,d));
	printf("%lld\n",ans);
	return 0;
}
