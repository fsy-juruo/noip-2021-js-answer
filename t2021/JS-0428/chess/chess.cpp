#include<bits/stdc++.h>
using namespace std;
struct Piece{
	int col,lv,pos;
	void Reset(int _pos){
		col=-1;
		lv=-1;
		pos=_pos;
	}
	void Set(Piece A){
		col=A.col;
		lv=A.lv;
	}
}a[100009];
int t,n,m,q;
string G[2][100009];
int ln[4][200009];
Piece chked[200009];
int d[4]={-m,-1,1,m};
bool vis[200009],cango[200009];int cnt=0;
void dfs(int pos,int col,int lv,int opt,int dir){
	cango[pos]=1;
	if(opt==1||chked[pos].lv!=-1)return ;
	vis[pos]=1;
	for(int p=0;p<4;p++)
		if(ln[p][pos]==opt&&!vis[pos+d[p]]&&chked[pos+d[p]].col!=col&&chked[pos+d[p]].lv<=lv&&(opt==2&&p==dir||opt==3)){
			int npos=pos+d[p];
			dfs(npos,col,lv,opt,dir);
		}
	vis[pos]=0;
}
void solve1(){
	for(int i=0;i<q;i++){
		int res=0;
		for(int p=0;p<4;p++)
			if(ln[p][a[i].pos]==1&&chked[a[i].pos+d[p]].col!=a[i].col&&chked[a[i].pos+d[p]].lv<=a[i].lv)
				res++;
		printf("%d\n",res);
		chked[a[i].pos].Set(a[i]);
	}
}
void solve2(){
	for(int i=0;i<q;i++){
		vis[a[i].pos]=1;
		cnt=0;
		for(int p=0;p<4;p++)
			if(ln[p][a[i].pos]>0&&chked[a[i].pos+d[p]].col!=a[i].col&&chked[a[i].pos+d[p]].lv<=a[i].lv)
				dfs(a[i].pos+d[p],a[i].col,a[i].lv,ln[p][a[i].pos],p);
		vis[a[i].pos]=0;
		chked[a[i].pos].Set(a[i]);
		for(int p=0;p<=5000;p++){cnt+=cango[p];cango[p]=0;}
		printf("%d\n",cnt);
	}
}
void solve(){
	bool Roadcnt[4]={0};
	for(int i=0;i<200009;i++)chked[i].Reset(i);
	memset(ln,-1,sizeof(ln));
	scanf("%d%d%d",&n,&m,&q);
	d[0]=-m;d[3]=m;
	for(int i=0;i<n;i++){
		cin>>G[0][i];
		for(int j=0;j<m-1;j++){
			Roadcnt[G[0][i][j]-'0']=1;
			ln[2][i*m+j]=G[0][i][j]-'0';
			ln[1][i*m+j+1]=G[0][i][j]-'0';
		}
	}
	for(int i=0;i<n-1;i++){
		cin>>G[1][i];
		for(int j=0;j<m;j++){
			Roadcnt[G[1][i][j]-'0']=1;
			ln[3][i*m+j]=G[1][i][j]-'0';
			ln[0][i*m+j+m]=G[1][i][j]-'0';
		}
	}
	for(int i=0;i<q;i++){
		int X,Y;
		scanf("%d%d%d%d",&a[i].col,&a[i].lv,&X,&Y);X--;Y--;
		a[i].pos=X*m+Y;
	}
	if(!Roadcnt[2]&&!Roadcnt[3])solve1();//8pts
	else if(n*m<=5000&&q<=2000)solve2();//24pts
//	else if(!Roadcnt[3])solve3();//12pts (unfinished)
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
