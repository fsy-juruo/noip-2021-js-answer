#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
struct node{
	int col;
	int lev;
};
int T, n, m, q, cnt;
string sl[MAXN], sr[MAXN];
map <pair <int, int>, node> mp;
void dfs(int x, int y, int cl, int lv, int way, int dir)
{
	pair <int, int> pr;
	if (y != n && sl[x][y - 1] == '1' && way == 4)
	{
		pr = make_pair(x, y + 1);
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
	}
	if (y != n && sl[x][y - 1] == '2' && (way == 4 || (way == 2 && dir == 1)))
	{
		pr = make_pair(x, y + 1);	
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
		if (mp[pr].col == 0) dfs(x, y + 1, cl, lv, 2, 1);
	}
	if (y != n && sl[x][y - 1] == '3' && (way == 4 || way == 3))
	{
		pr = make_pair(x, y + 1);
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
		if (mp[pr].col == 0) dfs(x, y + 1, cl, lv, 3, 1);
	}
//	
	if (y != 1 && sl[x][y - 2] == '1' && way == 4)
	{
		pr = make_pair(x, y - 1);
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
	}
	if (y != 1 && sl[x][y - 2] == '2' && (way == 4 || (way == 2 && dir == 3)))
	{
		pr = make_pair(x, y - 1);	
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
		if (mp[pr].col == 0) dfs(x, y - 1, cl, lv, 2, 3);
	}
	if (y != 1 && sl[x][y - 2] == '3' && (way == 4 || way == 3))
	{
		pr = make_pair(x, y - 1);
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
		if (mp[pr].col == 0) dfs(x, y - 1, cl, lv, 3, 3);
	}
//	
		if (x != n && sr[x][y - 1] == '1' && way == 4)
	{
		pr = make_pair(x + 1, y);
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
	}
	if (x != n && sl[x][y - 1] == '2' && (way == 4 || (way == 2 && dir == 4)))
	{
		pr = make_pair(x + 1, y);	
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
		if (mp[pr].col == 0) dfs(x + 1, y, cl, lv, 2, 4);
	}
	if (x != n && sl[x][y - 1] == '3' && (way == 4 || way == 3))
	{
		pr = make_pair(x + 1, y);
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
		if (mp[pr].col == 0) dfs(x + 1, y, cl, lv, 3, 4);
	}
//
		if (x != 1 && sl[x - 1][y - 1] == '1' && way == 4)
	{
		pr = make_pair(x - 1, y);
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
	}
	if (x != 1 && sl[x - 1][y - 1] == '2' && (way == 4 || (way == 2 && dir == 2)))
	{
		pr = make_pair(x - 1, y);	
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
		if (mp[pr].col == 0) dfs(x - 1, y, cl, lv, 2, 2);
	}
	if (x != 1 && sl[x - 1][y - 1] == '3' && (way == 4 || way == 3))
	{
		pr = make_pair(x - 1, y);
		if (cl != mp[pr].col && lv >= mp[pr].lev) cnt++;
		if (mp[pr].col == 0) dfs(x - 1, y, cl, lv, 3, 2);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out", "w",stdout);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> q;
		for (int i = 1; i <= n; i++)
			cin >> sl[i];
		for (int i = 1; i < n; i++)
			cin >> sr[i];
		while (q--)
		{
			int x, y, cl, lv;
			cin >> cl >> lv >> x >> y;
			if (cl == 0) cl = 2;
			pair <int, int> pr = make_pair(x, y);
			node ps; ps.col = cl; ps.lev = lv;
			mp[pr] = ps;
			cnt = 0;
			dfs(x, y, cl, lv, 4, 0);
			cout << cnt << '\n';
		}
	}
	return 0;
}
