#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll const N=1e4+10;
ll n,a[N];
ll t,s,b,ans;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void dfs(ll x,ll tot){
	ans=min(ans,tot);
	if(x>2*n) return;
	for(int i=2;i<n;i++){
		if(a[i-1]+a[i+1]>2*a[i]){
			if((n-1)*(a[i+1]+a[i-1])+2*a[i]<2*s){
				ll	sy=s;
				ll	ty=t;
				ll b=a[i];
		
					t=t-a[i]*a[i]+(a[i+1]+a[i-1]-a[i])*(a[i+1]+a[i-1]-a[i]);
					s=s+a[i+1]+a[i-1]-2*a[i];
							a[i]=a[i+1]+a[i-1]-a[i];
					dfs(x+1,n*t-s*s);
					s=sy;
					t=ty;
					a[i]=b;
			}
		}
		else{
			if(a[i-1]+a[i+1]<2*a[i]){
				if((n-1)*(a[i+1]+a[i-1])+2*a[i]>2*s){
				ll	sy=s;
				ll	ty=t;
				ll b=a[i];
				
					t=t-a[i]*a[i]+(a[i+1]+a[i-1]-a[i])*(a[i+1]+a[i-1]-a[i]);
					s=s+a[i+1]+a[i-1]-2*a[i];
					a[i]=a[i+1]+a[i-1]-a[i];
					dfs(x+1,n*t-s*s);
					s=sy;
					t=ty;
					a[i]=b;
				}
			}
		}
	}
	return;
}
int main(){

freopen("variance.in","r",stdin);
freopen("variance.out","w",stdout);
n=read();
for(int i=1;i<=n;i++) {
	a[i]=read();
	t+=a[i]*a[i];
	s+=a[i];
}
ans=n*t-s*s;
if(n>20) {
	printf("%lld\n",ans);
	return 0;
}
dfs(1,ans);
printf("%lld\n",ans);
return 0;
}

