#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0,w=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
}
void print(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9){
		print(x/10);
	}
	putchar(x%10+'0');
}
struct Node{
	int x;
	int y;
	int state;
	Node(){
	}
	Node(int _x,int _y,int _state){
		x=_x;
		y=_y;
		state=_state;
	}
};
int T,n,m,q;
int heng[5005][5005],zong[5005][5005],vis[5005][5005],mp[5005][5005],col[2005],lvl[2005],x,y;
queue<Node> qu;
bool go(int x,int y,int c,int l){
	return mp[x][y]==0||(col[mp[x][y]]!=c&&lvl[mp[x][y]]<=l);
}
int bfs(int x,int y,int c,int l){
	int cnt=0;
	while(!qu.empty()) qu.pop();
	vis[x][y]=true;
	if(x-1>=1&&go(x-1,y,c,l)&&zong[x-1][y]!=0){
		if(zong[x-1][y]==1){
			qu.push(Node(x-1,y,1));
		}else if(zong[x-1][y]==2){
			qu.push(Node(x-1,y,3));
		}else{
			qu.push(Node(x-1,y,4));
		}
		vis[x-1][y]=true;
	}
	if(y+1<=m&&go(x,y+1,c,l)&&heng[x][y]!=0){
		if(heng[x][y]==1){
			qu.push(Node(x,y+1,1));
		}else if(heng[x][y]==2){
			qu.push(Node(x,y+1,2));
		}else{
			qu.push(Node(x,y+1,4));
		}
		vis[x][y+1]=true;
	}
	if(y-1>=1&&go(x,y-1,c,l)&&heng[x][y-1]!=0){
		if(heng[x][y-1]==1){
			qu.push(Node(x,y-1,1));
		}else if(heng[x][y-1]==2){
			qu.push(Node(x,y-1,2));
		}else{
			qu.push(Node(x,y-1,4));
		}
		vis[x][y-1]=true;
	}
	if(x+1<=n&&go(x+1,y,c,l)&&zong[x][y]!=0){
		if(zong[x][y]==1){
			qu.push(Node(x+1,y,1));
		}else if(zong[x][y]==2){
			qu.push(Node(x+1,y,3));
		}else{
			qu.push(Node(x+1,y,4));
		}
		vis[x+1][y]=true;
	}
	while(!qu.empty()){
		Node h=qu.front();
		qu.pop();
		cnt++;
		int x=h.x,y=h.y,state=h.state;
//		printf("x:%d y:%d state:%d\n",x,y,state);
		if(state==1||mp[x][y]!=0){
			continue;
		}else if(state==2){
			if(y+1<=m&&go(x,y+1,c,l)&&heng[x][y]==2&&!vis[x][y+1]){
				qu.push(Node(x,y+1,2));
				vis[x][y+1]=true;
			}
			if(y-1>=1&&go(x,y-1,c,l)&&heng[x][y-1]==2&&!vis[x][y-1]){
				qu.push(Node(x,y-1,2));
				vis[x][y-1]=true;
			}
		}else if(state==3){
			if(x-1>=1&&go(x-1,y,c,l)&&zong[x-1][y]==2&&!vis[x-1][y]){
				qu.push(Node(x-1,y,3));
				vis[x-1][y]=true;
			}
			if(x+1<=n&&go(x+1,y,c,l)&&zong[x][y]==2&&!vis[x+1][y]){
				qu.push(Node(x+1,y,3));
				vis[x+1][y]=true;
			}
		}else if(state==4){
			if(y+1<=m&&go(x,y+1,c,l)&&heng[x][y]==3&&!vis[x][y+1]){
				qu.push(Node(x,y+1,4));
				vis[x][y+1]=true;
			}
			if(y-1>=1&&go(x,y-1,c,l)&&heng[x][y-1]==3&&!vis[x][y-1]){
				qu.push(Node(x,y-1,4));
				vis[x][y-1]=true;
			}
			if(x-1>=1&&go(x-1,y,c,l)&&zong[x-1][y]==3&&!vis[x-1][y]){
				qu.push(Node(x-1,y,4));
				vis[x-1][y]=true;
			}
			if(x+1<=n&&go(x+1,y,c,l)&&zong[x][y]==3&&!vis[x+1][y]){
				qu.push(Node(x+1,y,4));
				vis[x+1][y]=true;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--){
		memset(mp,0,sizeof(mp));
		n=read();
		m=read();
		q=read();
		char ch;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				ch=getchar();
				heng[i][j]=ch-'0';
			}
			ch=getchar();
		}
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=m;j++){
				ch=getchar();
				zong[i][j]=ch-'0';
			}
			ch=getchar();
		}
		if(n*m<=5000){
			for(int i=1;i<=q;i++){
				col[i]=read();
				lvl[i]=read();
				x=read();
				y=read();
				print(bfs(x,y,col[i],lvl[i]));
				putchar('\n');
				mp[x][y]=i;
				memset(vis,false,sizeof(vis));
			}
		}else{
			for(int i=1;i<=q;i++){
				col[i]=read();
				lvl[i]=read();
				x=read();
				y=read();
				int ans=0;
				if(x-1>=1&&go(x-1,y,col[i],lvl[i])&&heng[x-1][y]!=0){
					ans++;
				}
				if(x+1<=n&&go(x+1,y,col[i],lvl[i])&&heng[x][y]!=0){
					ans++;
				}
				if(y-1>=1&&go(x,y-1,col[i],lvl[i])&&zong[x][y-1]!=0){
					ans++;
				}
				if(y+1<=n&&go(x,y+1,col[i],lvl[i])&&zong[x][y]!=0){
					ans++;
				}
				mp[x][y]=i;
			}
		}
		
	}
	return 0;
}
