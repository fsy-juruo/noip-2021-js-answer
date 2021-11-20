#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MN = 2e5 + 5;

int N , M , Q , L[MN] , R[MN] , U[MN] , D[MN] , vis[MN] , cc[MN] , lev[MN] , col , lv , vis2[MN];
char S[MN];
vector < int > bb , ccc;

inline bool yes(int c , int l , int pc , int pl) {
	return ((pc == -1) || ((c != pc) && l >= pl));
}

inline int ID(int x , int y) {
	return (x - 1) * M + y;
} 
inline void dfs(int x , int y) {
	if (vis2[ID(x , y)]) return;
	if (cc[ID(x , y)] != -1) {
		if (yes(col , lv , cc[ID(x , y)] , lev[ID(x , y)])) {
			vis2[ID(x , y)] = 1;
			ccc.push_back(ID(x , y));
		}
		return;
	} else {
	    vis2[ID(x , y)] = 1;
	    ccc.push_back(ID(x , y));
	}
	if (x > 1 && U[ID(x , y)] == 3) dfs(x - 1 , y);
	if (x < N && D[ID(x , y)] == 3) dfs(x + 1 , y);
	if (y > 1 && L[ID(x , y)] == 3) dfs(x , y - 1);
	if (y < M && R[ID(x , y)] == 3) dfs(x , y + 1);
	return;  
} 

int main() {
	
	#ifndef evenbao
	freopen("chess.in" , "r" , stdin);
	freopen("chess.out" , "w" , stdout);
	#endif
	
	int T; scanf("%d" , &T);
	while (T--) {
		scanf("%d%d%d" , &N , &M , &Q);
		for (int i = 1; i <= N; ++i) {
			scanf("%s" , S + 1);
			for (int j = 1; j < M; ++j) {
				R[ID(i , j)] = S[j] - '0';
				L[ID(i , j + 1)] = R[ID(i , j)];
			}
		}
		for (int i = 1; i < N; ++i) {
			scanf("%s" , S + 1);
			for (int j = 1; j <= M; ++j) {
				D[ID(i , j)] = S[j] - '0';
				U[ID(i + 1 , j)] = D[ID(i , j)];
			}
		}
		for (int i = 1; i <= N * M; ++i) cc[i] = lev[i] = -1;
		while (Q--) {
			int x , y;
			scanf("%d%d%d%d" , &col , &lv , &x , &y);
			
			for (unsigned i = 0; i < bb.size(); ++i)
				vis[bb[i]] = 0;
			
			for (unsigned i = 0; i < ccc.size(); ++i)
				vis2[ccc[i]] = 0;
			
			bb.clear() , ccc.clear();
			
			if (x > 1 && U[ID(x , y)] == 1) {
				if (yes(col , lv , cc[ID(x - 1 , y)] , lev[ID(x - 1 , y)])) {
					vis[ID(x - 1 , y)] = 1;
					bb.push_back(ID(x - 1 , y));
				}
			}
			
			if (x < N && D[ID(x , y)] == 1) {
				if (yes(col , lv , cc[ID(x + 1 , y)] , lev[ID(x + 1 , y)])) {
					vis[ID(x + 1 , y)] = 1;
					bb.push_back(ID(x + 1 , y));
				}
			}
			
			if (y > 1 && L[ID(x , y)] == 1) {
				if (yes(col , lv , cc[ID(x , y - 1)] , lev[ID(x , y - 1)])) {
					vis[ID(x , y - 1)] = 1;
					bb.push_back(ID(x , y - 1));
				}
			}
			
			if (y < M && R[ID(x , y)] == 1) {
				if (yes(col , lv , cc[ID(x , y + 1)] , lev[ID(x , y + 1)])) {
					vis[ID(x , y + 1)] = 1; bb.push_back(ID(x , y + 1));
				}
			}
			
			int nowx = x , nowy = y;
			while (nowx > 1 && cc[ID(nowx - 1 , nowy)] == -1 && U[ID(nowx , nowy)] == 2) {
				vis[ID(nowx - 1 , nowy)] = 1; bb.push_back(ID(nowx - 1 , nowy));
				--nowx;
			}
			if (nowx > 1 && U[ID(nowx , nowy)] == 2) {
				if (yes(col , lv , cc[ID(nowx - 1 , nowy)] , lev[ID(nowx - 1 , nowy)])) {
					vis[ID(nowx - 1 , nowy)] = 1; bb.push_back(ID(nowx - 1 , nowy));
				}
			}
			
			nowx = x , nowy = y;
			while (nowx < N && cc[ID(nowx + 1 , nowy)] == -1 && D[ID(nowx , nowy)] == 2) {
				vis[ID(nowx + 1 , nowy)] = 1; bb.push_back(ID(nowx + 1 , nowy));
				++nowx;
			}
			if (nowx < N && D[ID(nowx , nowy)] == 2) {
				if (yes(col , lv , cc[ID(nowx + 1 , nowy)] , lev[ID(nowx + 1 , nowy)])) {
					vis[ID(nowx + 1 , nowy)] = 1;
					bb.push_back(ID(nowx + 1 , nowy));
				}
			}
			
			nowx = x , nowy = y;
			while (nowy > 1 && cc[ID(nowx , nowy - 1)] == -1 && L[ID(nowx , nowy)] == 2) {
				vis[ID(nowx , nowy - 1)] = 1;	
				bb.push_back(ID(nowx , nowy - 1));
				--nowy;
			}
			if (nowy > 1 && L[ID(nowx , nowy)] == 2) {
				if (yes(col , lv , cc[ID(nowx , nowy - 1)] , lev[ID(nowx , nowy - 1)])) {
					bb.push_back(ID(nowx , nowy - 1));
					vis[ID(nowx , nowy - 1)] = 1;
				}
			}
			
			nowx = x , nowy = y;
			while (nowy < M && cc[ID(nowx , nowy + 1)] == -1 && R[ID(nowx , nowy)] == 2) {
				vis[ID(nowx , nowy + 1)] = 1; bb.push_back(ID(nowx , nowy + 1));
				++nowy;
			}
			if (nowy < M && R[ID(nowx , nowy)] == 2) {
				if (yes(col , lv , cc[ID(nowx , nowy + 1)] , lev[ID(nowx , nowy + 1)])) {
					vis[ID(nowx , nowy + 1)] = 1;
					bb.push_back(ID(nowx , nowy + 1));
				}
			}
			
			dfs(x , y);
			
			int ans = 0;
			
			vis[ID(x , y)] = vis2[ID(x , y)] = 0;
			
			for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j)
				if (vis[ID(i , j)] || vis2[ID(i , j)]) ++ans;
			cc[ID(x , y)] = col; lev[ID(x , y)] = lv;
			printf("%d\n" , ans);
		}
	}
	return 0; 
} 
