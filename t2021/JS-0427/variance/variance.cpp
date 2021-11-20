#include<bits/stdc++.h>
using namespace std;
int n;
long long x[100100],va,t,ha;
long long res=1e18;
void gv(){
	va=0,t=0;
	for(int i=1;i<=n;i++) t+=x[i];
	for(int i=1;i<=n;i++) va+=(x[i]*n-t)*(x[i]*n-t);
	va/=n;
}
void hs(){
	ha=0;
	for(int i=1;i<=n;i++) ha=(ha*1003+x[i])%998244353;
}
set<long long> st;
void solve(){
	hs();
	if(st.count(ha)) return;
	st.insert(ha);
	gv();
	res=min(res,va);
	for(int i=2;i<n;i++){
		x[i]=x[i-1]+x[i+1]-x[i];
		solve();
		x[i]=x[i-1]+x[i+1]-x[i];
	}
}
int main(){
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i];
    solve();
    cout<<res<<endl;
    return 0;
}
