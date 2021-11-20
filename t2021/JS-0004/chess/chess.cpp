#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int SZ = 200005;
const int V = SZ * 10 * 20;
int read_int() {
	int f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	int x = 0;
	while (isdigit(c)) {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * f;
}
void print_int(int x) {
	if (!x) putchar('0');
	else {
		if (x < 0) x = -x, putchar('-');
		static char q[40];
		int tp = 0;
		while (x) q[tp++] = x % 10 + '0', x /= 10;
		while (tp) --tp, putchar(q[tp]);
	}
	putchar('\n');
}
struct Node {
	int lson, rson, sum;
} tr[V];
int tot;
/*
void debug(int i, int l, int r) {
	if (!i) return;
	if (l == r) {
		if (tr[i].sum) printf("(%d %d) ", l, tr[i].sum);
		return;
	}
	int mid = (l + r) >> 1;
	debug(tr[i].lson, l, mid);
	debug(tr[i].rson, mid + 1, r);
}
//*/
bool Ins(int &i, int l, int r, int pos, int ty = 0) {
	if (!i) {
		i = ++tot;
		tr[i].lson = tr[i].rson = tr[i].sum = 0;
	}
	if (l == r) {
		int tmp = tr[i].sum;
		if (!ty) tr[i].sum = 1;
		else tr[i].sum += ty;
		return !tmp;
	}
	int mid = (l + r) >> 1;
	int ret;
	if (pos <= mid) ret = Ins(tr[i].lson, l, mid, pos, ty);
	else ret = Ins(tr[i].rson, mid + 1, r, pos, ty);
	tr[i].sum = tr[tr[i].lson].sum + tr[tr[i].rson].sum;
	return ret;
}
int Merge(int i, int j, int l, int r) {
	if (!i || !j) return i | j;
	if (l == r) {
		return i;
	}
	int mid = (l + r) >> 1;
	tr[i].lson = Merge(tr[i].lson, tr[j].lson, l, mid);
	tr[i].rson = Merge(tr[i].rson, tr[j].rson, mid + 1, r);
	tr[i].sum = tr[tr[i].lson].sum + tr[tr[i].rson].sum;
	return i;
}
int Merge2(int i, int j, int l, int r) {
	if (!i || !j) return i | j;
	if (l == r) {
		tr[i].sum += tr[j].sum;
		return i;
	}
	int mid = (l + r) >> 1;
	tr[i].lson = Merge2(tr[i].lson, tr[j].lson, l, mid);
	tr[i].rson = Merge2(tr[i].rson, tr[j].rson, mid + 1, r);
	tr[i].sum = tr[tr[i].lson].sum + tr[tr[i].rson].sum;
	return i;
}
int Query(int i, int l, int r, int lf, int rg) {
	if (!i) return 0;
	if (lf <= l && r <= rg) return tr[i].sum;
	int mid = (l + r) >> 1, ret = 0;
	if (lf <= mid) ret += Query(tr[i].lson, l, mid, lf, rg);
	if (rg > mid) ret += Query(tr[i].rson, mid + 1, r, lf, rg);
	return ret;
}
int n, m, q, col[N], lv[N], qx[N], qy[N], ans[N], fa[SZ], rth[SZ], rts[SZ], rty[SZ], rtl[SZ][2];
vector<vector<int> > vh, vs, Up, Down, Left, Right;
vector<vector<pair<int, int> > > val;
set<int> sth[N], sts[N];
char str[N];
int Find(int x) {
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
int Merge3(int i, int j, int l, int r, int &rt0, int &rt1) {
	if (!i || !j) return i | j;
	if (l == r) {
		int x = (l - 1) / m + 1, y = (l - 1) % m + 1;
		if (val[x][y].first == 0) Ins(rt0, 1, q, val[x][y].second, -1);
		else Ins(rt1, 1, q, val[x][y].second, -1);
		return i;
	}
	int mid = (l + r) >> 1;
	tr[i].lson = Merge3(tr[i].lson, tr[j].lson, l, mid, rt0, rt1);
	tr[i].rson = Merge3(tr[i].rson, tr[j].rson, mid + 1, r, rt0, rt1);
	tr[i].sum = tr[tr[i].lson].sum + tr[tr[i].rson].sum;
	return i;
}
void Era(int &i, int l, int r, int pos, int &rt) {
	if (!i) return;
	if (l == r) {
		if (tr[i].sum) {
			tr[i].sum = 0;
			int x = (l - 1) / m + 1, y = (l - 1) % m + 1;
			Ins(rt, 1, q, val[x][y].second, -1);
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) Era(tr[i].lson, l, mid, pos, rt);
	else Era(tr[i].rson, mid + 1, r, pos, rt);
	tr[i].sum = tr[tr[i].lson].sum + tr[tr[i].rson].sum;
}
void Union(int id1, int id2) {
	id1 = Find(id1);
	id2 = Find(id2);
	if (id1 == id2) return;
	if (val[(id2 - 1) / m + 1][(id2 - 1) % m + 1].first == -1) {
		fa[id2] = id1;
		rtl[id1][0] = Merge2(rtl[id1][0], rtl[id2][0], 1, q);
		rtl[id1][1] = Merge2(rtl[id1][1], rtl[id2][1], 1, q);
		rty[id1] = Merge3(rty[id1], rty[id2], 1, n * m, rtl[id1][0], rtl[id1][1]);
		rth[id1] = Merge(rth[id1], rth[id2], 1, n * m);
		rts[id1] = Merge(rts[id1], rts[id2], 1, n * m);
	} else {
		int x = (id2 - 1) / m + 1, y = (id2 - 1) % m + 1;
		if (Ins(rty[id1], 1, n * m, id2)) Ins(rtl[id1][val[x][y].first], 1, q, val[x][y].second, 1);
	}
}
int id1(int x, int y) {
	return (x - 1) * m + y;
}
int id2(int x, int y) {
	return (y - 1) * n + x;
}
bool Beat(pair<int, int> a, pair<int, int> b) {
	return a.first != b.first && a.second >= b.second;
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int T;
	T = read_int();
	while (T--) {
		n = read_int();
		m = read_int();
		q = read_int();
		tot = 0;
		vh.resize(n + 1);
		vs.resize(n + 1);
		Up.resize(n + 1);
		Down.resize(n + 1);
		Left.resize(n + 1);
		Right.resize(n + 1);
		val.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			vh[i].resize(m + 1);
			vs[i].resize(m + 1);
			Up[i].resize(m + 1);
			Down[i].resize(m + 1);
			Left[i].resize(m + 1);
			Right[i].resize(m + 1);
			val[i].resize(m + 1);
			for (int j = 1; j <= m; j++) val[i][j] = make_pair(-1, -1);
		}
		for (int i = 1; i <= n; i++) {
			sth[i].clear();
			sth[i].insert(0);
			sth[i].insert(m + 1);
		}
		for (int j = 1; j <= m; j++) {
			sts[j].clear();
			sts[j].insert(0);
			sts[j].insert(n + 1);
		}
		for (int i = 1; i <= n; i++) {
			char ch = getchar();
			while (!isdigit(ch)) ch = getchar();
			int jj = 0;
			while (isdigit(ch)) {
				str[++jj] = ch;
				ch = getchar();
			}
			for (int j = 1; j < m; j++) {
				vh[i][j] = str[j] - '0';
			}
		}
		for (int i = 1; i < n; i++) {
			char ch = getchar();
			while (!isdigit(ch)) ch = getchar();
			int jj = 0;
			while (isdigit(ch)) {
				str[++jj] = ch;
				ch = getchar();
			}
			for (int j = 1; j <= m; j++) {
				vs[i][j] = str[j] - '0';
			}
		}
		for (int i = 1; i <= n; i++) {
			Left[i][1] = 1;
			for (int j = 2; j <= m; j++) {
				Left[i][j] = (vh[i][j - 1] == 2 ? Left[i][j - 1] : j);
			}
			Right[i][m] = m;
			for (int j = m - 1; j >= 1; j--) {
				Right[i][j] = (vh[i][j] == 2 ? Right[i][j + 1] : j);
			}
		}
		for (int j = 1; j <= m; j++) {
			Up[1][j] = 1;
			for (int i = 2; i <= n; i++) {
				Up[i][j] = (vs[i - 1][j] == 2 ? Up[i - 1][j] : i);
			}
			Down[n][j] = n;
			for (int i = n - 1; i >= 1; i--) {
				Down[i][j] = (vs[i][j] == 2 ? Down[i + 1][j] : i);
			}
		}
		for (int i = 1; i <= q; i++) {
			col[i] = read_int();
			lv[i] = read_int();
			qx[i] = read_int();
			qy[i] = read_int();
			val[qx[i]][qy[i]] = make_pair(col[i], lv[i]);
		}
		for (int i = 1; i <= n * m; i++) fa[i] = i, rth[i] = rts[i] = rty[i] = rtl[i][0] = rtl[i][1] = 0;
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) if (val[x][y].first == -1) {
				if (x < n && vs[x][y] == 3 && val[x + 1][y].first == -1) {
					int t1 = Find((x - 1) * m + y), t2 = Find(x * m + y);
					fa[t1] = t2;
				}
				if (y < m && vh[x][y] == 3 && val[x][y + 1].first == -1) {
					int t1 = Find((x - 1) * m + y), t2 = Find((x - 1) * m + y + 1);
					fa[t1] = t2;
				}
			}
		}
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) if (val[x][y].first != -1) {
				sth[x].insert(y);
				sts[y].insert(x);
			}
		}
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) if (val[x][y].first == -1) {
				int id = (x - 1) * m + y;
				int id2 = (y - 1) * n + x;
				int rf = Find(id);
				Ins(rth[rf], 1, n * m, id);
				Ins(rts[rf], 1, n * m, id2);
				if (x > 1 && vs[x - 1][y] == 3 && val[x - 1][y].first != -1)
					if (Ins(rty[rf], 1, n * m, (x - 2) * m + y)) Ins(rtl[rf][val[x - 1][y].first], 1, q, val[x - 1][y].second, 1);
				if (x < n && vs[x][y] == 3 && val[x + 1][y].first != -1)
					if (Ins(rty[rf], 1, n * m, x * m + y)) Ins(rtl[rf][val[x + 1][y].first], 1, q, val[x + 1][y].second, 1);
				if (y > 1 && vh[x][y - 1] == 3 && val[x][y - 1].first != -1)
					if (Ins(rty[rf], 1, n * m, (x - 1) * m + y - 1)) Ins(rtl[rf][val[x][y - 1].first], 1, q, val[x][y - 1].second, 1);
				if (y < m && vh[x][y] == 3 && val[x][y + 1].first != -1)
					if (Ins(rty[rf], 1, n * m, (x - 1) * m + y + 1)) Ins(rtl[rf][val[x][y + 1].first], 1, q, val[x][y + 1].second, 1);
			}
		}
		for (int i = q; i >= 1; i--) {
			int id = (qx[i] - 1) * m + qy[i];
			int ididid = (qy[i] - 1) * n + qx[i];
			Ins(rth[id], 1, n * m, id);
			Ins(rts[id], 1, n * m, ididid);
			if (qx[i] > 1 && vs[qx[i] - 1][qy[i]] == 3) {
				Union((qx[i] - 1) * m + qy[i], (qx[i] - 2) * m + qy[i]);
			}
			if (qx[i] < n && vs[qx[i]][qy[i]] == 3) {
				Union((qx[i] - 1) * m + qy[i], qx[i] * m + qy[i]);
			}
			if (qy[i] > 1 && vh[qx[i]][qy[i] - 1] == 3) {
				Union((qx[i] - 1) * m + qy[i], (qx[i] - 1) * m + qy[i] - 1);
			}
			if (qy[i] < m && vh[qx[i]][qy[i]] == 3) {
				Union((qx[i] - 1) * m + qy[i], (qx[i] - 1) * m + qy[i] + 1);
			}
			Era(rty[id], 1, n * m, id, rtl[id][val[qx[i]][qy[i]].first]);
			/*
			printf("Process %d\n", i);
			printf("HENG "); debug(rth[id], 1, n * m); puts("");
			printf("SHU "); debug(rts[id], 1, n * m); puts("");
			printf("YYY "); debug(rty[id], 1, n * m); puts("");
			printf("L0 "); debug(rtl[id][0], 1, q); puts("");
			printf("L1 "); debug(rtl[id][1], 1, q); puts("");
			//*/
			ans[i] = tr[rth[id]].sum - 1 + Query(rtl[id][val[qx[i]][qy[i]].first ^ 1], 1, q, 1, val[qx[i]][qy[i]].second);
			//printf("TMP %d %d\n", ans[i], val[qx[i]][qy[i]].first ^ 1);
			int UU = Up[qx[i]][qy[i]];
			if (qx[i] > 1 && vs[qx[i] - 1][qy[i]] == 1) UU = qx[i] - 1;
			int DD = Down[qx[i]][qy[i]];
			if (qx[i] < n && vs[qx[i]][qy[i]] == 1) DD = qx[i] + 1;
			int LL = Left[qx[i]][qy[i]];
			if (qy[i] > 1 && vh[qx[i]][qy[i] - 1] == 1) LL = qy[i] - 1;
			int RR = Right[qx[i]][qy[i]];
			if (qy[i] < m && vh[qx[i]][qy[i]] == 1) RR = qy[i] + 1;
			//printf("UDLR %d %d %d %d\n", UU, DD, LL, RR);
			set<int>::iterator it = sth[qx[i]].find(qy[i]), pv, nx;
			pv = it; --pv;
			if (*pv >= LL) {
				if (Beat(val[qx[i]][qy[i]], val[qx[i]][*pv]) && !Query(rty[id], 1, n * m, id1(qx[i], *pv), id1(qx[i], *pv))) ans[i]++;
				LL = *pv + 1;
			}
			if (LL < qy[i]) {
				ans[i] += qy[i] - LL - Query(rth[id], 1, n * m, id1(qx[i], LL), id1(qx[i], qy[i] - 1));
			}
			nx = it; ++nx;
			if (*nx <= RR) {
				if (Beat(val[qx[i]][qy[i]], val[qx[i]][*nx]) && !Query(rty[id], 1, n * m, id1(qx[i], *nx), id1(qx[i], *nx))) ans[i]++;
				RR = *nx - 1;
			}
			if (qy[i] < RR) {
				ans[i] += RR - qy[i] - Query(rth[id], 1, n * m, id1(qx[i], qy[i] + 1), id1(qx[i], RR));
			}
			sth[qx[i]].erase(it);
			it = sts[qy[i]].find(qx[i]);
			pv = it; --pv;
			if (*pv >= UU) {
				if (Beat(val[qx[i]][qy[i]], val[*pv][qy[i]]) && !Query(rty[id], 1, n * m, id1(*pv, qy[i]), id1(*pv, qy[i]))) ans[i]++;
				UU = *pv + 1;
			}
			if (UU < qx[i]) {
				ans[i] += qx[i] - UU - Query(rts[id], 1, n * m, id2(UU, qy[i]), id2(qx[i] - 1, qy[i]));
			}
			nx = it; ++nx;
			if (*nx <= DD) {
				if (Beat(val[qx[i]][qy[i]], val[*nx][qy[i]]) && !Query(rty[id], 1, n * m, id1(*nx, qy[i]), id1(*nx, qy[i]))) ans[i]++;
				DD = *nx - 1;
			}
			if (qx[i] < DD) {
				ans[i] += DD - qx[i] - Query(rts[id], 1, n * m, id2(qx[i] + 1, qy[i]), id2(DD, qy[i]));
			}
			sts[qy[i]].erase(it);
			val[qx[i]][qy[i]] = make_pair(-1, -1);
		}
		for (int i = 1; i <= q; i++) print_int(ans[i]);
	}
	return 0;
}
