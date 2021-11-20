#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
   ll x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
const ll INF = 1e7;
bool f[INF+4];
bool check(ll x){
	while(x){
		if (x%10==7)return false;
		x/=10;
	}
	return true;
}
ll a[214514];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(f,true,sizeof(f));
	ll T=read(),maxa=0;
	for (ll i=1;i<=T;++i){
		a[i]=read();
		maxa=max(maxa,a[i]);
	}
	maxa=min(maxa,INF+3);
	for (ll i=1;i<=maxa;++i){
		if (f[i]==true){
			if (!check(i)){
				f[i]=false;
				for (ll j=2;j<=maxa/i;++j){
					if (i*j>maxa)break;
					f[i*j]=false;
				}
			}
		}
	}
	for (ll i=1;i<=T;++i){
		ll x=a[i];
		if (f[x]==false)printf("-1\n");
		else {
			++x;
			while(f[x]==false)++x;
			printf("%lld\n",x);
		}
	}
	return 0;
}

