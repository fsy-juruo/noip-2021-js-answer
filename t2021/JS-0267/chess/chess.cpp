#include<bits/stdc++.h>
#define ll long long
#define rep(i,j,n) for(int i=j;i<=n;i++)
using namespace std;
template <typename T> void read(T&x){
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
const int N=1e5+5;
int T,n,m,q,lv[N];
bool co[N],v[5005][5005],vis[5005][5005];
short h[5005][5005],l[5005][5005];
unordered_map<int,int>a[N];
struct node{
	int x,y;
};
int check1(int i,int x,int y){
	if(v[x+1][y]==1)return 0;
	if(a[x+1][y]){
		int i2=a[x+1][y];
		if(co[i]==co[i2])return 0;
		if(lv[i]<lv[i2])return 0;
	}
	if(x+1>n)return 0;
	if(l[x][y]!=3)return 0;
	return 1;
}
int check2(int i,int x,int y){
	if(v[x-1][y]==1)return 0;
	if(a[x-1][y]){
		int i2=a[x-1][y];
		if(co[i]==co[i2])return 0;
		if(lv[i]<lv[i2])return 0;
	}
	if(x-1<1)return 0;
	if(l[x-1][y]!=3)return 0;
	return 1;
}
int check3(int i,int x,int y){
	if(v[x][y+1]==1)return 0;
	if(a[x][y+1]){
		int i2=a[x][y+1];
		if(co[i]==co[i2])return 0;
		if(lv[i]<lv[i2])return 0;
	}
	if(y+1>m)return 0;
	if(h[x][y]!=3)return 0;
	return 1;
}
int check4(int i,int x,int y){
	if(v[x][y-1]==1)return 0;
	if(a[x][y-1]){
		int i2=a[x][y-1];
		if(co[i]==co[i2])return 0;
		if(lv[i]<lv[i2])return 0;
	}
	if(y-1<1)return 0;
	if(h[x][y-1]!=3)return 0;
	return 1;
}
int bfs(int i,int x,int y,int dx,int dy,int ty){
//	cout<<ty<<" ";
	if(ty==0)return 0;
	if(ty==1){
		if(a[x+dx][y+dy]==0){return !v[x+dx][y+dy];}
		else{
			int i1=a[x][y],i2=a[x+dx][y+dy];
			if(co[i1]==co[i2])return 0;
			if(lv[i1]>=lv[i2])return !v[x+dx][y+dy];
			return 0;
		}
	}
	int cnt=0;
	int x1=x,y1=y;
	if(ty==2){
		if(dx==1){
			while(1){
				vis[x][y]=1;
				if((x!=x1||y!=y1)&&a[x][y]!=0)break;
				if(a[x+1][y]){
					int i2=a[x+1][y];
					if(co[i]==co[i2])break;
					if(lv[i]<lv[i2])break;
				}
				if(x+1>n)break;
				if(l[x][y]!=2)break;
				x++,cnt+=(!v[x][y]);
			}
		}
		if(dx==-1){
			while(1){
				vis[x][y]=1;
				if((x!=x1||y!=y1)&&a[x][y]!=0)break;
				if(a[x-1][y]){
					int i2=a[x-1][y];
					if(co[i]==co[i2])break;
					if(lv[i]<lv[i2])break;
				}
				if(x-1<1)break;
				if(l[x-1][y]!=2)break;
				x--,cnt+=(!v[x][y]);
			}
		}
		if(dy==1){
			while(1){
				vis[x][y]=1;
				if((x!=x1||y!=y1)&&a[x][y]!=0)break;
				if(a[x][y+1]){
					int i2=a[x][y+1];
					if(co[i]==co[i2])break;
					if(lv[i]<lv[i2])break;
				}
				if(y+1>m)break;
				if(h[x][y]!=2)break;
				y++,cnt+=(!v[x][y]);
			}
		}
		if(dy==-1){
			while(1){
				vis[x][y]=1;
				if((x!=x1||y!=y1)&&a[x][y]!=0)break;
				if(a[x][y-1]){
					int i2=a[x][y-1];
					if(co[i]==co[i2])break;
					if(lv[i]<lv[i2])break;
				}
				if(y-1<1)break;
				if(h[x][y-1]!=2)break;
				y--,cnt=cnt+(!v[x][y]);
			}
		}
		return cnt;
	}
	if(ty==3){
		queue<node>q;
		while(!q.empty())q.pop();
		q.push({x,y});
		while(!q.empty()){
			x=q.front().x,y=q.front().y;
			q.pop();
			if(v[x][y])continue;
			if(x!=x1||y!=y1)cnt+=!vis[x][y];
			v[x][y]=1;
			if((x!=x1||y!=y1)&&a[x][y]!=0)continue;
			if(check1(i,x,y)){
				q.push({x+1,y});
			}
			if(check2(i,x,y)){
				q.push({x-1,y});
			}
			if(check3(i,x,y)){
				q.push({x,y+1});
			}
			if(check4(i,x,y)){
				q.push({x,y-1});
			}
		}
		return cnt;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while(T--){
		read(n),read(m),read(q);
		rep(i,1,n){
			a[i].clear();
			rep(j,1,m-1){
				char ch=getchar();
				while(!isdigit(ch))ch=getchar();
				h[i][j]=ch-'0';
			}
		}
		rep(i,1,n-1){
			rep(j,1,m){
				char ch=getchar();
				while(!isdigit(ch))ch=getchar();
				l[i][j]=ch-'0';
			}
		}
		if(n<=5000&&m<=5000){
			rep(i,1,q){
				int x,y;
				read(co[i]),read(lv[i]),read(x),read(y);
				a[x][y]=i;
				int ans=0;
				memset(v,0,sizeof(v));
				memset(vis,0,sizeof(vis));
				ans+=bfs(i,x,y,1,0,l[x][y]);
//				printf("%d\n",ans);
				ans+=bfs(i,x,y,-1,0,l[x-1][y]);
//				printf("%d\n",ans);
				ans+=bfs(i,x,y,0,1,h[x][y]);
//				printf("%d\n",ans);
				ans+=bfs(i,x,y,0,-1,h[x][y-1]);
				printf("%d\n",ans);
//				cout<<endl;
			}
		}
	}
	return 0;
}

