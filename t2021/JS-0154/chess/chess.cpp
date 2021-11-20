#include<bits/stdc++.h>
using namespace std;

int read()
{
	int ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
void write(int x)
{
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void writeln(int x) {write(x); putchar('\n');}

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, q;
int lu[5005][5005][4];//0123:иосробвС 
char s[5005];
bool vis[5005][5005], rea[5005][5005];
struct CHESS{
	int col;
	int lv;
}che[5005][5005];

void dfs(int x, int y, int path, int color, int level, int heng)
{
	for(int i = 0, a, b;i < 4;++i)
	{
		a = x + dx[i]; b = y + dy[i];
		if(path == 2 && heng == i % 2) continue;
		if(a >= 1 && b >= 1 && a <= n && b <= m && !vis[a][b] && lu[x][y][i] == path && ((che[a][b].lv == 0) || (che[a][b].lv <= level && che[a][b].col != color)))
		{
			rea[a][b] = vis[a][b] = 1;
			if(path != 1) dfs(a, b, path, color, level, heng);
		}
	}
}

void HEHERE()
{
	memset(che, 0, sizeof(che));
	n = read(); m = read(); q = read();
	for(int i = 1;i <= n;++i)
	{
		scanf("%s",s);
		for(int j = 0;j < m - 1;++j) lu[i][j][1] = lu[i][j + 1][3] = s[j] - '0';
	}
	for(int i = 1;i <= n - 1;++i)
	{
		scanf("%s",s);
		for(int j = 0;j < m;++j) lu[i][j][2] = lu[i + 1][j][0] = s[j] - '0';
	}
	int a, b, c, d;
	while(q--)
	{
		a = read(); b = read(); c = read(); d = read();
		che[c][d].col = a; che[c][d].lv = b;
		
		for(int i = 1;i <= n;++i) for(int j = 1;j <= m;++j) rea[i][j] = 0;
		for(int i = 1;i <= n;++i) for(int j = 1;j <= m;++j) vis[i][j] = 0;
		dfs(c, d, 1, a, b, 0);
		for(int i = 1;i <= n;++i) for(int j = 1;j <= m;++j) vis[i][j] = 0;
		dfs(c, d, 2, a, b, 0);
		for(int i = 1;i <= n;++i) for(int j = 1;j <= m;++j) vis[i][j] = 0;
		dfs(c, d, 2, a, b, 1);
		for(int i = 1;i <= n;++i) for(int j = 1;j <= m;++j) vis[i][j] = 0;
		dfs(c, d, 3, a, b, 0);
		
		int ans = 0;
		for(int i = 1;i <= n;++i)
			for(int j = 1;j <= m;++j)
				if(rea[i][j])
					++ans;
		writeln(ans);
	}
}


int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t = read();
	while(t--) HEHERE();
	return 0;
}
