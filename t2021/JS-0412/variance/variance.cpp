#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rp(i,n) for(int i=1;i<=n;i++)
#define forn(i,a,n) for(int i=a;i<n;i++)
#define sz(s) (int)(s.size())
using namespace std;
int n;
int a[101];
void cz(int x){
	a[x]=a[x-1]+a[x+1]-a[x];
}
int ga(){
	int sum=0,ps=0;
	rep(i,n){
		sum+=a[i];
		ps+=a[i]*a[i];
	}
	sum*=sum;
	ps*=n;
	return ps-sum;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	rep(i,n)
	cin>>a[i];
	if(n==3){
		int ans=ga();
		cz(1);
		ans=min(ans,ga());
		cout<<ans;
	}else if(n==4){
		int b[4];
		rep(i,n)
		b[i]=a[i];
		int ans=ga();
		cz(1);
		int now=2;
		while(1){
			bool f=false;
			rep(i,n)
			if(a[i]!=b[i])
			f=true;
			if(!f)
			break;
			ans=min(ga(),ans);
			cz(now);
			now=3-now;
		}
		cz(2);
		now=1;
		while(1){
			bool f=false;
			rep(i,n)
			if(a[i]!=b[i])
			f=true;
			if(!f)
			break;
			ans=min(ga(),ans);
			cz(now);
			now=3-now;
		}
		cout<<ans;
	}
	return 0;
}


