#include<bits/stdc++.h>
using namespace std;
int T,n,m,q;
int a[5010][5010],b[5010][5010],c[5010][5010],h[5010][5010],lv[5010][5010],col,lvv,co,ans;
bool hb[5010][5010];
int read(){
	int xx=0,ff=1;char ch=getchar();
	while (!isdigit(ch)) {if (ch=='-') ff=-1; ch=getchar();}
	while (isdigit(ch)) {xx=(xx<<1)+(xx<<3)+ch-'0';ch=getchar();}
	return xx*ff;
}
void dfs(int x,int y,int zt,int fj){
	
	if (x>n||y>m||x<1||y<1||h[x][y]==co) return;
	if (lv[x][y]){
		if (hb[x][y]!=col&&lvv>=lv[x][y]) ans++;//cout<<'@'<<x<<' '<<y<<' '<<col<<' '<<hb[x][y]<<endl;
		h[x][y]=co;
		return; 
	}
//	cout<<x<<' '<<y<<' '<<zt<<' '<<fj<<endl;
	h[x][y]=co;
	++ans;
    for (int j=1; j<m; j++){
    //	cout<<'!'<<x<<' '<<j<<' '<<a[x][j]<<endl;
    	if (a[x][j]!=0) {
    		if (a[x][j]==1&&h[x][j+1]!=co&&zt==0) h[x][j+1]=co,++ans;//cout<<x<<' '<<j+1<<endl;
    		if (a[x][j]==2&&(fj==0||fj==1)&&(zt==2||zt==0)) dfs(x,j+1,2,1);
    		if (a[x][j]==3&&(zt==3||zt==0)) dfs(x,j+1,3,0);
		}
	}
	for (int j=2; j<=m; j++){
    	if (a[x][j-1]!=0) {
    		if (a[x][j-1]==1&&h[x][j-1]!=co&&zt==0) h[x][j-1]=co,++ans;//cout<<x<<' '<<j-1<<endl;
    		if (a[x][j-1]==2&&(fj==0||fj==1)&&(zt==2||zt==0)) dfs(x,j-1,2,1);
    		if (a[x][j-1]==3&&(zt==3||zt==0)) dfs(x,j-1,3,0);
		}
	}
	for (int i=1; i<n; i++){
    	if (b[i][y]!=0) {
    		if (b[i][y]==1&&h[i+1][y]!=co&&zt==0) h[i+1][y]=co,++ans;//cout<<i+1<<' '<<y<<endl;
    		if (b[i][y]==2&&(fj==0||fj==2)&&(zt==2||zt==0)) dfs(i+1,y,2,2);
    		if (b[i][y]==3&&(zt==3||zt==0)) dfs(i+1,y,3,0);
		}
	}
	for (int i=2; i<=n; i++){
    	if (b[i-1][y]!=0) {
    		if (b[i-1][y]==1&&h[i-1][y]!=co&&zt==0) h[i-1][y]=co,++ans;//cout<<i-1<<' '<<y<<endl;
    		if (b[i-1][y]==2&&(fj==0||fj==2)&&(zt==2||zt==0)) dfs(i-1,y,2,2);
    		if (b[i-1][y]==3&&(zt==3||zt==0)) dfs(i-1,y,3,0);
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    T=read();
    for (int i=1; i<=T; i++){
    	n=read(),m=read(),q=read();
    	for (int ii=1; ii<=n; ii++){
    		for (int jj=1; jj<m; jj++){
    			char ch=getchar();
    			while (!isdigit(ch)) ch=getchar();
    			a[ii][jj]=ch-'0';
    		//	cout<<'!'<<a[ii][jj]<<endl;
			}
		}
		for (int ii=1; ii<n; ii++){
    		for (int jj=1; jj<=m; jj++){
    			char ch=getchar();
    			while (!isdigit(ch)) ch=getchar();
    			b[ii][jj]=ch-'0';
			}
		}
		for (int ii=1; ii<=q; ii++){
			col=read(),lvv=read();
			int x=read(),y=read();
			++co;
			ans=-1;
			dfs(x,y,0,0);
			hb[x][y]=col,lv[x][y]=lvv;
			printf("%d\n",ans);
		}
	}
	return 0;
}
