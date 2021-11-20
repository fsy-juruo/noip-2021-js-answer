#include<bits/stdc++.h>
#define next Cry_For_theMoon
#define lc(x) (x<<1)
#define rc(x) ((x<<1)|1)
#define mp make_pair
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
#define fr first
#define se second
#define pb push_back
#define is insert
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10,nxtx[4]={-1,1,0,0},nxty[4]={0,0,-1,1};
int T;
int n,m,q,col[MAXN],lv[MAXN],x[MAXN],y[MAXN];
pi cs[MAXN];
int vis[MAXN],flag;
char ch;
int e[MAXN][4]; //up down left right
queue<int>qu;
int h(int i,int j){return (i-1)*m+j;}
pi r(int x){
	return mp((x-1)/m+1,(x-1)%m+1);	
}
int won(int x,int y){
	if(cs[y].fr==-1)return 1;
	if(cs[y].fr==cs[x].fr)return 0;
	return cs[y].se<=cs[x].se;
}
void task1(){
	rep(i,1,q){
		rep(j,1,n*m)vis[j]=0;
		cs[h(x[i],y[i])]=mp(col[i],lv[i]);
		rep(j,0,3){
			if(e[h(x[i],y[i])][j]!=1)continue;
			int kx=x[i]+nxtx[j],ky=y[i]+nxty[j];
			if(won(h(x[i],y[i]),h(kx,ky)))vis[h(kx,ky)]=1;
		}
		rep(j,0,3){
			int u=x[i],v=y[i];
			while(1){
				if(e[h(u,v)][j]!=2)break;
				u=u+nxtx[j],v=v+nxty[j];
				if(!won(h(x[i],y[i]),h(u,v)))break;
				vis[h(u,v)]=1;
				if(cs[h(u,v)].fr!=-1)break;
			}
		}
		qu.push(h(x[i],y[i]));vis[h(x[i],y[i])]=2;
		while(qu.size()){
			int u=qu.front();qu.pop();
			rep(j,0,3){
				if(e[u][j]!=3)continue;
				int a=r(u).fr,b=r(u).se;
				int c=a+nxtx[j],d=b+nxty[j];
				if(vis[h(c,d)]==2)continue;
				if(!won(h(x[i],y[i]),h(c,d)))continue;
				vis[h(c,d)]=2;
				if(cs[h(c,d)].fr==-1){
					qu.push(h(c,d));
				}
			}
		}
		int cnt=0;
		rep(j,1,n*m)if(vis[j] && j!=h(x[i],y[i]))cnt++;
		printf("%d\n",cnt);
	}
}
void task2(){
	rep(i,1,q){
		int cnt=0;
		cs[h(x[i],y[i])]=mp(col[i],lv[i]);
		rep(j,0,3){
			if(!e[h(x[i],y[i])][j])continue;
			int kx=x[i]+nxtx[j],ky=y[i]+nxty[j];
			if(won(h(x[i],y[i]),h(kx,ky))){
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
}
void solve(){
	scanf("%d%d%d",&n,&m,&q);
	flag=0;
	rep(i,1,n*m)rep(j,0,3)e[i][j]=0,cs[i]=mp(-1,0);
	rep(i,1,n)rep(j,1,m-1){
		scanf(" %c",&ch);
		if(ch=='0')continue;
		if(ch!='1')flag++;
		e[h(i,j)][3]=ch-'0';
		e[h(i,j+1)][2]=ch-'0';
	}
	rep(i,1,n-1)rep(j,1,m){
		scanf(" %c",&ch);
		if(ch=='0')continue;
		if(ch!='1')flag++;
		e[h(i,j)][1]=ch-'0';
		e[h(i+1,j)][0]=ch-'0';
	}
	rep(i,1,q){
		scanf("%d%d%d%d",&col[i],&lv[i],&x[i],&y[i]);
	}
	if(n*m<=5000 && q<=2000){
		//only 24pts /fn
		task1();
		return;
	}
	if(flag==0){
		//only 8pts /fn
		task2();
		return;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		solve();
	}
	
	return 0;
}
/*
1
2 2 4
1
1
11
0 1 1 1
0 2 1 2
0 3 2 1
0 4 2 2
*/
