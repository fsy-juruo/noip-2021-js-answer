#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

namespace IO
{
	const int BSIZ = 4096;
	char bufi[4105], bufo[4105];
	int posi = BSIZ, poso;
	void flI()
	{
		fread(bufi, 1, BSIZ, stdin); posi = 0;
	}
	void flO()
	{
		fwrite(bufo, 1, poso, stdout); poso = 0;
	}
	void getC(char& ch)
	{
		if(posi == BSIZ) flI();
		ch = bufi[posi ++];
	}
	void putC(char ch)
	{
		if(poso == BSIZ) flO();
		bufo[poso ++] = ch;
	}
	void getD(int& x)
	{
		char ch;
		do getC(ch);
		while(ch < '0' || ch > '9');
		x = ch - '0';
	}
	template<typename T>
	void getU(T& x)
	{
		char ch; x = 0;
		do getC(ch);
		while(ch < '0' || ch > '9');
		do {
			x = x * 10 + (ch - '0'); getC(ch);
		} while(ch >= '0' && ch <= '9');
	}
	char buf[25];
	template<typename T>
	void putU(T x)
	{
		int len = 0;
		do {
			buf[len ++] = x % 10 + '0'; x /= 10;
		} while(x > 0);
		for(int i = len - 1; i >= 0; i --) putC(buf[i]);
	}
}

int n, m, q, tpr[200005], tpd[200005], tim[200005];
int qc[200005], ql[200005], qx[200005], qy[200005], ans[200005];
int rt[200005], tl[200005], tr[200005], tu[200005], td[200005];
int vc[200005], vl[200005], vtl[200005], vtr[200005], vtu[200005], vtd[200005];
int par[200005], dfn[200005], dfo[200005], siz[200005], pr[2000005], tot;
int vpos[200005][5];
vector<int> G[200005], hv[200005];

int root(int x, int arr[])
{
	return x == arr[x] ? x : arr[x] = root(arr[x], arr);
}
void unite(int x, int y)
{
	x = rt[root(x, rt)]; y = rt[root(y, rt)];
	if(x == y) return;
	par[x] = rt[x] = y; G[y].push_back(x);
}

void vunite(int v)
{
	int x = v / m, y = v % m;
	vtu[v] = vtd[v] = vtl[v] = vtr[v] = v;
	if(x > 0) {
		if(tpd[v - m] == 3 && tim[v - m] >= tim[v]) unite(v - m, v); 
		else if(tpd[v - m] == 2) {
			tu[v] = v - m; vtu[v] = root(v, tu);
		} else if(tpd[v - m] == 1) vtu[v] = v - m;
	}
	if(x < n - 1) {
		if(tpd[v] == 3 && tim[v + m] >= tim[v]) unite(v + m, v);
		else if(tpd[v] == 2) {
			td[v] = v + m; vtd[v] = root(v, td);
		} else if(tpd[v] == 1) vtd[v] = v + m;
	}
	if(y > 0) {
		if(tpr[v - 1] == 3 && tim[v - 1] >= tim[v]) unite(v - 1, v);
		else if(tpr[v - 1] == 2) {
			tl[v] = v - 1; vtl[v] = root(v, tl);
		} else if(tpr[v - 1] == 1) vtl[v] = v - 1;
	}
	if(y < m - 1) {
		if(tpr[v] == 3 && tim[v + 1] >= tim[v]) unite(v + 1, v);
		else if(tpr[v] == 2) {
			tr[v] = v + 1; vtr[v] = root(v, tr);
		} else if(tpr[v] == 1) vtr[v] = v + 1;
	}
}

void dfs0(int v)
{
	dfn[v] = tot ++; siz[v] = 1;
	rep(i, G[v].size()) {
		int u = G[v][i];
		dfs0(u); siz[v] += siz[u];
	}
	dfo[v] = tot - 1;
}
void dfs1(int v, int pv)
{
	pr[v] = pv;
	int mu = -1;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(mu == -1 || siz[u] > siz[mu]) mu = u;
	}
	rep(i, G[v].size()) {
		int u = G[v][i];
		dfs1(u, u == mu ? pv : u);
	}
}
int lca(int u, int v)
{
	while(pr[u] != pr[v]) {
		if(dfn[pr[u]] < dfn[pr[v]]) swap(u, v);
		u = par[pr[u]];
	}
	return dfn[u] < dfn[v] ? u : v;
}

