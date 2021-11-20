#include <bits/stdc++.h>
using namespace std;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int n,m,q;
vector<int> g1[200010],g2[200010];

inline int getint()
{
	int r=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		r=(r<<3)+(r<<1)+ch-'0';
		ch=getchar();
	}
	return r;
}

inline void printint(int x)
{
	if(x>=10) printint(x/10);
	putchar('0'^(x%10));
}

signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int cases=getint();
	while(cases--){
		n=getint();m=getint();q=getint();
		vector<vector<int> > v1,v2,a,b;
		v1.resize(n+1,vector<int>(m,0));
		v2.resize(n,vector<int>(m+1,0));
		a.resize(n+1,vector<int>(m+1,0));
		b.resize(n+1,vector<int>(m+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				char ch=getchar();
				while(ch<'0'||ch>'3') ch=getchar();
				v1[i][j]=ch-'0';
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=m;j++){
				char ch=getchar();
				while(ch<'0'||ch>'3') ch=getchar();
				v2[i][j]=ch-'0';
			}
		}
		if(n*m<=10000){
			vector<vector<int> > vis,ok;
			vis.resize(n+1,vector<int>(m+1,0));
			ok.resize(n+1,vector<int>(m+1,0));
			for(int i=1;i<=q;i++){
				int col=getint(),lvl=getint(),x=getint(),y=getint();
				ok[x][y]=1;
				for(int dir=0;dir<4;dir++){
					int nx=x+dx[dir],ny=y+dy[dir];
					if(nx<1||ny<1||nx>n||ny>m) continue;
					int val;
					if(dir==0) val=v1[x][y];
					if(dir==1) val=v1[nx][ny];
					if(dir==2) val=v2[x][y];
					if(dir==3) val=v2[nx][ny];
					if(val==1){
						if(b[nx][ny]){
							if(col!=a[nx][ny]&&lvl>=b[nx][ny]) ok[nx][ny]=1;
						}
						else ok[nx][ny]=1;
					}
					if(val==2){
						int px=x,py=y;
						while(true){
							if(b[nx][ny]){
								if(col!=a[nx][ny]&&lvl>=b[nx][ny]) ok[nx][ny]=1;
								break;
							}
							ok[nx][ny]=1;
							px=nx;py=ny;
							nx+=dx[dir];ny+=dy[dir];
							if(nx<1||ny<1||nx>n||ny>m) break;
							int val;
							if(dir==0) val=v1[px][py];
							if(dir==1) val=v1[nx][ny];
							if(dir==2) val=v2[px][py];
							if(dir==3) val=v2[nx][ny];
							if(val!=2) break;
						}
					}
				}
				queue<pair<int,int> > q;
				q.push(make_pair(x,y));vis[x][y]=1;
				while(!q.empty()){
					int x=q.front().first,y=q.front().second;q.pop();
					if(b[x][y]){
						if(col!=a[x][y]&&lvl>=b[x][y]) ok[x][y]=1;
						continue;
					}
					ok[x][y]=1;
					for(int dir=0;dir<4;dir++){
						int nx=x+dx[dir],ny=y+dy[dir];
						if(nx<1||ny<1||nx>n||ny>m) continue;
						if(vis[nx][ny]) continue;
						int val;
						if(dir==0) val=v1[x][y];
						if(dir==1) val=v1[nx][ny];
						if(dir==2) val=v2[x][y];
						if(dir==3) val=v2[nx][ny];
						if(val==3){
							vis[nx][ny]=1;
							q.push(make_pair(nx,ny));
						}
					}
				}
				a[x][y]=col;b[x][y]=lvl;
				int cnt=0;
				for(int j=1;j<=n;j++) for(int k=1;k<=m;k++) if(ok[j][k]) cnt++;
				printint(cnt-1);putchar('\n');
				for(int j=1;j<=n;j++) for(int k=1;k<=m;k++) vis[j][k]=0,ok[j][k]=0;
			}
		}
		else{
			vector<vector<int> > ok0,ok1,ok2,ok3;
			ok0.resize(n+1,vector<int>(m+1,0));
			ok1.resize(n+1,vector<int>(m+1,0));
			ok2.resize(n+1,vector<int>(m+1,0));
			ok3.resize(n+1,vector<int>(m+1,0));
			for(int i=1;i<=n;i++){
				ok0[i][m]=0;
				for(int j=m-1;j>=1;j--){
					if(v1[i][j]!=2) ok0[i][j]=0;
					else ok0[i][j]=ok0[i][j+1]+1;
				}
			}
			for(int i=1;i<=n;i++){
				ok1[i][1]=0;
				for(int j=2;j<=m;j++){
					if(v1[i][j-1]!=2) ok1[i][j]=0;
					else ok1[i][j]=ok1[i][j-1]+1;
				}
			}
			for(int i=1;i<=m;i++){
				ok2[n][i]=0;
				for(int j=n-1;j>=1;j--){
					if(v2[j][i]!=2) ok2[j][i]=0;
					else ok2[j][i]=ok2[j+1][i]+1;
				}
			}
			for(int i=1;i<=m;i++){
				ok3[1][i]=0;
				for(int j=2;j<=n;j++){
					if(v2[j-1][i]!=2) ok3[j][i]=0;
					else ok3[j][i]=ok3[j-1][i]+1;
				} 
			}
			for(int i=1;i<=n;i++) g1[i].clear();
			for(int i=1;i<=m;i++) g2[i].clear();
			for(int i=1;i<=q;i++){
				int col=getint(),lvl=getint(),x=getint(),y=getint(),cnt=0;
				for(int dir=0;dir<4;dir++){
					int nx=x+dx[dir],ny=y+dy[dir];
					if(nx<1||ny<1||nx>n||ny>m) continue;
					int val;
					if(dir==0) val=v1[x][y];
					if(dir==1) val=v1[nx][ny];
					if(dir==2) val=v2[x][y];
					if(dir==3) val=v2[nx][ny];
					if(val==1){
						if(b[nx][ny]){
							if(col!=a[nx][ny]&&lvl>=b[nx][ny]) cnt++;
						}
						else cnt++;
					}
					if(val==2){
						if(dir==0){
							int pos=lower_bound(g1[x].begin(),g1[x].end(),y)-g1[x].begin();
							if(pos==(int)g1[x].size()) cnt+=ok0[x][y];
							else if(g1[x][pos]>y+ok0[x][y]) cnt+=ok0[x][y];
							else{
								cnt+=g1[x][pos]-y-1;
								if(col!=a[x][g1[x][pos]]&&lvl>=b[x][g1[x][pos]]) cnt++;
							}
						}
						if(dir==1){
							int pos=lower_bound(g1[x].begin(),g1[x].end(),y)-g1[x].begin()-1;
							if(pos==-1) cnt+=ok1[x][y];
							else if(g1[x][pos]<y-ok1[x][y]) cnt+=ok1[x][y];
							else{
								cnt+=y-g1[x][pos]-1;
								if(col!=a[x][g1[x][pos]]&&lvl>=b[x][g1[x][pos]]) cnt++;
							}
						}
						if(dir==2){
							int pos=lower_bound(g2[y].begin(),g2[y].end(),x)-g2[y].begin();
							if(pos==(int)g2[y].size()) cnt+=ok2[x][y];
							else if(g2[y][pos]>x+ok2[x][y]) cnt+=ok2[x][y];
							else{
								cnt+=g2[y][pos]-x-1;
								if(col!=a[g2[y][pos]][y]&&lvl>=b[g2[y][pos]][y]) cnt++;
							}
						}
						if(dir==3){
							int pos=lower_bound(g2[y].begin(),g2[y].end(),x)-g2[y].begin()-1;
							if(pos==-1) cnt+=ok3[x][y];
							else if(g2[y][pos]<x-ok3[x][y]) cnt+=ok3[x][y];
							else{
								cnt+=x-g2[y][pos]-1;
								if(col!=a[g2[y][pos]][y]&&lvl>=b[g2[y][pos]][y]) cnt++;
							}
						}
					}
				}
				printint(cnt);putchar('\n');
				a[x][y]=col;b[x][y]=lvl;
				g1[x].push_back(y);
				g2[y].push_back(x);
			}
		}
	}
	return 0;
}
