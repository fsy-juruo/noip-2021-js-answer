#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define init(a,i) memset(a,i,sizeof(a))
int n,a[10004];
vector<int>v;
int x,ave,cnt,ans=998244353;
set<vector<int> >s; 
queue<vector<int> >q;
void solve(){
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n)v.push_back(a[i]);
	s.insert(v);
	q.push(v);
	while(!q.empty()){
		v=q.front();
		q.pop();
		forr(i,1,n-2){	
			x=v[i];
			v[i]=v[i-1]+v[i+1]-v[i];
			if(s.lower_bound(v)==s.end()||(*(s.lower_bound(v)))!=v){
				q.push(v);
				s.insert(v);
			}
			v[i]=x;
		} 
	} 
	for(set<vector<int> >::iterator it=s.begin();it!=s.end();it++){
		v=*it;
		ave=0;
		rep(i,n)ave+=v[i];
		cnt=0;
		rep(i,n)cnt+=(v[i]*n-ave)*(v[i]*n-ave);
		ans=min(ans,cnt/n);
	}
	cout<<ans;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){solve();}
	return 0;
}

