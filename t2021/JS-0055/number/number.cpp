/*
dog pear fruit fake win like ant
seven eagle fire bat pen take juice
*/
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const int mxn=1e7+777;
int hv[mxn];
int bad[mxn];
int lst[mxn];
inline void calc(){
	for(int i=1;i<mxn;++i)if(i%10==7 or hv[i/10])hv[i]=1;
	for(int i=1;i<mxn;++i){
		if(!hv[i] or bad[i])continue;
		for(int j=i;j<mxn;j+=i)bad[j]=1;
	}
	for(int i=mxn-3;~i;--i){
		if(!bad[i+1])lst[i]=i+1;
		else lst[i]=lst[i+1];
	}
}
inline void solve(){
	int x;cin>>x;
	if(bad[x])cout<<-1<<'\n';
	else cout<<lst[x]<<'\n';
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	calc();
	int T;cin>>T;
	for(;T--;)solve();
	return 0;
}
