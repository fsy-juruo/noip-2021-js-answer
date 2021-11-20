#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x){
	long long ff=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')ff=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=ff;
}
template<typename T>inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);putchar('\n');
}
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
const int N=1e6;
int n,m,Q,h[4],r[N+10],c[N+10];
int get(int x,int y){
	return (x-1)*m+y;
}
struct Node{
	int va,tp;
};
vector<Node>A[N+10];
void add(int x,int y,int tp){
	A[x].push_back((Node){y,tp});
	A[y].push_back((Node){x,tp});
}
Node p[N+10];
int vis1[N+10],vis2[N+10],vis3[N+10],cnt=0;
bool ok(int x,int y){
	return 1<=x&&x<=n&&1<=y&&y<=m;
}
bool win(Node p,Node q){
	return p.tp!=q.tp&&p.va>=q.va;
}
void dfs3(int x,int y,Node now){
	if(!ok(x,y))return;
	if(ok(x,y+1)&&r[get(x,y)]==3){
		if(p[get(x,y+1)].tp==-1){
			if(!vis3[get(x,y+1)]){
				vis3[get(x,y+1)]=1;
				dfs3(x,y+1,now);
			}
		}else{
			if(win(now,p[get(x,y+1)]))vis3[get(x,y+1)]=1;
		}
	}
	if(ok(x,y-1)&&r[get(x,y-1)]==3){
		if(p[get(x,y-1)].tp==-1){
			if(!vis3[get(x,y-1)]){
				vis3[get(x,y-1)]=1;
				dfs3(x,y-1,now);
			}
		}else{
			if(win(now,p[get(x,y-1)]))vis3[get(x,y-1)]=1;
		}
	}
	if(ok(x+1,y)&&c[get(x,y)]==3){
		if(p[get(x+1,y)].tp==-1){
			if(!vis3[get(x+1,y)]){
				vis3[get(x+1,y)]=1;
				dfs3(x+1,y,now);
			}
		}else{
			if(win(now,p[get(x+1,y)]))vis3[get(x+1,y)]=1;
		}
	}
	if(ok(x-1,y)&&c[get(x-1,y)]==3){
		if(p[get(x-1,y)].tp==-1){
			if(!vis3[get(x-1,y)]){
				vis3[get(x-1,y)]=1;
				dfs3(x-1,y,now);
			}
		}else{
			if(win(now,p[get(x-1,y)]))vis3[get(x-1,y)]=1;
		}
	}
}
void bf(){
	for(int i=1;i<=n*m;i++)p[i].tp=-1;
	while(Q--){
		for(int i=1;i<=n*m;i++)vis1[i]=vis2[i]=vis3[i]=0;
		Node now;
		int x,y;
		read(now.tp);read(now.va);read(x);read(y);
		//1
		if(ok(x,y+1)&&r[get(x,y)]==1){
			if(p[get(x,y+1)].tp==-1){
				vis1[get(x,y+1)]=1;
			}else{
				if(win(now,p[get(x,y+1)]))vis1[get(x,y+1)]=1;
			}
		}
		if(ok(x,y-1)&&r[get(x,y-1)]==1){
			if(p[get(x,y-1)].tp==-1){
				vis1[get(x,y-1)]=1;
			}else{
				if(win(now,p[get(x,y-1)]))vis1[get(x,y-1)]=1;
			}
		}
		if(ok(x+1,y)&&c[get(x,y)]==1){
			if(p[get(x+1,y)].tp==-1){
				vis1[get(x+1,y)]=1;
			}else{
				if(win(now,p[get(x+1,y)]))vis1[get(x+1,y)]=1;
			}
		}
		if(ok(x-1,y)&&c[get(x-1,y)]==1){
			if(p[get(x-1,y)].tp==-1){
				vis1[get(x-1,y)]=1;
			}else{
				if(win(now,p[get(x-1,y)]))vis1[get(x-1,y)]=1;
			}
		}
		//2
		for(int i=y;i>1;i--){
			if(ok(x,i-1)&&r[get(x,i-1)]==2){
				if(p[get(x,i-1)].tp==-1){
					vis2[get(x,i-1)]=1;
				}else{
					if(win(now,p[get(x,i-1)]))vis2[get(x,i-1)]=1;
					break;
				}
			}else{
				break;
			}
		}
		for(int i=y;i<m;i++){
			if(ok(x,i+1)&&r[get(x,i)]==2){
				if(p[get(x,i+1)].tp==-1){
					vis2[get(x,i+1)]=1;
				}else{
					if(win(now,p[get(x,i+1)]))vis2[get(x,i+1)]=1;
					break;
				}
			}else{
				break;
			}
		}
		for(int i=x;i>1;i--){
			if(ok(i-1,y)&&c[get(i-1,y)]==2){
				if(p[get(i-1,y)].tp==-1){
					vis2[get(i-1,y)]=1;
				}else{
					if(win(now,p[get(i-1,y)]))vis2[get(i-1,y)]=1;
					break;
				}
			}else{
				break;
			}
		}
		for(int i=x;i<n;i++){
			if(ok(i+1,y)&&c[get(i,y)]==2){
				if(p[get(i+1,y)].tp==-1){
					vis2[get(i+1,y)]=1;
				}else{
					if(win(now,p[get(i+1,y)]))vis2[get(i+1,y)]=1;
					break;
				}
			}else{
				break;
			}
		}
		//3
		dfs3(x,y,now);
		
		cnt=0;
		for(int i=1;i<=n*m;i++){
			if(i==get(x,y))continue;
			if(vis1[i]||vis2[i]||vis3[i]){
				cnt++;
			}
		}
		writeln(cnt);
		
		p[get(x,y)]=now;
	}
}
void solve(){
	read(n);read(m);read(Q);
	for(int i=1;i<=n*m;i++)r[i]=c[i]=0;
	memset(h,0,sizeof(h));
	int x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			char ch;cin>>ch;x=ch-'0';
			h[x]=1;r[get(i,j)]=x;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			char ch;cin>>ch;x=ch-'0';
			h[x]=1;c[get(i,j)]=x;
		}
	}
	bf();
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int T;read(T);
	while(T--)solve();
	return 0;
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

1
3 3 1
13
22
23
010
233
0 1 2 3

2
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
3 2 3
3
1
3
32
32
0 2 1 2
1 2 3 2
0 1 2 2

*/
