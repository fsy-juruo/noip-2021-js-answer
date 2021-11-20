#include<bits/stdc++.h>
using namespace std;
#define MAXN 500500
int n;
int a[10010],ans=MAXN;
map<string,int> mp;
string turn(){
	string s="";
	for(int i=1;i<=n;i++){
		int x=a[i];
		while(x){
			s+=x%10+'0';
			x/=10;
		}
	}
//	cout<<s<<'\n';
	return s;
}
int V(){
	int sum=0,sum2=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		sum2+=a[i]*a[i];
	}
	return n*sum2-sum*sum;
/*
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		res+=(a[i]*n-sum)*(a[i]*n-sum);
	}
*/	
}
void dfs(int x){
	if(a[x-1]+a[x+1]==2*a[x]){
		return;
	}
	int res=0;
	a[x]=a[x-1]+a[x+1]-a[x];
	string s=turn();
	if(mp[s]){
		return;
	}
	res=V();
	mp[s]=res;
	ans=min(ans,res);
	for(int i=2;i<n;i++){
		if(i!=x)
			dfs(i);
	}
	a[x]=a[x-1]+a[x+1]-a[x];
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	int tot=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot+=a[i];
	}
	ans=V();
	mp[turn()]++;
	for(int i=2;i<n;i++){
		dfs(i);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99
*/
