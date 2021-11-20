//rp++
#include<bits/stdc++.h>
using namespace std;

void fre() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef double db;
typedef vector<int> vi;

inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline int readi() {
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	return ch-'0';
}
inline void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')

#define rep(x,l,r) for(int x=l;x<=r;x++)
#define per(x,r,l) for(int x=r;x>=l;x--)
#define rep0(x) while(x--)

#define psf push_front
#define psb push_back
#define ppf pop_front
#define ppb pop_back

#define fi first
#define se second

int t;
int n,m,q;
vector<vi> R,C;
vector<vector<pii> > a;//(col,lv)

void init() {
	a.clear(),R.clear(),C.clear();
	rep(i,0,n+10) a.psb(vector<pii>()),R.psb(vi()),C.psb(vi());
	rep(i,0,n+5) rep(j,0,n+5) a[i].psb(pii(-1,0)),R[i].psb(0),C[i].psb(0);
}

vector<vi> vis;
void vis_init() {
	vis.clear();
	rep(i,0,n+10) vis.psb(vi());
	rep(i,0,n+5) rep(j,0,n+5) vis[i].psb(0);
}

int res=0;
void dfs(int x,int y,int col,int lv) {
	if(a[x][y].fi==col) return;
	if(a[x][y].se>lv) return;
	vis[x][y]=1;
	res++;
	if(a[x][y].fi!=-1) return;
	if(x<n&&C[x][y]==3&&!vis[x+1][y]) dfs(x+1,y,col,lv);
	if(y<m&&R[x][y]==3&&!vis[x][y+1]) dfs(x,y+1,col,lv);
	if(x>1&&C[x-1][y]==3&&!vis[x-1][y]) dfs(x-1,y,col,lv);
	if(y>1&&R[x][y-1]==3&&!vis[x][y-1]) dfs(x,y-1,col,lv);
}

int main() {
	fre();
	
	t=read();
	rep0(t) {
		n=read(),m=read(),q=read();
		
		init();
		rep(i,1,n) rep(j,1,m-1) R[i][j]=readi();
		rep(i,1,n-1) rep(j,1,m) C[i][j]=readi();
		//rep(i,1,n) rep(j,1,m) a[i][j]=;
		
		rep0(q) {
			int col=read(),lv=read(),x=read(),y=read();
			res=0;
			vis_init();
			//1
			if(x<n&&C[x][y]==1) {
				if(a[x+1][y].fi!=col&&a[x+1][y].se<=lv) res++,vis[x+1][y]=1;
			}
			if(y<m&&R[x][y]==1) {
				if(a[x][y+1].fi!=col&&a[x][y+1].se<=lv) res++,vis[x][y+1]=1;
			}
			if(x>1&&C[x-1][y]==1) {
				if(a[x-1][y].fi!=col&&a[x-1][y].se<=lv) res++,vis[x-1][y]=1;
			}
			if(y>1&&R[x][y-1]==1) {
				if(a[x][y-1].fi!=col&&a[x][y-1].se<=lv) res++,vis[x][y-1]=1;
			}
			//2
			int p;
			p=x;
			while(p<n&&C[p][y]==2&&a[p][y].fi==-1) {
				if(a[p+1][y].fi!=col&&a[p+1][y].se<=lv) {
					p++;
					res++;
					vis[p][y]=1;
				} else break;
			}
			p=y;
			while(p<m&&R[x][p]==2&&a[x][p].fi==-1) {
				if(a[x][p+1].fi!=col&&a[x][p+1].se<=lv) {
					p++;
					res++;
					vis[x][p]=1;
				} else break;
			}
			p=x;
			while(p>1&&C[p-1][y]==2&&a[p][y].fi==-1) {
				if(a[p-1][y].fi!=col&&a[p-1][y].se<=lv) {
					p--;
					res++;
					vis[p][y]=1;
				} else break;
			}
			p=y;
			while(p>1&&R[x][p-1]==2&&a[x][p].fi==-1) {
				if(a[x][p-1].fi!=col&&a[x][p-1].se<=lv) {
					p--;
					res++;
					vis[x][p]=1;
				} else break;
			}
			//3
			dfs(x,y,col,lv);
			//record
			a[x][y]=pii(col,lv);
			writeln(res-1);	//(x,y) had been count into res
			/*
			rep(i,1,n) {
				rep(j,1,m-1) writesp(vis[i][j]);
				writeln(vis[i][m]);
			}
			*/
		}
	}
	
	return 0;
}
