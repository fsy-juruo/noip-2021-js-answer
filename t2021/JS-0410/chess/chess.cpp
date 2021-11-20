#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int pos(int x, int y){
	return x * m + y;
}

int op1[400010];
int op2[400010];
int COL[400010], LV[400010];
int vis[400010], allvis[400010];
int ans = 0;
int ran, chen;

int beat(int xb, int yb){
	if (allvis[pos(xb, yb)]) return 0;
	allvis[pos(xb, yb)] = 1;
	if (LV[pos(xb, yb)] == 0) return 1;
	if (ran != COL[pos(xb, yb)] && chen >= LV[pos(xb, yb)]) return 1;
	else return 0;
}

void dfs(int x, int y, int op, int d){
//	cout << x << " " << y << endl;
	if (vis[pos(x, y)]) return;
	vis[pos(x, y)] = 1;
	if (!allvis[pos(x, y)]){
		if (LV[pos(x, y)] != 0) {ans += beat(x, y); return;}
		else ans++;	
	}
	else if (LV[pos(x, y)] != 0) return;
	allvis[pos(x, y)] = 1;
	if (d == -1){
		if (op1[pos(x, y)] == op){
			if (op == 1){
				if (!allvis[pos(x, y + 1)]) ans += beat(x, y + 1);
			}
			else{
				dfs(x, y + 1, op, d);
			}
		}
		if (op1[pos(x, y - 1)] == op){
			if (op == 1){
				if (!allvis[pos(x, y - 1)]) ans += beat(x, y - 1);
			}
			else{
				dfs(x, y - 1, op, d);
			}
		}
		if (op2[pos(x, y)] == op){
			if (op == 1){
				if (!allvis[pos(x + 1, y)]) ans += beat(x + 1, y);
			}
			else{
				dfs(x + 1, y, op, d);
			}
		}
		if (op2[pos(x - 1, y)] == op){
			if (op == 1){
				if (!allvis[pos(x - 1, y)]) ans += beat(x - 1, y);
			}
			else{
				dfs(x - 1, y, op, d);
			}
		}
	}
	else{
		switch (d){
			case 1:{
				if (op1[pos(x, y)] == op){
					dfs(x, y + 1, op, d);
				}	
				break;
			}
			case 2:{
				if (op1[pos(x, y - 1)] == op){
					dfs(x, y - 1, op, d);
				}	
				break;
			}
			case 3:{
				if (op2[pos(x, y)] == op){
					dfs(x + 1, y, op, d);
				}	
				break;
			}
			case 4:{
				if (op2[pos(x - 1, y)] == op){
					dfs(x - 1, y, op, d);
				}	
				break;
			}
		}
	}
}

void clr1(){
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) vis[pos(i, j)] = 0;
}

void clr2(){
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) allvis[pos(i, j)] = 0;
}

void clr3(){
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) COL[pos(i, j)] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) LV[pos(i, j)] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) op1[pos(i, j)] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) op2[pos(i, j)] = 0;
}

int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int T;
	cin >> T;
	while (T--){
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 1; i <= n; i++){
			string s;
			cin >> s;
			for (int j = 0; j < s.size(); j++){
				op1[pos(i, j + 1)] = s[j] - '0';
			}
		}
		for (int i = 1; i < n; i++){
			string s;
			cin >> s;
			for (int j = 0; j < s.size(); j++){
				op2[pos(i, j + 1)] = s[j] - '0';
			}
		}
		for (int i = 1; i <= q; i++){
			int col, lv, x, y;
			scanf("%d%d%d%d", &col, &lv, &x, &y);
			ans = 0;
			ran = col, chen = lv;
			dfs(x, y, 1, -1);
			clr1();
			for (int j = 1; j <= 4; j++){
				dfs(x, y, 2, j);
				clr1();
			}
			dfs(x, y, 3, -1);
			clr1();
			clr2();
			COL[pos(x, y)] = col;
			LV[pos(x, y)] = lv;
			printf("%d\n", ans - 1);
		}
		clr3();	
	}
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
