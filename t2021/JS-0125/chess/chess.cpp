#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

long long t,n,m,q,ans;
string cal[100010],row[100010];
struct chess{
	long long c;long long l;
}map[10010][10010];
bool vis[10010][10010];
int hx[4] = {1,-1,0,0};
int hy[4] = {0,0,1,-1};
long long read(){
	long long sum = 0;
	int neg = 1;
	char c = getchar();
	while(c<'0'||c>'9'){
		if(c == '-')neg = -1;
		c = getchar();
	}
	while(c>='0'&&c<='9'){
		sum = sum*10+(c-'0');
		c = getchar();
	}
	return sum * neg;
}

void dfs(long long c,long long lv,long long x,long long y,int typ,int dir){
	if(map[x+hx[dir]][y+hy[dir]].c == 0||(map[x][y].c != c&&map[x][y].l <= lv)){
		if(x+hx[dir]<0||x+hx[dir]>n||y+hy[dir]<0||y+hy[dir]>n){}
		else{
		ans += !vis[x][y];
		vis[x][y] = 1;
		if(map[x+hx[dir]][y+hy[dir]].c != 0)return;}
	}
	if(typ == 1){
		if(map[x+hx[dir]][y+hy[dir]].c == 0||(map[x][y].c != c&&map[x][y].l <= lv)){
			if(x+hx[dir]<0||x+hx[dir]>n||y+hy[dir]<0||y+hy[dir]>n){}
			else{ans += !vis[x+hx[dir]][y+hy[dir]];
			vis[x+hx[dir]][y+hy[dir]] = 1;
			return;}
		}
	}
	if(typ == 2){
		if(x+hx[dir]<0||x+hx[dir]>n||y+hy[dir]<0||y+hy[dir]>n){}
		else{
		dfs(c,lv,x+hx[dir],y+hy[dir],1,dir);}
	}
	if(typ == 3){
		
		for(long long i = 0;i<4;i++){	
			if(x+hx[i]<0||x+hx[i]>n||y+hy[i]<0||y+hy[i]>n)continue;
			if(i == 0&&cal[x][y] =='3')dfs(c,lv,x+hx[i],y+hy[i],2,0);
			if(i == 1&&cal[x-1][y] =='3')dfs(c,lv,x+hx[i],y+hy[i],2,1);
			if(i == 2&&row[x][y] =='3')dfs(c,lv,x+hx[i],y+hy[i],2,2);
			if(i == 3&&row[x][y-1] =='3')dfs(c,lv,x+hx[i],y+hy[i],2,3);
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t = read();
	while(t--){
		ans = 0;
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		n = read();m = read();q = read();
		for(long long i = 0;i<n;i++){
			cin>>cal[i];
		}
		for(long long i = 0;i<n-1;i++){
			cin>>row[i];
		}
		for(long long i = 0;i<q;i++){
			memset(vis,0,sizeof(vis));
			ans = 0;
			long long col,lv,x,y;
			
			col = read();lv = read();x = read();y = read();
			x--;y--;
			long long t = x;
			x = y;y=t;
			map[x][y].c = int(col+1);
			map[x][y].l = lv;
			vis[x][y] = 1;
			for(long long i = 0;i<4;i++){	
				if(x+hx[i]<0||x+hx[i]>n||y+hy[i]<0||y+hy[i]>n)continue;
				if(i == 0)dfs(col,lv,x+hx[i],y+hy[i],cal[x][y]-'0',0);
				if(i == 1)dfs(col,lv,x+hx[i],y+hy[i],cal[x][y-1]-'0',1);
				if(i == 2)dfs(col,lv,x+hx[i],y+hy[i],row[x][y]-'0',2);
				if(i == 3)dfs(col,lv,x+hx[i],y+hy[i],row[x][y-1]-'0',3);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

