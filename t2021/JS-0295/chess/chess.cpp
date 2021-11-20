#include <cstdio>
#include <cstdlib>

int n,m,q;
int **col,**lin,**bod,**clr;

void del()
{
	for(int i=0;i<=n;i++)
	{
		delete[] col[i];
		if(i!=n)
			delete[] lin[i];
		delete[] bod[i];
		delete[] clr[i];
	}
	delete[] col;
	delete[] lin;
	delete[] bod;
	delete[] clr;
	return;
}

void init()
{
	scanf("%d%d%d",&n,&m,&q);
	col=new int*[n+1];
	col[0]=nullptr;
	for(int i=1;i<=n;i++)
	{
		col[i]=new int[m];
		for(int j=1;j<m;j++)
			scanf("%1d",&col[i][j]);
	}
	lin=new int*[n];
	lin[0]=nullptr;
	for(int i=1;i<n;i++)
	{
		lin[i]=new int[m+1];
		for(int j=1;j<=m;j++)
			scanf("%1d",&lin[i][j]);
	}
	bod=new int*[n+1];clr=new int*[n+1];
	bod[0]=nullptr;clr[0]=nullptr;
	for(int i=1;i<=n;i++)
	{
		bod[i]=new int[m+1];clr[i]=new int[m+1];
		for(int j=1;j<=m;j++)
			bod[i][j]=clr[i][j]=-1;
	}
	return;
}

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int sch(int x,int y,int from,int type,int color,int lv)
{
	if(clr[x][y]==color||(bod[x][y]!=-1&&bod[x][y]>lv))
		return 0;
	int ans=1;
	if(from!=RIGHT&&y<m&&col[x][y]==type&&(type==3||(type==2&&from==LEFT)))
		ans+=sch(x,y+1,LEFT,type,color,lv);
	if(from!=LEFT&&y>1&&col[x][y-1]==type&&(type==3||(type==2&&from==RIGHT)))
		ans+=sch(x,y-1,RIGHT,type,color,lv);
	if(from!=DOWN&&x<n&&lin[x][y]==type&&(type==3||(type==2&&from==UP)))
		ans+=sch(x+1,y,UP,type,color,lv);
	if(from!=DOWN&&x>1&&lin[x-1][y]==type&&(type==3||(type==2&&from==DOWN)))
		ans+=sch(x-1,y,DOWN,type,color,lv);
	return ans;
}

void work()
{
	for(int i=0;i<q;i++)
	{
		int cor,lv,x,y;
		scanf("%d%d%d%d",&cor,&lv,&x,&y);
		bod[x][y]=lv,clr[x][y]=cor;
		int ans=0;
		if(y<m&&col[x][y]!=0)
			ans+=sch(x,y+1,LEFT,col[x][y],cor,lv);
		if(y>1&&col[x][y-1]!=0)
			ans+=sch(x,y-1,RIGHT,col[x][y-1],cor,lv);
		if(x<n&&lin[x][y]!=0)
			ans+=sch(x+1,y,UP,lin[x][y],cor,lv);
		if(x>1&&lin[x-1][y]!=0)
			ans+=sch(x-1,y,DOWN,lin[x-1][y],cor,lv);
		printf("%d\n",ans);
	}
	return;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		init();
		work();
		del();
	}
	return 0;
}
