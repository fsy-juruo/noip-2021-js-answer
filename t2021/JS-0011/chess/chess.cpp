#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, q;
string D[maxn], R[maxn];

namespace Solve1{
  const int maxv = 5005;
  int hd, tl;
  pair<int, int> que[maxv];
  
  vector<vector<int> > has, a, vis;
  
  inline void check(int x, int y, int col, int lv){
    if(!~has[x][y] || (~has[x][y] && has[x][y] != col && a[x][y] <= lv))
      vis[x][y] = true;
    return;
  }
  
  inline void relax(int x, int y, int col, int lv){
    check(x, y, col, lv);
    if(!~has[x][y])
      que[tl++] = make_pair(x, y);
    return;
  }
  inline void bfs(int col, int lv, int sx, int sy){
    hd = tl = 0; que[tl++] = make_pair(sx, sy); vis[sx][sy] = 1;
    for(; hd < tl; ++hd){
      int x = que[hd].first, y = que[hd].second;
      if(x - 1 >= 0 && D[x - 1][y] == '3' && !vis[x - 1][y])
	relax(x - 1, y, col, lv);
      if(x + 1 < n && D[x][y] == '3' && !vis[x + 1][y])
	relax(x + 1, y, col, lv);
      if(y - 1 >= 0 && R[x][y - 1] == '3' && !vis[x][y - 1])
	relax(x, y - 1, col, lv);
      if(y + 1 < m && R[x][y] == '3' && !vis[x][y + 1])
	relax(x, y + 1, col, lv);
    }
    return;
  }
  
  inline void work(){
    has.resize(n), a.resize(n), vis.resize(n);
    for(int i = 0; i < n; ++i)
      has[i].resize(m), a[i].resize(m), vis[i].resize(m);

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
	has[i][j] = -1;
    
    for(int it = 0; it < q; ++it){
      int col, lv, x, y;
      scanf("%d%d%d%d", &col, &lv, &x, &y);
      --x, --y;
      for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j)
	  vis[i][j] = false;
      bfs(col, lv, x, y);
      for(int i = x - 1; i >= 0 && D[i][y] == '2'; --i){
	check(i, y, col, lv);
	if(~has[i][y])
	  break;
      }
      for(int i = x + 1; i < n && D[i - 1][y] == '2'; ++i){
	check(i, y, col, lv);
	if(~has[i][y])
	  break;
      }
      for(int j = y - 1; j >= 0 && R[x][j] == '2'; --j){
	check(x, j, col, lv);
	if(~has[x][j])
	  break;
      }
      for(int j = y + 1; j < m && R[x][j - 1] == '2'; ++j){
	check(x, j, col, lv);
	if(~has[x][j])
	  break;
      }
      if(x - 1 >= 0 && D[x - 1][y] == '1')
	check(x - 1, y, col, lv);
      if(x + 1 < n && D[x][y] == '1')
	check(x + 1, y, col, lv);
      if(y - 1 >= 0 && R[x][y - 1] == '1')
	check(x, y - 1, col, lv);
      if(y + 1 < m && R[x][y] == '1')
	check(x, y + 1, col, lv);
      int sum = 0;
      for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j){
	  sum += vis[i][j];
	}
      has[x][y] = col, a[x][y] = lv;
      printf("%d\n", sum - 1);
    }
  }
}

namespace Solve2{
  set<pair<int, pair<int, int> > > H[maxn], V[maxn];
  vector<vector<int> > preL, preR, preU, preD;

  inline bool check(int c1, int l1, int c2, int l2){
    if(c1 == c2)
      return false;
    return l2 >= l1;
  }
  
  inline void work(){
    preL.resize(n), preR.resize(n), preU.resize(n), preD.resize(n);
    for(int i = 0; i < n; ++i)
      preL[i].resize(m), preR[i].resize(m), preU[i].resize(m), preD[i].resize(m);
    for(int i = 0; i < n; ++i)
      H[i].clear();
    for(int j = 0; j < m; ++j)
      V[j].clear();
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j){
	if(i - 1 >= 0 && D[i - 1][j] == '2')
	  preU[i][j] = preU[i - 1][j];
	else
	  preU[i][j] = i;
	if(j - 1 >= 0 && R[i][j - 1] == '2')
	  preL[i][j] = preL[i][j - 1];
	else
	  preL[i][j] = j;
      }
    for(int i = n - 1; i >= 0; --i)
      for(int j = m - 1; j >= 0; --j){
	if(i + 1 < n && D[i][j] == '2')
	  preD[i][j] = preD[i + 1][j];
	else
	  preD[i][j] = i;
	if(j + 1 < m && R[i][j] == '2')
	  preR[i][j] = preR[i][j + 1];
	else
	  preR[i][j] = j;
      }

    q = 1;
    for(int it = 0; it < q; ++it){
      int col, lv, x, y; scanf("%d%d%d%d", &col, &lv, &x, &y);
      --x, --y;
      int ans = 0;
      if(x - 1 >= 0){
	int res;
	set<pair<int, pair<int, int> > >::iterator it = V[y].lower_bound(make_pair(x, make_pair(0, 0)));
	if(it == V[y].begin())
	  res = 0;
	else
	  --it, res = check((it -> second).first, (it -> second).second, col, lv) ? it -> first : it -> first + 1;
	if(D[x - 1][y] == '2')
	  res = max(res, preU[x][y]);
	else
	  res = max(res, x - 1);
	ans += x - res;
      }
      if(x + 1 < n){
	int res;
	set<pair<int, pair<int, int> > >::iterator it = V[y].lower_bound(make_pair(x, make_pair(0, 0)));
	if(it == V[y].end())
	  res = n - 1;
	else
	  res = check((it -> second).first, (it -> second).second, col, lv) ? it -> first : it -> first - 1;
	if(D[x][y] == '2')
	  res = min(res, preD[x][y]);
	else
	  res = min(res, x + 1);
	ans += res - x;
      }
      if(y - 1 >= 0){
	int res;
	set<pair<int, pair<int, int> > >::iterator it = H[x].lower_bound(make_pair(x, make_pair(0, 0)));
	if(it == H[x].begin())
	  res = 0;
	else
	  --it, res = check((it -> second).first, (it -> second).second, col, lv) ? it -> first : it -> first + 1;
	if(R[x][y - 1] == '2')
	  res = max(res, preL[x][y]);
	else
	  res = max(res, y - 1);
	ans += y - res;
      }
      if(y + 1 < m){
	int res;
	set<pair<int, pair<int, int> > >::iterator it = H[x].lower_bound(make_pair(x, make_pair(0, 0)));
	if(it == H[x].end())
	  res = m - 1;
	else
	  res = check((it -> second).first, (it -> second).second, col, lv) ? it -> first : it -> first - 1;
	if(R[x][y] == '2')
	  res = min(res, preR[x][y]);
	else
	  res = min(res, y + 1);
	ans += res - y;
      }

      printf("%d\n", ans);
      V[y].insert(make_pair(x, make_pair(col, lv)));
      H[x].insert(make_pair(y, make_pair(col, lv)));
    }
  }
}

inline void solve(){
  cin >> n >> m >> q;
  for(int i = 0; i < n; ++i)
    cin >> R[i];
  for(int i = 0; i < n - 1; ++i)
    cin >> D[i];
  
  if(q <= 2000 && n * m <= 5000)
    Solve1::work();
  else
    Solve2::work();
  return;
}

int main(){
  freopen("chess.in", "r", stdin);
  freopen("chess.out", "w", stdout);

  int T;
  for(cin >> T; T--; solve());
  return 0;
}
