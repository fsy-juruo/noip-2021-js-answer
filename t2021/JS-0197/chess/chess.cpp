#include <bits/stdc++.h>
using namespace std;
template<typename TT>void read(TT &x){
	x=0;int f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	x*=f;
}

int n,m,q;
pair<int,int> G[5100][5100];
char heng[5100][5100],shu[5100][5100];
bool vis[5100][5100],ga[5100][5100];
queue<pair<int,int> > que;
void init(){
	read(n);read(m);read(q);
//	char heng[n+5][m+5],shu[n+5][m+5];
//	pair<int,int> G[n+5][m+5];
	for(int i=0;i<n+5;i++)
	for(int j=0;j<m+5;j++)G[i][j]=make_pair(-1,0);
	for(int i=1;i<=n;i++)scanf("%s",shu[i]+1);
	for(int i=1;i<n;i++)scanf("%s",heng[i]+1);
	while(q--){
		for(int i=1;i<=n+3;i++)
		for(int j=1;j<=m+3;j++)ga[i][j]=0;
		int col,lv,x,y,ans=0;
		read(col);read(lv);read(x);read(y);
		if(shu[x][y]=='1'&&G[x][y+1].first!=col&&G[x][y+1].second<=lv)ans++,ga[x][y+1]=1;
		if(shu[x][y-1]=='1'&&G[x][y-1].first!=col&&G[x][y-1].second<=lv)ans++,ga[x][y-1]=1;
		if(heng[x][y]=='1'&&G[x+1][y].first!=col&&G[x+1][y].second<=lv)ans++,ga[x+1][y]=1;
		if(heng[x-1][y]=='1'&&G[x-1][y].first!=col&&G[x-1][y].second<=lv)ans++,ga[x-1][y]=1;
		
		int i,j;
		for(j=y+1;j<=m;j++){
			if(shu[x][j-1]=='2'&&G[x][j].first==-1)ans++,ga[x][j]=1;
			else break;
		}
		if(j!=y+1)j--;
		j++;
		if(shu[x][j-1]=='2'&&j<=m&&G[x][j].first!=col&&G[x][j].second<=lv)ans++,ga[x][j]=1;
		for(j=y-1;j>=1;j--){
			if(shu[x][j]=='2'&&G[x][j].first==-1)ans++,ga[x][j]=1;
			else break;
		}
		if(j!=y-1)j--;
		if(shu[x][j]=='2'&&j>=1&&G[x][j].first!=col&&G[x][j].second<=lv)ans++,ga[x][j]=1;
		
		
		for(i=x+1;i<=n;i++){
			if(heng[i-1][y]=='2'&&G[i][y].first==-1)ans++,ga[i][y]=1;
			else break;
		}
		if(i!=x+1)i++;
		if(heng[i-1][y]=='2'&&i<=n&&G[i][y].first!=col&&G[i][y].second<=lv)ans++,ga[i][y]=1;
		for(i=x-1;i>=1;i--){
			if(heng[i][y]=='2'&&G[i][y].first==-1)ans++,ga[i][y]=1;
			else break;
		}
		if(i!=x-1)i--;
		if(heng[i][y]=='2'&&i>=1&&G[i][y].first!=col&&G[i][y].second<=lv)ans++,ga[i][y]=1;
		while(!que.empty())que.pop();
		for(int i=1;i<=n+3;i++)
		for(int j=1;j<=m+3;j++)vis[i][j]=0;
		que.push(make_pair(x,y));vis[x][y]=1;
		while(!que.empty()){
			pair<int,int> tmp=que.front();que.pop();
			int nx=tmp.first,ny=tmp.second;
			if(!vis[nx][ny+1]&&shu[nx][ny]=='3'&&G[nx][ny+1].first!=-1&&G[nx][ny+1].first!=col&&G[nx][ny+1].second<=lv)if(!ga[nx][ny+1])ans++;
			if(!vis[nx][ny-1]&&shu[nx][ny-1]=='3'&&G[nx][ny-1].first!=-1&&G[nx][ny-1].first!=col&&G[nx][ny-1].second<=lv)if(!ga[nx][ny-1])ans++;
			if(!vis[nx+1][ny]&&heng[nx][ny]=='3'&&G[nx+1][ny].first!=-1&&G[nx+1][ny].first!=col&&G[nx+1][ny].second<=lv)if(!ga[nx+1][ny])ans++;
			if(!vis[nx-1][ny]&&heng[nx-1][ny]=='3'&&G[nx-1][ny].first!=-1&&G[nx-1][ny].first!=col&&G[nx-1][ny].second<=lv)if(!ga[nx-1][ny])ans++;
			if(!vis[nx][ny+1]&&shu[nx][ny]=='3'&&G[nx][ny+1].first==-1)que.push(make_pair(nx,ny+1)),ans+=!ga[nx][ny+1];
			if(!vis[nx][ny-1]&&shu[nx][ny-1]=='3'&&G[nx][ny-1].first==-1)que.push(make_pair(nx,ny-1)),ans+=!ga[nx][ny-1];
			if(!vis[nx+1][ny]&&heng[nx][ny]=='3'&&G[nx+1][ny].first==-1)que.push(make_pair(nx+1,ny)),ans+=!ga[nx+1][ny];
			if(!vis[nx-1][ny]&&heng[nx-1][ny]=='3'&&G[nx-1][ny].first==-1)que.push(make_pair(nx-1,ny)),ans+=!ga[nx-1][ny];
			vis[nx][ny+1]=vis[nx][ny-1]=vis[nx+1][ny]=vis[nx-1][ny]=1;
		}
		printf("%d\n",ans);
		G[x][y]=make_pair(col,lv);
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;read(t);
	while(t--)init();
	return 0;
}

