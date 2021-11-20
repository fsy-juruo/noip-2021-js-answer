#include<bits/stdc++.h>
#define RE return
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define P pair
#define F first
#define S second
#define ALL(a) a.begin(),a.end()
#define FILL(a,b) memset(a,b,sizeof(a))
#define gmin(a,b) a=min(a,b)
#define gmax(a,b) a=max(a,b)
#define PB emplace_back
#define MP make_pair
#define lwb lower_bound
using namespace std;
void read(int &x){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	x=0;
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-'0',c=getchar();
}
void read2(int &x){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	x=c-'0';
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
V<V<int> > g1,g2;
int n1,m2;
struct query{
	int col,lv,x,y;
	void read(int &x){
		char c=getchar();
		while(c<'0'||c>'9')c=getchar();
		x=0;
		while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-'0',c=getchar();
	}
	void read(){
		read(col);read(lv);read(x);read(y);
	}
};
query qr[100005];
P<int,int> Q[5005];
int s,t;
V<V<P<int,int> > > hav;
V<V<int> > vis;
int n,m,q;
void init(V<V<P<int,int> > > &x){
	x.clear();
	V<P<int,int> > now(m+1,MP(0,0));
	FOR(i,0,n)x.PB(now);
}
void init(V<V<int> > &x){
	x.clear();
	V<int> now(m+1,0);
	FOR(i,0,n)x.PB(now);
}
bool check(int x,int y,int c,int l){
	if(hav[x][y].S){
		RE c!=hav[x][y].F&&l>=hav[x][y].S;
	}
	RE 1;
}
set<int> s1[200005],s2[200005];
void solve(){
	read(n);read(m);read(q);
	V<int> tv(m+1,0); 
	g1.clear();g2.clear();
	g1.PB(tv);g2.PB(tv);
	bool ff[4]={};
	FOR(i,1,n){
		V<int> now;now.PB(0);
		rep(j,1,m){
			now.PB(0);
			read2(now.back());
			ff[now.back()]=1;
		}
		now.PB(0);
		g1.PB(now);
	}
	FOR(i,1,n){
		V<int> now;
		now.PB(0);
		FOR(j,1,m){
			now.PB(0);
			if(i<n)read2(now.back());
			ff[now.back()]=1;
		}
		g2.PB(now);
	}
	FOR(i,1,q){
		qr[i].read();
	}
	if(n*m<=10000&&q<=2000){
		init(hav);init(vis);
		FOR(_,1,q){
			s=1;
			t=0;
			FOR(i,1,n)FOR(j,1,m)vis[i][j]=0;
			int tx=qr[_].x,ty=qr[_].y;
			Q[++t]=MP(qr[_].x,qr[_].y);
			vis[qr[_].x][qr[_].y]=1;
			while(s<=t){
				P<int,int> now=Q[s++];
				if(hav[now.F][now.S].S)continue;
				if(now.F>1&&!vis[now.F-1][now.S]){
					if(g2[now.F-1][now.S]==3&&check(now.F-1,now.S,qr[_].col,qr[_].lv)){
						vis[now.F-1][now.S]=1;
						Q[++t]=MP(now.F-1,now.S);
					}
				}
				if(now.F<n&&!vis[now.F+1][now.S]){
					if(g2[now.F][now.S]==3&&check(now.F+1,now.S,qr[_].col,qr[_].lv)){
						vis[now.F+1][now.S]=1;
						Q[++t]=MP(now.F+1,now.S);
					}
				}
				if(now.S<m&&!vis[now.F][now.S+1]){
					if(g1[now.F][now.S]==3&&check(now.F,now.S+1,qr[_].col,qr[_].lv)){
						vis[now.F][now.S+1]=1;
						Q[++t]=MP(now.F,now.S+1);
					}
				}
				if(now.S>1&&!vis[now.F][now.S-1]){
					if(g1[now.F][now.S-1]==3&&check(now.F,now.S-1,qr[_].col,qr[_].lv)){
						vis[now.F][now.S-1]=1;
						Q[++t]=MP(now.F,now.S-1);
					}
				}
			}
			if(ty<m&&g1[tx][ty]==1){
				if(check(tx,ty+1,qr[_].col,qr[_].lv))vis[tx][ty+1]=1;
			}else if(g1[tx][ty]==2){
				int lx=tx,ly=ty;
				rep(j,ty,m)if(g1[lx][ly]==2){
					if(hav[lx][ly+1].S){
						if(check(lx,ly+1,qr[_].col,qr[_].lv))vis[lx][ly+1]=1;
						break;
					}else vis[lx][ly+1]=1;
					ly++;
				}else break;
			}
			if(g2[tx][ty]==1){
				if(tx<n&&check(tx+1,ty,qr[_].col,qr[_].lv))vis[tx+1][ty]=1;
			}else if(g2[tx][ty]==2){
				int lx=tx,ly=ty;
				rep(j,tx,n)if(g2[lx][ly]==2){
					if(hav[lx+1][ly].S){
						if(check(lx+1,ly,qr[_].col,qr[_].lv))vis[lx+1][ly]=1;
						break;
					}else vis[lx+1][ly]=1;
					lx++;
				}else break;
			}
			if(g2[tx-1][ty]==1){
				if(check(tx-1,ty,qr[_].col,qr[_].lv))vis[tx-1][ty]=1;
			}else if(g2[tx-1][ty]==2){
				int lx=tx,ly=ty;
				for(int j=tx;j>1;j--)if(g2[lx-1][ly]==2){
					if(hav[lx-1][ly].S){
						if(check(lx-1,ly,qr[_].col,qr[_].lv))vis[lx-1][ly]=1;
						break;
					}else vis[lx-1][ly]=1;
					lx--;
				}else break;
			}
			if(g1[tx][ty-1]==1){
				if(check(tx,ty-1,qr[_].col,qr[_].lv))vis[tx][ty-1]=1;
			}else if(g1[tx][ty-1]==2){
				int lx=tx,ly=ty;
				for(int j=ty;j>1;j--)if(g1[lx][ly-1]==2){
					if(hav[lx][ly-1].S){
						if(check(lx,ly-1,qr[_].col,qr[_].lv))vis[lx][ly-1]=1;
						break;
					}else vis[lx][ly-1]=1;
					ly--;
				}else break;
			}
			int ans=0;
			FOR(i,1,n){
				FOR(j,1,m){
					if(vis[i][j])ans++;
				}
			}
			write(ans-1);
			putchar('\n');
			hav[qr[_].x][qr[_].y]=MP(qr[_].col,qr[_].lv);
		}
	}else if(!ff[2]&&!ff[3]){
		init(hav);
		FOR(_,1,q){
			int ans=0;
			int tx=qr[_].x,ty=qr[_].y;
			if(ty<m&&g1[tx][ty]==1){
				if(check(tx,ty+1,qr[_].col,qr[_].lv))ans++;
			}
			if(g2[tx][ty]==1){
				if(tx<n&&check(tx+1,ty,qr[_].col,qr[_].lv))ans++;
			}
			if(g2[tx-1][ty]==1){
				if(check(tx-1,ty,qr[_].col,qr[_].lv))ans++;
			}
			if(g1[tx][ty-1]==1){
				if(check(tx,ty-1,qr[_].col,qr[_].lv))ans++;
			}
			write(ans);putchar('\n');
			hav[qr[_].x][qr[_].y]=MP(qr[_].col,qr[_].lv);
		}
	}else if(!ff[3]){
		init(hav);
		V<V<int> > lst1,lst2,nxt1,nxt2;
		init(lst1);init(lst2);init(nxt1);init(nxt2);
		FOR(i,1,n)s1[i].clear(),s1[i].emplace(1),s1[i].emplace(m);
		FOR(i,1,m)s2[i].clear(),s2[i].emplace(1),s2[i].emplace(n);
		FOR(i,1,n){
			FOR(j,1,m){
				if(g1[i][j-1]!=2){
					lst1[i][j]=j;
				}else lst1[i][j]=lst1[i][j-1];
			}
			for(int j=m;j>=1;j--){
				if(g1[i][j]!=2){
					nxt1[i][j]=j;
				}else nxt1[i][j]=nxt1[i][j+1];
			}
		}
		FOR(i,1,n){
			FOR(j,1,m){
				if(g2[i][j-1]==2){
					lst2[i][j]=lst2[i-1][j];
				}else lst2[i][j]=i;
			}
		}
		for(int i=n;i>=1;i--){
			FOR(j,1,m){
				if(g2[i][j]==2){
					nxt2[i][j]=nxt2[i+1][j];
				}else nxt2[i][j]=i;
			}
		}
		FOR(_,1,q){
			int ans=0;
			int tx=qr[_].x,ty=qr[_].y;
			if(ty<m&&g1[tx][ty]==1){
				if(check(tx,ty+1,qr[_].col,qr[_].lv))ans++;
			}
			if(g2[tx][ty]==1){
				if(tx<n&&check(tx+1,ty,qr[_].col,qr[_].lv))ans++;
			}
			if(g2[tx-1][ty]==1){
				if(check(tx-1,ty,qr[_].col,qr[_].lv))ans++;
			}
			if(g1[tx][ty-1]==1){
				if(check(tx,ty-1,qr[_].col,qr[_].lv))ans++;
			}
			int tl=lst1[tx][ty],tr=nxt1[tx][ty];
			auto u=s1[tx].lwb(ty);
			gmin(tr,*u);
			u--;
			gmax(tl,*u);
			if(!check(tx,tl,qr[_].col,qr[_].lv))tl++;
			if(!check(tx,tr,qr[_].col,qr[_].lv))tr--;
			ans+=tr-tl;
			tl=lst2[tx][ty],tr=nxt2[tx][ty];
			u=s2[ty].lwb(tx);
			gmin(tr,*u);
			u--;
			gmax(tl,*u);
			if(!check(tl,ty,qr[_].col,qr[_].lv))tl++;
			if(!check(tr,ty,qr[_].col,qr[_].lv))tr--;
			ans+=tr-tl;
			write(ans);putchar('\n');
			hav[qr[_].x][qr[_].y]=MP(qr[_].col,qr[_].lv);
			s1[tx].emplace(ty);
			s2[ty].emplace(tx);
		}
	}
}
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	read(T);
	while(T--)solve();
	RE 0;
}

