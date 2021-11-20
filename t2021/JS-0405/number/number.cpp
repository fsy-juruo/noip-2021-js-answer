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

vector<int> bad;
bool has7[10001000];
bool isbad[10001000];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for(int i = 7; i <= 10000100; i++){
		has7[i] = (i % 10 == 7) | (has7[i / 10]);
		if(has7[i] && !isbad[i])
			for(int j = i; j <= 10000100; j += i)
				isbad[j] = 1;
	}
//	cout << (int)p.size() << endl;
	int T;
	readint(T);
	while(T--){
		int x;
		readint(x);
		if(isbad[x])
			puts("-1");
		else {
			x++;
			while(isbad[x])
				x++;
			putint(x);
			puts("");
		}
	}
	return 0;
}
