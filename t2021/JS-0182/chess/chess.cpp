#include <bits/stdc++.h>
#define LL long long
using namespace std;

int T, n, m, q, ans, heng[1005][1005], zong[1005][1005];
int ext[1005][1005], LV[1005][1005], vis[1005][1005];
int dx[4] = {0, 1, 0, -1}, dy[4] ={1, 0, -1, 0};
char ch[200005];

inline void dfs(int x, int y, int col, int lv)
{
	if (ext[x][y] >= 0)
	{
		if (ext[x][y] == col || LV[x][y] > lv) return;
		else ++ans;
		return;
	}
	if (vis[x][y]) return;
	vis[x][y] = 1;
	++ans;
	if (x > 1)
	{
		if (heng[x - 1][y] == 3) dfs(x - 1, y, col, lv);
	}
	if (x < n && heng[x][y] == 3) dfs(x + 1, y, col, lv);
	if (y > 1 && zong[x][y - 1] == 3) dfs(x, y - 1, col, lv);
	if (y < m && zong[x][y] == 3) dfs(x, y + 1, col, lv);
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		memset(ext, -1, sizeof(ext));
		scanf("%d %d %d", &n, &m, &q);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", ch);
			for (int j = 1; j < m; ++j)
				heng[i][j] = ch[j - 1] - '0';
		}
		for (int i = 1; i < n; ++i)
		{
			scanf("%s", ch);
			for (int j = 1; j <= m; ++j)
				zong[i][j] = ch[j - 1] - '0';
		}
		while (q--)
		{
			
			int col, lv, x, y;
			ans = 0;
			scanf("%d %d %d %d", &col, &lv, &x, &y);
			if (x > 1)
			{
				int xx = x, yy = y;
				if (heng[xx - 1][yy] == 1)
				{
					if (ext[xx - 1][yy] >= 0 && (ext[xx - 1][yy] == col || LV[xx - 1][yy] > lv));
					else ++ans;
				}
				while (heng[xx - 1][yy] == 2)
				{
					if (ext[xx - 1][yy] >= 0 && (ext[xx - 1][yy] == col || LV[xx - 1][yy] > lv)) break;
					else ++ans;
					if (ext[xx - 1][yy] >= 0) break;
					--xx;
				}
			}
			if (x < n)
			{
				int xx = x, yy = y;
				if (heng[xx][yy] == 1)
				{
					if (ext[xx + 1][yy] >= 0 && (ext[xx + 1][yy] == col || LV[xx + 1][yy] > lv));
					else ++ans;
				}
				while (heng[xx][y] == 2)
				{
					if (ext[xx + 1][yy] >= 0 && (ext[xx + 1][yy] == col || LV[xx + 1][yy] > lv)) break;
					else ++ans;
					if (ext[xx + 1][yy] >= 0) break;
					++xx;
				}
			}
			if (y > 1)
			{
				int xx = x, yy = y;
				if (zong[xx][yy - 1] == 1)
				{
					if (ext[xx][yy - 1] >= 0 && (ext[xx][yy - 1] == col || LV[xx][yy - 1] > lv));
					else ++ans;
				}
				while (heng[xx][yy - 1] == 2)
				{
					if (ext[xx][yy - 1] >= 0 && (ext[xx][yy - 1] == col || LV[xx][yy - 1] > lv)) break;
					else ++ans;
					if (ext[xx][yy - 1] >= 0) break;
					--yy;
				}
				//printf("%d\n", ans);
			}
			if (y < m)
			{
				int xx = x, yy = y;
				if (zong[xx][yy] == 1)
				{
					if (ext[xx][yy + 1] >= 0 && (ext[xx][yy + 1] == col || LV[xx][yy + 1] > lv));
					else ++ans;
				}
				while (heng[xx][yy] == 2)
				{
					if (ext[xx][yy + 1] >= 0 && (ext[xx][yy + 1] == col || LV[xx][yy + 1] > lv)) break;
					else ++ans;
					if (ext[xx][yy + 1] >= 0) break;
					++yy;
				}
			}
			memset(vis, 0, sizeof(vis));
			dfs(x, y, col, lv);
			printf("%d\n", ans);
			ext[x][y] = col, LV[x][y] = lv;
		}
	}
	return 0;
}

