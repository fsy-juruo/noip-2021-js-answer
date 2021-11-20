#include<bits/stdc++.h>
using namespace std;
int xro[5005][5005],yro[5005][5005],n,m,q;
struct c{
	int lv;
	int co;
}p[5005][5005];
struct tp{
	int x;int y;
};
queue <tp> g;
 int ch(int x,int y,int col,int lv,int r,int f){
	int ans=0,a1,a2,a3,a4;
	if(x>n||y>m||x<1||y<1)
	return 0;
	if(p[x][y].co==col)
	return 0;
	if(p[x][y].lv>lv)
	return 0;
	if(p[x][y].lv!=0)
	return 1;
	if(r<=1)
	return r;
    if(r==5)
{
	p[x][y].co=col;
	a1=ch(x+1,y,col,lv,xro[x][y],1);
	a2=ch(x-1,y,col,lv,xro[x-1][y],1);
	a3=ch(x,y+1,col,lv,xro[x][y],2);
	a4=ch(x,y-1,col,lv,xro[x][y-1],2);
	p[x][y].co=0;
	return a1+a2+a3+a4;
	
}
if(r==2)
{
	p[x][y].co=col;
	if(f==1){
		if(xro[x][y]==2)
		a1=ch(x+1,y,col,lv,2,1);
		if(xro[x-1][y]==2)
		a2=ch(x-1,y,col,lv,2,1);
	}
	if(f==2){
		if(yro[x][y]==2)
		a1=ch(x,y+1,col,lv,2,2);
		if(yro[x][y-1]==2)
		a2=ch(x,y-1,col,lv,2,2);
	}
	p[x][y].co=0;
	return a1+a2;
}
if(r==3)
{
	p[x][y].co=col;

		if(xro[x][y]==3)
		a1=ch(x+1,y,col,lv,3,1);
		if(xro[x-1][y]==3)
		a2=ch(x-1,y,col,lv,3,1);
		if(yro[x][y]==3)
		a3=ch(x,y+1,col,lv,3,2);
		if(yro[x][y-1]==3)
		a4=ch(x,y-1,col,lv,3,2);
	p[x][y].co=0;
	return a1+a2+a3+a4;
}
}
int main()
{
	int T;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
cin>>T;
while(T--)
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		p[i][j].co=0;
		p[i][j].lv=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		yro[i][j]=getchar()-'0';
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		xro[i][j]=getchar()-'0';
	}
	int lv,x,y;
	int  col;
	for(int i=1;i<=q;i++)
	{
		cin>>col>>lv>>x>>y;
		col++;
		p[x][y].co=col;
		p[x][y].lv=lv;
		cout<<ch(x,y,col,lv,0,0)<<endl;
	}
	
}
}
