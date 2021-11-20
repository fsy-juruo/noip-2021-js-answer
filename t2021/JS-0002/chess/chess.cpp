#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define mp pair<int,int>
using namespace std;
int n,m,q;
string ro[200000+1],co[200000+1];
int walk[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void solve(){
	cin>>n>>m>>q;
	rb(i,1,n) cin>>ro[i];
	rb(i,1,n-1) cin>>co[i];
	vector<vector<short > > c;
	vector<vector<short > > l;
	c.resize(n+1);
	rb(i,1,n) c[i].resize(m+1);
	l=c;
	rb(i,1,n) rb(j,1,m) c[i][j]=-1;
	rb(i,1,q){
		int col,lv,x,y;
		cin>>col>>lv>>x>>y;
		c[x][y]=col;
		l[x][y]=lv;
		int answer=0;
		rb(j,0,3){
			int nx,ny;
			nx=x+walk[j][0];
			ny=y+walk[j][1];
			if(nx>=1&&ny>=1&&nx<=n&&ny<=m){
				if(ny==y-1&&ro[nx][ny-1]=='0') continue;
				if(ny==y+1&&ro[nx][y]=='0') continue;
				if(nx==x-1&&co[nx][y-1]=='0') continue;
				if(nx==x+1&&co[x][y-1]=='0') continue;
				if(c[nx][ny]==-1||(c[nx][ny]!=col&&l[nx][ny]<=lv)) answer++;
			}
		}
		cout<<answer<<endl;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
