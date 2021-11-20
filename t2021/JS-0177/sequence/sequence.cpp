#include <bits/stdc++.h>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const long long MOD = 998244353;
long long a[111],f[111][111],ans,ANS;
int fod[111],mk[111]
;int i,j,n,m,k,ad,trn,nw,bnd;
long long mth(int a,int b){
	int i;
	long long ans=1;
	rep(i,a-b+1,a) ans*=i;
	rep(i,2,b) ans/=i;
	return ans;
}
void dfsnxt(int dep,int lst){
	int i;
	if (dep==nw){
		fod[dep]=lst;
		ANS=1;
		rep(i,1,nw)
			ANS=(ANS*f[mk[i]][fod[i]])%MOD;
		ans=(ans+ANS)%MOD;
		return;
	}
	rep(i,1,lst-nw+dep){
		fod[dep]=i;
		dfsnxt(dep+1,lst-i);
	}
	return;
}
void dfs(int dep,int pre){
	int i;
	if (dep>nw){
		dfsnxt(1,n);
		return;
	}
	rep(i,pre,m+ad-nw+dep){
		mk[dep]=i;
		dfs(dep+1,i+1);
	}
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,0,m) cin>>a[i];
	f[0][1]=a[0];
	rep(i,1,m){
		bnd=max(n,1<<i);
		f[i][1]=a[i];
		rep(j,2,bnd)
			rep(trn,1,j-1)
				f[i][j]=(f[i][j]+f[i-1][trn]*f[i-1][j-trn])%MOD;
	}
	ad=1;
	while (ad<=n) ad=ad<<1;
	ad--;
	rep(i,1,ad)
		rep(j,1<<i,n)
			rep(trn,1,j-1)
				f[m+i][j]=(f[m+i][j]+f[m+i-1][trn]*f[m+i-1][j-trn])%MOD;
	rep(nw,1,k)
		dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