bool cmp(int x, int y)
{
	return dfn[x] < dfn[y];
}
void vgen(int v)
{
	int x = v / m, y = v % m, len = 0;
	if(x > 0 && tpd[v - m] == 3 && tim[v - m] > tim[v]) {
		hv[v - m].push_back(v); vpos[v][len ++] = v - m;
	}
	if(x < n - 1 && tpd[v] == 3 && tim[v + m] > tim[v]) {
		hv[v + m].push_back(v); vpos[v][len ++] = v + m;
	}
	if(y > 0 && tpr[v - 1] == 3 && tim[v - 1] > tim[v]) {
		hv[v - 1].push_back(v); vpos[v][len ++] = v - 1;
	}
	if(y < m - 1 && tpr[v] == 3 && tim[v + 1] > tim[v]) {
		hv[v + 1].push_back(v); vpos[v][len ++] = v + 1;
	}
	sort(vpos[v], vpos[v] + len, cmp);
	rep(i, len - 1) hv[lca(vpos[v][i], vpos[v][i + 1])].push_back(~v);
	if(len > 0) hv[v].push_back(~v);
	vpos[v][len] = -1;
}

struct fwt
{
	int dat[200005];
	void clear()
	{
		memset(dat, 0, sizeof(dat));
	}
	void add(int id, int val)
	{
		for(; id <= 200000; id += id & -id) dat[id] += val;
	}
	int query(int id)
	{
		int ret = 0;
		for(; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
	int query(int l, int r)
	{
		return query(r) - query(l - 1);
	}
}f[2], g, h;

bool isin(int x, int v)
{
	if(vc[x] == vc[v] || vl[x] > vl[v]) return true;
	for(int i = 0; vpos[x][i] != -1; i ++) if(dfn[vpos[x][i]] >= dfn[v] && dfn[vpos[x][i]] <= dfo[v]) return true;
	return false;
}
int calc(int v)
{
	int ret = f[!vc[v]].query(vl[v]);
	ret -= g.query(vtl[v] + 1, vtr[v] + 1);
	ret -= h.query(vtu[v] % m * n + vtu[v] / m + 1, vtd[v] % m * n + vtd[v] / m + 1);
	return ret;
}
void dfs2(int v)
{
	if(tim[v] != q) {
		ans[v] = siz[v];
		if(tim[vtu[v]] < tim[v]) {
			if(!isin(vtu[v], v)) ans[v] ++;
			vtu[v] += m;
		}
		if(tim[vtd[v]] < tim[v]) {
			if(!isin(vtd[v], v)) ans[v] ++;
			vtd[v] -= m;
		}
		if(tim[vtl[v]] < tim[v]) {
			if(!isin(vtl[v], v)) ans[v] ++;
			vtl[v] ++;
		}
		if(tim[vtr[v]] < tim[v]) {
			if(!isin(vtr[v], v)) ans[v] ++;
			vtr[v] --;
		}
		ans[v] += vtr[v] - vtl[v] + (vtd[v] - vtu[v]) / m + 1;
		ans[v] -= calc(v);
	}
	rep(i, hv[v].size()) {
		int u = hv[v][i], c = 1;
		if(u < 0) {
			c = -1; u = ~u;
		}
		f[vc[u]].add(vl[u], c);
	}
	g.add(v + 1, 1);
	h.add(v % m * n + v / m + 1, 1);
	rep(i, G[v].size()) dfs2(G[v][i]);
	if(tim[v] != q) ans[v] += calc(v);
}

void solve()
{
	IO::getU(n); IO::getU(m); IO::getU(q);
	rep(i, n) rep(j, m - 1) IO::getD(tpr[i * m + j]);
	rep(i, n - 1) rep(j, m) IO::getD(tpd[i * m + j]);
	rep(i, n * m) tim[i] = q;
	rep(i, q) {
		IO::getU(qc[i]); IO::getU(ql[i]); IO::getU(qx[i]); IO::getU(qy[i]);
		qx[i] --; qy[i] --;
		int id = qx[i] * m + qy[i];
		vc[id] = qc[i]; vl[id] = ql[i]; tim[id] = i;
	}
	rep(i, n * m + 1) G[i].clear();
	rep(i, n * m) rt[i] = tl[i] = tr[i] = tu[i] = td[i] = i;
	
	rep(i, n * m) if(tim[i] == q) vunite(i);
	for(int i = q - 1; i >= 0; i --) vunite(qx[i] * m + qy[i]);
	
	tot = 0;
	rep(i, n * m) if(rt[i] == i) {
		par[i] = n * m; G[n * m].push_back(i);
	} 
	dfs0(n * m);
	dfs1(n * m, n * m);
	
	rep(i, n * m + 1) hv[i].clear();
	rep(i, n * m) if(tim[i] != q) vgen(i);
	
	f[0].clear(); f[1].clear(); g.clear(); h.clear();
	rep(i, n * m) if(rt[i] == i) dfs2(i);
	
	rep(i, q) {
		IO::putU(ans[qx[i] * m + qy[i]]); IO::putC('\n');
	}
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	
	int T;
	IO::getU(T);
	while(T --) solve();
	IO::flO();
	return 0;
}
