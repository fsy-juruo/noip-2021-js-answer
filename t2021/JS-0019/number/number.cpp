#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define N 10010000
#define M 1000100
using namespace std;

int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = (s<<3) + (s<<1) + (ch^48), ch = getchar();
	return s*w;
}

bool vis[N], seven[N];
int legal[M], pos[N], n;

void sleave(){
	int x;
	rep(i,1,N-10){
		if(seven[i] || i%10 == 7){
			vis[i] = seven[i] = true;
			if(i*10 < N-10)
				rep(p,0,9) seven[i*10+p] = true;
		}
		if(!vis[i]){ 
			legal[++n] = i, pos[i] = n;
			continue;
		}
		if(!seven[i]) continue;
		int j = 1;
		for(; j <= n; j++)
			i*legal[j] < N ? vis[i*legal[j]] = true : j = n+2;
		if(j == n+1) rep(k,legal[n]+1,N-5){
			i*k < N ? vis[i*k] = true : k = N;
		}
	}
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	sleave();
	int T = read(), x;
	while(T--){
		x = read();
		if(vis[x]) puts("-1");
		else printf("%d\n", legal[pos[x]+1]);
	}
	return 0;
}
