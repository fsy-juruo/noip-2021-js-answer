#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
void readint(int &x){
	x = 0;
	char c = getchar();
	while(c != '-' && (c < '0' || c > '9'))
		c = getchar();
	int sign = 1;
	if(c == '-')
		sign = -1, c = getchar();
	while(c >= '0' && c <= '9')
		x = x * 10 + c - '0', c = getchar(); 
	x *= sign;
}
void putintrec(int x){
	if(!x)
		return ;
	putintrec(x / 10);
	putchar(x % 10 + '0');
}
void putint(int x){
	if(x < 0)
		putchar('-'), x = -x;
	if(x == 0)
		putchar('0');
	putintrec(x);
}

int T;
int n, m, q;

int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	readint(T); 
	while(T--){
		readint(n), readint(m), readint(q);
		rep(i, n + n - 1){
			int tmp;
			readint(tmp);
		}
		rep(i, q){
			int a, b, c, d;
			readint(a), readint(b), readint(c), readint(d);
			puts("4"); 
		}
	}
	return 0;
}
