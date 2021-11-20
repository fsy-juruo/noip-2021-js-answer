#include<bits/stdc++.h>
using namespace std;
struct Node{
	int c,l;
}f[5010][5010];
bool vis1[5010][5010],vis2[5010][5010];
int ans,T,n,m,q;
int h[5010][5010],s[5010][5010];
void dfs(int x,int y,int d,int t,int c,int l){
	if(t==0)return ;
	Node p=f[x][y];
	if(p.c!=-1){
		if(p.c==c||(p.c!=c&&p.l>l))return ;
		if(vis1[x][y]){
			ans++;
			vis1[x][y]=false;
		}
		return ;
	}else{
		if(t==3)vis2[x][y]=false;
		if(vis1[x][y]){
			ans++;
			vis1[x][y]=false;
		}
		if(t==1)return ;
		if(t==2){
			if(d==1){
				if(x>1&&s[x-1][y]==2)dfs(x-1,y,1,2,c,l);
			}
			if(d==2){
				if(y>1&&h[x][y-1]==2)dfs(x,y-1,2,2,c,l);
			}
			if(d==3){
				if(x<n&&s[x][y]==2)dfs(x+1,y,3,2,c,l);
			}
			if(d==4){
				if(y<m&&h[x][y]==2)dfs(x,y+1,4,2,c,l);
			}
		}
		if(t==3){
			if(x>1&&vis2[x-1][y]&&s[x-1][y]==3)dfs(x-1,y,1,3,c,l);
			if(y>1&&vis2[x][y-1]&&h[x][y-1]==3)dfs(x,y-1,2,3,c,l);
			if(x<n&&vis2[x+1][y]&&s[x][y]==3)dfs(x+1,y,3,3,c,l);
			if(y<m&&vis2[x][y+1]&&h[x][y]==3)dfs(x,y+1,4,3,c,l);
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=(Node){-1,-1};
			}
		}
		for(int i=1;i<=n;i++){
			string st;
			cin>>st;
			for(int j=0;st[j];j++){
				h[i][j+1]=st[j]-'0';
			}
		}
		for(int i=1;i<=n-1;i++){
			string st;
			cin>>st;
			for(int j=0;st[j];j++){
				s[i][j+1]=st[j]-'0';
			}
		}
		for(int i=1;i<=q;i++){
			int c,l,x,y;
			cin>>c>>l>>x>>y;
			f[x][y]=(Node){c,l};
			memset(vis1,true,sizeof(vis1));
			memset(vis2,true,sizeof(vis2));
			vis1[x][y]=false;
			vis2[x][y]=false;
			ans=0;
			if(x>1)dfs(x-1,y,1,s[x-1][y],c,l);
			if(y>1)dfs(x,y-1,2,h[x][y-1],c,l);
			if(x<n)dfs(x+1,y,3,s[x][y],c,l);
			if(y<m)dfs(x,y+1,4,h[x][y],c,l);
			cout<<ans<<endl;
		}
	}
	return 0;
}

