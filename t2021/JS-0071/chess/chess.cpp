#include<bits/stdc++.h>
using namespace std;
int read(){
	char c;
	int ret=0;
	do{
		c=getchar();
	}while(c<=32);
	do{
		ret=ret*10+c-'0';
		c=getchar();
	}while('0'<=c&&c<='9');
	return ret;
}
typedef vector<int>vi;
char buffer[200006];
class Solution{
public:
	int h,w,q;
	int COL,LV,SIGN,DIR;
	const int dx[4]{-1,1,0,0},dy[4]{0,0,1,-1};
	vector<vi>a[4],col,lv,u,v;
	void work(){
		cin>>h>>w>>q;
		getchar();
		for(int i=0;i<4;i++)
			a[i]=vector<vi>(h+1,vi(w+1,0));
		col=vector<vi>(h+1,vi(w+1,0));
		lv=vector<vi>(h+1,vi(w+1,0));
		u=vector<vi>(h+1,vi(w+1,0));
		v=vector<vi>(h+1,vi(w+1,0));
		for(int i=1;i<=h;i++){
			fgets(buffer+1,200004,stdin);
			for(int j=1;j<w;j++){
				a[2][i][j]=buffer[j]-'0';
				a[3][i][j+1]=buffer[j]-'0';
			}
		}
		for(int i=1;i<h;i++){
			fgets(buffer+1,200004,stdin);
			for(int j=1;j<=w;j++){
				a[1][i][j]=buffer[j]-'0';
				a[0][i+1][j]=buffer[j]-'0';
			}
		}
		for(int i=1;i<=q;i++){
			COL=read(),LV=read();
			int x=read(),y=read(),ans=0;
			SIGN=i;
			u[x][y]=SIGN;
			v[x][y]=SIGN;//forbidden
			for(int d=0;d<4;d++){
				int xx=x+dx[d],yy=y+dy[d];
				if(a[d][x][y]==1){
					ans+=walk1(xx,yy);
				}else if(a[d][x][y]==2){
					DIR=d;
					ans+=walk2(xx,yy);
				} 
			}
			for(int d=0;d<4;d++){
				int xx=x+dx[d],yy=y+dy[d];
				if(a[d][x][y]==3){
					ans+=walk3(xx,yy);
				}
			}
			printf("%d\n",ans);
			col[x][y]=COL;
			lv[x][y]=LV;
		}
	}
	void show(){
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(u[i][j]==SIGN){
					cout<<i<<":"<<j<<"\n";
				}
			}
		}
	}
	int check(int x,int y){
		if(lv[x][y]==0||(LV>=lv[x][y]&&COL!=col[x][y])){
			return 1;
		}
		return 0;
	}
	int walk1(int x,int y){
		if(!check(x,y)||u[x][y]==SIGN){
			return 0;
		}
		u[x][y]=SIGN;
		return 1;
	}
	int walk2(int x,int y){
		if(!check(x,y)||u[x][y]==SIGN){
			return 0;
		}
		u[x][y]=SIGN;
		int xx=x+dx[DIR],yy=y+dy[DIR];
		if(a[DIR][x][y]==2&&lv[x][y]==0){
			return walk2(xx,yy)+1;
		}
		return 1;
	}
	int walk3(int x,int y){
		if(!check(x,y)||v[x][y]==SIGN){
			return 0;
		}
		v[x][y]=SIGN;
		int ret;
		if(u[x][y]==SIGN){
			ret=0;
		}else{
			ret=1;
		}
		if(lv[x][y]!=0){
			return ret;
		}
		for(int d=0;d<4;d++){
			int xx=x+dx[d],yy=y+dy[d];
			if(a[d][x][y]==3){
				ret+=walk3(xx,yy);
			}
		}
		return ret;
	}
};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		Solution*n=new Solution;
		n->work();
		delete n;
	}
	
	return 0; 
}
