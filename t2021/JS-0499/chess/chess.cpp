#include<bits/stdc++.h>
using namespace std;
vector<int>c[200005],v[200005],vis[200005],pl[200005];
int ans,n,m,Q;
int lv[100005],col[100005];
queue<pair<int,int> >q;
void bfs(int x,int y,int kkk){
	while(!q.empty())q.pop();
	q.push(make_pair(x,y));
	vis[x][y]=1;
//	printf("START %d\n",kkk);
	//type 3
	while(!q.empty()){
		pair<int,int>f=q.front();q.pop();
		int nx=f.first;
		int ny=f.second;
		if(nx-1>=1 && v[nx-1][ny]==3 && vis[nx-1][ny]==0){
			if(pl[nx-1][ny]==0){
				vis[nx-1][ny]=1;
				ans++;
				q.push(make_pair(nx-1,ny));
			}
			else if(col[kkk]!=col[pl[nx-1][ny]] && lv[kkk]>=lv[pl[nx-1][ny]]){
				vis[nx-1][ny]=1;
				ans++;
			}
		}
		if(nx+1<=n && v[nx][ny]==3 && vis[nx+1][ny]==0){
			if(pl[nx+1][ny]==0){
				vis[nx+1][ny]=1;
				ans++;
				q.push(make_pair(nx+1,ny));
			}
			else if(col[kkk]!=col[pl[nx+1][ny]] && lv[kkk]>=lv[pl[nx+1][ny]]){
				vis[nx+1][ny]=1;
				ans++;
			}
		}
		if(ny-1>=1 && c[nx][ny-1]==3 && vis[nx][ny-1]==0){
			if(pl[nx][ny-1]==0){
				vis[nx][ny-1]=1;
				ans++;
				q.push(make_pair(nx,ny-1));
			}
			else if(col[kkk]!=col[pl[nx][ny-1]] && lv[kkk]>=lv[pl[nx][ny-1]]){
				vis[nx][ny-1]=1;
				ans++;
			}
		}
		if(ny+1<=m && c[nx][ny]==3 && vis[nx][ny+1]==0){
			if(pl[nx][ny+1]==0){
				vis[nx][ny+1]=1;
				ans++;
				q.push(make_pair(nx,ny+1));
			}
			else if(col[kkk]!=col[pl[nx][ny+1]] && lv[kkk]>=lv[pl[nx][ny+1]]){
				vis[nx][ny+1]=1;
				ans++;
			}
		}
	}
//	printf("TYPE 3\n");
	//type 2
	for(int nx=x-1;nx>=1;nx--){
		if(v[nx][y]!=2)break;
		if(pl[nx][y]!=0 && col[kkk]!=col[pl[nx][y]] && lv[kkk]>=lv[pl[nx][y]] && vis[nx][y]==0){
			vis[nx][y]=1;
			ans++;
			break;
		}
		if(pl[nx][y]==0 && vis[nx][y]==0){
			vis[nx][y]=1;
			ans++;
		}
	}
	for(int nx=x+1;nx<=n;nx++){
		if(v[nx-1][y]!=2)break;
		if(pl[nx][y]!=0 && col[kkk]!=col[pl[nx][y]] && lv[kkk]>=lv[pl[nx][y]] && vis[nx][y]==0){
			vis[nx][y]=1;
			ans++;
			break;
		}
		if(pl[nx][y]==0 && vis[nx][y]==0){
			vis[nx][y]=1;
			ans++;
		}
	}
	for(int ny=y-1;ny>=1;ny--){
		if(c[x][ny]!=2)break;
		if(pl[x][ny]!=0 && col[kkk]!=col[pl[x][ny]] && lv[kkk]>=lv[pl[x][ny]] && vis[x][ny]==0){
			vis[x][ny]=1;
			ans++;
			break;
		}
		if(pl[x][ny]==0 && vis[x][ny]==0){
			vis[x][ny]=1;
			ans++;
		}
	}
	for(int ny=y+1;ny<=m;ny++){
		if(c[x][ny-1]!=2)break;
		if(pl[x][ny]!=0 && col[kkk]!=col[pl[x][ny]] && lv[kkk]>=lv[pl[x][ny]] && vis[x][ny]==0){
			vis[x][ny]=1;
			ans++;
			break;
		}
		if(pl[x][ny]==0 && vis[x][ny]==0){
			vis[x][ny]=1;
			ans++;
		}
	}
//	printf("TYPE 2\n");
	//type 1
	if(x-1>=1 && ((pl[x-1][y]!=0 && col[kkk]!=col[pl[x-1][y]] && lv[kkk]>=lv[pl[x-1][y]]) || pl[x-1][y]==0) && v[x-1][y]==1 && vis[x-1][y]==0){
		vis[x-1][y]=1;
		ans++;
	}
	if(x+1<=n && ((pl[x+1][y]!=0 && col[kkk]!=col[pl[x+1][y]] && lv[kkk]>=lv[pl[x+1][y]]) || pl[x+1][y]==0) && v[x][y]==1 && vis[x+1][y]==0){
		vis[x+1][y]=1;
		ans++;
	}
	if(y-1>=1 && ((pl[x][y-1]!=0 && col[kkk]!=col[pl[x][y-1]] && lv[kkk]>=lv[pl[x][y-1]]) || pl[x][y-1]==0) && c[x][y-1]==1 && vis[x][y-1]==0){
		vis[x][y-1]=1;
		ans++;
	}
	if(y+1<=m && ((pl[x][y+1]!=0 && col[kkk]!=col[pl[x][y+1]] && lv[kkk]>=lv[pl[x][y+1]]) || pl[x][y+1]==0) && c[x][y]==1 && vis[x][y+1]==0){
		vis[x][y+1]=1;
		ans++;
	}
//	printf("TYPE 1\n");
}
void only1_bfs(int x,int y,int kkk){
	//type 1
	if(x-1>=1 && ((pl[x-1][y]!=0 && col[kkk]!=col[pl[x-1][y]] && lv[kkk]>=lv[pl[x-1][y]]) || pl[x-1][y]==0) && v[x-1][y]==1 && vis[x-1][y]==0){
		vis[x-1][y]=1;
		ans++;
	}
	if(x+1<=n && ((pl[x+1][y]!=0 && col[kkk]!=col[pl[x+1][y]] && lv[kkk]>=lv[pl[x+1][y]]) || pl[x+1][y]==0) && v[x][y]==1 && vis[x+1][y]==0){
		vis[x+1][y]=1;
		ans++;
	}
	if(y-1>=1 && ((pl[x][y-1]!=0 && col[kkk]!=col[pl[x][y-1]] && lv[kkk]>=lv[pl[x][y-1]]) || pl[x][y-1]==0) && c[x][y-1]==1 && vis[x][y-1]==0){
		vis[x][y-1]=1;
		ans++;
	}
	if(y+1<=m && ((pl[x][y+1]!=0 && col[kkk]!=col[pl[x][y+1]] && lv[kkk]>=lv[pl[x][y+1]]) || pl[x][y+1]==0) && c[x][y]==1 && vis[x][y+1]==0){
		vis[x][y+1]=1;
		ans++;
	}
//	printf("TYPE 1\n");
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&Q);
		for(int i=1;i<=n;i++)c[i].resize(m);
		for(int i=1;i<=n;i++)v[i].resize(m+1);
		for(int i=1;i<=n;i++)vis[i].resize(m+1);
		for(int i=1;i<=n;i++){
			pl[i].resize(m+1);
			for(int j=1;j<=m;j++)pl[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			int cnt=0;
			while(cnt<m-1){
				char ch=getchar();
				if(ch>='0' && ch<='3')c[i][++cnt]=ch-'0';
			}
		}
		for(int i=1;i<n;i++){
			int cnt=0;
			while(cnt<m){
				char ch=getchar();
				if(ch>='0' && ch<='3')v[i][++cnt]=ch-'0';
			}
		}
		for(int kkk=1;kkk<=Q;kkk++){
			int x,y;
			scanf("%d%d%d%d",&col[kkk],&lv[kkk],&x,&y);
			pl[x][y]=kkk;
//			printf("INPUT %d\n",kkk);
			ans=0;
			if(n*m<=5000){
				for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)vis[i][j]=0;
//				printf("INIT\n");
				bfs(x,y,kkk);
				printf("%d\n",ans);
			}
			else{
				only1_bfs(x,y,kkk);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
