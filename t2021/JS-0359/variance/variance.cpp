#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
#define FIO "variance"
#define ll long long
ll a[10005];
ll d[10001];
ll f[1000][1000];
vector<ll>s;
ll z0(){
	ll cnt=0;
	int m=s.size()-1;
	for(int i=1;i<=m;i++){
		f[i][i]=s[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++) f[i][j]=f[i][j-1]+s[j];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			ll x=f[i][j]*f[i][j];
			cnt+=x;
		}
	}
	return cnt;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen(FIO".in","r",stdin);
	freopen(FIO".out","w",stdout);
	int n;
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		d[i-1]=a[i]-a[i-1];
	}
	sort(d+1,d+n,cmp);
	s.push_back(0);
	s.push_back(d[1]);
	s.push_back(d[2]);
	s[0]=1;
	for(int i=3;i<n;i++){
		s.insert(s.begin()+s[0],d[i]);
		ll lx=z0();s.erase(s.begin()+s[0]);
		s.insert(s.begin()+s[0]+1,d[i]);
		ll rx=z0();s.erase(s.begin()+s[0]+1);
		if(lx<=rx){
			s.insert(s.begin()+s[0],d[i]);
		}
		else{
			s.insert(s.begin()+s[0]+1,d[i]);s[0]++;
		}
	}
	n--;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		f[i][i]=s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) f[i][j]=f[i][j-1]+s[j];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ll x=f[i][j]*f[i][j];
			cnt+=x;
		}
	}
	cout<<cnt;
	return 0;
}

