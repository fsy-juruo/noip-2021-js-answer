#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
bool Mbe;
//func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func_func
namespace fastio{
//char buf_[1<<23],*st_=buf_,*ed_=buf_,wbuf_[1<<23],*wed_=wbuf_; 
//#define getchar() (st_==ed_&&(ed_=(st_=buf_)+fread(buf_,1,1<<22,stdin),st_==ed_)?EOF:*st_++) 
//#define putchar(x) (*wed_++=(x))
void putchar_final(){
	#ifdef putchar
	fwrite(wbuf_,1,wed_-wbuf_,stdout);
	wed_=wbuf_;
	#endif
}
void read(int &x){
	x=0;char c=getchar();bool ne=false;
	while(!isdigit(c))ne|=c=='-',c=getchar();
	while(isdigit(c))x=10*x+(c^48),c=getchar(); 
	if(ne)x=-x;
}
void prt(int x){
	x<0&&(putchar('-'),x=-x);
	x>9&&(prt(x/10),0);
	putchar(x%10^48);
}
}using fastio::putchar_final;using fastio::read;using fastio::prt;
const int N=2e5+10;
int n,m,qu;
vector<vector<int> > o1,o2,C,L,ok,vis,lft,rit,up,dwn;
char str[N];
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0}; 
pair<int,int> q[N];int head,tail;
bool eat(int x,int y,int col,int lv){
	return C[x][y]?col!=C[x][y]&&lv>=L[x][y]:1;
}
set<int> st1[N],st2[N];
void mian(){
	read(n),read(m),read(qu);
	o1.clear(),o2.clear(),C.clear(),L.clear();
	o1.resize(n+1,vector<int>(m,0)),o2.resize(n,vector<int>(m+1,0));
	C.resize(n+1,vector<int>(m+1,0)),L.resize(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<m;j++)o1[i][j]=str[j]^48;
	}
	for(int i=1;i<n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)o2[i][j]=str[j]^48;
	}
	if(n*m<=10000&&qu<=2000){
		while(qu--){
			int col,lv,x,y;
			read(col),read(lv),read(x),read(y);
			col++;
			ok.clear(),ok.resize(n+1,vector<int>(m+1,0));
			if(y>1)ok[x][y-1]=o1[x][y-1]==1&&eat(x,y-1,col,lv);if(y<m)ok[x][y+1]=o1[x][y]==1&&eat(x,y+1,col,lv);
			if(x>1)ok[x-1][y]=o2[x-1][y]==1&&eat(x-1,y,col,lv);if(x<n)ok[x+1][y]=o2[x][y]==1&&eat(x+1,y,col,lv);
			for(int i=y-1;i>=1&&o1[x][i]==2;i--){if(C[x][i]){ok[x][i]|=eat(x,i,col,lv);break;}ok[x][i]=true;}
			for(int i=y+1;i<=m&&o1[x][i-1]==2;i++){if(C[x][i]){ok[x][i]|=eat(x,i,col,lv);break;}ok[x][i]=true;}
			for(int i=x-1;i>=1&&o2[i][y]==2;i--){if(C[i][y]){ok[i][y]|=eat(i,y,col,lv);break;}ok[i][y]=true;}
			for(int i=x+1;i<=n&&o2[i-1][y]==2;i++){if(C[i][y]){ok[i][y]|=eat(i,y,col,lv);break;}ok[i][y]=true;}
			head=tail=0;
			q[tail++]=mp(x,y);
			vis.clear(),vis.resize(n+1,vector<int>(m+1,0));
			vis[x][y]=true;
			while(head<tail){
				int xn=q[head].X,yn=q[head].Y;head++;
				ok[xn][yn]|=eat(xn,yn,col,lv);
				if(!C[xn][yn]){
					if(yn>1&&o1[xn][yn-1]==3&&!vis[xn][yn-1])q[tail++]=mp(xn,yn-1),vis[xn][yn-1]=true;
					if(yn<m&&o1[xn][yn]==3&&!vis[xn][yn+1])q[tail++]=mp(xn,yn+1),vis[xn][yn+1]=true;
					if(xn>1&&o2[xn-1][yn]==3&&!vis[xn-1][yn])q[tail++]=mp(xn-1,yn),vis[xn-1][yn]=true;
					if(xn<n&&o2[xn][yn]==3&&!vis[xn+1][yn])q[tail++]=mp(xn+1,yn),vis[xn+1][yn]=true;
				}
			}
			int ans=-1;
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans+=ok[i][j]/*,cout<<ok[i][j]<<" \n"[j==m]*/;
			prt(ans),puts("");
			C[x][y]=col,L[x][y]=lv;
		}
	}
	else{
		while(qu--){
			up.clear(),dwn.clear(),lft.clear(),rit.clear();
			up.resize(n+1,vector<int>(m+1,0));
			dwn.resize(n+1,vector<int>(m+1,0));
			lft.resize(n+1,vector<int>(m+1,0));
			rit.resize(n+1,vector<int>(m+1,0));
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)up[i][j]=i>1&&o2[i-1][j]==2?up[i-1][j]:i;
			for(int i=n;i;i--)for(int j=1;j<=m;j++)dwn[i][j]=i<n&&o2[i][j]==2?dwn[i+1][j]:i;
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)lft[i][j]=j>1&&o1[i][j-1]==2?lft[i][j-1]:j;
			for(int i=1;i<=n;i++)for(int j=m;j;j--)rit[i][j]=j<m&&o1[i][j]==2?rit[i][j+1]:j;
			for(int i=1;i<=n;i++)st1[i].insert(1),st1[i].insert(m); 
			for(int i=1;i<=m;i++)st2[i].insert(1),st2[i].insert(n); 
			while(qu--){
				int col,lv,x,y;
				read(col),read(lv),read(x),read(y);
				col++;
				set<int>::iterator itr=st1[x].lower_bound(y),jtr=st2[y].lower_bound(x),ktr=itr--,otr=jtr--;
				int l=max(lft[x][y],*itr),r=min(rit[x][y],*ktr),u=max(up[x][y],*jtr),d=min(dwn[x][y],*otr);
				if(!eat(x,l,col,lv))l++;if(!eat(x,r,col,lv))r--;if(!eat(u,y,col,lv))u++;if(!eat(d,y,col,lv))d--;
				prt(r-l+d-u),puts("");
				st1[x].insert(y),st2[y].insert(x);
				C[x][y]=col,L[x][y]=lv;
			}
		}
	}
}
//main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main_main
bool Med;
signed main(){
	fprintf(stderr,"size: %.3lfMB\n",1.*(&Mbe-&Med)/(1<<20));
	freopen("chess.in","r",stdin);freopen("chess.out","w",stdout);
	int t;
	read(t);
	while(t--)mian();
	return putchar_final(),0;
}
