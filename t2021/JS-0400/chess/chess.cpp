#include<bits/stdc++.h>
using namespace std;
bool vis[5003][5003];
int n,m,q,ans;
string s[200003],t[200003];
vector<int>Col[5003],Lv[5003];
void dfs(int x,int y,int col,int lv){
	if(Col[x][y]==col||Lv[x][y]>lv)return;
	vis[x][y]=1;ans++;
	if(Col[x][y]!=-1)return;
	if(x>=1&&!vis[x-1][y]&&t[x-1][y]=='3')
		dfs(x-1,y,col,lv);
	if(x<=n-2&&!vis[x+1][y]&&t[x][y]=='3')
		dfs(x+1,y,col,lv);
	if(y>=1&&!vis[x][y-1]&&s[x][y-1]=='3')
		dfs(x,y-1,col,lv);
	if(y<=m-2&&!vis[x][y+1]&&s[x][y]=='3')
		dfs(x,y+1,col,lv);
}
void solve(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++){
		cin>>s[i],
		Col[i].clear();
		Lv[i].clear();
		for(int j=0;j<m;j++){
			Col[i].push_back(-1);
			Lv[i].push_back(-1);
		}
	}
	for(int i=0;i<n-1;i++)
		cin>>t[i];
	while(q--){
		if(n*m<=5000)
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					vis[i][j]=0;
		ans=-1;
		int col,lv,x,y;
		scanf("%d%d%d%d",&col,&lv,&x,&y);x--;y--;
		dfs(x,y,col,lv);vis[x][y]=0;
		int nwx=x,nwy=y;
		while(nwx>=1&&t[nwx-1][nwy]=='2'){nwx--;
			if(Col[nwx][nwy]==col||Lv[nwx][nwy]>lv)break; 
			if(vis[nwx][nwy]==0)ans++;
			if(Col[nwx][nwy]!=-1)break;
		}
		nwx=x;nwy=y;
		while(nwx<=n-2&&t[nwx][nwy]=='2'){nwx++;
			if(Col[nwx][nwy]==col||Lv[nwx][nwy]>lv)break; 
			if(vis[nwx][nwy]==0)ans++;
			if(Col[nwx][nwy]!=-1)break;
		}
		nwx=x;nwy=y;
		while(nwy>=1&&s[nwx][nwy-1]=='2'){nwy--;
			if(Col[nwx][nwy]==col||Lv[nwx][nwy]>lv)break; 
			if(vis[nwx][nwy]==0)ans++;
			if(Col[nwx][nwy]!=-1)break;
		}
		nwx=x;nwy=y;
		while(nwy<=m-2&&s[nwx][nwy]=='2'){nwy++;
			if(Col[nwx][nwy]==col||Lv[nwx][nwy]>lv)break; 
			if(vis[nwx][nwy]==0)ans++;
			if(Col[nwx][nwy]!=-1)break;
		}
		if(x>=1&&!vis[x-1][y]&&t[x-1][y]=='1'&&Lv[x-1][y]<=lv&&Col[x-1][y]!=col)
			ans++;
		if(x<=m-2&&!vis[x+1][y]&&t[x][y]=='1'&&Lv[x+1][y]<=lv&&Col[x+1][y]!=col)
			ans++;
		if(y>=1&&!vis[x][y-1]&&s[x][y-1]=='1'&&Lv[x][y-1]<=lv&&Col[x][y-1]!=col)
			ans++;
		if(y<=m-2&&!vis[x][y+1]&&s[x][y]=='1'&&Lv[x][y+1]<=lv&&Col[x][y+1]!=col)
			ans++;
		Col[x][y]=col;Lv[x][y]=lv;
		printf("%d\n",ans);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0; 
}
