#include <bits/stdc++.h>
using namespace std;
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
inline int read(){ 
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-48;c=getchar();}
	return x*f;
}
inline void writ(int x){
	if(x<0){putchar('-');x=-x;}
	if(x/10)writ(x/10);
	putchar(x%10+48);
}
int ch[5010][5010];
bool vis[5010][5010];
char a[5010][5010][4];
int T,n,m,q;
int col,lv,sx,sy;
struct node{
	int nx,ny,ro,fx;
};
bool check(int dsx,int dsy){
	if(dsx<1||dsx>n||dsy<1||dsy>m||vis[dsx][dsy])return 1;
	return 0;
}
int work(){
	int sum=-1;
	memset(vis,0,sizeof(vis));
	queue <node> q;
	q.push(node{sx,sy,-1,-1});
	vis[sx][sy]=1;
	while(!q.empty()){
		node T=q.front();
		q.pop();
		if(ch[T.nx][T.ny]!=0){
			if(ch[T.nx][T.ny]*col>0)continue ;
			else if(abs(ch[T.nx][T.ny])<=lv)sum++;
			continue ;
		}	
		sum++;
		if(T.ro==1)continue ;
		int xx=T.nx,yy=T.ny;
		for(int i=0;i<4;++i){
			if(check(xx+dx[i],yy+dy[i]))continue;
			if(a[xx][yy][i]=='0')continue;
			if(T.ro==-1||T.ro==a[xx][yy][i]-48){
				if(T.ro==2){
					if(T.fx==i){
						q.push(node{xx+dx[i],yy+dy[i],2,i});
						vis[xx+dx[i]][yy+dy[i]]=1;
					}
						
				}
				else if(T.ro==3){
					q.push(node{xx+dx[i],yy+dy[i],3,i});vis[xx+dx[i]][yy+dy[i]]=1;
				}
				else if(T.ro==-1){
				q.push({node{xx+dx[i],yy+dy[i],a[xx][yy][i]-48,i}});vis[xx+dx[i]][yy+dy[i]]=1;
				}
			}
		}
	}
	return sum;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T){
	T--;
	n=read();m=read();q=read();	
	memset(ch,0,sizeof(ch));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=0;k<4;++k)a[i][j][k]='0';
		}
	}
	int cnt=0,i=1,j=0;
	char c;
	while(cnt<n*(m-1)){
		c=getchar();
		if(c>='0'&&c<='9'){
			cnt++;
			j++;
			if(j==m){i++;j=1;}
			a[i][j][0]=c;
			a[i][j+1][1]=c;
		}
	}
	cnt=0,i=1,j=0;
	while(cnt<(n-1)*m){
		c=getchar();
		if(c>='0'&&c<='9'){
			cnt++;
			j++;
			if(j>m){i++;j=1;}
			a[i][j][3]=c;
			a[i+1][j][2]=c;
		}
	}
	for(int i=1;i<=q;++i){
		col=read(),lv=read(),sx=read(),sy=read();
		if(!col)col=-1;
		writ(work());putchar('\n');
		ch[sx][sy]=lv*col;
	}
	}
	return 0;
}

