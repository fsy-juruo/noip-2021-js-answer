#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-9;
typedef long long ll;
int n,m,qq;
string s1[200005],s2[200005];
char buf[200005];
string read(){scanf("%s",buf);return buf;}
int lvl[5005][5005],col[5005][5005];
bool vis[5005][5005];
char opt[5005][5005][4];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int q[10005],b,e;
void bfsolve(){
	memset(opt,0,sizeof opt);
	memset(col,-1,sizeof col);
	memset(lvl,-1,sizeof lvl);
	for(int i=1;i<=n;i++)for(int j=1;j<m;j++){
		opt[i][j][2]=opt[i][j+1][3]=s1[i][j]-'0';
	}
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++){
		opt[i][j][0]=opt[i+1][j][1]=s2[i][j]-'0';
	}
	while(qq--){
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)vis[i][j]=0;
		int c,l,x,y;scanf("%d%d%d%d",&c,&l,&x,&y);vis[x][y]=1;
		//opt==3
		b=e=0;q[e++]=x;q[e++]=y;
		while(b<e){
			int cx=q[b++],cy=q[b++];
			if(lvl[cx][cy]!=-1)continue;
//			cerr<<cx<<" "<<cy<<endl;
			for(int t=0;t<4;t++){
				int nx=cx+dx[t],ny=cy+dy[t];
				if(opt[cx][cy][t]==3&&!vis[cx+dx[t]][cy+dy[t]])if(lvl[nx][ny]==-1||(lvl[nx][ny]<=l&&col[nx][ny]!=c)){
					vis[cx+dx[t]][cy+dy[t]]=1;q[e++]=cx+dx[t];q[e++]=cy+dy[t];
				}
			}
		}
		//opt==2
		for(int t=0;t<4;t++){
			int cx=x,cy=y;
//			cerr<<cx<<" "<<cy<<" "<<(int)opt[cx][cy][t]<<endl;
			while(opt[cx][cy][t]==2){
				cx+=dx[t];cy+=dy[t];
				if(lvl[cx][cy]==-1||(lvl[cx][cy]<=l&&col[cx][cy]!=c))vis[cx][cy]=1;
				if(lvl[cx][cy]!=-1)break;
			}
		}
		//opt==1
		for(int t=0;t<4;t++){
			int nx=x+dx[t],ny=y+dy[t];
			if(opt[x][y][t]==1)if(lvl[nx][ny]==-1||(lvl[nx][ny]<=l&&col[nx][ny]!=c))vis[x+dx[t]][y+dy[t]]=1;
		}
		lvl[x][y]=l;col[x][y]=c;int ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(vis[i][j]&&(i!=x||j!=y))ans++;
		printf("%d\n",ans);
	}
}
int get_opt(int x,int y,int tp){
	if(tp==0)return s2[x][y]-'0';
	if(tp==1)return s2[x-1][y]-'0';
	if(tp==2)return s1[x][y]-'0';
	if(tp==3)return s1[x][y-1]-'0';
}
void subtask1(){
	vector<vector<int> >col(n+1,vector<int>(m+1,-1));vector<vector<int> >lvl=col;
	while(qq--){
		int c,l,x,y;scanf("%d%d%d%d",&c,&l,&x,&y);
		int ans=0;
		for(int t=0;t<4;t++){
			int nx=x+dx[t],ny=y+dy[t];
			if(get_opt(x,y,t)==1)if(lvl[nx][ny]==-1||(lvl[nx][ny]<=l&&col[nx][ny]!=c))ans++;
		}
		lvl[x][y]=l;col[x][y]=c;
		printf("%d\n",ans);
	}
}
set<pair<int,pair<int,int> > >rr[200005],cc[200005];
void subtask2(){
	for(int i=1;i<=n;i++)rr[i].clear();
	for(int i=1;i<=m;i++)cc[i].clear();
	vector<vector<int> >col(n+1,vector<int>(m+1,-1));vector<vector<int> >lvl=col;
	vector<vector<int> >nxt[4];
	for(int i=0;i<4;i++){
		nxt[i].resize(n+1);
		for(int j=1;j<=n;j++)nxt[i][j].resize(j+1,-1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			nxt[1][i][j]=i>1&&get_opt(i,j,1)==2?nxt[1][i-1][j]:i;
			nxt[3][i][j]=j>1&&get_opt(i,j,3)==2?nxt[3][i][j-1]:j;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			nxt[0][i][j]=i<n&&get_opt(i,j,0)==2?nxt[0][i+1][j]:i;
			nxt[2][i][j]=j<m&&get_opt(i,j,2)==2?nxt[2][i][j+1]:j;
		}
	}
	while(qq--){
		int c,l,x,y;scanf("%d%d%d%d",&c,&l,&x,&y);
		int ans=0;
		for(int t=0;t<4;t++){
			int nx=x+dx[t],ny=y+dy[t];
//			cerr<<x<<" "<<y<<" "<<t<<" "<<get_opt(x,y,t)<<endl;
			if(get_opt(x,y,t)==1)if(lvl[nx][ny]==-1||(lvl[nx][ny]<=l&&col[nx][ny]!=c))ans++;
			if(get_opt(x,y,t)==2){
				int max_len=t<2?abs(nxt[t][x][y]-x):abs(nxt[t][x][y]-y);
//				cerr<<max_len<<endl;
				if(t==2){
					auto itr=rr[x].lower_bound(make_pair(y,make_pair(0,0)));
					if(itr!=rr[x].end()){
						max_len=min(max_len,itr->first-y-1+(itr->second.second<=l&&itr->second.first!=c));
					}
				}
				if(t==3){
					auto itr=rr[x].lower_bound(make_pair(y,make_pair(0,0)));
					if(itr!=rr[x].begin()){
						itr--;
//						cerr<<"show: "<<x<<" "<<itr->first<<endl;
						max_len=min(max_len,y-itr->first-1+(itr->second.second<=l&&itr->second.first!=c));
					}
				}
				if(t==0){
					auto itr=cc[y].lower_bound(make_pair(x,make_pair(0,0)));
					if(itr!=cc[y].end()){
						max_len=min(max_len,itr->first-x-1+(itr->second.second<=l&&itr->second.first!=c));
					}
				}
				if(t==1){
					auto itr=cc[y].lower_bound(make_pair(x,make_pair(0,0)));
					if(itr!=cc[y].begin()){
						itr--;max_len=min(max_len,x-itr->first-1+(itr->second.second<=l&&itr->second.first!=c));
					}
				}
				ans+=max_len;
			}
		}
		rr[x].insert(make_pair(y,make_pair(c,l)));
		cc[y].insert(make_pair(x,make_pair(c,l)));
		lvl[x][y]=l;col[x][y]=c;
		printf("%d\n",ans);
	}
}
bool occ[5];
void solve(){
	scanf("%d%d%d",&n,&m,&qq);
	for(int i=1;i<=n;i++)s1[i]=" "+read()+"0";
	for(int i=1;i<n;i++)s2[i]=" "+read();
	s2[n]=" ";
	for(int i=1;i<=m;i++)s2[n].push_back('0');
	memset(occ,0,sizeof occ);
	for(int i=1;i<=n;i++)for(int j=1;j<m;j++)occ[s1[i][j]-'0']=1;
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)occ[s2[i][j]-'0']=1;
	if(n*m<=5000){
		bfsolve();
		return;
	}
	if(!occ[2]&&!occ[3]){
		subtask1();
		return;
	}
	if(!occ[3]){
		subtask2();
		return;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout); 
	int T;scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
