#include<bits/stdc++.h>
using namespace std;
template<typename T> void read(T &x)
{
	long long f=1;x=0;char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	x*=f;
}
template<typename T> void write(T x)
{
	if(x<0)
	{
		putchar('-');x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
template<typename T> void writeln(T x)
{
	write(x);putchar('\n');
}
int T,n,m,q,co,lv,x,y;
char h;
string sa[100010],sb[100010];
struct duck{
	int lv,co;
};
struct qi{
	bool b[10];
};
vector<duck> qp[100010];
vector<qi> f[100010];
void bfs(int x,int y,int co,int lv)
{
	struct heqi{
		int x,y,fx,pt;
	}ls;
	queue<heqi> q;
	ls.x=x;ls.y=y;ls.fx=5;ls.pt=1;f[x][y-1].b[9]=1;
	q.push(ls);
	while(!q.empty())
	{
		heqi p=q.front();q.pop();
		if(p.x>1)
		{
			if(sb[p.x-1][p.y-1]=='1')
			{
				if(p.pt==1)
				{
					
					ls.x=p.x-1;ls.y=p.y;ls.fx=5;ls.pt=0;
					if(qp[p.x-1][p.y-1].lv==0)
					{
						if(f[x-1][y-1].b[4]==0)
						{
						f[x-1][y-1].b[4]=1;
						q.push(ls);	
						}
					}
					else
					{
						if(qp[p.x-1][p.y-1].co!=co)
						{
							if(qp[p.x-1][p.y-1].lv<=lv) f[x-1][y-1].b[4]=1;
						}
					}
				}
			}
			if(sb[p.x-1][p.y-1]=='2')
			{
				if((p.fx==1)||(p.fx==5))
				{
					ls.x=p.x-1;ls.y=p.y;ls.fx=1;ls.pt=p.pt;
					if(qp[p.x-1][p.y-1].lv==0)
					{
						if(f[x-1][y-1].b[p.pt*5]==0)
						{
						f[x-1][y-1].b[p.pt*5]=1;
						q.push(ls);	
						}
					}
					else
					{
						if(qp[p.x-1][p.y-1].co!=co)
						{
							if(qp[p.x-1][p.y-1].lv<=lv) f[x-1][y-1].b[p.pt*5]=1;
						}
					}
				}
			}
			if(sb[p.x-1][p.y-1]=='3')
			{
				ls.x=p.x-1;ls.y=p.y;ls.fx=5;ls.pt=p.pt;
				if(qp[p.x-1][p.y-1].lv==0)
				{
						if(f[x-1][y-1].b[p.pt*5+4]==0)
						{
						f[x-1][y-1].b[p.pt*5+4]=1;
						q.push(ls);	
						}
				}
				else
				{
					if(qp[p.x-1][p.y-1].co!=co)
					{
						if(qp[p.x-1][p.y-1].lv<=lv) f[x-1][y-1].b[p.pt*5+4]=1;
					}
				}
			}
		}
		if(p.x<n)
		{
			if(sb[p.x+1][p.y-1]=='1')
			{
				if(p.pt==1)
				{
					
					ls.x=p.x+1;ls.y=p.y;ls.fx=5;ls.pt=0;
					if(qp[p.x+1][p.y-1].lv==0)
					{
						if(f[x+1][y-1].b[4]==0)
						{
						f[x+1][y-1].b[4]=1;
						q.push(ls);	
						}
					}
					else
					{
						if(qp[p.x+1][p.y-1].co!=co)
						{
							if(qp[p.x+1][p.y-1].lv<=lv) f[x+1][y-1].b[4]=1;
						}
					}
				}
			}
			if(sb[p.x+1][p.y-1]=='2')
			{
				if((p.fx==1)||(p.fx==5))
				{
					ls.x=p.x+1;ls.y=p.y;ls.fx=2;ls.pt=p.pt;
					if(qp[p.x+1][p.y-1].lv==0)
					{
						if(f[x+1][y-1].b[p.pt*5+1]==0)
						{
						f[x+1][y-1].b[p.pt*5+1]=1;
						q.push(ls);	
						}
					}
					else
					{
						if(qp[p.x+1][p.y-1].co!=co)
						{
							if(qp[p.x+1][p.y-1].lv<=lv) f[x+1][y-1].b[p.pt*5+1]=1;
						}
					}
				}
			}
			if(sb[p.x+1][p.y-1]=='3')
			{
				ls.x=p.x+1;ls.y=p.y;ls.fx=5;ls.pt=p.pt;
				if(qp[p.x+1][p.y-1].lv==0)
				{
						if(f[x+1][y-1].b[p.pt*5+4]==0)
						{
						f[x+1][y-1].b[p.pt*5+4]=1;
						q.push(ls);	
						}
				}
				else
				{
					if(qp[p.x+1][p.y-1].co!=co)
					{
						if(qp[p.x+1][p.y-1].lv<=lv) f[x-1][y-1].b[p.pt*5+4]=1;
					}
				}
			}
		}
		if(p.y>1)
		{
			if(sa[p.x][p.y-2]=='1')
			{
				if(p.pt==1)
				{
					
					ls.x=p.x;ls.y=p.y-1;ls.fx=5;ls.pt=0;
					if(qp[p.x][p.y-2].lv==0)
					{
						if(f[x][y-2].b[4]==0)
						{
						f[x][y-2].b[4]=1;
						q.push(ls);	
						}
					}
					else
					{
						if(qp[p.x][p.y-2].co!=co)
						{
							if(qp[p.x][p.y-2].lv<=lv) f[x][y-2].b[4]=1;
						}
					}
				}
			}
			if(sa[p.x][p.y-2]=='2')
			{
				if((p.fx==1)||(p.fx==5))
				{
					ls.x=p.x;ls.y=p.y-1;ls.fx=3;ls.pt=p.pt;
					if(qp[p.x][p.y-2].lv==0)
					{
						if(f[x][y-2].b[p.pt*5+2]==0)
						{
						f[x][y-2].b[p.pt*5+2]=1;
						q.push(ls);	
						}
					}
					else
					{
						if(qp[p.x][p.y-2].co!=co)
						{
							if(qp[p.x][p.y-2].lv<=lv) f[x][y-2].b[p.pt*5+2]=1;
						}
					}
				}
			}
			if(sa[p.x][p.y-2]=='3')
			{
				ls.x=p.x;ls.y=p.y-1;ls.fx=5;ls.pt=p.pt;
				if(qp[p.x][p.y-2].lv==0)
				{
						if(f[x][y-2].b[p.pt*5+4]==0)
						{
						f[x][y-2].b[p.pt*5+4]=1;
						q.push(ls);	
						}
				}
				else
				{
					if(qp[p.x][p.y-2].co!=co)
					{
						if(qp[p.x][p.y-2].lv<=lv) f[x][y-2].b[p.pt*5+4]=1;
					}
				}
			}
		}
		if(p.y<n)
		{
			if(sa[p.x][p.y]=='1')
			{
				if(p.pt==1)
				{
					
					ls.x=p.x;ls.y=p.y+1;ls.fx=5;ls.pt=0;
					if(qp[p.x][p.y].lv==0)
					{
						if(f[x][y].b[4]==0)
						{
						f[x][y].b[4]=1;
						q.push(ls);	
						}
					}
					else
					{
						if(qp[p.x][p.y].co!=co)
						{
							if(qp[p.x][p.y].lv<=lv) f[x][y].b[4]=1;
						}
					}
				}
			}
			if(sa[p.x][p.y]=='2')
			{
				if((p.fx==1)||(p.fx==5))
				{
					ls.x=p.x;ls.y=p.y+1;ls.fx=4;ls.pt=p.pt;
					if(qp[p.x][p.y].lv==0)
					{
						if(f[x][y].b[p.pt*5+3]==0)
						{
						f[x][y].b[p.pt*5+3]=1;
						q.push(ls);	
						}
					}
					else
					{
						if(qp[p.x][p.y].co!=co)
						{
							if(qp[p.x][p.y].lv<=lv) f[x][y].b[p.pt*5+3]=1;
						}
					}
				}
			}
			if(sa[p.x][p.y]=='3')
			{
				ls.x=p.x;ls.y=p.y+1;ls.fx=5;ls.pt=p.pt;
				if(qp[p.x][p.y].lv==0)
				{
						if(f[x][y].b[p.pt*5+4]==0)
						{
						f[x][y].b[p.pt*5+4]=1;
						q.push(ls);	
						}
				}
				else
				{
					if(qp[p.x][p.y].co!=co)
					{
						if(qp[p.x][p.y].lv<=lv) f[x][y].b[p.pt*5+4]=1;
					}
				}
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n);read(m);read(q);
		for(int i=1;i<=n;i++)
		{
			sa[i].clear();sb[i].clear();qp[i].clear();f[i].clear();
		}
		
		for(int i=1;i<=n;i++)
		 for(int j=1;j<m;j++)
		 {
		 	h=getchar();
		 	while((h!='0')&&(h!='1')&&(h!='2')&&(h!='3')) h=getchar();
		 	sa[i].push_back(h);
		 }
		for(int i=1;i<n;i++)
		 for(int j=1;j<=m;j++)
		 {
		 	h=getchar();
		 	while((h!='0')&&(h!='1')&&(h!='2')&&(h!='3')) h=getchar();
		 	sb[i].push_back(h);
		 }
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=m;j++)
		 {
		 	duck he;
		 	he.co=0;he.lv=0;
		 	qp[i].push_back(he);
		 }
		for(int i=1;i<=q;i++)
		{
			read(co);read(lv);read(x);read(y);
			qp[x][y-1].co=co+1;qp[x][y-1].lv=lv;
			for(int j=1;j<=n;j++)
			 for(int k=1;k<=m;k++) 
			 {
			 	qi ll;f[j].push_back(ll);
			 }
			bfs(x,y,co,lv);int tot=0,ltot;
			for(int j=1;j<=n;j++)
			 for(int k=0;k<m;k++)
			 {
			 	ltot=0;
				 for(int l=0;l<10;l++) ltot=max(ltot,(int)f[j][k].b[l]);
				tot+=ltot;
			 }
			writeln(tot);  
		} 
	}
	return 0;
}
//明日复明日，明日和棋多 
