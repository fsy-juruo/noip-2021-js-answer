#include<bits/stdc++.h>
#define id ((x-1)*m+(y-1))
#define iid ((nx-1)*m+(ny-1))
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
vector<int>a[200010],b[200010];
int vis[400010];
int viss[400010];
int ans,n,m;
struct node{
	int col,lv;
}mp[200010];
int firid;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
const int ddx[4]={-1,0,0,0};
const int ddy[4]={0,0,-1,0};
bool check(int x,int y,int nx,int ny,int zt,int sx,int ii){
	if(nx<1||nx>n||ny<1||ny>m)return false;
	if(zt==1)return false;
	if(ii<2){
		if(b[x+ddx[ii]][y-1]==0)return false;
//		if(x==2&&y==3&&nx==1&&ny==3)cout<<1<<endl;
		if(b[x+ddx[ii]][y-1]==2)return false;
		if(zt==0)return true;
		if(b[x+ddx[ii]][y-1]!=zt)return false;
		if(zt==3)return true;
		if(sx)return false;
		return true;
	}else{
		if(a[x][y+ddy[ii]-1]==0)return false;
		if(a[x][y+ddy[ii]-1]==2)return false;
		if(zt==0)return true;
		if(a[x][y+ddy[ii]-1]!=zt)return false;
		if(zt==3)return true;
		if(sx)return true;
		return false;
	}
}
bool dcheck(int x,int y,int ccol,int llv){
	if(!vis[id])return true;
	if(ccol!=mp[id].col&&llv>=mp[id].lv)return true;
	return false;
}
void dfs(int x,int y,int zt,int sx,int ccol,int llv){
	if(viss[id])return;
	viss[id]=1;
//	cout<<x<<" "<<y<<endl;
	for(int jjj=3;jjj>=0;jjj--){
		int nx=x+dx[jjj];
		int ny=y+dy[jjj];
//		if(x==2&&y==2&&jjj==3)cout<<777<<endl;
//		if(x==2&&y==2)cout<<" "<<nx<<" "<<ny<<endl;
		if(check(x,y,nx,ny,zt,sx,jjj)){
			if(vis[iid]&&iid!=firid){
				if(!dcheck(nx,ny,ccol,llv))return;
			}
			if(jjj<2)dfs(nx,ny,b[x+ddx[jjj]][y-1],0,ccol,llv);
			else dfs(nx,ny,a[x][y+ddy[jjj]-1],1,ccol,llv);
		}
	}
}
void ddfs(int x,int y,int ccol,int llv){
	for(int i=0;i<4;i++){
		int j=0;
		while(1){
			j++;
			int nx=x+j*dx[i];
			int ny=y+j*dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
//				if(x==2&&y==2)cout<<nx<<" "<<ny<<"*"<<endl;
				if(vis[iid]){
					if(dcheck(nx,ny,ccol,llv))viss[iid]=1;
					break;
				}
				if(i==0){
					if(b[x-j][y-1]==2)viss[iid]=1;
					else break;
				}
				if(i==1){
					if(b[x+j-1][y-1]==2)viss[iid]=1;
					else break;
				}
				if(i==2){
					if(a[x][y-j-1]==2)viss[iid]=1;
					else break;
				}
				if(i==3){
					if(a[x][y+j-2]==2)viss[iid]=1;
					else break;
				}
			}else{
				break;
			}
		}
	}
}
void dddfs(int x,int y,int zt,int sx,int ccol,int llv){
	if(viss[id])return;
	viss[id]=1;
//	cout<<x<<" "<<y<<endl;
	for(int jjj=0;jjj<4;jjj++){
		int nx=x+dx[jjj];
		int ny=y+dy[jjj];
//		if(x==2&&y==2&&jjj==3)cout<<777<<endl;
//		if(x==2&&y==2)cout<<" "<<nx<<" "<<ny<<endl;
		if(check(x,y,nx,ny,zt,sx,jjj)){
			if(vis[iid]&&iid!=firid){
				if(!dcheck(nx,ny,ccol,llv))return;
			}
			if(jjj<2)dddfs(nx,ny,b[x+ddx[jjj]][y-1],0,ccol,llv);
			else dddfs(nx,ny,a[x][y+ddy[jjj]-1],1,ccol,llv);
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	read(T);
	while(T--){
		int q;
		read(n);read(m);read(q);
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++){
				char x;
				cin>>x;
				a[i].push_back(x-'0'); 
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++){
				char x;
				cin>>x;
				b[i].push_back(x-'0');
			}
		}
		while(q--){
			memset(viss,0,sizeof(viss));ans=0;
			int col,lv,x,y;
			read(col);read(lv);read(x);read(y);
			vis[id]=1;firid=id;
			node nn;nn.col=col;nn.lv=lv;mp[id]=nn;
			
			dfs(x,y,0,0,col,lv);
			dddfs(x,y,0,0,col,lv);
			ddfs(x,y,col,lv);
			
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
				if(viss[(i-1)*m+j-1]){
					ans++;
//					if(x==2&&y==2)cout<<i<<" "<<j<<endl;
				}	
			}
			cout<<ans-1<<endl;
		}
		for(int i=1;i<=n;i++)a[i].clear(),b[i].clear();
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

