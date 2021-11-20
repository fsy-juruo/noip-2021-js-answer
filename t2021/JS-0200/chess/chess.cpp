#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#define N 200005
using namespace std;

vector <pair<int,int> > a[N];
vector <int> b[N];

int T,n,m,q,K2,K3,co,li,x,y,ans,p;
int dx[5]={0,1,0,-1},dy[5]={-1,0,1,0},g[5005][5005],col[5005][5005],vis[5005][5005];
string c1[N],c2[N];

bool check(int x,int y,int s,int t){
	if(a[x][y].first!=a[s][t].first&&a[x][y].second<=a[s][t].second) return true;
	return false;
}

int path1(int x,int y,int z){	
	int p=0;
	if(y-1>=1&&y-1<=m&&c1[x][y-2]=='1'&&check(x,y-1,x,y)) p++,b[x][y-1]=z;
	if(y+1>=1&&y+1<=m&&c1[x][y-1]=='1'&&check(x,y+1,x,y)) p++,b[x][y+1]=z;
	if(x-1>=1&&x-1<=n&&c2[x-1][y-1]=='1'&&check(x-1,y,x,y)) p++,b[x-1][y]=z;
	if(x+1>=1&&x+1<=n&&c2[x][y-1]=='1'&&check(x+1,y,x,y)) p++,b[x+1][y]=z;
	return p;
}

int path2(int x,int y,int z){
	int p=0;
	for(int i=x+1;i<=n;i++){
		if(a[i][y].first==a[x][y].first||a[i][y].second>a[x][y].second) break;
		if(c2[i-1][y-1]!='2') break;
		b[i][y]=z;p++;
		if(a[i][y].first!=-1) break;
	}
	for(int i=x-1;i>=1;i--){
		if(a[i][y].first==a[x][y].first||a[i][y].second>a[x][y].second) break;
		if(c2[i+1][y-1]!='2') break;
		b[i][y]=z;p++;
		if(a[i][y].first!=-1) break;
	}
	for(int i=y+1;i<=m;i++){
		if(a[x][i].first==a[x][y].first||a[x][i].second>a[x][y].second) break;
		if(c1[x][i-2]!='2') break;
		b[x][i]=z;p++;
		if(a[x][i].first!=-1) break;
	}
	for(int i=y-1;i>=1;i--){
		if(a[x][i].first==a[x][y].first||a[x][i].second>a[x][y].second) break;
		if(c2[x][i-1]!='2') break;
		b[x][i]=z;p++;
		if(a[x][i].first!=-1) break;
	}
	return p;
}

bool check2(int x,int y,int s,int t){
	if(x<1||x>n||y<1||y>m) return false;
	if(vis[x][y]) return false;
	if(a[x][y].first==a[s][t].first||a[x][y].second>a[s][t].second) return false;
}

void dfs(int x,int y,int z,int s,int t){
	vis[x][y]=1;
	if(a[x][y].first!=-1&&(x!=s||y!=t)) return;
 	if(check2(x-1,y,s,t)&&c2[x-1][y-1]=='3'){
 		if(b[x-1][y]!=z) b[x-1][y]=z,p++;
 		dfs(x-1,y,z,s,t);
	 }
	if(check2(x+1,y,s,t)&&c2[x][y-1]=='3'){
 		if(b[x+1][y]!=z) b[x+1][y]=z,p++;
 		dfs(x+1,y,z,s,t);
	 }
	if(check2(x,y-1,s,t)&&c1[x][y-2]=='3'){
 		if(b[x][y-1]!=z) b[x][y-1]=z,p++;
 		dfs(x,y-1,z,s,t);
	 }
	 if(check2(x,y+1,s,t)&&c1[x][y-1]=='3'){
 		if(b[x][y+1]!=z) b[x][y+1]=z,p++;
 		dfs(x,y+1,z,s,t);
	 }
}

void solve1(){
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>co>>li>>x>>y;
		a[x][y].first=co,a[x][y].second=li;
		b[x][y]=1;
		ans+=path1(x,y,i);
		ans+=path2(x,y,i);p=0;
		dfs(x,y,i,x,y);
		for(int j=1;j<=n;j++)
		  for(int w=1;w<=m;w++) vis[j][w]=0;
		printf("%d\n",ans+p);
	}
}

void solve2(){
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>co>>li>>x>>y;
		a[x][y].first=co;a[x][y].second=li;
		ans+=path1(x,y,i);
		printf("%d\n",ans);
	}
}

void solve3(){
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>co>>li>>x>>y;
		a[x][y].first=co;a[x][y].second=li;
		ans+=path1(x,y,i);
		ans+=path2(x,y,i);
		printf("%d\n",ans);
	}
}

void work(){
	K2=0;K3=0;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>c1[i];
		for(int j=0;j<m-1;j++){
			if(c1[i][j]=='2') K2=1;
			if(c1[i][j]=='3') K3=1;
		}
	}
	for(int i=1;i<n;i++){
		cin>>c2[i];
		for(int j=0;j<m;j++){
			if(c2[i][j]=='2') K2=1;
			if(c2[i][j]=='3') K3=1;
		}
	}
	if(n*m<=5000) solve1();
	for(int i=1;i<=n;i++)
	  for(int j=0;j<=m;j++){
	  	if(a[i].size()<j+1) a[i].push_back(make_pair(-1,0)),b[i].push_back(0);
	  	else a[i][j]=make_pair(-1,0),b[i][j]=0;
	}
	if(n*m<=5000) solve1();
	else if(K2==0&&K3==0) solve2();
	else if(K3==0) solve3();
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		work();
	}
	return 0;
}
