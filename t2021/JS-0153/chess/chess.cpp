#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template <typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
		x*=f;
	}
	template <typename T>inline void write(T x){
		if(x<0){putchar('-');x=-x;}
		if(x>9)write(x/10);
		putchar(x%10+'0');
	}
	template <typename T>inline void writeln(T x){
		write(x);putchar('\n');
	}
	template <typename T>inline void writesp(T x){
		write(x);putchar(' ');
	}
}
using namespace IO;
struct Info{
	int col,l; 
}c[2002]; 
int n,m,ans; 
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
string a[5002],b[5002]; 
int p[5001][5001]; 
void dfs1(int x,int y,int ccol,int cl){
	if(!p[x][y]){
		++ans;
		return;
	}
	int vis=p[x][y];
	if(ccol==c[vis].col||(ccol!=c[vis].col&&cl<c[vis].l))return;
	++ans;
}

void dfs2(int x,int y,int X,int Y,int ccol,int cl){
	if(p[x][y]){
		int vis=p[x][y];
		if(ccol==c[vis].col||(ccol!=c[vis].col&&cl<c[vis].l))return;
		++ans;
		return;
	}
	//cout<<x<<' '<<y<<endl;
	++ans;
	int tx=x+X;
	int ty=y+Y;
	if(tx<1||tx>n||ty<1||ty>m)return;
	if(!X){
		if(a[x][min(y,ty)-1]=='2')dfs2(tx,ty,X,Y,ccol,cl);
	}else{
		if(b[min(x,tx)][y-1]=='2')dfs2(tx,ty,X,Y,ccol,cl);
	}
} 

void dfs3(int x,int y,int ccol,int cl){
	//cout<<x<<' '<<y<<endl;
	if(p[x][y]){
		int vis=p[x][y];
		if(ccol==c[vis].col||(ccol!=c[vis].col&&cl<c[vis].l))return;
		++ans;
		return;
	}
	++ans;
	for(int i=0;i<4;++i){
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(tx<1||tx>n||ty<1||ty>m||p[tx][ty]==-1)continue;
		if(!dir[i][0]){
			if(a[x][min(y,ty)-1]!='3')continue;
		}else{
			if(b[min(x,tx)][y-1]!='3')continue;
		}
		p[tx][ty]=-1;
		dfs3(tx,ty,ccol,cl);
		p[tx][ty]=0;
	}
}

void jzx(int x,int y,int ccol,int cl){
	for(int i=0;i<4;++i){
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(tx<1||tx>n||ty<1||ty>m)continue;
		if(!dir[i][0]){
			switch(a[x][min(y,ty)-1]){
				case '0':{break;}
				case '1':{dfs1(tx,ty,ccol,cl);break;}
				case '2':{dfs2(tx,ty,dir[i][0],dir[i][1],ccol,cl);break;}
				case '3':{p[x][y]=-1;dfs3(tx,ty,ccol,cl);break;}
			}
		}else{
			switch(b[min(x,tx)][y-1]){
				case '0':{break;}
				case '1':{dfs1(tx,ty,ccol,cl);break;}
				case '2':{dfs2(tx,ty,dir[i][0],dir[i][1],ccol,cl);break;}
				case '3':{p[x][y]=-1;dfs3(tx,ty,ccol,cl);break;}
			}
		}
	}
}
void work(){
	int q;
	read(n);read(m);read(q);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<n;++i){
		cin>>b[i];
	}
	
	for(int i=1;i<=q;++i){
		int x,y;
		read(c[i].col);read(c[i].l);read(x);read(y);
		
		ans=0;
		jzx(x,y,c[i].col,c[i].l);
		p[x][y]=i;
		writeln(ans);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);

	int Q;
	read(Q);
	
	while(Q--){
		work();
	}
	return 0;
}

