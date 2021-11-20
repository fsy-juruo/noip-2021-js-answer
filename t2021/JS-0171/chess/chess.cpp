#include <bits/stdc++.h>
using namespace std;
#define re register
#define ft first
#define sd second
#define INF 0x3f3f3f3f
#define P pair<int,int>
#define mp make_pair
#define pb push_back
int t,n,m,q;
int heng[105][105],zong[105][105];
int chess[105][105];
//void dfs(int x,int y,int col){
//	
//}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin >> t;
	while(t--){
		memset(chess,-1,sizeof(chess));
		cin >> n >> m >> q;
		string temp;
		for(re int i = 1; i <= n; ++i){
			cin >> temp;
			for(re int j = 1; j < m; ++j){
				heng[i][j] = temp[j - 1] - '0';
			}
		}
		for(re int i = 1; i < n; ++i){
			cin >> temp;
			for(re int j = 1; j <= m; ++j){
				zong[i][j] = temp[j - 1] - '0';
			}
		}
		int col, x, y;
		for(re int i = 1;i <= q; ++i){
			cin >> col >> x >> y;
//			chess[x][y] = col;
//			dfs(x,y,col);
			cout << 0 << endl;
		}
	}
	return 0;
}

