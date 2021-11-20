#include<bits/stdc++.h>
using namespace std;
long longT,n,m,q,qz,ans,T;
int heng[2001][2001],shu[2001][2001],col[10001],lv[10001],x[10001],y[10001],a[2001][2001],vis[2001][2001],viss[2001][2001];
void dfs(int xx,int yy,int opt,int fx,int fy){
	if(vis[xx][yy]==0)ans++;
	if(opt==1)return;
	if(opt==2){
		int in=1;
		while(a[xx+fx*in][yy+fy*in]==0){
			ans++;
			in++;
		}
		if(col[a[xx+fx*in][yy+fy*in]]!=col[qz]&&lv[qz]>=lv[a[xx+fx*in][yy+fy*in]]){
			ans++;
		}
		return;
	}
	vis[xx][yy]=1;
	viss[xx][yy]=1;
	if(a[xx][yy+1]!=0&&col[a[xx][yy+1]]!=col[qz]&&lv[qz]>=lv[a[xx][yy+1]]&&heng[xx][yy]==3&&vis[xx][yy+1]==0){
		ans++;
		vis[xx][yy+1]=1;
	}
	if(a[xx][yy-1]!=0&&col[a[xx][yy-1]]!=col[qz]&&lv[qz]>=lv[a[xx][yy-1]]&&heng[xx][yy-1]==3&&vis[xx][yy-1]==0){
		ans++;
		vis[xx][yy-1]=1;
	}
	if(a[xx+1][yy]!=0&&col[a[xx+1][yy]]!=col[qz]&&lv[qz]>=lv[a[xx+1][yy]]&&shu[xx][yy]==3&&vis[xx+1][yy]==0){
		ans++;
		vis[xx+1][yy]=1;
	}
	if(a[xx-1][yy]!=0&&col[a[xx-1][yy]]!=col[qz]&&lv[qz]>=lv[a[xx-1][yy]]&&shu[xx][yy]==3&&vis[xx-1][yy]==0){
		ans++;
		vis[xx-1][yy]=1;
	}
	if(a[xx][yy+1]==0&&heng[xx][yy]==3&&viss[xx][yy+1]==0){
		dfs(xx,yy+1,3,0,0);
	}
	if(a[xx][yy-1]==0&&heng[xx][yy-1]==3&&viss[xx][yy-1]==0){
		dfs(xx,yy-1,3,0,0);
	}
	if(a[xx+1][yy]==0&&shu[xx][yy]==3&&viss[xx+1][yy]==0){
		dfs(xx+1,yy,3,0,0);
	}
	if(a[xx-1][yy]==0&&shu[xx-1][yy]==3&&viss[xx-1][yy]==0){
		dfs(xx-1,yy,3,0,0);
	}
	viss[xx][yy]=0;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	for(int qwe=1;qwe<=T;qwe++){
			cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				cin>>heng[i][j];
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=m;j++){
				cin>>shu[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>col[i]>>lv[i]>>x[i]>>y[i];
			a[x[i]][y[i]]=i;
			qz=i;
			ans=0;
			if(a[x[i]][y[i]+1]!=0&&col[a[x[i]][y[i]+1]]!=col[i]&&lv[i]>=lv[a[x[i]][y[i]+1]]&&heng[x[i]][y[i]]!=0){
				ans++;
				vis[x[i]][y[i]+1]=1;
			}
			if(a[x[i]+1][y[i]]!=0&&col[a[x[i]+1][y[i]]]!=col[i]&&lv[i]>=lv[a[x[i]+1][y[i]]]&&shu[x[i]][y[i]]!=0){
				ans++;
				vis[x[i]+1][y[i]]=1;
			}
			if(a[x[i]][y[i]-1]!=0&&col[a[x[i]][y[i]-1]]!=col[i]&&lv[i]>=lv[a[x[i]][y[i]-1]]&&heng[x[i]][y[i]-1]!=0){
				ans++;
				vis[x[i]][y[i]-1]=1;
			}
			if(a[x[i]-1][y[i]]!=0&&col[a[x[i]-1][y[i]]]!=col[i]&&lv[i]>=lv[a[x[i]-1][y[i]]]&&shu[x[i]-1][y[i]]!=0){
				ans++;
				vis[x[i]-1][y[i]]=1;
			}
			if(a[x[i]][y[i]+1]==0){
				dfs(x[i],y[i]+1,heng[x[i]][y[i]],0,1);
			}
			if(a[x[i]+1][y[i]]==0){
				dfs(x[i]+1,y[i],shu[x[i]][y[i]],1,0);
			}
			if(a[x[i]][y[i]-1]==0){
				dfs(x[i],y[i]-1,heng[x[i]][y[i]-1],0,-1);
			}
			if(a[x[i]-1][y[i]]==0){
				dfs(x[i]-1,y[i],shu[x[i]-1][y[i]],-1,0);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
