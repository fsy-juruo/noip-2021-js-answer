#include<bits/stdc++.h>
using namespace std;
int read(){
	 int r=0,f=1;char ch=getchar();
	 while (!isdigit(ch)&&ch!='-') ch=getchar();
	 if (ch=='-') f=-1,ch=getchar();
	 while (isdigit(ch)) r=(r<<3)+(r<<1)+ch-'0',ch=getchar();
	 return r*f;
}
struct node{
	bool f;
	int col,lev;
}Q[5105][5105];
int T,n,m,q,ans1;
int a[6005][6005];
bool vis[6005],vis1[6005];
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool check1(int x,int y){
	if (x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
void dfs(int x,int y,int c,int l){
	vis[x*m+y]=1;
	for (int j=0;j<4;j++){
		int tx=x+dx[j],ty=y+dy[j];
		if (!check1(tx,ty)) continue;
		if (a[tx*m+ty][x*m+y]!=3) continue;
		if (vis[tx*m+ty]) continue;
		if (Q[tx][ty].f==0){
			if (!vis1[tx*m+ty]) vis1[tx*m+ty]=1,ans1++;
			dfs(tx,ty,c,l);
		}
		else {
			if (Q[tx][ty].col!=c&&Q[tx][ty].lev<=l&&!vis1[tx*m+ty]) vis1[tx*m+ty]=1,vis[tx*m+ty]=1,ans1++;
			continue;
		}
	}
}
void Clear(){
	memset(a,0,sizeof(a));
	for (int i=0;i<=5000;i++)
	for (int j=0;j<=5000;j++) Q[i][j].f=Q[i][j].col=Q[i][j].lev=0;
	return ;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
//	cout<<(sizeof(Q)+sizeof(a))/1024/1024<<endl;
	T=read();
	while (T--){
		n=read(),m=read(),q=read();
		Clear();
		if (n*m<=10000&&q<=2000){
			string st;
			for (int i=1;i<=n;i++) {
				cin>>st;
				for (int j=0;j<m-1;j++) a[(i-1)*m+j][(i-1)*m+j+1]=a[(i-1)*m+j+1][(i-1)*m+j]=st[j]-'0';
//				cout<<i-1<<' '<<j<<' '<<i-1<<' '<<j+1<<' '<<st[j]-'0'<<endl;
			}
			for (int i=1;i<=n-1;i++) {
				cin>>st;
				for (int j=0;j<m;j++) a[(i-1)*m+j][i*m+j]=a[i*m+j][(i-1)*m+j]=st[j]-'0';
//				,cout<<i-1<<' '<<j<<' '<<i<<' '<<j<<' '<<st[j]-'0'<<endl;
			}
			for (int i=1;i<=q;i++){
				int c=read(),l=read(),x=read(),y=read();x--,y--;
				Q[x][y].f=1;
				Q[x][y].col=c;
				Q[x][y].lev=l;
				int ans=0;memset(vis,0,sizeof(vis));vis[x*m+y]=1;memset(vis1,0,sizeof(vis1));vis1[x*m+y]=1;
				for (int j=0;j<4;j++){
					int tx=x+dx[j],ty=y+dy[j];
					if (!check1(tx,ty)) continue;
//					cout<<tx<<' '<<ty<<' '<<tx*m+ty<<' '<<x*m+y<<endl;
					if (a[tx*m+ty][x*m+y]!=1) continue;
//					cout<<tx<<' '<<ty<<endl;
					if (Q[tx][ty].f==0) vis1[tx*m+ty]=1,ans++;
					if (Q[tx][ty].f==1&&Q[tx][ty].col!=c&&Q[tx][ty].lev<=l) vis1[tx*m+ty]=1,ans++;
				}
//				cout<<ans<<endl;
				for (int j=0;j<4;j++){
					for (int k=1,tx=x+dx[j],ty=y+dy[j],lx=x,ly=y;check1(tx,ty);k++,lx=tx,ly=ty,tx+=dx[j],ty+=dy[j]){
						if (a[tx*m+ty][lx*m+ly]!=2) break;
						if (vis1[tx*m+ty]) continue;
						if (Q[tx][ty].f==0&&vis[tx*m+ty]==0) vis1[tx*m+ty]=1,ans++;
						if (Q[tx][ty].f==1){
							if (Q[tx][ty].col!=c&&Q[tx][ty].lev<=l) vis1[tx*m+ty]=1,ans++;
							break;
						}
					}
				}
//				cout<<ans<<endl;
				ans1=0;
				dfs(x,y,c,l);
				ans+=ans1;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}

