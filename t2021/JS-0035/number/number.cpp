#include<bits/stdc++.h>
#define VI vector<int>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (b); i >= (a); --i)
#define fi first
#define se second
#define pb push_back
#define N
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
bool vis[10000015];
int vec[10000015], tot;
bool check(int x) {
	while(x) {
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
void init() {
	int top = 10000000 + 10;
	rep(i, 1, top) {
		if(check(i) && (i % 7) != 0 && vis[i] == 0) {
			for(int j = i + i; j <= top; j += i) vis[j] = 1;
		}
		if(i % 7 == 0 || check(i)) vis[i] = 1;
		if(!vis[i]) vec[++tot] = i;
	}
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	init();
	int T;
	scanf("%d", &T);
	while(T--) {
		int x;
		scanf("%d", &x);
		int pos = lower_bound(vec + 1, vec + tot + 1, x) - vec;
		if(vec[pos] != x) puts("-1");
		else printf("%d\n", vec[pos + 1]);
	}
	return 0;
}

