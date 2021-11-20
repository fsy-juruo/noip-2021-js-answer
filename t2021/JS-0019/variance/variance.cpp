#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define N 10100
#define Inf 0x3f3f3f3f
using namespace std;

int n, a[N];
int ans;
map<vector<int>, int> vis;

void dfs(vector<int> v){
	if(vis[v]) return;
	vis[v] = true;
	int x = 0, y = 0;
	for(int k : v) x += n*k*k, y += k;
	ans = min(ans, x - y*y);
	rep(i,1,n-2){
		int tmp = v[i];
		v[i] = v[i-1] + v[i+1] - v[i];
		dfs(v), v[i] = tmp;
	}
}

int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	cin>>n;
	int mid = 0;
	rep(i,1,n) cin>>a[i];
	ans = Inf;
	vector<int> v;
	rep(i,1,n) v.push_back(a[i]);
	dfs(v);
	cout<< ans <<endl;
	return 0;
}
/*
4
1 2 4 6
*/
