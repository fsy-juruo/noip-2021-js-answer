#include<bits/stdc++.h>
using namespace std;
int lv[1010][1010],x,y,m,n;
bool ps[1010][1010][7];
set<pair<int,int> > o;
inline int red()
{
	char ch;
	int bf;
	bf=0;
	ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		bf=(bf<<1)+(bf<<3)+(ch-'0');
		ch=getchar();
	}
	return bf;
}
void dfs(int xx,int yy,int rd)
{
	lv[xx][yy]=lv[x][y];
	switch(rd)
	{
		case 2:
			if((yy+1<=m)&&((lv[xx][yy]>=0&&lv[xx][yy+1]<=0)||(lv[xx][yy]<=0&&lv[xx][yy+1]>=0)))
			{
				if(ps[xx][yy][2])
				{
					o.insert(make_pair(xx,yy+1));
					if(lv[xx][yy+1]==0)
					dfs(xx,yy+1,2);
				}
			}
			break;
		case 3:
			if((yy+1<=m)&&((lv[xx][yy]>=0&&lv[xx][yy+1]<=0)||(lv[xx][yy]<=0&&lv[xx][yy+1]>=0)))
			{
				if(ps[xx][yy][3])
				{
					o.insert(make_pair(xx,yy+1));
					if(lv[xx][yy+1]==0)
					dfs(xx,yy+1,3);
				}
			}
			if((xx+1<=n)&&((lv[xx][yy]>=0&&lv[xx+1][yy]<=0)||(lv[xx][yy]<=0&&lv[xx+1][yy]>=0)))
			{
				if(ps[xx][yy][6])
				{
					o.insert(make_pair(xx+1,yy));
					if(lv[xx+1][yy]==0)
					dfs(xx+1,yy,6);
				}
			}
			if((xx-1>=1)&&((lv[xx][yy]>=0&&lv[xx-1][yy]<=0)||(lv[xx][yy]<=0&&lv[xx-1][yy]>=0)))
			{
				if(ps[xx-1][yy][6])
				{
					o.insert(make_pair(xx-1,yy));
					if(lv[xx-1][yy]==0)
					dfs(xx-1,yy,-6);
				}
			}
			break;
		case 4:
			if((xx+1<=n)&&((lv[xx][yy]>=0&&lv[xx+1][yy]<=0)||(lv[xx][yy]<=0&&lv[xx+1][yy]>=0)))
			{
				if(ps[xx][yy][4])
				{
					o.insert(make_pair(xx+1,yy));
					if(lv[xx+1][yy]==0)
					dfs(xx+1,yy,4);
				}
			}
			break;
		case 6:
			if((yy+1<=m)&&((lv[xx][yy]>=0&&lv[xx][yy+1]<=0)||(lv[xx][yy]<=0&&lv[xx][yy+1]>=0)))
			{
				if(ps[xx][yy][3])
				{
					o.insert(make_pair(xx,yy+1));
					if(lv[xx][yy+1]==0)
					dfs(xx,yy+1,3);
				}
			}
			if((xx+1<=n)&&((lv[xx][yy]>=0&&lv[xx+1][yy]<=0)||(lv[xx][yy]<=0&&lv[xx+1][yy]>=0)))
			{
				if(ps[xx][yy][6])
				{
					o.insert(make_pair(xx+1,yy));
					if(lv[xx+1][yy]==0)
					dfs(xx+1,yy,6);
				}
			}
			if((yy-1>=1)&&((lv[xx][yy]>=0&&lv[xx][yy-1]<=0)||(lv[xx][yy]<=0&&lv[xx][yy-1]>=0)))
			{
				if(ps[xx][yy-1][3])
				{
					o.insert(make_pair(xx,yy-1));
					if(lv[xx][yy-1]==0)
					dfs(xx,yy-1,-3);
				}
			}
			break;
		case -2:
			if((yy-1>=1)&&((lv[xx][yy]>=0&&lv[xx][yy-1]<=0)||(lv[xx][yy]<=0&&lv[xx][yy-1]>=0)))
			{
				if(abs(lv[xx][yy])>=abs(lv[xx][yy-1]))
				{
					if(ps[xx][yy-1][2])
					{
						o.insert(make_pair(xx,yy-1));
						if(lv[xx][yy-1]==0)
						dfs(xx,yy-1,-2);
					}
				}
			}
			break;
		case -3:
			if((xx+1<=n)&&((lv[xx][yy]>=0&&lv[xx+1][yy]<=0)||(lv[xx][yy]<=0&&lv[xx+1][yy]>=0)))
			{
				if(ps[xx][yy][6])
				{
					o.insert(make_pair(xx+1,yy));
					if(lv[xx+1][yy]==0)
					dfs(xx+1,yy,6);
				}
			}
			if((xx-1>=1)&&((lv[xx][yy]>=0&&lv[xx-1][yy]<=0)||(lv[xx][yy]<=0&&lv[xx-1][yy]>=0)))
			{
				if(ps[xx-1][yy][6])
				{
					o.insert(make_pair(xx-1,yy));
					if(lv[xx-1][yy]==0)
					dfs(xx-1,yy,-6);
				}
			}
			if((yy-1>=1)&&((lv[xx][yy]>=0&&lv[xx][yy-1]<=0)||(lv[xx][yy]<=0&&lv[xx][yy-1]>=0)))
			{
				if(ps[xx][yy-1][3])
				{
					o.insert(make_pair(xx,yy-1));
					if(lv[xx][yy-1]==0)
					dfs(xx,yy-1,-3);
				}
			}
			break;
		case -4:
			if((xx-1>=1)&&((lv[xx][yy]>=0&&lv[xx-1][yy]<=0)||(lv[xx][yy]<=0&&lv[xx-1][yy]>=0)))
			{
				if(abs(lv[xx][yy])>=abs(lv[xx-1][yy]))
				{
					if(ps[xx-1][yy][4])
					{
						o.insert(make_pair(xx-1,yy));
						if(lv[xx-1][yy]==0)
						dfs(xx-1,yy,-4);
					}
				}
			}
			break;
		case -6:
			if((yy+1<=m)&&((lv[xx][yy]>=0&&lv[xx][yy+1]<=0)||(lv[xx][yy]<=0&&lv[xx][yy+1]>=0)))
			{
				if(ps[xx][yy][3])
				{
					o.insert(make_pair(xx,yy+1));
					if(lv[xx][yy+1]==0)
					dfs(xx,yy+1,3);
				}
			}
			if((xx-1>=1)&&((lv[xx][yy]>=0&&lv[xx-1][yy]<=0)||(lv[xx][yy]<=0&&lv[xx-1][yy]>=0)))
			{
				if(ps[xx-1][yy][6])
				{
					o.insert(make_pair(xx-1,yy));
					if(lv[xx-1][yy]==0)
					dfs(xx-1,yy,-6);
				}
			}
			if((yy-1>=1)&&((lv[xx][yy]>=0&&lv[xx][yy-1]<=0)||(lv[xx][yy]<=0&&lv[xx][yy-1]>=0)))
			{
				if(ps[xx][yy-1][3])
				{
					o.insert(make_pair(xx,yy-1));
					if(lv[xx][yy-1]==0)
					dfs(xx,yy-1,-3);
				}
			}
			break;
		default: break;
	}
	lv[xx][yy]=0;
	return;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int a,b,c,d,q,t;
	t=red();
	while(t--)
	{
		memset(lv,0,sizeof(lv));
		memset(ps,false,sizeof(ps));
		n=red();
		m=red();
		q=red();
		for(a=1;a<=n;a++)
		{
			for(b=1;b<m;b++)
			{
				c=getchar()-'0';
				if(c!=0)
				ps[a][b][c]=true;
			}
			getchar();
		}
		for(a=1;a<n;a++)
		{
			for(b=1;b<=m;b++)
			{
				c=getchar()-'0';
				if(c!=0)
				{
					if(c==2)
					c=4;
					if(c==1)
					c=5;
					if(c==3)
					c=6;
					ps[a][b][c]=true;
				}
			}
			getchar();
		}
		for(a=1;a<=q;a++)
		{
			o.clear();
			scanf("%d%d%d%d",&c,&d,&x,&y);
			if(c==1)
			d=-d;
			lv[x][y]=d;
			if((y+1<=m)&&((lv[x][y]>=0&&lv[x][y+1]<=0)||(lv[x][y]<=0&&lv[x][y+1]>=0)))
			{
				if(abs(lv[x][y])>=abs(lv[x][y+1]))
				{
					if(ps[x][y][1])
					o.insert(make_pair(x,y+1));
					else
					{
						if(ps[x][y][2])
						{
							o.insert(make_pair(x,y+1));
							if(lv[x][y+1]==0)
							dfs(x,y+1,2);
						}
						else
							{
							if(ps[x][y][3])
							{
								o.insert(make_pair(x,y+1));
								if(lv[x][y+1]==0)
								dfs(x,y+1,3);
							}
						}
					}
				}
			}
			if((x+1<=n)&&((lv[x][y]>=0&&lv[x+1][y]<=0)||(lv[x][y]<=0&&lv[x+1][y]>=0)))
			{
				if(abs(lv[x][y])>=abs(lv[x+1][y]))
				{
					if(ps[x][y][5])
					o.insert(make_pair(x+1,y));
					else
					{
						if(ps[x][y][4])
						{
							o.insert(make_pair(x+1,y));
							if(lv[x+1][y]==0)
							dfs(x+1,y,4);
						}
						else
						{
							if(ps[x][y][6])
							{
								o.insert(make_pair(x+1,y));
								if(lv[x+1][y]==0)
								dfs(x+1,y,6);
							}
						}
					}
				}
			}
			if((x-1>=1)&&((lv[x][y]>=0&&lv[x-1][y]<=0)||(lv[x][y]<=0&&lv[x-1][y]>=0)))
			{
				if(abs(lv[x][y])>=abs(lv[x-1][y]))
				{
					if(ps[x-1][y][5])
					o.insert(make_pair(x-1,y));
					else
					{
						if(ps[x-1][y][4])
						{
							o.insert(make_pair(x-1,y));
							if(lv[x-1][y]==0)
							dfs(x-1,y,-4);
						}
						else
						{
							if(ps[x-1][y][6])
							{
								o.insert(make_pair(x-1,y));
								if(lv[x-1][y]==0)
								dfs(x-1,y,-6);
							}
						}
					}
				}
			}
			if((y-1>=1)&&((lv[x][y]>=0&&lv[x][y-1]<=0)||(lv[x][y]<=0&&lv[x][y-1]>=0)))
			{
				if(abs(lv[x][y])>=abs(lv[x][y-1]))
				{
					if(ps[x][y-1][1])
					o.insert(make_pair(x,y-1));
					else
					{
						if(ps[x][y-1][2])
						{
							o.insert(make_pair(x,y-1));
							if(lv[x][y-1]==0)
							dfs(x,y-1,-2);
						}
						else
							{
							if(ps[x][y-1][3])
							{
								o.insert(make_pair(x,y-1));
								if(lv[x][y-1]==0)
								dfs(x,y-1,-3);
							}
						}
					}
				}
			}
			printf("%d\n",o.size());
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
