//12.23 byebye
#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5,M=1e5+5;

int n,m,q;
int opt[N][3];
int st[N];

struct Node
{
	int c,lv,x,y;
}cs[M];

int get_id(int x,int y)
{
	return m*(x-1)+y; 
}

inline int read()
{
	int date=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') w=-1;c=getchar();}
	while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
	return date*w;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

void init()
{
	memset(opt,0,sizeof opt);
	memset(st,false,sizeof false);
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	T=read();
	
	while(T--)
	{
		init();
		n=read(),m=read(),q=read();
		
		char c;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				int t=get_id(i,j);
				c=getchar();
				if(c=='0') opt[t][0]=0;
				else opt[t][0]=1;
			}
			c=getchar();
		}
		
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int t=get_id(i,j);
				c=getchar();
				if(c=='0') opt[t][1]=0;
				else opt[t][1]=1;
			}
			c=getchar();
		}
		
		for(int i=1;i<=q;i++)
		{
			int ans=0;
			int c=read(),lv=read(),x=read(),y=read();
			cs[i]={c,lv,x,y};
			int k=get_id(x,y);
			int t=get_id(x,y+1);
			st[k]=i;
			if(opt[k][0])
			{
				if(!st[t])
				{
					ans++;
				}
				else
				{
					if(c!=cs[st[t]].c&&lv>=cs[st[t]].lv) ans++;
				}
			}
			t=get_id(x+1,y);
			if(opt[k][1])
			{
				if(!st[t]) 
				{
					ans++;
				}
				else
				{
					if(c!=cs[st[t]].c&&lv>=cs[st[t]].lv) ans++;
				}
			}
			if(x-1>0)
			{
				t=get_id(x-1,y);
				if(opt[t][1])
				{
					if(!st[t]) ans++;
					else if(c!=cs[st[t]].c&&lv>=cs[st[t]].lv) ans++;
				}	
			}
			if(y-1>0)
			{
				t=get_id(x,y-1);
				if(opt[t][0])
				{
					if(!st[t]) ans++;
					else if(c!=cs[st[t]].c&&lv>=cs[st[t]].lv) ans++;
				}
			}
			write(ans);
			puts("");
		}
	}
}
/*
1
3 3 2
11
10
11
111
111
0 1 2 3
1 2 2 2
*/
