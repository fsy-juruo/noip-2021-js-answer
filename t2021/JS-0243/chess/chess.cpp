#include<bits/stdc++.h>
#define MP make_pair 
using namespace std;
struct node{
	int kind,xto,yto;
};
map<pair<int,int>,int>vis,c,l,vis2; 
int n,m,t,q;
string s;
int col[300001],lv[300001],x[300001],y[300001];
vector<int> a[300001],b[300001];
void read(int &x)
{
	int f=1;char ch;
	while(ch=getchar(),!isdigit(ch))if(ch=='-')f=-1;x=ch-'0';
	while(ch=getchar(),isdigit(ch))x=(x<<3)+(x<<1)+ch-'0';x*=f;
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
void writeln(int x)
{
	write(x);
	putchar('\n');
}
int eat(int x,int y,int a,int b)
{
	if(c[MP(x,y)]!=c[MP(a,b)])
	{
		if(l[MP(x,y)]>=l[MP(a,b)])
		return 1;
	}
	return 0;
}
void dfs(int dep,int x,int y,int kind,int q,int bx,int by)
{
//	cout<<dep<<' '<<x<<' '<<y<<' '<<kind<<' '<<q<<' '<<bx<<' '<<by<<endl;
	vis[MP(x,y)]=1;
	if(x>1)
	{
		int p=b[x-1][y];
		//cout<<p<<endl;
		if(p!=0)
		{
			if(kind==0)
			{
				if((!vis.count(MP(x-1,y))||vis[MP(x-1,y)]==0)&&(!vis2.count(MP(x-1,y))||vis2[MP(x-1,y)]!=p))
				{
				vis[MP(x-1,y)]=1;
			    if(c.count(MP(x-1,y)))
			    {
			    	if(eat(bx,by,x-1,y))
			    	{
			    		vis2[MP(x-1,y)]=p;
					}
				}
				else
				{
					vis2[MP(x-1,y)]=p;
					dfs(dep+1,x-1,y,p,1,bx,by);
				}
				vis[MP(x-1,y)]=0;
			    }
			}
			else
			{
				if((kind==p&&p==3)||((kind==p&&p==2&&q==1)))
				{
				if((!vis.count(MP(x-1,y))||vis[MP(x-1,y)]==0)&&(!vis2.count(MP(x-1,y))||vis2[MP(x-1,y)]!=p))
				{
				vis[MP(x-1,y)]=1;
			    if(c.count(MP(x-1,y)))
			    {
			    	if(eat(bx,by,x-1,y))
			    	{
			    		vis2[MP(x-1,y)]=p;
					}
				}
				else
				{
					vis2[MP(x-1,y)]=p;
					dfs(dep+1,x-1,y,p,q,bx,by);
				}
				vis[MP(x-1,y)]=0;
			    }
				}	
			}
		}
	}
	if(x<n)
	{
		int p=b[x][y];
		//cout<<p<<endl;
		if(p!=0)
		{
			if(kind==0)
			{
				if((!vis.count(MP(x+1,y))||vis[MP(x+1,y)]==0)&&(!vis2.count(MP(x+1,y))||vis2[MP(x+1,y)]!=p))
				{
				vis[MP(x+1,y)]=1;
			    if(c.count(MP(x+1,y)))
			    {
			    	if(eat(bx,by,x+1,y))
			    	{
			    		vis2[MP(x+1,y)]=p;
					}
				}
				else
				{
					vis2[MP(x+1,y)]=p;
					dfs(dep+1,x+1,y,p,1,bx,by);
				}vis[MP(x+1,y)]=0;
			    }
			}
			else
			{
				if((kind==p&&p==3)||((kind==p&&p==2&&q==1)))
				{
					
				if((!vis.count(MP(x+1,y))||vis[MP(x+1,y)]==0)&&(!vis2.count(MP(x+1,y))||vis2[MP(x+1,y)]!=p))
				{
				vis[MP(x+1,y)]=p;
			    if(c.count(MP(x+1,y)))
			    {
			    	if(eat(bx,by,x+1,y))
			    	{
			    		vis2[MP(x+1,y)]=1;
					}
				}
				else
				{
					vis2[MP(x+1,y)]=p;
					dfs(dep+1,x+1,y,p,q,bx,by);
				}
				vis[MP(x+1,y)]=0;
			    }
				}	
			}
		}
	}
	if(y>1)
	{
		int p=a[x][y-1];
		//cout<<p<<endl;
		if(p!=0)
		{
			if(kind==0)
			{
				if((!vis.count(MP(x,y-1))||vis[MP(x,y-1)]==0)&&(!vis2.count(MP(x,y-1))||vis2[MP(x,y-1)]!=p))
				{
				vis[MP(x,y-1)]=1;
			    if(c.count(MP(x,y-1)))
			    {
			    	if(eat(bx,by,x,y-1))
			    	{
			    		vis2[MP(x,y-1)]=p;
					}
				}
				else
				{
					vis2[MP(x,y-1)]=p;
					dfs(dep+1,x,y-1,p,2,bx,by);
				}
				vis[MP(x,y-1)]=0;
			    }
			    
			}
			else
			{
				if((kind==p&&p==3)||((kind==p&&p==2&&q==2)))
				{
				
				if((!vis.count(MP(x,y-1))||vis[MP(x,y-1)]==0)&&(!vis2.count(MP(x,y-1))||vis2[MP(x,y-1)]!=p))
				{
				vis[MP(x,y-1)]=1;
			    if(c.count(MP(x,y-1)))
			    {
			    	if(eat(bx,by,x,y-1))
			    	{
			    		vis2[MP(x,y-1)]=p;
					}
				}
				else
				{
					vis2[MP(x,y-1)]=p;
					dfs(dep+1,x,y-1,p,q,bx,by);
				}
				vis[MP(x,y-1)]=0;
			    }
				}	
			}
		}
	}
	if(y<m)
	{
		int p=a[x][y];
		//cout<<p<<endl;
		if(p!=0)
		{
			if(kind==0)
			{
				if((!vis.count(MP(x,y+1))||vis[MP(x,y+1)]==0)&&(!vis2.count(MP(x,y+1))||vis2[MP(x,y+1)]!=p))
				{
				vis[MP(x,y+1)]=1;
			    if(c.count(MP(x,y+1)))
			    {
			    	if(eat(bx,by,x,y+1))
			    	{
			    		vis2[MP(x,y+1)]=p;
					}
				}
				else
				{
					vis2[MP(x,y+1)]=p;
					dfs(dep+1,x,y+1,p,2,bx,by);
				}
				vis[MP(x,y+1)]=0;
			    }
			    
			}
			else
			{
				if((kind==p&&p==3)||((kind==p&&p==2&&q==2)))
				{
				
				if((!vis.count(MP(x,y+1))||vis[MP(x,y+1)]==0)&&(!vis2.count(MP(x,y+1))||vis2[MP(x,y+1)]!=p))
				{
				vis[MP(x,y+1)]=1;
			    if(c.count(MP(x,y+1)))
			    {
			    	if(eat(bx,by,x,y+1))
			    	{
			    		vis2[MP(x,y+1)]=p;
					}
				}
				else
				{
					vis2[MP(x,y+1)]=p;
					dfs(dep+1,x,y+1,p,q,bx,by);
				}
				vis[MP(x,y+1)]=0;
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
	cin>>t;
	while(t--)
	{
		read(n),read(m),read(q);
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			a[i].push_back(0);
			for(int j=0;j<s.size();j++)
			{
				a[i].push_back(int(s[j])-48);
			}
		}
		for(int i=1;i<n;i++)
		{
			cin>>s;
			b[i].push_back(0);
			for(int j=0;j<s.size();j++)
			{
				b[i].push_back(int(s[j])-48);
			}
		}
		
		for(int i=1;i<=q;i++)
		{
			read(col[i]),read(lv[i]),read(x[i]),read(y[i]);
			c[MP(x[i],y[i])]=col[i];
			l[MP(x[i],y[i])]=lv[i];
			dfs(0,x[i],y[i],0,0,x[i],y[i]);
			writeln(vis2.size());
			vis2.clear();
			vis.clear();
		 } 
		c.clear();
		l.clear();
		for(int i=1;i<=n;i++)
		{
			a[i].clear();
			b[i].clear();
		}
	}
	
	return 0;
}

