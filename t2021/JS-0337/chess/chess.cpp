#include<bits/stdc++.h>
using namespace std;
int t;
int n,mm,q;
int xi[4]={0,0,1,-1};
int yi[4]={1,-1,0,0};
struct node{
	int col,lv,x,y;
}e[5005];
bool vis[100][100];
struct pp{
	bool cov=0;
	int co,ll;	
}m[102][102];
char hang[105][105];
char lie[105][105];	
int ans;
void  dfs(int c,int lvv,int j,int k,int l){
	if(hang[j-1][k]==l==1&&!vis[j-1][k]&&(m[j-1][k].cov==0||(m[j-1][k].co!=c&&m[j-1][k].ll<=lvv))){
		ans++;
		vis[j-1][k]=1;
		return;
	}
	if(hang[j][k]==l==1&&!vis[j+1][k]&&(m[j+1][k].cov==0||(m[j+1][k].co!=c&&m[j+1][k].ll<=lvv))){
		ans++;
		vis[j+1][k]=1;
		return;
	}
	if(lie[j][k-1]==l==1&&!	vis[j][k-1]&&(m[j][k-1].cov==0||(m[j][k-1].co!=c&&m[j][k-1].ll<=lvv))){
		ans++;
		vis[j][k-1]=1;
		return;
	}
	if(lie[j][k]==l==1&&!vis[j][k+1]&&(m[j][k+1].cov==0||(m[j][k+1].co!=c&&m[j][k+1].ll<=lvv))){
		ans++;
		vis[j][k+1]=1;
		return;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>t;
	while(t--){	
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
				m[i][j].cov=0;
		cin>>n>>mm>>q;
		memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=mm-1;j++)
				cin>>hang[i][j];
		for(int i=1;i<n;i++)
			for(int j=1;j<=mm;j++)
				cin>>lie[i][j];
		for(int i=1;i<=q;i++){
			memset(vis,0,sizeof(vis));
			cin>>e[i].col>>e[i].lv>>e[i].x>>e[i].y;
			m[e[i].y][e[i].x].cov=1;
			ans=0;
			dfs(e[i].col,e[i].lv,e[i].y,e[i].x,1);
			cout<<ans<<endl;
		}
	}
return 0;
}

