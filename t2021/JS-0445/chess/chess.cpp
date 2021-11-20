#include <bits/stdc++.h>
using namespace std;

const int N=2e3+2;

inline int read() {
	char ch=getchar(); int x=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-f; ch=getchar();}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}

inline void write(int x) {
	if(x<0) {putchar('-'); write(-x); return;}
	if(x<10) {putchar(x%10+'0'); return;}
	write(x/10); putchar(x%10+'0');
}

struct node {
	int lv,col;
} a[N][N];

int T,n,m,q,ans=0;
char L[N][N],R[N][N],U[N][N],D[N][N];
char crj[N];

bool h[N][N];

inline void dfs(register int x,register int y,register int col,register int lv,register bool flag) {
	if(flag) {
		if(h[x][y] || a[x][y].col == col || (a[x][y].col != col && a[x][y].lv > lv)) return;
		if(a[x][y].col != col && a[x][y].col != -1) {ans++; h[x][y]=1; return;}
	}
//	printf("SEARCHING : %d %d\n",x,y);
	ans+=flag; h[x][y]=flag;
	if(L[x][y]=='3') dfs(x,y-1,col,lv,1);
	if(R[x][y]=='3') dfs(x,y+1,col,lv,1);
	if(U[x][y]=='3') dfs(x-1,y,col,lv,1);
	if(D[x][y]=='3') dfs(x+1,y,col,lv,1);
}

int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--) {
		n=read(),m=read(),q=read();
		for(register int i=1;i<=n;i=-~i)
		for(register int j=1;j<=m;j=-~j)
			L[i][j] = R[i][j] = U[i][j] = D[i][j] = ' ' , a[i][j].lv = 0 , a[i][j].col = -1;
	
		bool three=0,two=0;
	
		for(register int i=1;i<=n;i=-~i)
		for(register int j=1;j<m;j=-~j) {
			char c; cin>>c;
			if(c=='3' && !three) three=1;
			if(c=='2' && !two) two=1;
			R[i][j]=L[i][j+1]=c;
		}
		for(register int i=1;i<n;i=-~i)
		for(register int j=1;j<=m;j=-~j) {
			char c; cin>>c;
			if(c=='3' && !three) three=1;
			if(c=='2' && !two) two=1;
			D[i][j]=U[i+1][j]=c;
		}
		
	/*	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++) printf("%d %d : %d %d %d %d\n",i,j,L[i][j]-'0',R[i][j]-'0',D[i][j]-'0',U[i][j]-'0');
		puts("");*/
		
		while(q--) {
			int lv,col,x,y; ans=0;
			col=read(); lv=read(); x=read(); y=read();
			
			// 3
			if(three) {
				memset(h,0,sizeof(h));
				dfs(x,y,col,lv,0);
			}
			
//			printf("%d\n",ans);
			
			// 1
			if (L[x][y]=='1' && (a[x][y-1].col != col && a[x][y-1].lv <= lv) && !h[x][y-1]) ans=-~ans , h[x][y-1] = 1;
			if (R[x][y]=='1' && (a[x][y+1].col != col && a[x][y+1].lv <= lv) && !h[x][y+1]) ans=-~ans , h[x][y+1] = 1;
			if (U[x][y]=='1' && (a[x-1][y].col != col && a[x-1][y].lv <= lv) && !h[x-1][y]) ans=-~ans , h[x-1][y] = 1;
			if (D[x][y]=='1' && (a[x+1][y].col != col && a[x+1][y].lv <= lv) && !h[x+1][y]) ans=-~ans , h[x+1][y] = 1;
//			printf("%d\n",ans);
			
			// 2
			if(two) {
				if(U[x][y]=='2') {
					for(register int i=x-1;i>=1;i--) {
						if(D[i][y]!='2') break;
						if(a[i][y].col == col || (a[i][y].col != col && a[i][y].lv > lv)) break;
						if(!h[i][y]) ans=-~ans , h[i][y] = 1;
						if(a[i][y].col != col && a[i][y].col != -1) break;
					}
				}
				if(D[x][y]=='2') {
					for(register int i=x+1;i<=n;i=-~i) {
						if(U[i][y]!='2') break;
						if(a[i][y].col == col || (a[i][y].col != col && a[i][y].lv > lv)) break;
						if(!h[i][y]) ans=-~ans , h[i][y] = 1;
						if(a[i][y].col != col && a[i][y].col != -1) break;
					}
				}
				if(L[x][y]=='2') {
					for(register int j=y-1;j>=1;j--) {
						if(R[x][j]!='2') break;
						if(a[x][j].col == col || (a[x][j].col != col && a[x][j].lv > lv)) break;
						if(!h[x][j]) ans=-~ans , h[x][j] = 1;
						if(a[x][j].col != col && a[x][j].col != -1) break;
					}
				}
				if(R[x][y]=='2') {
					for(register int j=y+1;j<=m;j=-~j) {
						if(L[x][j]!='2') break;
						if(a[x][j].col == col || (a[x][j].col != col && a[x][j].lv > lv)) break;
						if(!h[x][j]) ans=-~ans , h[x][j] = 1;
						if(a[x][j].col != col && a[x][j].col != -1) break;
					}
				}
			}
			
//			printf("%d\n",ans);
//			printf("LASTANS : %d\n",ans-h[x][y]);
			
			write(ans - h[x][y]); putchar('\n');
			a[x][y].col = col; a[x][y].lv = lv;
		}
	}
	return 0;
}

