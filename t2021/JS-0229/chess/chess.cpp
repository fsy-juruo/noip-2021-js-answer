#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int t,g1[N][N],g2[N][N],c[N][N],l[N][N],n,m,q,ans,vh[N][N];
int read(){
	int f=0;
	char x=getchar();
	while(x>'9'||x<'0'){x=getchar();}
	while(x<='9'&&x>='0'){f=f*10+x-'0';x=getchar();}
	return f;
}
void dfs(int x,int y,int ty,int cl,int le,int pos){
//	cout<<x<<' '<<y<<endl;
	if(ty==0)return;
	if(c[x][y]>-1){
		return;
	}
	int xx=x+dx[0],yy=y+dy[0];
	if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vh[xx][yy]&&(c[xx][yy]!=cl||c[xx][yy]==-1)&&(ty=-1||g1[x][y]
	&&g1[x][y]==ty)&&(l[xx][yy]<le)&&(g1[x][y]!=2||g1[x][y]==2&&(pos==-1||pos==0))){
		if(ty==-1||g1[x][y]==ty){
			ans++;
			vh[xx][yy]=1;
		//	cout<<g1[x][y]<<endl;
		//	cout<<ty<<endl;
		//	cout<<'*'<<endl;
			if(g1[x][y]!=1)dfs(xx,yy,g1[x][y],cl,le,0);
		}
			
	}
	xx=x+dx[1],yy=y+dy[1];
	if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vh[xx][yy]&&(c[xx][yy]!=cl||c[xx][yy]==-1)&&
	(ty=-1||g1[x][y-1]&&g1[x][y-1]==ty)&&(l[xx][yy]<le)&&(g1[x][y-1]!=2||g1[x][y-1]==2&&(pos==-1||pos==1))){
		if(ty==-1||g1[x][y-1]==ty){
			ans++;
			vh[xx][yy]=1;
		//	cout<<g1[x][y-1]<<endl;
		//	cout<<ty<<endl;
		//	cout<<'*'<<endl;
			if(g1[x][y-1]!=1)dfs(xx,yy,g1[x][y-1],cl,le,1);
		}
			
	}
	xx=x+dx[2],yy=y+dy[2];
	if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vh[xx][yy]&&(c[xx][yy]!=cl||c[xx][yy]==-1)&&
	(ty=-1||g2[x][y]&&g2[x][y]==ty)&&(l[xx][yy]<le)&&(g2[x][y]!=2||g2[x][y]==2&&(pos==-1||pos==2))){
		if(ty==-1||g2[x][y]==ty){
			ans++;
			vh[xx][yy]=1;
		//	cout<<g2[x][y]<<endl;
		//	cout<<ty<<endl;
		//	cout<<'*'<<endl;
			if(g1[x][y]!=1)dfs(xx,yy,g2[x][y],cl,le,2);
		}
			
	}
	xx=x+dx[3],yy=y+dy[3];
	if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vh[xx][yy]&&(c[xx][yy]!=cl||c[xx][yy]==-1)&&
	(ty=-1||g2[x-1][y]&&g2[x-1][y]==ty)&&(l[xx][yy]<le)&&(g2[x-1][y]!=2||g2[x-1][y]==2&&(pos==-1||pos==3))){
		if(ty==-1||g2[x-1][y]==ty){
			ans++;
			vh[xx][yy]=1;
	//		cout<<g2[x-1][y]<<endl;
	//		cout<<ty<<endl;
			if(g1[x-1][y]!=1)dfs(xx,yy,g2[x-1][y],cl,le,3);
		}
			
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	for(int ll=1;ll<=t;ll++){
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;i++){
			string str;
			cin>>str;
			for(int j=0;j<m-1;j++){
				g1[i][j+1]=str[j]-'0';
			}
		}
		for(int i=1;i<n;i++){
			string str;
			cin>>str;
			for(int j=0;j<m;j++)
			g2[i][j+1]=str[j]-'0';
		}
		memset(c,-1,sizeof(c));
		memset(l,-1,sizeof(l));
		for(int i=1;i<=q;i++){
			int a,b,cd,dd;
			a=read(),b=read(),cd=read(),dd=read();
			ans=0;
			memset(vh,0,sizeof(vh));
			vh[cd][dd]=1;
			dfs(cd,dd,-1,a,b,-1);
			c[cd][dd]=a;
			l[cd][dd]=b;
			printf("%d\n",ans);
//			cout<<endl;
		}
	}
	return 0;
}
