#include<bits/stdc++.h>
using namespace std;
map<vector<int>,bool>m;
vector<int>v;
//bool vis[100005];
int n,c=0;
int ans=10000000;
void dfs(vector<int>v){
//	c++;
//	cout<<c<<endl;
	if(m[v])
	return;
	m[v]=1;
//	for(int i=0;i<v.size();i++)
//	cout<<v[i]<<" ";
//	cout<<endl;
	
	int sum=0,cnt=0;
	for(int i=0;i<v.size();i++){
		sum+=v[i];
	}
	for(int i=0;i<v.size();i++){
		cnt+=(sum-n*v[i])*(sum-n*v[i]);
	}
	cnt/=n;
//	cout<<cnt<<endl;
	ans=min(cnt,ans);
	
	
	for(int i=1;i<v.size()-1;i++){
		v[i]=v[i-1]+v[i+1]-v[i];
		dfs(v);
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	dfs(v);
	cout<<ans;
}
