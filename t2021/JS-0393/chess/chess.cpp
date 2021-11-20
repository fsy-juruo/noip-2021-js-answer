#include<bits/stdc++.h>
using namespace std;
struct Node{
	int ys,dj;
}; 
Node k[10000+100][10000+100];
string a[10000+100];
string b[10000+100];
long long n,m,q,t;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>t;
	while(t--){
		memset(k,0,sizeof(k));
		cin>>n>>m>>q;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++){
			cin>>b[i];
		}
		int col,iv,x,y;
		for(int i=1;i<=q;i++){
			cin>>col>>iv>>x>>y;
			col++;
			x--;
			y--;
			k[x][y].dj=iv;
			k[x][y].ys=col;
			int ans=0;
			if(a[x-1][y]=='1'){
				if(k[x-1][y].dj>=iv || k[x-1][y].ys==col){
					
				}
				else{
					ans++;
				}
			}
			if(a[x][y]=='1' && x!=n-1){
				if(k[x+1][y].dj>=iv || k[x+1][y].ys==col){
					
				}
				else{
					ans++;
				}
			}
			if(b[x][y-1]=='1'){
				if(k[x][y-1].dj>=iv || k[x][y-1].ys==col){
					
				}
				else{
					ans++;
				}
			}
			if(b[x][y]=='1' && y!=m-1){
				if(k[x][y+1].dj>=iv || k[x][y+1].ys==col){
					
				}
				else{
					ans++;
				}
			}
			cout<<ans<<endl;
		}	
	}
	
	return 0;
}
/*
1
3 3 1
11
11
11
111
111
1 1 2 2
*/
