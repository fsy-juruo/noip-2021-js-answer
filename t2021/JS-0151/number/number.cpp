/*
my blog:
www.cnblogs.com/luoyj506
welcome to visit
*/
#include<bits/stdc++.h>
using namespace std;

inline long long read(){
	long long s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-')
			w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		s = s * 10 + ch - '0';
	return s * w;
}

inline void fre(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
}

const int MAXM = 1e7+10, MAXN = 1e6+10;
int ans[MAXM], p[MAXN], cnt, tot, las;
bool v[MAXM], vis[MAXM];

bool check(int x){
	while (x){
		if (x % 10 == 7)
			return true;
		x /= 10;
	}
	return false;
}

int main(){
	fre();
	for (int i = 2; i <= MAXM-8; i++){
		if (!vis[i])
			p[++cnt] = i;
		for (int j = 1; j <= cnt && i*p[j] <= MAXM-8; j++){
			vis[i*p[j]] = true;
			if (i % p[j] == 0)
				break;
		}
	}
	ans[0] = 1, las = 1;
	for (int i = 2; i <= MAXM-8; i++){
		if (v[i] || check(i)){
			if (!v[i])
				ans[i] = 1;
			v[i] = true;
			for (int j = 1; j <= cnt && i * p[j] <= MAXM-8; j++){
				v[i*p[j]] = 1, ans[i*p[j]] = ans[i] * p[j];
				if (ans[i] % p[j] == 0)
					break;
			}
		}
		else
			ans[las] = i, las = i;
	}
	int T = read();
	while (T--){
		int k = read();
		if (v[k])
			puts("-1");
		else
			printf("%d\n", ans[k]);
	}
	return 0;
}

