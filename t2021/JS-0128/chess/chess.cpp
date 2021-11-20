#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int n,m,q;
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
string h[200010];string l[200010];
vector<char>st[200010];
vector<bool>vis[200010];int tot=0;queue<pair<int,int> >qq;
vector<int>mp[2][200010];
int col,lv,x,y;
void dfs(int x,int y,char tmp,int cnt,int lst){
	if(tmp=='1'&&cnt>1)return;
	if(st[x][y]==tmp)return;
	st[x][y]=tmp;
	if(!vis[x][y]){
		tot++;vis[x][y]=1;
		qq.push(make_pair(x,y));
	}
	if(lst==-2)return;
	rep(i,0,3){
		int tx=x+dir[i][0];int ty=y+dir[i][1];
		if(tx<1||ty<1||tx>n||ty>m)continue;
		if(tmp=='2'&&lst!=-1&&lst!=i&&(lst^i)!=1)continue;
		if(i==0){
			if(h[x][y-1]!=tmp)continue;
			if(mp[1][tx][ty]!=0){
				if(mp[0][tx][ty]==col||mp[1][tx][ty]>lv)continue;
				dfs(tx,ty,tmp,cnt+1,-2);
			}else{
				dfs(tx,ty,tmp,cnt+1,i);
			}
		}else if(i==1){
			if(h[x][y-2]!=tmp)continue;
			if(mp[1][tx][ty]!=0){
				if(mp[0][tx][ty]==col||mp[1][tx][ty]>lv)continue;
				dfs(tx,ty,tmp,cnt+1,-2);
			}else{
				dfs(tx,ty,tmp,cnt+1,i);
			}
		}else if(i==2){
			if(l[x][y-1]!=tmp)continue;
			if(mp[1][tx][ty]!=0){
				if(mp[0][tx][ty]==col||mp[1][tx][ty]>lv)continue;
				dfs(tx,ty,tmp,cnt+1,-2);
			}else{
				dfs(tx,ty,tmp,cnt+1,i);
			}
		}else{
			if(l[x-1][y-1]!=tmp)continue;
			if(mp[1][tx][ty]!=0){
				if(mp[0][tx][ty]==col||mp[1][tx][ty]>lv)continue;
				dfs(tx,ty,tmp,cnt+1,-2);
			}else{
				dfs(tx,ty,tmp,cnt+1,i);
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int T;read(T);
	while(T--){
		read(n);read(m);read(q);
		rep(i,1,n){st[i].clear();vis[i].clear();mp[0][i].clear();mp[1][i].clear();}
		rep(i,1,n)cin>>h[i];
		rep(i,1,n-1)cin>>l[i];
		rep(i,1,n){
			rep(j,0,m){
				st[i].push_back('#');vis[i].push_back(0);
				mp[0][i].push_back(0);mp[1][i].push_back(0);	
			}
		}
		
		while(q--){
			read(col);read(lv);read(x);read(y);
			tot=0;
			if(n*m<=5000){
				dfs(x,y,'1',0,-1);dfs(x,y,'2',0,-1);dfs(x,y,'3',0,-1);
			}else{
				dfs(x,y,'1',0,-1);
			}
			mp[0][x][y]=col;mp[1][x][y]=lv;
			write(tot-1);
			while(!qq.empty()){
				vis[qq.front().first][qq.front().second]=0;
				st[qq.front().first][qq.front().second]='#';
				qq.pop();
			}
		}
	}
	return 0;
}
