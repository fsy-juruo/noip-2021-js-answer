#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct edge
{
	int from,to;
	int opt,next;
	int dic;
}a[N * 4 * 2];
struct node
{
	int col,lv,x,y;
}c[N];
int t,n,m,q,ans;
int head[N],cnt;
int f[N];
int l[N];
bool vis[N];
bool wq[N];
int color[N];

inline int read()
{
	int s = 0,w = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-')
			w = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		s = (s << 1) + (s << 3) + (ch ^ 48);
		ch = getchar();
	}
	return s * w;
}

void write(int x)
{
	if(x > 9)	write(x / 10);
	putchar((x % 10) + '0');
}

void add(int from,int to,int opt,int dic)
{
	a[++cnt].from = from;
	a[cnt].to = to;
	a[cnt].opt = opt;
	a[cnt].dic = dic;
	a[cnt].next = head[from];
	head[from] = cnt;
}

int num(int x,int y)
{
	return m * (x - 1) + y;
}

void dfs(int now,int opt,int dic,int col,int lv)
{

	for(int i = head[now];i != -1;i = a[i].next)
	{
		if(!wq[a[i].to] && a[i].opt == opt)
		{
			if(a[i].opt == 2 && a[i].dic == dic)
			{	
				if(color[a[i].to] == -1)
				{
					vis[a[i].to] = true;
					wq[a[i].to] = true;
					dfs(a[i].to,a[i].opt,a[i].dic,col,lv);
					wq[a[i].to] = false;
				}
				else
				{
					if(color[a[i].to] != col && l[a[i].to] <= lv)
						vis[a[i].to] = true;
				}
			}
			if(a[i].opt == 3)
			{
				if(color[a[i].to] == -1)
				{	
					vis[a[i].to] = true;
					wq[a[i].to] = true;
					dfs(a[i].to,a[i].opt,a[i].dic,col,lv);
					wq[a[i].to] = false;
				}
				else
				{
			//		cout << "-> " << now << " " << a[i].to  << " "<< opt << " " << lv<< endl;
					if(color[a[i].to] != col && l[a[i].to] <= lv)
						vis[a[i].to] = true;
				}
			}
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t = read();
	while(t--)
	{
		memset(color,-1,sizeof(color));
		memset(l,-1,sizeof(l));
		memset(head,-1,sizeof(head));
		cnt = 0;
		n = read(),m = read(),q = read();
		for(int i = 1;i <= n;i++)
			for(int j = 1;j < m;j++)
			{
				char opt = getchar();
				while(!isdigit(opt))
					opt = getchar();
				if(opt != '0')
				{
				//	cout << i << " " << j << endl;
				//	cout << "-> "<< num(i,j) << " " << num(i,j + 1) << endl;
					add(num(i,j),num(i,j + 1),opt ^ 48,1);
					add(num(i,j + 1),num(i,j),opt ^ 48,3);
				}
			}
		for(int i = 1;i < n;i++)
			for(int j = 1;j <= m;j++)
			{
				char opt = getchar();
				while(!isdigit(opt))
					opt = getchar();
				if(opt != '0')
				{
					add(num(i,j),num(i + 1,j),opt ^ 48,2);
					add(num(i + 1,j),num(i,j),opt ^ 48,4);
				}
			}
		for(int i = 1;i <= q;i++)
			c[i].col = read(),c[i].lv = read(),c[i].x = read(),c[i].y = read();
			
	//		cout << endl;
	//	for(int i = 1;i <= cnt;i++)
	//		cout <<	a[i].from << " " << a[i].to << " " << a[i].opt << " " << a[i].dic <<endl;
	
		
		for(int k = 1;k <= q;k++)
		{
			memset(vis,0,sizeof(vis));
			memset(wq,0,sizeof(wq));
			ans = 0;
			int now = num(c[k].x,c[k].y);
			l[now] = c[k].lv;
			color[now] = c[k].col;
			wq[now] = false;
		//	vis[now] = true;
			for(int i = head[now];i != -1;i = a[i].next)
			{
			//	cout << k << "wqnb" << endl;
			//		cout << now <<" " << a[i].to << endl;	
				if(color[a[i].to] == -1)
				{
					if(a[i].opt == 1)
						vis[a[i].to] = true;
					else
					{
						vis[a[i].to] = true;
						wq[a[i].to] = true;
						dfs(a[i].to,a[i].opt,a[i].dic,c[k].col,c[k].lv);
						wq[a[i].to] = false;	
					}
				}
				else
				{
					if(color[a[i].to] != color[now] && l[a[i].to] <= l[now])
						vis[a[i].to] = true;
				}
			}
			for(int i = 1;i <= n * m;i++)
				if(vis[i])
					ans++;
//			for(int i = 1;i <= n;i++)
//				for(int j = 1;j <= m;j++)
//				{
//					if(vis[num(i,j)])
//						cout << i << " "<< j << endl;
//				}
		//	cout << endl;
			write(ans);
			putchar('\n');
		}	
	}
	return 0;
}

