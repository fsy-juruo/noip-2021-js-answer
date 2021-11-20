#include <bits/stdc++.h>
using namespace std;
int edtp[5086][5086][4];
int cc[5086][5086];
int cl[5086][5086];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int t,n,m,q;
char inp[5086];
bool ed[5086][5086][4];
bool nd[5086][5086];
struct thl{
	int x,y,tp,di;
};
struct sco{
	int x,y;
};
queue<thl>qu;
set<pair<int,int> >s;
bool in(int x,int y,int c,int l){
	if(x>=1&&y>=1&&x<=n&&y<=m){
		if(cc[x][y]==c||cl[x][y]>l)return false;
		return true;
	}
	else return false;
}
void bfs(int x,int y,int c,int l){
	while(!qu.empty())qu.pop();
	s.clear();
	for(int i=0;i<4;i++){
		qu.push(thl{x,y,edtp[x][y][i],i});
	}
	while(!qu.empty()){
		thl cur=qu.front();
		qu.pop();
		if(cur.tp==0)continue;
		if(cc[cur.x][cur.y]!=c)continue;
		if(cur.tp==1){
			int tx=cur.x+dx[cur.di];
			int ty=cur.y+dy[cur.di];
			if(in(tx,ty,c,l)){
				s.insert(make_pair(tx,ty));
			}
		}
		if(cur.tp==2){
			int tx=cur.x+dx[cur.di];
			int ty=cur.y+dy[cur.di];
			if(in(tx,ty,c,l)&&edtp[cur.x][cur.y][cur.di]==2){
				s.insert(make_pair(tx,ty));
				qu.push(thl{tx,tx,cur.tp,cur.di});
			}
		}
		if(cur.tp==3){
			for(int i=0;i<4;i++){
				int tx=cur.x+dx[i];
				int ty=cur.y+dy[i];
				if(in(tx,ty,c,l)&&edtp[cur.x][cur.y][i]==3){
					s.insert(make_pair(tx,ty));
					qu.push(thl{tx,ty,cur.tp,cur.di});
				}
			}
		}
	}
	printf("%d\n",s.size());
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++){
			scanf("%s",&inp[1]);
			for(int j=1;j<m;j++){
				edtp[i][j][1]=edtp[i][j+1][3]=int(inp[j])-48;
			}
		}
		for(int i=1;i<n;i++){
			scanf("%s",&inp[1]);
			for(int j=1;j<=m;j++){
				edtp[i][j][2]=edtp[i+1][j][0]=int(inp[j])-48;
			}
		}
		int x,y,c,l;
		while(q--){
			scanf("%d%d%d%d",&c,&l,&x,&y);
			cc[x][y]=c;
			cl[x][y]=l;
			bfs(x,y,c,l);
		}
	}
	return 0;
}
