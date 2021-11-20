/*
I bet there's no NetworkFlow in this :]
Happy DS time~~~
---Zzzyt
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define INF 1000000007

int n,m,q;
char buf[200005];

char je[5005][105];
char ie[5005][105];
pii a[5005][105];
bool used[5005][105];
bool used3[5005][105];
vector<pii> v;

const int dxt[]={-1,0,1,0};
const int dyt[]={0,-1,0,1};

char typ(int x,int y,int dk){
	int nx=x+dxt[dk];
	int ny=y+dyt[dk];
	if(nx<1||ny<1||nx>n||ny>m)return '0';
	if(dk==0){
		return ie[x-1][y];
	}
	else if(dk==1){
		return je[x][y-1];
	}
	else if(dk==2){
		return ie[x][y];
	}
	else{
		return je[x][y];
	}
}

bool addifcan(int x,int y,int col,int lv){
	if(x<1||y<1||x>n||y>m)return false;
	if(a[x][y].first){
		if(a[x][y].first!=col&&a[x][y].second<=lv){
//			cerr<<"add&end "<<x<<' '<<y<<endl;
			used[x][y]=true;
			v.push_back(make_pair(x,y));
		}
		return false;
	}
//	cerr<<"add "<<x<<' '<<y<<endl;
	used[x][y]=true;
	v.push_back(make_pair(x,y));
	return true;
}

void parse(int x,int y,int dk,int col,int lv){
	char t=typ(x,y,dk);
//	cerr<<"parse "<<dk<<' '<<t<<endl;
	if(t=='0')return;
	int dx=dxt[dk];
	int dy=dyt[dk];
	if(t=='1'){
		addifcan(x+dx,y+dy,col,lv);
	}
	else if(t=='2'){
		while(true){
			if(!addifcan(x,y,col,lv))break;
			if(typ(x,y,dk)!='2')break;
			x+=dx;
			y+=dy;
		}
	}
}

void dfs(int x,int y,int col,int lv){
	if(used3[x][y])return;
	if(!addifcan(x,y,col,lv))return;
	used3[x][y]=true;
	for(int dk=0;dk<4;dk++){
		if(typ(x,y,dk)=='3'){
			dfs(x+dxt[dk],y+dyt[dk],col,lv);
		}
	}
}

vector<pii> added;

void solver1(){
	bool swapped=false;
	if(m>n){
		swapped=true;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",buf+1);
		for(int j=1;j<m;j++){
			if(swapped){
				ie[j][i]=buf[j];
			}
			else{
				je[i][j]=buf[j];
			}
		}
	}
	for(int i=1;i<n;i++){
		scanf("%s",buf+1);
		for(int j=1;j<=m;j++){
			if(swapped){
				je[j][i]=buf[j];
			}
			else{
				ie[i][j]=buf[j];
			}
		}
	}
	if(swapped){
		swap(m,n);
	}
//	for(int i=1;i<=3;i++){
//		for(int j=1;j<=3;j++){
//			cerr<<ie[i][j]<<'\t';
//		}
//		cerr<<endl;
//	}
//	for(int i=1;i<=3;i++){
//		for(int j=1;j<=3;j++){
//			cerr<<je[i][j]<<'\t';
//		}
//		cerr<<endl;
//	}
	for(int qq=0;qq<q;qq++){
		int col,lv,x,y;
		scanf("%d%d%d%d",&col,&lv,&x,&y);
		if(swapped){
			swap(x,y);
		}
		col++;
		parse(x,y,0,col,lv);
		parse(x,y,1,col,lv);
		parse(x,y,2,col,lv);
		parse(x,y,3,col,lv);
//		cerr<<"dfs"<<endl;
		dfs(x,y,col,lv);
		int ans=0;
		for(int i=0;i<v.size();i++){
			int xx=v[i].first;
			int yy=v[i].second;
			if(!used[xx][yy])continue;
			used[xx][yy]=false;
			used3[xx][yy]=false;
			if(x==xx&&y==yy)continue;
//			cerr<<xx<<' '<<yy<<endl;
			ans++;
		}
		v.clear();
		printf("%d\n",ans);
		added.push_back(make_pair(x,y));
		a[x][y]=make_pair(col,lv);
	}
	for(int i=0;i<added.size();i++){
		a[added[i].first][added[i].second]=make_pair(0,0);
	}
	added.clear();
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	freopen("chess.in","r",stdin);
#ifndef ZZZYT
	freopen("chess.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		solver1();
	}
	return 0;
}

