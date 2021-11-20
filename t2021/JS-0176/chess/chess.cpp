#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node{
	int x,id;
}a[N];
int T,n,m,q,ans,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool b[5],c[N];
vector<node> g[N];
bool check(int x,int z){
	int y=x%m;
	x/=m;
	int nx=x+dx[z],ny=y+dy[z];
	if(x<0 or y<0 or x>=n or y>=m)
		return true;
	return false;
}
void dfs(int x,int y,int z,int lv,int col){
	c[x]=1;
	if(y==1)return ;
	if(y==2){
		if(check(x,z))return ;
		int j=0;
		int abc=0;
		for(;j<g[x].size();j++)
			if(g[x][j].id==x+m*dx[z]+dy[z]){
				abc=1;
				break;
			}
		if(abc==0)return ;
		if(a[g[x][j].id].x<=lv and c[g[x][j].id]==0 and g[x][j].x==2 and a[g[x][j].id].id!=col)
			dfs(g[x][j].id,2,z,lv,col);
		return ;
	}
	for(int i=0;i<g[x].size();i++){
		node u=g[x][i];
		if(a[u.id].x<=lv and c[u.id]==0 and u.x==3 and a[u.id].id!=col)
			dfs(u.id,3,z,lv,col);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> q;
		for(int i=0;i<n*m;i++){
			a[i].id=a[i].x=-1;
			g[i].clear();
		}
		for(int i=0;i<n;i++){
			string s;
			cin >> s;
			for(int j=0;j<m-1;j++){
				node x;
				x.id=i*m+j+1;
				x.x=s[j]-'0';
				if(x.x==0)continue;
				b[x.x]=1;
				g[i*m+j].push_back(x);
				x.id=i*m+j;
				g[i*m+j+1].push_back(x);
			}
		}
		for(int i=0;i<n-1;i++){
			string s;
			cin >> s;
			for(int j=0;j<m;j++){
				node x;
				x.id=(i+1)*m+j;
				x.x=s[j]-'0';
				if(x.x==0)continue;
				b[x.x]=1;
				g[i*m+j].push_back(x);
				x.id=i*m+j;
				g[(i+1)*m+j].push_back(x);
			}
		}
		while(q--){
			int col,lv,x,y;
			cin >> col >> lv >> x >> y;
			x--,y--;
			int z=x*m+y;
			a[z].id=col;
			a[z].x=lv;
			memset(c,0,sizeof(c));
			c[z]=1;
			ans=-1;
			for(int i=0;i<g[z].size();i++){
				if(c[g[z][i].id]==0 and lv>=a[g[z][i].id].x and a[g[z][i].id].id!=col){
					int j=0;
					for(;j<4;j++)
						if(g[z][i].id==(x+dx[j])*m+y+dy[j])
							break;
					dfs(g[z][i].id,g[z][i].x,j,lv,col);
				}
			}
			for(int i=0;i<n*m;i++)
				ans+=c[i];
			cout << ans << endl;
		}
	}
	return 0;
}
