#include<bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
const int MAXN = 1e7 + 10;
const int N = 1e7;
const int MAXM =  + 10;

inline int fread(void){
	char ch = getchar(); int ret = 0, op = 1;
	for(; !isdigit(ch) && ch != '-'; ch = getchar());
	if(ch == '-') op = -1;
	else ret = ch - '0';
	ch = getchar();
	for(; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return ret * op;
}
bool fob[MAXN]; int num[MAXN], cnt, nxt[MAXN];
void dfs(int step, int opt, int sum){
	if(step == 0){
		num[++ cnt] = sum; return; 
	}
	if(step == 1 && !opt){
		dfs(step - 1, 1, sum * 10 + 7);
		return;
	} 
	for(int i = 0; i <= 9; ++ i)
		dfs(step - 1, opt | (i == 7), sum * 10 + i);
}
inline void init(void){
	dfs(7, 0, 0);
	for(int i = 1; i <= cnt; ++ i) assert(num[i - 1] <= num[i]);
	for(int i = 1; i <= cnt; ++ i){
		for(int j = num[i]; j <= N; j += num[i]){
			//if(fob[j]) break;
			fob[j] = 1; 
		}
	}
	int tmp = N + 1; 
	for(int i = N; i >= 1; -- i){
		if(fob[i]) continue;
		nxt[i] = tmp; tmp = i; 
	}
}

inline void work(void){
	int T = fread();
	for(int t = 1; t <= T; ++ t){
		int now = fread();
		if(fob[now]) printf("-1\n");
		else printf("%d\n", nxt[now]);
	}
}
//Warning !!! haven't deal with the special number N
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init(); work();
	fclose(stdin); fclose(stdout);
	return 0;
}

