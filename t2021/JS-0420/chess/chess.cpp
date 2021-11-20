#include <bits/stdc++.h>
#define maxn 200010
#define getloc(x, y) ((x - 1) * m + y)
using namespace std;
inline int read()
{
	int X = 0; bool f = false; char ch = getchar();
	while (ch > '9' || ch < '0') {f |= ch == '-'; ch = getchar();}
	while (ch <= '9' && ch >= '0') {X = (X << 3) + (X << 1) + (ch ^ 48); ch = getchar();}
	return f ? -X : X;
}
inline void write(int X)
{
	if (X == 0) {putchar('0'); return;}
	if (X < 0) {putchar('-'); X = -X;}
	short num[16], cnt = 0;
	while (X) {num[++cnt] = X % 10; X /= 10;}
	while (cnt) putchar(num[cnt--] ^ 48);
	return;
}
struct Node
{
	bool is_visited;
	vector < int > sidelistpt, sidelistzx_x, sidelistzx_y, sidelistht;
	int color, lv;
}Nodelist[maxn];
inline void build_side(int from, int to, int w, int direction)
{
	switch (w)
	{
		case '1': Nodelist[from].sidelistpt.push_back(to); Nodelist[to].sidelistpt.push_back(from); break;
		case '2': 
			if (direction == 1) {Nodelist[from].sidelistzx_x.push_back(to); Nodelist[to].sidelistzx_x.push_back(from);}
			else {Nodelist[from].sidelistzx_y.push_back(to); Nodelist[to].sidelistzx_y.push_back(from);}
		break;
		case '3': Nodelist[from].sidelistht.push_back(to); Nodelist[to].sidelistht.push_back(from); break;
		//default: printf("CCF nmsl，搞不合法数据是吧\n"); exit(114514);
	}
}
void getgame();
void playgame();
void dfs1(int loc);
void dfs2(int loc, int dire);
int T, n, m, q, lx, ly, lcolor, llv, lid;
set < int > ans;
string str;
int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	cin.tie(0);
	T = read();
	for (int i = 1; i <= T; ++i) {getgame(); for (int j = 1; j <= q; ++j) {playgame(); write(ans.size()); putchar('\n');}}
}

void getgame()
{
	n = read(); m = read(); q = read();
	for (int i = 1; i <= n * m; ++i) 
	{
		Nodelist[i].is_visited = false; Nodelist[i].color = -1; Nodelist[i].lv = -1;
		Nodelist[i].sidelistht.clear(); Nodelist[i].sidelistpt.clear(); Nodelist[i].sidelistzx_x.clear(); Nodelist[i].sidelistzx_y.clear();
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> str;
		for (int j = 1; j < m; ++j) if (str[j - 1] != '0') build_side(getloc(i, j), getloc(i, j + 1), str[j - 1], 1);
	}
	for (int i = 1; i < n; ++i)
	{
		cin >> str;
		for (int j = 1; j <= m; ++j) if (str[j - 1] != '0') build_side(getloc(i, j), getloc(i + 1, j), str[j - 1], 2);
	}
	/*
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cerr << i << "," << j << ":" << endl;
			cerr << "  id:" << getloc(i, j) << endl;
			cerr << "  side:" << endl;
			cerr << "    type1:" << endl;
			for (int k = 0; k < Nodelist[getloc(i, j)].sidelistpt.size(); ++k) cerr << "    ->" << Nodelist[getloc(i, j)].sidelistpt[k] << endl;
			cerr << "    type2(LR):" << endl;
			for (int k = 0; k < Nodelist[getloc(i, j)].sidelistzx_x.size(); ++k) cerr << "    ->" << Nodelist[getloc(i, j)].sidelistzx_x[k] << endl;
			cerr << "    type2(UD):" << endl;
			for (int k = 0; k < Nodelist[getloc(i, j)].sidelistzx_y.size(); ++k) cerr << "    ->" << Nodelist[getloc(i, j)].sidelistzx_y[k] << endl;
			cerr << "    type3:" << endl;
			for (int k = 0; k < Nodelist[getloc(i, j)].sidelistht.size(); ++k) cerr << "    ->" << Nodelist[getloc(i, j)].sidelistht[k] << endl;
			cerr << endl;
		}
	}
	*/
	return;
}

void playgame()
{
	lcolor = read(); llv = read(); lx = read(); ly = read();
	lid = getloc(lx, ly); ans.clear();
	Nodelist[lid].color = lcolor; Nodelist[lid].lv = llv;
	Nodelist[lid].is_visited = true;
	for (int i = 0; i < Nodelist[lid].sidelistpt.size(); ++i)
	{
		if (Nodelist[Nodelist[lid].sidelistpt[i]].color != lcolor && Nodelist[Nodelist[lid].sidelistpt[i]].lv <= llv) ans.insert(Nodelist[lid].sidelistpt[i]);
	}
	for (int i = 0; i < Nodelist[lid].sidelistht.size(); ++i) dfs1(Nodelist[lid].sidelistht[i]);
	for (int i = 0; i < Nodelist[lid].sidelistzx_x.size(); ++i) dfs2(Nodelist[lid].sidelistzx_x[i], 1);
	for (int i = 0; i < Nodelist[lid].sidelistzx_y.size(); ++i) dfs2(Nodelist[lid].sidelistzx_y[i], 2);
	Nodelist[lid].is_visited = false;
	return;
}

void dfs1(int loc)
{
	if (Nodelist[loc].color != -1)
	{
		if (Nodelist[loc].color != lcolor && Nodelist[loc].lv <= llv) ans.insert(loc);
		return;
	}
	ans.insert(loc);
	Nodelist[loc].is_visited = true;
	for (int i = 0; i < Nodelist[loc].sidelistht.size(); ++i)
	{
		if (!Nodelist[Nodelist[loc].sidelistht[i]].is_visited) dfs1(Nodelist[loc].sidelistht[i]);
	}
	Nodelist[loc].is_visited = false;
	return;
}

void dfs2(int loc, int dire)
{
	if (Nodelist[loc].color != -1)
	{
		if (Nodelist[loc].color != lcolor && Nodelist[loc].lv <= llv) ans.insert(loc);
		return;
	}
	ans.insert(loc);
	Nodelist[loc].is_visited = true;
	switch (dire)
	{
		case 1:
			for (int i = 0; i < Nodelist[loc].sidelistzx_x.size(); ++i)
			{
				if (!Nodelist[Nodelist[loc].sidelistzx_x[i]].is_visited) dfs2(Nodelist[loc].sidelistzx_x[i], 1);
			}
			break;
		case 2:
			for (int i = 0; i < Nodelist[loc].sidelistzx_y.size(); ++i)
			{
				if (!Nodelist[Nodelist[loc].sidelistzx_y[i]].is_visited) dfs2(Nodelist[loc].sidelistzx_y[i], 1);
			}
			break;
	}
	Nodelist[loc].is_visited = false;
	return;
}
