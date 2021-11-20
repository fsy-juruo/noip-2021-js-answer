#include<bits/stdc++.h>
#define VNAME(x) (#x)
#define DE(x) cerr<<VNAME(x)<<":"<<x<<endl;
#define DEB(a,x)  cerr<<VNAME(a)<<"["<<x<<"]"<<a[x]<<endl;
#define fi first
#define se second
using namespace std;
template<typename Tp>
void read(Tp &num){
	num=0;
	Tp f=1;
	char c=getchar();
	while(!isdigit(c))   f=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))    num=num*10+(c^48),c=getchar();
	num*=f;
}
template<typename Tp,typename... etc>
void read(Tp &num,etc&... more){
	read(num);
	read(more...);
}
typedef pair<int,int> pa;
const int MAXN=3007;
const int dx[]={-1,+1,0,0},dy[]={0,0,+1,-1};
int T,n,m,q,sv[4][MAXN][MAXN],ans;
bitset<MAXN> nvis[MAXN],vis[MAXN];
pa mp[MAXN][MAXN];
inline bool ck(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void dfs(int nowx,int nowy,int tp,int dir,pa mi){
//	DE(nowx) DE(nowy) DE(tp) DE(dir) DE(mi.fi) DE(mi.se)
	if(mp[nowx][nowy].se){
		if(mp[nowx][nowy].fi==mi.fi||mp[nowx][nowy].se>mi.se)
		return;
		if(!vis[nowx][nowy]){
			++ans;
			vis[nowx][nowy]=1;
		}
		return;
	}
	if(!vis[nowx][nowy]){
		++ans;
		vis[nowx][nowy]=1;
	}
	if(tp==1){
		return;
	}
	if(tp==0){
		for(register int i=0;i<4;++i){
			int xx=nowx+dx[i],yy=nowy+dy[i];
			if(!ck(xx,yy))
			continue;
			if(sv[i][nowx][nowy]==1){
				dfs(xx,yy,1,0,mi);
			}
		}
	}
	if(tp==2||tp==0){
		if(dir==1||tp==0){
			for(register int i=0;i<2;++i){
				int xx=nowx+dx[i],yy=nowy+dy[i];
				if(!ck(xx,yy)||nvis[xx][yy])
				continue;
				if(sv[i][nowx][nowy]!=2)
				continue;
				nvis[xx][yy]=1;
				dfs(xx,yy,2,1,mi);
				nvis[xx][yy]=0;
			}
		}
		if(dir==2||tp==0){
			for(register int i=2;i<4;++i){
				int xx=nowx+dx[i],yy=nowy+dy[i];
				if(!ck(xx,yy)||nvis[xx][yy])
				continue;
				if(sv[i][nowx][nowy]!=2)
				continue;
				nvis[xx][yy]=1;
				dfs(xx,yy,2,2,mi);
				nvis[xx][yy]=0;
			}
		}
	}
	if(tp==3||tp==0){
		for(register int i=0;i<4;++i){
			int xx=nowx+dx[i],yy=nowy+dy[i];
			if(!ck(xx,yy)||nvis[xx][yy])
			continue;
			if(sv[i][nowx][nowy]==3){
				nvis[xx][yy]=1;
				dfs(xx,yy,3,0,mi);
				nvis[xx][yy]=0;
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while(T--){
		read(n,m,q);
		for(register int i=1;i<=n;++i){
			for(register int j=1;j<=m;++j){
				mp[i][j].fi=mp[i][j].se=0;
				for(register int k=0;k<4;++k){
					sv[k][i][j]=0;
				}
			}
		}
		for(register int i=1;i<=n;++i){
			for(register int j=1;j<=m-1;++j){
				char c=getchar();
				while(isspace(c))
				c=getchar();
				sv[2][i][j]=sv[3][i][j+1]=(c^48);
			}
		}
		for(register int i=1;i<=n-1;++i){
			for(register int j=1;j<=m;++j){
				char c=getchar();
				while(isspace(c))
				c=getchar();
				sv[1][i][j]=sv[0][i+1][j]=(c^48);
			}
		}
		for(register int i=1;i<=q;++i){
			int x,y;
			pa t;
			read(t.fi,t.se,x,y);
			for(register int j=1;j<=n;++j){
				vis[j].reset();
			}
			ans=0;
			nvis[x][y]=1;
			dfs(x,y,0,0,t);
			nvis[x][y]=0;
			mp[x][y]=t;
			printf("%d\n",ans-1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

