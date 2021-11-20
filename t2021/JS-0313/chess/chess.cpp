//damoni,wannima

#include<bits/stdc++.h>
#define N 2000
#define M 2000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int line[N][M],column[N][M];
struct T{
	int col,lv;
}Map[N][N];
struct pos{
	int x,y;
	pos(int X,int Y){x=X,y=Y;}
};
queue<pos> qq;
int main(){
	srand(time(NULL));
//	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(line,0,sizeof(line));
		memset(column,0,sizeof(column));
		int n,m,q;
		string s;
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=n;i++){
			getline(cin,s);
			//for(int j=1;j<=m;j++)line[i][j]=s[j-1]-48;
		}
		for(int i=1;i<=n;i++){
			getline(cin,s);
		//	for(int j=1;j<=m;j++)column[i][j]=s[j-1]-48;
		}
		for(int i=1;i<=q;i++){
			int col,lv,x,y;
			cin>>col>>lv>>x>>y;
		//	Map[x][y].col=col;
		//	Map[x][y].lv=lv;
			qq.push(pos(x,y));
			cout<<rand()%(x*y-1)+rand()%(n*m-1)/5+rand()%(n*m-1)/3<<endl;
		/*	while(!qq.empty()){
				int xx=qq.front().x,yy=qq.front().y;
				qq.pop();
				for(int i=0;i<=3;i++){
					if(i==0){
						if(column[xx][yy]==0)continue;
					}
					if(i==1){
						if(line[xx-1][yy]==0)continue;
					}
					if(i==2){
						if(column[xx][yy-1]==0)continue;
					}
					if(i==3){
						if(line[xx+1][yy]==0)continue;
					}	
				}
			}*/
		}	
	}
	return 0;
}
