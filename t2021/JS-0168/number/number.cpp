#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5+10;

int T;
bool have[maxn];

int read() {
	char ch = getchar();
	int x = 0, f = 1;
	while((ch > '9' || ch < '0') && ch != '-') {
		ch = getchar();
	}
	if(ch == '-') {
		ch = getchar();
		f = -1;
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch -'0';
		ch = getchar();
	}
	return x * f;
}

int check(int x) {
	for(register int j = x; j >= 1; j--) {
		if(x % j)continue;
		if(have[j])return 0;
	}
	return 1;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T = read();
	for(register int i=1;i<=200005;i++) {
		int flag = 0;
		int j = i;
		while(j) {
			if(j % 10 == 7) {
				have[i] = 1;
				flag=1;
				break;
			}
			j /= 10;
		}
		if(!flag)have[i] = 0;
	}
	while(T--) {
		int x = read();
		for(register int i=x;i<=maxn;i++) {
			if (check(i)) {
				if(i == x) continue;
				else printf("%d\n",i);
				break;
			}
			else {
				if(i == x) {
					printf("-1\n");	
					break;
				}
			}
		}
	}
	return 0;
}
