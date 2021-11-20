#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-9;
typedef long long ll;
//remember to use int64_t
int n,a[10005],b[10005];
ll eval(ll x,ll y){
	return (1ll*x*n-y)*(1ll*x*n-y);
}
int get_id(int val,int pos){
	return val*n+pos-1;
}
void upd(ll &x,ll y){
	if(x>y)x=y;
}
ll pre[6060],id[405][605];
ll dp[6060][405];
ll solve(int x){
	for(int i=0;i<=a[n];i++)for(int j=0;j<=n;j++)id[i][j]=get_id(i,j);
	memset(dp,inf,sizeof dp);const ll cmp=dp[0][0];
	dp[get_id(a[1],1)][n]=eval(a[1],x)+eval(a[n],x);
	for(int lval=1;lval<=a[n];lval++){
		for(int l=1;l<=n;l++){
			for(int r=n;r>l;r--){
				int dif=a[n]-a[1]-pre[n-r+l-1];
				int rval=lval+dif;
				if(dp[id[lval][l]][r]<cmp){
					int cur=l+(n-r);
					upd(dp[id[lval+b[cur]][l+1]][r],dp[id[lval][l]][r]+eval(lval+b[cur],x));
					upd(dp[id[lval][l]][r-1],dp[id[lval][l]][r]+eval(rval-b[cur],x));
				}
			}
		}
	}
	ll ret=(ll)1e18;
	for(int i=1;i<n;i++){
		for(int lval=1;lval<=a[n];lval++){
			for(int rval=lval;rval<=a[n];rval++)ret=min(ret,dp[id[lval][i]][i+1]);
		}
	}
//	cerr<<x<<" "<<ret<<endl;
	return ret/n;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	sort(b+1,b+n);reverse(b+1,b+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+b[i];
	int l=0,r=n*a[n]+1;
	while(r-l>1){
//		cerr<<l<<" "<<r<<endl;
		int mid=(l+r)/2;
		if(solve(mid)<solve(mid+1))r=mid;
		else l=mid; 
	}
	int L=l,R=r;
	ll ans=min(solve(L),solve(R));
//	for(int _=0;_<100;_++){
	while(1.0*clock()/CLOCKS_PER_SEC<0.92){
		if(L>0)L--;if(R<n*a[n])R++;
		ans=min(ans,solve(L));
		ans=min(ans,solve(R));
	}
	cout<<ans<<endl;
	return 0;
}
