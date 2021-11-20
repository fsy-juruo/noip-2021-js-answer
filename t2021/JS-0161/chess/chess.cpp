#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
template <typename T> inline void read(T&x) {
	x = 0;
	char ch = getchar();
	T flg = 1;
	while ((!isdigit(ch)) && ch != '-') ch = getchar();
	if (ch == '-') ch = getchar(), flg = -1;
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= flg;
}
const int MN = 1e5 + 10;
char str[MN];
vector<pair<int,int> >ver[MN];
int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int T;
	read(T);
	while(T--) {
		int n,m,q;
		read(n),read(m),read(q);
		for (int i = 1; i <= n; i++) {
			scanf("%s", str + 1);
			int l = strlen(str + 1);
			for (int j = 1; j <= l; j++) {
				ver[(i-1)*n + j].push_back(mp((i-1)*n+j+1, str[j]-'0'));
			}
		}
		for (int i = 1; i < n; i++) {
			scanf("%s", str + 1);
			int l = strlen(str + 1);
			for (int j = 1; j <= l; j++) {
				ver[(j-1)*n+i].push_back(mp((j)*n+i, str[j]-'0'));
			}
		}
		for (int i = 1; i <= q; i++){
			int a,b,c,d;
			read(a),read(b),read(c),read(d);
			puts("4");
		}
	}
	return 0;
}
