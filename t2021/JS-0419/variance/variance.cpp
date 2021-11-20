#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define lc(x) (x<<1)
#define rc(x) ((x<<1)|1)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
#define fr first
#define se second
#define pb push_back()
#define is insert()
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const ll MAXN=1e4+10,INF=1e18;
ll n,a[MAXN],d[MAXN],ans=INF;
ll vis[MAXN],p[MAXN],b[MAXN];
void dfs(int r){
	if(r==n-1){
		b[1]=a[1];
		rep(i,2,n){
			b[i]=b[i-1]+p[i-1];
		}
		ll sum=0,sum2=0;
		rep(i,1,n){
			sum+=b[i];
			sum2+=b[i]*b[i];
		}
		ans=min(ans,n*sum2-sum*sum);
		return;
	}
	rep(i,1,n-1){if(vis[i])continue;
		p[r+1]=d[i];
		vis[i]=1;
		dfs(r+1);
		vis[i]=0;
	}
}
void task1(){
	rep(i,1,n-1)d[i]=a[i+1]-a[i];
	dfs(0);
	cout<<ans<<endl;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	rep(i,1,n){cin>>a[i];}
	if(n<=10){task1();return 0;}
	
	return 0;
}
