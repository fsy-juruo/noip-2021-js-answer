#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}

#define lowbit(n) n&(-n)
const int N=1e5+10;
int n,m,ans,q,T;
struct nodde{
	int k;
};
vector <bool> H[4][N];
struct node{
	int col,lv,p;
}a;
vector <node> c[N];

struct noode{
	int x,y,u,v;
};
map<pair<int,pair<int,pair<int,int> > > ,int> ma;
#define mp(a,b,c,d) make_pair(a,make_pair(b,make_pair(c,d)))
int dx[4]={0,1,0,1};
int dy[4]={-1,0,-1,0};
int d[4]={1,2,3,4};//up down right left
//void dfs(int x,int y,int k,int last){
//	if (k!=-1) H[k][x][y]=1;
//	for (int i=0;i<4;i++){
//		int nx=x+dx[i]; int ny=y+dy[i];
//	
//		if (k!=-1&&check(x,y,nx,ny)) continue;	
//		if (k==0) continue;
//		if (k==1){
//			if (c[x][y].p){
//			if (a.col!=c[nx][ny].col&&a.lv>c[nx][ny].lv){
//				ans+=1-H[ma(noode{x,y,nx,ny})][nx][ny]; H[ma(noode{x,y,nx,ny})][nx][ny]=1; continue;
//				}
//			}else ans+=1-H[ma(noode{x,y,nx,ny})][nx][ny]; H[ma(noode{x,y,nx,ny})][nx][ny]=1; continue;
//		}
//		if (k==2){
//			if (i%2!=last&&last!=-1) continue;
//		}
//		if (c[x][y].p){
//			if (a.col!=c[nx][ny].col&&a.lv>c[nx][ny].lv){
//				ans+=1-H[ma(noode{x,y,nx,ny})][nx][ny]; H[ma(noode{x,y,nx,ny})][nx][ny]=1; continue;
//			}
//		}
//		ans++;
//		dfs(nx,ny,ma(node{x,y,nx,ny}),i%2);
//	}
//}
void work(){
	read(n); read(m); read(q);
	string s;
	for (int i=1;i<=n;i++){
		cin>>s;
		for (int j=1;j<=m-1;j++)
			ma[mp(i,j,i,j+1)]=s[j-1]-48,ma[mp(i,j+1,i,j)]=s[j-1]-48;
	}
	for (int i=1;i<=n-1;i++){
		cin>>s;
		for (int j=1;j<=m;j++)
			ma[mp(i+1,j,i,j)]=s[j-1]-48,ma[mp(i+1,j,i,j)]=s[j-1]-48;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			c[i].push_back(node{0,0,0});
			for (int k=0;k<4;k++) H[k][i].push_back(0);
		}
	}
	while (q--){
		int x,y,col,lv;
		read(col); read(lv); read(x); read(y);
		c[x][y]=node{col,lv,1};
		ans=0;
		for (int i=0;i<4;i++){
			int nx=dx[i]+x,ny=dy[i]+y;
			if (ma[mp(x,y,nx,ny)]!=0){
				if (c[nx][ny].p==1){
					if (c[nx][ny].col!=col&&lv>=c[nx][ny].lv) ans++;
				}else ans++;
			}
		}
		cout<<ans<<endl;
	}
	for (int i=1;i<=n;i++){
		c[i].clear();
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while (T--){
		ma.clear();
		work();
	}
	return 0;
}

