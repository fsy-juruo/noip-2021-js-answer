#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,t,T,vis[1010][1010],p,P,Col[1010][1010],Lin[1010][1010];
struct node1
{
  int x,y,lev,opt;
}a[1010][1010];
struct node
{
  int x,y;
};
queue<node>A;

bool check1(int x,int y,int z,int l)//x-1,y 
{
  if(a[x-1][y].lev==0)return true;
  if(a[x-1][y].opt!=z&&a[x-1][y].lev<=l)return true;
  return false;
}
bool check2(int x,int y,int z,int l)//x,y-1
{
  if(a[x][y-1].lev==0)return true;
  if(a[x][y-1].opt!=z&&a[x][y-1].lev<=l)return true;
  return false;
}
bool check3(int x,int y,int z,int l)//x+1,y
{
  if(a[x+1][y].lev==0)return true;
  if(a[x+1][y].opt!=z&&a[x+1][y].lev<=l)return true;
  return false;
}
bool check4(int x,int y,int z,int l)//x,y+1
{
  if(a[x][y+1].lev==0)return true;
  if(a[x][y+1].opt!=z&&a[x][y+1].lev<=l)return true;
  return false;
}
void bfs(int x,int y,int z,int l)
{
  while(!A.empty())A.pop();
  node q;
  q.x=x;q.y=y;
  A.push(q);
  while(!A.empty())
  {
    q=A.front();
    A.pop();
    vis[q.x][q.y]=1;
    if(!vis[q.x-1][q.y]&&Lin[q.x-1][q.y]==3&&check1(q.x,q.y,z,l)){node w;w.x=q.x-1,w.y=q.y;A.push(w);}
    if(!vis[q.x+1][q.y]&&Lin[q.x][q.y]==3&&check3(q.x,q.y,z,l)){node w;w.x=q.x+1,w.y=q.y;A.push(w);}
    if(!vis[q.x][q.y-1]&&Col[q.x][q.y-1]==3&&check2(q.x,q.y,z,l)){node w;w.x=q.x,w.y=q.y-1;A.push(w);}
    if(!vis[q.x][q.y+1]&&Col[q.x][q.y]==3&&check4(q.x,q.y,z,l)){node w;w.x=q.x,w.y=q.y+1;A.push(w);}
  }
}
void dfs(int x,int y,int z,int l)
{
  //1
  if(a[x-1][y].lev!=0)
  {
  	if(a[x-1][y].lev<=l&&a[x-1][y].opt!=z&&Lin[x-1][y]!=0)vis[x-1][y]=1;
  }
  else
  {
  	if(Lin[x-1][y]==1)vis[x-1][y]=1;
  	if(Lin[x-1][y]==2)
    {
      vis[x-1][y]=1;
      int i=x-1;
      while(Lin[i-1][y]==2&&check1(i,y,z,l))
        vis[i-1][y]=1,i--;
	}
	if(Lin[x-1][y]==3)
	  bfs(x-1,y,z,l);
  }
  //2
  if(a[x+1][y].lev!=0)
  {
  	if(a[x+1][y].lev<=l&&a[x+1][y].opt!=z&&Lin[x][y]!=0)vis[x+1][y]=1;
  }
  else
  {
  	if(Lin[x][y]==1)vis[x+1][y]=1;
  	if(Lin[x][y]==2)
    {
      vis[x+1][y]=1;
      int i=x+1;
      while(Lin[i][y]==2&&check3(i,y,z,l))
        vis[i+1][y]=1,i++;
	}
	if(Lin[x][y]==3)
	  if(!vis[x+1][y])bfs(x+1,y,z,l);
  }
  
  if(a[x][y-1].lev!=0)
  {
  	if(a[x][y-1].lev<=l&&a[x][y-1].opt!=z&&Col[x][y-1]!=0)vis[x][y-1]=1;
  }
  else
  {
  	if(Col[x][y-1]==1)vis[x][y-1]=1;
  	if(Col[x][y-1]==2)
    {
      vis[x][y-1]=1;
      int i=y-1;
      while(Col[x][i-1]==2&&check2(x,i,z,l))
        vis[x][i-1]=1,i--;
	}
	if(Col[x][y-1]==3)
	  if(!vis[x][y-1])bfs(x,y-1,z,l);
  }
  
  if(a[x][y+1].lev!=0)
  {
  	if(a[x][y+1].lev<=l&&a[x][y+1].opt!=z&&Col[x][y]!=0)vis[x][y+1]=1;
  }
  else
  {
  	if(Col[x][y]==1)vis[x][y+1]=1;
  	if(Col[x][y]==2)
    {
      vis[x][y+1]=1;
      int i=y+1;
      while(Col[x][i]==2&&check4(x,i,z,l))
        vis[x][i+1]=1,i++;
	}
	if(Col[x][y]==3)
	  if(!vis[x][y+1])bfs(x,y+1,z,l);
  }
  
}
int calc()
{
  int sum=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(vis[i][j])sum++;
  return sum;
}
int main()
{
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);
  scanf("%d",&T);
  for(t=1;t<=T;t++)
  {
  	scanf("%d%d%d",&n,&m,&P);
  	memset(Lin,0,sizeof(Lin));
  	memset(Col,0,sizeof(Col));
  	for(i=1;i<=n;i++)
  	  for(j=1;j<=m;j++)
  	    a[i][j].lev=0;
	for(i=1;i<=n;i++)//i,j->i,j+1
  	{
  	  char c=getchar();
  	  while(!isdigit(c))c=getchar();
  	  for(j=1;j<m;j++)
  	  {
  	  	p=c-48;
  	  	Col[i][j]=p;
  	  	c=getchar();
	  }
	}
  	for(i=1;i<n;i++)//i,j->i+1,j
  	{
  	  char c=getchar();
  	  while(!isdigit(c))c=getchar();
  	  for(j=1;j<=m;j++)
  	  {
  	  	p=c-48;
  	  	Lin[i][j]=p;
  	  	c=getchar();
	  }
	}
//	for(i=1;i<n;i++)
//	{
//	  for(j=1;j<=m;j++)
//	    printf("%d ",Lin[i][j]);
//	  printf("\n");
//	}
	  
	for(i=1;i<=P;i++)
	{
	  int opt,lev,x,y;
	  scanf("%d%d%d%d",&opt,&lev,&x,&y);
	  memset(vis,0,sizeof(vis));
	  vis[x][y]=1;
	  dfs(x,y,opt,lev);
//	  for(int i=1;i<=n;i++)
//	  {
//	  	for(int j=1;j<=m;j++)
//	  	  printf("%d ",vis[i][j]);
//	  	printf("\n");
//	  }
	  printf("%d\n",calc()-1);
	  a[x][y].opt=opt;
	  a[x][y].lev=lev;
//	  printf("%d %d\n",i,p);
 	}
  }
  
  return 0;
}
