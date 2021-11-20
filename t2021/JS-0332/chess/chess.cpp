#include <bits/stdc++.h>
using namespace std;
const int N = 7000;
const int xx[5]={0,1,0,-1,0};
const int yy[5]={0,0,1,0,-1};
int mp[N][N];
int c[N][N],cnt;
struct pio{
	int col,lv;
}p[N];
int t,m,n,q;
int make(int x,int y){
	return (x-1)*n+y;
}
int read(){
	char a = getchar();
	while(a<'0'||a>'9'){
		a = getchar();
	}
	int ans = 0;
	while(a>='0'&&a<='9'){
		ans = ans*10+a-'0';
		a = getchar();
	}
	return ans;
}
void red(int i){
	char a = getchar();
	while(a<'0'||a>'9'){
		a = getchar();
	}
	for(int j = 1;j < m;j++){
		mp[(i-1)*n+j][(i-1)*n+j+1] = a-'0';
		mp[(i-1)*n+j+1][(i-1)*n+j] = a-'0';
		a = getchar();
	}
	return;
}
void reg(int i){
	char a = getchar();
	while(a<'0'||a>'9'){
		a = getchar();
	}
	for(int j = 1;j < m;j++){
		mp[(i-1)*n+j][(i)*n+j] = a-'0';
		mp[(i)*n+j][(i-1)*n+j] = a-'0';
		a = getchar();
	}
	return;
}
void write(int a){
	int x[14];
	int l = 1,b = a/10;
	while(a > 0){
		x[l] = a-b*10;
		l++;
		a = b;
		b = a/10;
	}
	l--;
	char o;
	while(l){
		o = '0'+ x[l];
		putchar(o);
		l--;
	}
	o = 10;
	putchar(o);
	return;
}
int find(int co,int lv,int x,int y){
	int ans = 0;
	for(int i = 1;i <= 4;i++){
		if(x+xx[i]>n||x+xx[i]<1||y+yy[i]>m||y+yy[i]<1) continue;
		int z = mp[make(x,y)][make(x+xx[i],y+yy[i])];
		if(z == 3){
			int cc = c[x+xx[i]][y+yy[i]];
			if(cc != 0){
				if(p[cc].col != co&& lv > p[cc].lv){
					ans++;
					
				}
				continue; 
			} else{
				ans++;
				ans+= find(co,lv,x+xx[i],y+yy[i]);
			}
		}
	}
	return ans;
}
int g(int co,int lv,int x,int y){
	int ans = 0;
	for(int i = 1;i <= 4;i++){
		if(x+xx[i]>n||x+xx[i]<1||y+yy[i]>m||y+yy[i]<1) continue;
		int z =mp[make(x,y)][make(x+xx[i],y+yy[i])];
		if(z== 0){
			continue;
		} else if(z == 1){
			int cc = c[x+xx[i]][y+yy[i]];
			if(cc != 0){
				if(p[cc].col != co&& lv > p[cc].lv){
					ans += 1; 
				}
			} else{
				ans++;
			}
		} else if(z == 2){
			int nx=x,ny=y;
			while(nx<=n&&nx>0&&ny<=m&&ny>0&&mp[make(nx,ny)][make(nx+xx[i],ny+yy[i])]==2){
				nx+= xx[i];
				ny+= yy[i];
				int cc = c[nx][ny];
				if(cc != 0){
					if(p[cc].col != co&& lv > p[cc].lv){
						ans += 1; 
					} 
					break;
				} else{
					ans++;
				}	
			}
		}
	}
	return ans;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t = read();
	while(t){
		memset(c,0,sizeof(c));
		memset(mp,-1,sizeof(mp));
		t--;
		n = read();
		m = read();
		q = read();
		for(int i = 1;i <= n;i++){
			red(i);
		}
		for(int i = 1;i < n;i++){
			reg(i);
		}
		int x,y;
		for(int i = 1;i <= q;i++){
			p[i].col = read();p[i].lv = read();x = read();y = read();
			c[x][y] = i;
			write(g(p[i].col,p[i].lv,x,y)+find(p[i].col,p[i].lv,x,y));
		}
	}
	return 0;
}
