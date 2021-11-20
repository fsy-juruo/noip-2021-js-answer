#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<vector<int> > > >v;
int curcol[5010][5010],curlev[5010][5010],has[5010][5010];
vector<int>t1;
vector<vector<vector<int> > >t2;
vector<vector<int> >t3;
struct node{
	int x0,y0,con,len,di;
};
queue<node>bfs;
int eat(int x,int y,int col,int lv){
	if(curlev[x][y]==0)return 0;
	if(curcol[x][y]==col)return 1;
	if(curlev[x][y]>lv)return 1;
	return 2;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(;T;T--){
		int n,m,q;
		cin>>n>>m>>q;
		string tmps;
		memset(curcol,0,sizeof(curcol));
		memset(curlev,0,sizeof(curlev));
		v.clear();
		t1.push_back(0);
		for(int i=0;i<=n+100;i++){
			t3.push_back(t1);
		}
		for(int i=0;i<=n+100;i++){
			t2.push_back(t3);
		}
		for(int i=0;i<=n+100;i++){
			v.push_back(t2);
		}
		for(int i=1;i<=n;i++){
			cin>>tmps;
			for(int j=1;j<=tmps.size();j++){
				v[i][j][i][j+1]=tmps[j-1]-'0';
			}
		}
		for(int i=1;i<=n-1;i++){
			cin>>tmps;
			for(int j=1;j<=tmps.size()+1;j++){
				v[i][j][i+1][j]=tmps[j-1]-'0';
			}
		}
		int col,lv,x,y,ans;
		for(int i=1;i<=q;i++){
			memset(has,0,sizeof(has));
			ans=0;
			scanf("%d%d%d%d",col,lv,x,y);
			curcol[x][y]=col;
			curlev[x][y]=lv;
			has[x][y]=true;
			node tmp;
			tmp.len=1;
			if(x+1<=n&&v[x][y][x+1][y]!=0){
				switch(eat(x+1,y,col,lv)){
					case 0:{
						has[x+1][y]=true;
						tmp.con=v[x][y][x+1][y];
						tmp.x0=x+1;
						tmp.y0=y;
						tmp.di=1;
						bfs.push(tmp);
						ans++;
						break;
					}
					case 2:{
						ans++;
						break;
					}
				}
			}
			if(y-1>0&&v[x][y][x][y-1]!=0){
				switch(eat(x,y-1,col,lv)){
					case 0:{
						has[x][y-1]=true;
						tmp.con=v[x][y][x][y-1];
						tmp.x0=x;
						tmp.y0=y-1;
						tmp.di=2;
						bfs.push(tmp);
						ans++;
						break;
					}
					case 2:{
						ans++;
						break;
					}
				}
			}
			if(y+1<=m&&v[x][y][x][y+1]!=0){
				switch(eat(x,y+1,col,lv)){
					case 0:{
						has[x][y+1]=true;
						tmp.con=v[x][y][x][y+1];
						tmp.x0=x;
						tmp.y0=y+1;
						tmp.di=3;
						bfs.push(tmp);
						ans++;
						break;
					}
					case 2:{
						ans++;
						break;
					}
				}
			}
			if(x-1>0&&v[x][y][x-1][y]!=0){
				switch(eat(x-1,y,col,lv)){
					case 0:{
						has[x-1][y]=true;
						tmp.con=v[x][y][x-1][y];
						tmp.x0=x-1;
						tmp.y0=y;
						tmp.di=4;
						bfs.push(tmp);
						ans++;
						break;
					}
					case 2:{
						ans++;
						break;
					}
				}
			}
			while(!bfs.empty()){
				tmp=bfs.front();
				if(tmp.con==1){
					bfs.pop();
					continue;
				}
				int x1,y1;
				if(tmp.di==1)x1=tmp.x0+1,y1=tmp.y0;
				if(tmp.di==2)x1=tmp.x0,y1=tmp.y0-1;
				if(tmp.di==3)x1=tmp.x0,y1=tmp.y0+1;
				if(tmp.di==4)x1=tmp.x0-1,y1=tmp.y0;
				if(tmp.con==2&&x1>0&&x1<=n&&y1>0&&y1<=m&&has[x1][y1]==0&&v[tmp.x0][tmp.y0][x1][y1]==2){
					int e=eat(x1,y1,col,lv);
					if(e==0){
						node tmp0=tmp;
						tmp0.x0=x1;
						tmp0.y0=y1;
						ans++;
						bfs.push(tmp);
						bfs.pop();
					}
					else if(e==1){
						bfs.pop();
					}
					else{
						bfs.pop();
						ans++;
					}
				}
				if(tmp.con==3){
					int x0=tmp.x0,y0=tmp.y0;
					if(x0+1<=n&&has[x0+1][y0]==0&&v[x0][y0][x0+1][y0]==3){
						int x1=x0+1,y1=y0;
						int e=eat(x1,y1,col,lv);
						if(e==0){
							node tmp0=tmp;
							tmp0.x0=x1;
							tmp0.y0=y1;
							ans++;
							bfs.push(tmp);
						}
						else if(e==2){
							ans++;
						}
					}if(y0+1<=m&&has[x0][y0+1]==0&&v[x0][y0][x0][y0+1]==3){
						int x1=x0,y1=y0+1;
						int e=eat(x1,y1,col,lv);
						if(e==0){
							node tmp0=tmp;
							tmp0.x0=x1;
							tmp0.y0=y1;
							ans++;
							bfs.push(tmp);
							bfs.pop();
						}
						else if(e==2){
							ans++;
						}
					}if(x0-1>0&&has[x0-1][y0]==0&&v[x0][y0][x0-1][y0]==3){
						int x1=x0-1,y1=y0;
						int e=eat(x1,y1,col,lv);
						if(e==0){
							node tmp0=tmp;
							tmp0.x0=x1;
							tmp0.y0=y1;
							ans++;
							bfs.push(tmp);
							bfs.pop();
						}
						else if(e==2){
							ans++;
						}
					}if(y0-1>0&&has[x0][y0-1]==0&&v[x0][y0][x0][y0-1]==3){
						int x1=x0,y1=y0-1;
						int e=eat(x1,y1,col,lv);
						if(e==0){
							node tmp0=tmp;
							tmp0.x0=x1;
							tmp0.y0=y1;
							ans++;
							bfs.push(tmp);
							bfs.pop();
						}
						else if(e==2){
							ans++;
						}
					}
					bfs.pop();
				}
			}
			printf("%d\n",ans);
		}
	} 
	return 0;
}
