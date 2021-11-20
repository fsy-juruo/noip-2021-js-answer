#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define inf 0x3f3f3f3f
#define djq 998244353
inline void file(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
inline int read(){
	int ret=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
int _,n,m,q,a[5005][5005][2];
int lv,col,x,y;
bool vis[5005][4];
char s1[5005][5005],s2[5005][5005];
inline int id(int x,int y){
	return (x-1)*m+y;
}
void dfs(int x,int y,int ___,int __){
	if(vis[id(x,y)]) return;
	if(a[x][y][0]){
		if(a[x][y][0]==___||a[x][y][1]>__) return;
	}
	vis[id(x,y)][2]=1;
	if(a[x][y][0]) return;
	if(s1[x][y]=='3'&&y<m) vis[id(x,y+1)][2]=1,dfs(x,y+1,___,__);
	if(s1[x][y-1]=='3'&&y>1) vis[id(x,y-1)][2]=1,dfs(x,y-1,___,__);
	if(s2[x][y]=='3'&&x<n) vis[id(x+1,y)][2]=1,dfs(x+1,y,___,__);
	if(s2[x-1][y]=='3'&&x>1) vis[id(x-1,y)][2]=1,dfs(x-1,y,___,__);
}
signed main(){
	//system("fc number4.out number4.ans");
	file();
	_=read();
	while(_--){
		memset(a,0,sizeof(a));
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;++i){
			scanf("%s",s1+1);
		}
		for(int i=1;i<n;++i){
			scanf("%s",s2+1);
	}
		for(int i=1;i<=q;++i){
			memset(vis,0,sizeof(vis));
			col=read(),lv=read(),x=read(),y=read();
			a[x][y][0]=col; a[x][y][1]=lv;
			if(s1[x][y]=='1'&&y<m&&a[x][y+1][0]!=col&&a[x][y+1][1]<=lv) vis[id(x,y+1)][0]=1;
			if(s1[x][y-1]=='1'&&y>1&&a[x][y-1][0]!=col&&a[x][y-1][1]<=lv) vis[id(x,y-1)][0]=1;
			if(s2[x][y]=='1'&&x<n&&a[x+1][y][0]!=col&&a[x+1][y][1]<=lv) vis[id(x+1,y)][0]=1;
			if(s2[x-1][y]=='1'&&x>1&&a[x-1][y][0]!=col&&a[x-1][y][1]<=lv) vis[id(x-1,y)][0]=1;
			for(int j=y;s1[x][j]=='2'&&j<m&&a[x][j+1][0]!=col&&a[x][j+1][1]<=lv;++j){
				vis[id(x,j+1)][1]=1;
				if(a[x][j+1][0]) break;
			}
			for(int j=y;s1[x][j-1]=='2'&&j>1&&a[x][j-1][0]!=col&&a[x][j-1][1]<=lv;--j){
				vis[id(x,j-1)][1]=1;
				if(a[x][j-1][0]) break;
			}
			for(int j=x;s1[j][y]=='2'&&j<n&&a[j+1][y][0]!=col&&a[j+1][y][1]<=lv;++j) vis[id(j+1,y)][1]=1;
			for(int j=x;s1[j-1][y]=='2'&&j>1&&a[j-1][y][0]!=col&&a[j-1][y][1]<=lv;--j) vis[id(j-1,y)][1]=1;
			dfs(x,y,col,lv); int cnt=0;
			for(int j=1;j<=n;++j){
				for(int k=1;k<=m;++k){
					if(j==x&&k==y) continue;
					if(vis[id(j,k)][0]||vis[id(j,k)][1]||vis[id(j,k)][2]) ++cnt;
				}
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
