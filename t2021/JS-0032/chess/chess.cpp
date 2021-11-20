#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
int T,n,m,q,c,l,tx,ty;
int col[200005],lv[200005];
bool cr[5005],vis[5005];
std::string tyl[200005];
std::string tyc[200005];
int read()
{
	int res=0,pn=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') pn=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<1)+(res<<3)+int(c-48);
		c=getchar();
	}
	return res*pn;
}
std::string reads()
{
	std::string res="";
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res+=c;
		c=getchar();
	}
	return res;
}
void write(int px)
{
	if(px<0){
		putchar('-');
		write(-px);
	}
	else if(px==0){
		return;
	}
	else{
		write(px/10);
		putchar((char)('0'+px%10));
	}
}
void outp(int px){
	if(px==0){
		putchar('0');
	}
	else{
		write(px);
	}
}
inline int coor(int x,int y){
	return (x-1)*m+(y-1);
}
void dfs(int x,int y){
	if(x!=1&&(!vis[coor(x-1,y)])&&tyc[x-1][y-1]=='3'&&col[coor(x-1,y)]!=c&&lv[coor(x-1,y)]<=l){
		cr[coor(x-1,y)]=1,vis[coor(x-1,y)]=1;
		if(col[coor(x-1,y)]==-1) dfs(x-1,y);
	} 
	if(x!=n&&(!vis[coor(x+1,y)])&&tyc[x][y-1]=='3'&&col[coor(x+1,y)]!=c&&lv[coor(x+1,y)]<=l){
		cr[coor(x+1,y)]=1,vis[coor(x+1,y)]=1;
		if(col[coor(x+1,y)]==-1) dfs(x+1,y);
	} 
	if(y!=1&&(!vis[coor(x,y-1)])&&tyl[x][y-2]=='3'&&col[coor(x,y-1)]!=c&&lv[coor(x,y-1)]<=l){
		cr[coor(x,y-1)]=1,vis[coor(x,y-1)]=1;
		if(col[coor(x,y-1)]==-1) dfs(x,y-1);
	} 
	if(y!=m&&(!vis[coor(x,y+1)])&&tyl[x][y-1]=='3'&&col[coor(x,y+1)]!=c&&lv[coor(x,y+1)]<=l){
		cr[coor(x,y+1)]=1,vis[coor(x,y+1)]=1;
		if(col[coor(x,y+1)]==-1) dfs(x,y+1);
	} 
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;++i){
			tyl[i]=reads();
		}
		for(int i=1;i<n;++i){
			tyc[i]=reads();
		}
		if(n*m>5001||q>2001){
			memset(col,-1,sizeof(col));
			memset(lv,0,sizeof(lv));
			for(int i=1,c,l,tx,ty;i<=q;++i){
				c=read(),l=read(),tx=read(),ty=read();
				int res=0;
				if(tx!=1&&tyc[tx-1][ty-1]=='1'&&col[coor(tx-1,ty)]!=c&&lv[coor(tx-1,ty)]<=l) ++res;
				if(tx!=n&&tyc[tx][ty-1]=='1'&&col[coor(tx+1,ty)]!=c&&lv[coor(tx+1,ty)]<=l) ++res;
				if(ty!=1&&tyl[tx][ty-2]=='1'&&col[coor(tx,ty-1)]!=c&&lv[coor(tx,ty-1)]<=l) ++res;
				if(ty!=m&&tyl[tx][ty-1]=='1'&&col[coor(tx,ty+1)]!=c&&lv[coor(tx,ty+1)]<=l) ++res;
				outp(res);
				putchar('\n');
				col[coor(tx,ty)]=c;
				lv[coor(tx,ty)]=l;
			}
		}
		else{
			memset(col,-1,sizeof(col));
			memset(lv,0,sizeof(lv));
			for(int i=1;i<=q;++i){
				memset(cr,0,sizeof(cr));
				memset(vis,0,sizeof(vis));
				c=read(),l=read(),tx=read(),ty=read();
				int res=0;
				if(tx!=1&&tyc[tx-1][ty-1]=='1'&&col[coor(tx-1,ty)]!=c&&lv[coor(tx-1,ty)]<=l) cr[coor(tx-1,ty)]=1;
				if(tx!=n&&tyc[tx][ty-1]=='1'&&col[coor(tx+1,ty)]!=c&&lv[coor(tx+1,ty)]<=l) cr[coor(tx+1,ty)]=1;
				if(ty!=1&&tyl[tx][ty-2]=='1'&&col[coor(tx,ty-1)]!=c&&lv[coor(tx,ty-1)]<=l) cr[coor(tx,ty-1)]=1;
				if(ty!=m&&tyl[tx][ty-1]=='1'&&col[coor(tx,ty+1)]!=c&&lv[coor(tx,ty+1)]<=l) cr[coor(tx,ty+1)]=1;
				
				for(int j=tx;j>=2;--j){
					if(tyc[j-1][ty-1]=='2'&&col[coor(j-1,ty)]!=c&&lv[coor(j-1,ty)]<=l) cr[coor(j-1,ty)]=1;
					if(col[coor(j-1,ty)]!=-1||tyc[j-1][ty-1]!='2') break;
				}
				for(int j=tx;j<n;++j){
					if(tyc[j][ty-1]=='2'&&col[coor(j+1,ty)]!=c&&lv[coor(j+1,ty)]<=l) cr[coor(j+1,ty)]=1;
					if(col[coor(j+1,ty)]!=-1||tyc[j][ty-1]!='2') break;
				}
				for(int j=ty;j>=2;--j){
					if(tyl[tx][j-2]=='2'&&col[coor(tx,j-1)]!=c&&lv[coor(tx,j-1)]<=l) cr[coor(tx,j-1)]=1;
					if(col[coor(tx,j-1)]!=-1||tyl[tx][j-2]!='2') break;
				}
				for(int j=ty;j<m;++j){
					if(tyl[tx][j-1]=='2'&&col[coor(tx,j+1)]!=c&&lv[coor(tx,j+1)]<=l) cr[coor(tx,j+1)]=1;
					if(col[coor(tx,j+1)]!=-1||tyl[tx][j-1]!='2') break;
				}
				
				vis[coor(tx,ty)]=1;
				dfs(tx,ty);
				
//				for(int j=1;j<=n;++j){
//					for(int k=1;k<=m;++k){
//						std::cout<<cr[coor(j,k)]<<" ";
//					}
//					std::cout<<"\n";
//				}
				for(int j=0;j<n*m;++j){
					if(cr[j]) res++;
				}
				
				outp(res);
				putchar('\n');
				col[coor(tx,ty)]=c;
				lv[coor(tx,ty)]=l;
			}
		}
	}
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
