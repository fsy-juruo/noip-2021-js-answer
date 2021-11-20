#include<bits/stdc++.h>

using namespace std;
const int MAXN=5000+100;
string str;
struct Node{
	int x,y;
}maze[MAXN][MAXN];
struct ja{
	int c,l,k;
}mape[MAXN][MAXN];
int T;
int n,m,q;
int ans=0;
void dfs(int col,int lv,int xx,int yy,int dir,int zt){
	mape[xx][yy].c=col;
	mape[xx][yy].k=q;
	mape[xx][yy].l=lv;
	if(zt==0){
		if(xx-1>=1&&mape[xx-1][yy].k==0&&maze[xx-1][yy].y!=0){
			//cout<<1<<endl;
			ans++;
			dfs(col,lv,xx-1,yy,1,maze[xx-1][yy].y);
		}if(xx-1>=1&&mape[xx-1][yy].k==q&&maze[xx-1][yy].y!=0){
			dfs(col,lv,xx-1,yy,1,maze[xx-1][yy].y);
		}
		if(xx-1>=1&&mape[xx-1][yy].c!=col&&mape[xx-1][yy].l<=lv&&maze[xx-1][yy].y!=0){
			ans++;
		}
		if(yy+1<=m&&mape[xx][yy+1].k==0&&maze[xx][yy].x!=0){
			//cout<<2<<endl;
			ans++;
			dfs(col,lv,xx,yy+1,2,maze[xx][yy].x);	
		}if(yy+1<=m&&mape[xx][yy+1].k==q&&maze[xx][yy].x!=0){
			dfs(col,lv,xx,yy+1,2,maze[xx][yy].x);
		}
		if(yy+1<=m&&mape[xx][yy+1].c!=col&&mape[xx][yy+1].l<=lv&&maze[xx][yy].x!=0){
			ans++;
		}
		if(xx+1<=n&&mape[xx+1][yy].k==0&&maze[xx][yy].y!=0){
			//cout<<3<<endl;
			ans++;
			dfs(col,lv,xx+1,yy,3,maze[xx][yy].y);
			
		}
		if(xx+1<=n&&mape[xx+1][yy].k==q&&maze[xx][yy].y!=0){
			dfs(col,lv,xx+1,yy,3,maze[xx][yy].y);
		}	
		if(xx+1<=n&&mape[xx+1][yy].c!=col&&mape[xx+1][yy].l<=lv&&maze[xx][yy].y!=0){
			ans++;
		}
		if(yy-1>=1&&mape[xx][yy-1].k==0&&maze[xx][yy-1].x!=0){
			//cout<<4<<endl;
			ans++;
			dfs(col,lv,xx,yy-1,4,maze[xx][yy-1].x);
		}if(yy-1>=1&&mape[xx][yy-1].k==q&&maze[xx][yy-1].x!=0){
			dfs(col,lv,xx,yy-1,4,maze[xx][yy-1].x);
		}
		if(yy-1>=1&&mape[xx][yy-1].c!=col&&mape[xx][yy-1].l<=lv&&maze[xx][yy-1].x!=0){
			ans++;
		}
		return;
	} 
	else if(zt==2){
		if(dir==1){
			if(xx-1>=1&&maze[xx-1][yy].y==2){
				if(mape[xx-1][yy].k==0){
					ans++;
					dfs(col,lv,xx-1,yy,1,2);
				}
				if(mape[xx-1][yy].k==q){
					dfs(col,lv,xx-1,yy,1,maze[xx-1][yy].y);
				}
				else if(mape[xx-1][yy].c!=col&&mape[xx-1][yy].l<=lv){
					ans++;
				}
			}
		}
		if(dir==3){
			if(xx+1<=n&&maze[xx][yy].y==2){
				if(mape[xx+1][yy].k==0){
					ans++;
					dfs(col,lv,xx+1,yy,3,2);
				}
				if(mape[xx+1][yy].k==q){
					dfs(col,lv,xx-1,yy,3,maze[xx-1][yy].y);
				}
				else if(mape[xx+1][yy].c!=col&&mape[xx+1][yy].l<=lv){
					ans++;
				}
			}
		}
		if(dir==2){
			if(yy+1<=m&&maze[xx][yy].x==2){
				if(mape[xx][yy+1].k==0){
					ans++;
					dfs(col,lv,xx,yy+1,2,2);
				}
				if(mape[xx][yy+1].k==q){
					dfs(col,lv,xx,yy+1,2,2);
				}
				else if(mape[xx-1][yy].c!=col&&mape[xx-1][yy].l<=lv){
					ans++;
				}
			}
		}
		if(dir==4){
			if(yy-1>=1&&maze[xx][yy-1].y==2){
				if(mape[xx][yy-1].k==0){
					ans++;
					dfs(col,lv,xx,yy-1,4,2);
				}
				if(mape[xx][yy-1].k==q){
					dfs(col,lv,xx,yy-1,4,2);
				}
				else if(mape[xx][yy-1].c!=col&&mape[xx][yy-1].l<=lv){
					ans++;
				}
			}	
		}
		return;
	}
	else if(zt==1){
		return;
	}
	else{
		if(xx-1>=1&&mape[xx-1][yy].k==0&&maze[xx-1][yy].y==3){
			//cout<<1<<endl;
			ans++;
			dfs(col,lv,xx-1,yy,1,maze[xx-1][yy].y);
		}if(xx-1>=1&&mape[xx-1][yy].k==q&&maze[xx-1][yy].y==3){
			dfs(col,lv,xx-1,yy,1,maze[xx-1][yy].y);
		}
		if(xx-1>=1&&mape[xx-1][yy].c!=col&&mape[xx-1][yy].l<=lv&&maze[xx-1][yy].y==3){
			ans++;
		}
		if(yy+1<=m&&mape[xx][yy+1].k==0&&maze[xx][yy].x==3){
			//cout<<2<<endl;
			ans++;
			dfs(col,lv,xx,yy+1,2,maze[xx][yy].x);	
		}if(yy+1<=m&&mape[xx][yy+1].k==q&&maze[xx][yy].x==3){
			dfs(col,lv,xx-1,yy,2,maze[xx-1][yy].y);
		}
		if(yy+1<=m&&mape[xx][yy+1].c!=col&&mape[xx][yy+1].l<=lv&&maze[xx][yy].x==3){
			ans++;
		}
		if(xx+1<=n&&mape[xx+1][yy].k==0&&maze[xx][yy].y==3){
			//cout<<3<<endl;
			ans++;
			dfs(col,lv,xx+1,yy,3,maze[xx][yy].y);
			
		}
		if(xx+1<=n&&mape[xx+1][yy].k==q&&maze[xx][yy].y==3){
			dfs(col,lv,xx-1,yy,3,maze[xx-1][yy].y);
		}	
		if(xx+1<=n&&mape[xx+1][yy].c!=col&&mape[xx+1][yy].l<=lv&&maze[xx][yy].y==3){
			ans++;
		}
		if(yy-1>=1&&mape[xx][yy-1].k==0&&maze[xx][yy-1].x==3){
			//cout<<4<<endl;
			ans++;
			dfs(col,lv,xx,yy-1,4,maze[xx][yy-1].x);
		}
		if(yy-1>=1&&mape[xx][yy-1].k==q&&maze[xx][yy-1].x==3){
			dfs(col,lv,xx-1,yy,4,maze[xx-1][yy].y);
		}
		if(yy-1>=1&&mape[xx][yy-1].c!=col&&mape[xx][yy-1].l<=lv&&maze[xx][yy-1].x==3){
			ans++;
		}
		return;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--){
		memset(mape,0,sizeof(mape));
		memset(maze,0,sizeof(maze));
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			cin>>str;
			for(int j=0;j<=m-2;j++){
				
				maze[i][j+1].x=str[j]-'0';
			}
		}
		for(int i=1;i<=n-1;i++){
			cin>>str;
			for(int j=0;j<=m-1;j++){
				maze[i][j+1].y=str[j]-'0';
			}
		}
		while(q--){
			int col,lv,xx,yy;
			ans=0;
			cin>>col>>lv>>xx>>yy;
			dfs(col,lv,xx,yy,-1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
