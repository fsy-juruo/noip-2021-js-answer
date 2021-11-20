#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}
	return s*f;
}
int n,m,q,x[2000][2000],y[2000][2000],c,l,px,py,ans;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct node{
	int c,l;
}k[2000][2000];
int main(){

freopen("chess.in","r",stdin);
freopen("chess.out","w",stdout);
srand(time(NULL));
n=read();
m=read();
q=read();
for(int i=1;i<=n;i++){
	for(int j=1;j<m;j++){
		x[i][j]=read();
	}
}
for(int j=1;j<=m;j++){
	for(int i=1;i<n;i++){
		y[j][i]=read();
	}
}
while(q--){
	c=read();
	l=read();
	px=read();
	py=read();
	k[px][py].c=c;
	k[px][py].l=l;
	int s=4;
	for(int i=0;i<4;i++){
		int tx=px+dx[i];
		int ty=py+dy[i];
		if(k[tx][ty].l!=0){
			if(l<k[tx][ty].l||c==k[tx][ty].c)s--;
		}
	}
	cout<<s<<endl;
}
return 0;
}

