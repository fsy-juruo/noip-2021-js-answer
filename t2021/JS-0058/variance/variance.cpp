#include<bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
const int MAXN = 100 + 10;
const int INF = 0x3f3f3f3f;
const int MAXM = 6e3 + 10;

inline int fread(void){
	char ch = getchar(); int ret = 0, op = 1;
	for(; !isdigit(ch) && ch != '-'; ch = getchar());
	if(ch == '-') op = -1;
	else ret = ch - '0';
	ch = getchar();
	for(; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return ret * op;
}
int n, a[MAXN], b[MAXN], c[MAXN], m, sumc;
int can[2][MAXM], pre[MAXM]; 
inline void init(void){
	n = fread();
	for(int i = 1; i <= n; ++ i)
		a[i] = fread();//b[i] = a[i + 1] - a[i];
	for(int i = 1; i <= n; ++ i) b[i] = a[i + 1] - a[i];
	sort(b + 1, b + n); 
	m = n - 2; 
	for(int i = 1; i <= m; ++ i) c[i] = b[i + 1], sumc += c[i];
	
}
int tmp[MAXN];
inline int calc(int arr[]){
	tmp[1] = a[1];
	int sum = 0; 
	for(int i = 2; i <= n; ++ i) tmp[i] = tmp[i - 1] + arr[i - 1];
	for(int i = 1; i <= n; ++ i) sum += tmp[i]; 
	int res = 0;
	for(int i = 1; i <= n; ++ i){
		res += (n * tmp[i] - sum) * (n * tmp[i] - sum);
	}
	return res / n; 
}

namespace Solution48pts{
deque<int>lft, rgt;
int mis[MAXN], Ans = INF;
inline int comp(int x, int y){ return x > y; }
void solve(void){
	for(int s = 0; s < (1 << m); ++ s){
		lft.clear(); rgt.clear(); int cnt = 0; 
		for(int i = 0; i < m; ++ i){
			if(!((s >> i) & 1)) rgt.push_back(c[i + 1]);
			else lft.push_front(c[i + 1]);
		}		
		for(auto v : lft) mis[++ cnt] = v;
		mis[++ cnt] = b[1];
		for(auto v : rgt) mis[++ cnt] = v;
		Ans = min(Ans, calc(mis));
	}
	printf("%d", Ans);
}


}
/*
int comp(int x, int y){ return x > y; }
vector<int>lft, rft;
inline void work(void){
	can[0][0] = 1;
	for(int i = 1; i <= m; ++ i){
		//memset(can[i & 1], 0, sizeof(can[i & 1]));
		for(int j = 0; j <= m * 100; ++ j) 
			can[i & 1][j] = can[(i - 1) & 1][j];
		for(int j = c[i]; j <= m * 100; ++ j){
			if(!can[i & 1][j] && can[(i - 1) & 1][j - c[i]]){
				can[i & 1][j] = 1; pre[j] = c[i];
			}
		}
	}
	int pick = 0; 
	for(int i = 0; i <= sumc / 2; ++ i){
		if(can[m & 1][sumc / 2 - i]){
			pick = sumc / 2 - i; break;
		}
	}
	dbg(pick); 
	while(pick != 0){
		lft.push_back(pre[pick]);
		pick -= pre[pick];
	}
	for(auto v : lft) printf("%d ", v);
}
*/
int main(){
	freopen("variance.in", "r", stdin); freopen("variance.out", "w", stdout);
	init(); //work();
	Solution48pts::solve();
	fclose(stdin); fclose(stdout);
	return 0;
}

