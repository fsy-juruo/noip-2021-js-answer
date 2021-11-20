#include<bits/stdc++.h>
using namespace std;
#define LL long long
char ch=getchar();
int read(){
	int x=0,sign=1;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-'){
		sign=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*sign;
}
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t=read();
	for(int itp=1;itp<=t;itp++){
		int n=read(),m=read(),q=read();
		if(n<=100){
			char lr[200005][105];
			char ud[200005][105];
			int col[200005][105];
			int lv[200005][105];
			for(int i=1;i<=n;i++){
				while(ch>'3'||ch<'1') ch=getchar();
				for(int j=1;j<m;j++){
					lr[i][j]=ch;
					ch=getchar();
				}
			}
			for(int i=1;i<n;i++){
				while(ch>'3'||ch<'1') ch=getchar();
				for(int j=1;j<=m;j++){
					ud[i][j]=ch;
					ch=getchar();
				}
			}
			for(int i=1;i<=q;i++){
				int c=read(),l=read(),x=read(),y=read();
				col[x][y]=c+1;
				lv[x][y]=l;
				int cnt=0;
				for(int j=0;j<4;j++){
					int a=x+dx[j];
					int b=y+dy[j];
					if(j==0&&lr[x][y]==0) continue;
					if(j==1&&lr[x][y-1]==0) continue;
					if(j==2&&ud[x][y]==0) continue;
					if(j==3&&ud[x-1][y]==0) continue;
					if(a>n||a<1||b>m||b<1||col[x][y]==c+1||lv[x][y]>l) continue;
					cnt++;
				}
				printf("%d\n",cnt);
			}
		}
		else if(m<=100){
			char lr[105][200005];
			char ud[105][200005];
			int col[105][200005];
			int lv[105][200005];
			for(int i=1;i<=n;i++){
				while(ch>'3'||ch<'1') ch=getchar();
				for(int j=1;j<m;j++){
					lr[i][j]=ch;
					ch=getchar();
				}
			}
			for(int i=1;i<n;i++){
				while(ch>'3'||ch<'1') ch=getchar();
				for(int j=1;j<=m;j++){
					ud[i][j]=ch;
					ch=getchar();
				}
			}
			for(int i=1;i<=q;i++){
				int c=read(),l=read(),x=read(),y=read();
				col[x][y]=c+1;
				lv[x][y]=l;
				int cnt=0;
				for(int j=0;j<4;j++){
					int a=x+dx[j];
					int b=y+dy[j];
					if(j==0&&lr[x][y]==0) continue;
					if(j==1&&lr[x][y-1]==0) continue;
					if(j==2&&ud[x][y]==0) continue;
					if(j==3&&ud[x-1][y]==0) continue;
					if(a>n||a<1||b>m||b<1||col[x][y]==c+1||lv[x][y]>l) continue;
					cnt++;
				}
				printf("%d\n",cnt);
			}
		}
		else{
			char lr[2000][2000];
			char ud[2000][2000];
			int col[2000][2000];
			int lv[2000][2000];
			for(int i=1;i<=n;i++){
				while(ch>'3'||ch<'1') ch=getchar();
				for(int j=1;j<m;j++){
					lr[i][j]=ch;
					ch=getchar();
				}
			}
			for(int i=1;i<n;i++){
				while(ch>'3'||ch<'1') ch=getchar();
				for(int j=1;j<=m;j++){
					ud[i][j]=ch;
					ch=getchar();
				}
			}
			for(int i=1;i<=q;i++){
				int c=read(),l=read(),x=read(),y=read();
				col[x][y]=c+1;
				lv[x][y]=l;
				int cnt=0;
				for(int j=0;j<4;j++){
					int a=x+dx[j];
					int b=y+dy[j];
					if(j==0&&lr[x][y]==0) continue;
					if(j==1&&lr[x][y-1]==0) continue;
					if(j==2&&ud[x][y]==0) continue;
					if(j==3&&ud[x-1][y]==0) continue;
					if(a>n||a<1||b>m||b<1||col[x][y]==c+1||lv[x][y]>l) continue;
					cnt++;
				}
				printf("%d\n",cnt);
			}
		}
	}
	
	return 0;
}
