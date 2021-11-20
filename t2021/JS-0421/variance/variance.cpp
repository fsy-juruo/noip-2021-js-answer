#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define fore(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define m_p make_pair
using namespace std;
const int N=405;
int n,a[N];
int c[N];
int cc[N],aa[N];
void solve1(){
	int mn=1e9;
	vector<int>v1,v2;
	v1.clear();v2.clear();	
	rep(i,1<<(n-2)){
		v1.clear();v2.clear();
		rep(j,n-2){
			if((i>>j)&1)v1.pb(c[j+2]);
			else v2.pb(c[j+2]);
		}
		int pos=0;
		fore(j,(int)v1.size()-1,0){
			cc[++pos]=v1[j];
		}
		cc[++pos]=c[1];
		rep(j,(int)v2.size()){
			cc[++pos]=v2[j];
		}
		aa[1]=0;
		forn(i,2,n){
			aa[i]=aa[i-1]+cc[i-1];
		}
		int sum=0;
		forn(i,1,n){
			sum+=aa[i];
		}
		int ans=0;
		forn(i,1,n){
			ans+=(aa[i]*n-sum)*(aa[i]*n-sum);
		}
		mn=min(mn,ans);			
	}
	cout<<mn/n<<"\n";
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	forn(i,1,n)cin>>a[i];
	forn(i,1,n-1)c[i]=a[i+1]-a[i];
	sort(c+1,c+n);
	if(n<=20)solve1();
	return 0;
}
