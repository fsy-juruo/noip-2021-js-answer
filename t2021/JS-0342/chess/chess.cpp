#include<bits/stdc++.h>
using namespace std;
//!I forget how to write fast-read&fast-write
//(>_<)!!!
int c,l,x,y;
const int maxn=1e5+7;
int n,m,q,T; 
struct node{
	bool vis;
	int x1;
	int y1;
	int col,lv;
}way[10][10];
void inp()
{
	scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=m-1;j++)  
		        scanf("%1d",&way[i][j].x1);
		for(int i=1;i<=n-1;i++)
		    for(int j=1;j<=m;j++)
		        scanf("%1d",&way[i][j].y1);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d%d%d",&c,&l,&x,&y);
			way[x][y].vis=true;
			way[x][y].col=c;
			way[x][y].lv=l;
		}
}
int main()
{
	//金陵中学河西校区C-14的右shift键非常难按下去
	//在此强烈谴责一下
	//我调教了它好久都没办法顺畅地使用（（
	//以及，麻烦小z同学不会的问题自己解决（雾 
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	int ans=0;
	while(T--)
	{
		inp();
		//骗一下7~8的分数 
		if(way[x][y-1].vis==false||(way[x][y].col!=way[x][y-1].col && way[x][y].lv>way[x][y-1].lv && way[x][y-1].vis==true))
		   ans++;
		if(way[x][y+1].vis==false||(way[x][y].col!=way[x][y+1].col && way[x][y].lv>way[x][y+1].lv && way[x][y+1].vis==true))
		   ans++;
		if(way[x+1][y].vis==false||(way[x][y].col!=way[x+1][y].col && way[x][y].lv>way[x+1][y].lv && way[x+1][y].vis==true))
		   ans++;
		if(way[x-1][y].vis==false||(way[x][y].col!=way[x-1][y].col && way[x][y].lv>way[x-1][y].lv && way[x-1][y].vis==true))
		   ans++;
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
