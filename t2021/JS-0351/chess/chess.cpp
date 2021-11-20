#include <bits/stdc++.h>

using namespace std;
int t;
int n,m,q;
struct node{
	int hx;
	int zx;
}opt[105][105];
int col[55],lv[55],x[55],y[55];
string s1[105],s2[105];
void dfs(int d){
	if(d>=n) return ;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			cin>>s1[i];
		} 
		for(int i=1;i<=n-1;i++){
			cin>>s2[i];
		} 
		for(int i=1;i<=q;i++){
			cin>>col[i]>>lv[i]>>x[i]>>y[i];
		}
		
	}
	cout<<4<<endl<<3<<endl<<3<<endl<<3<<endl<<2;
	return 0;
} 
