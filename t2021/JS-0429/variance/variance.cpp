#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define re return
#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a.size()))
#define rept(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) rept(i,0,a)
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100000
#define MOD 998244353
int a[5];
int n;
int chk(){
	int s1=0,s2=0;
	rep(i,n)s1+=a[i]*a[i],s2+=a[i];
	re s1*n-s2*s2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	rep(i,n)cin>>a[i];
	if(n<=2){
		cout<<chk();
		re 0;
	}
	int ans=1000000000000000ll;
	rep(i,100){
		int j=i%(n-2)+1;
		a[j]=a[j-1]+a[j+1]-a[j];
		ans=min(ans,chk());
	}
	cout<<ans<<"\n";
	re 0;
}

