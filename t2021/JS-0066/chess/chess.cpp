#include<stdio.h>
#include<string.h>
#include<queue>
#define MAXN 200005
typedef long long ll;
using namespace std;
void readc(char &c)	{c=getchar();for	(;c<'0'||c>'3';c=getchar());}
template<typename qwq> void read(qwq &a)
{
	a=0;char c=getchar();int x=1;
	for	(;c<'0'||c>'9';c=getchar())	x=c=='-'?-x:x;
	for	(;c>='0'&&c<='9';a=(a<<1)+(a<<3)+(c^48),c=getchar());a*=x;
}
template<typename qwq> void write(qwq a){if	(a>9)	write(a/10);putchar(a%10+48);}
template<typename qwq> void twrite(qwq a){if	(a<0)	putchar('-'),write(-a);else	write(a);}
template<typename qwq> void writeln(qwq a)	{twrite(a),puts("");}
struct edge_{
	int to_,next_,value_,tp_;
} e[MAXN<<2];
int head[MAXN],tot;
void Add(int x,int y,int z,int w)
{
	e[++tot].to_=y;
	e[tot].value_=z;
	e[tot].tp_=w;
	e[tot].next_=head[x];
	head[x]=tot;
}
char hx[MAXN],sx[MAXN];
int lv[MAXN],cl[MAXN],vis[MAXN],tv[MAXN][4];
int N,M,Q,NM;
bool ex[MAXN];
void bfs(int col,int rk,int now)
{
	int ans=0;
	queue<pair<int,int> > a;
	ex[now]=true,lv[now]=rk,cl[now]=col;
	for	(int i=head[now],y,z,w;i;i=e[i].next_)
		{
			y=e[i].to_,z=e[i].value_,w=e[i].tp_;
			if	(!ex[y])
				{
					if	(z==1)	vis[y]=now,ans++;
					if	(z==2)	a.push(make_pair(y,w)),vis[y]=now,ans++;
				}
			else
				{
					if	(lv[y]<=rk&&cl[y]!=col)	vis[y]=now,ans++;
				}
		}
	while	(!a.empty())
		{
			pair<int,int> xx=a.front();a.pop();
			int x=xx.first,t=xx.second;
			for	(int i=head[x],y,z,w;i;i=e[i].next_)
				{
					y=e[i].to_,z=e[i].value_,w=e[i].tp_;
					if	(z==2&&w==t&&tv[y][t]!=now)
						{
							if	(ex[y])
								{
									if	(vis[y]!=now&&cl[y]!=col&&lv[y]<=rk)	ans++,vis[y]=now;
									continue;
								}
							if	(vis[y]!=now)	ans++,vis[y]=now;
							a.push(make_pair(y,t));
							tv[y][t]=now;
						}
				}
		}
	queue<int> b;
	for	(int i=head[now],y,z;i;i=e[i].next_)
		{
			y=e[i].to_,z=e[i].value_;
			if	(z==3)
				{
					if	(!ex[y])
						{
							b.push(y);
							if	(vis[y]!=now)	vis[y]=now,ans++;
						}
					else
						{
							if	(lv[y]<=rk&&cl[y]!=col&&vis[y]!=now)	vis[y]=now,ans++;
						}
				}
		}
	while	(!b.empty())
		{
			int x=b.front();b.pop();
			for	(int i=head[x],y,z;i;i=e[i].next_)
				{
					y=e[i].to_,z=e[i].value_;
					if	(z==3&&tv[y][3]!=now)
						{
							if	(ex[y])
								{
									if	(vis[y]!=now&&cl[y]!=col&&lv[y]<=rk)	ans++,vis[y]=now;
									continue;
								}
							if	(vis[y]!=now)	ans++,vis[y]=now;
							b.push(y);
							tv[y][3]=now;
						}
				}
		}
	//for	(int i=0;i<NM;i++) if	(vis[i]==now)	printf("(%d,%d) ",i/M+1,i%M+1);
	writeln(ans);
}
void work()
{
	read(N),read(M),read(Q);
	NM=N*M;
	for	(int i=0;i<N;i++)
		for	(int j=0;j+1<M;j++)
			{
				char c;readc(c);
				int x=i*M+j,y=x+1;
				if	(c!='0')	Add(x,y,c-48,1),Add(y,x,c-48,1);
			}
	for	(int i=0;i+1<N;i++)
		for	(int j=0;j<M;j++)
			{
				char c;readc(c);
				int x=i*M+j,y=x+M;
				if	(c!='0')	Add(x,y,c-48,2),Add(y,x,c-48,2);
			}
	for	(int i=1;i<=Q;i++)
		{
			int col,rk,x,y;
			read(col),read(rk),read(x),read(y);
			x--,y--;
			int now=x*M+y;
			bfs(col,rk,now);
		}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;read(T);
	while	(T)
		{
			memset(ex,0,sizeof(ex));
			memset(vis,0xff,sizeof(vis));
			memset(tv,0xff,sizeof(tv));
			memset(head,0,sizeof(head));
			tot=0;
			work();
			T--;
		}
	return 0;
}

