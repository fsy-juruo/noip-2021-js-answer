#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int tot,n,m,q;
char a[5050][5050];
char b[5050][5050];
struct node{
	int c,l;
}f[5050][5050];
void dfs(int x,int y,char k){
	tot++;
	for (int i=0;i<=3;i++){
		int nx,ny;
		nx=x+dx[i];
		ny=y+dy[i];
		if (nx<1||nx>n||ny<1||ny>m) continue;
		if (f[nx][ny].l!=0){
			if (f[x][y].c!=f[nx][ny].c&&f[x][y].l>=f[nx][ny].l){
				tot++;
			}
		}
		else if (k=='5'){
			if (nx>x) dfs(nx,ny,b[x][y]);
			if (nx<x) dfs(nx,ny,b[nx][y]);
			if (ny>y) dfs(nx,ny,a[x][y]);
			if (ny<y) dfs(nx,ny,b[x][ny]);
		}
		else if (k!='5'){
			if (nx>x&&b[x][y]==k) dfs(nx,ny,b[x][y]);
			if (nx<x&&b[nx][y]==k) dfs(nx,ny,b[nx][y]);
			if (ny>y&&a[x][y]==k) dfs(nx,ny,a[x][y]);
			if (ny<y&&a[x][ny]==k) dfs(nx,ny,a[x][ny]);
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);

   int T;
   cin>>T;
   while (T--){
   	  memset(f,sizeof(f),0);
   	  scanf("%d%d%d",&n,&m,&q);
   	  for (int i=1;i<=n;i++)
   	     scanf("%s",a[i]+1);
   	  for (int j=1;j<=m;j++)
   	     scanf("%s",b[j]+1);
   	  for (int i=1;i<=q;i++){
   	  	int c,l,x,y;
   	  	scanf("%d%d%d%d",&c,&l,&x,&y);
   	  	f[x][y].c=c;
   	  	f[x][y].l=l;
   	  	tot=0;
   	  	dfs(x,y,'5');
   	  	printf("%d\n",tot-1);
	  } 
   }

	return 0;
}

