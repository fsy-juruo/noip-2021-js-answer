#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef unsigned long long ll;
inline ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch^48); ch = getchar();}
    return x * f;
}
inline void print(ll x){
    if (x){
        print(x / 10);
        putchar(x % 10 + '0');
    }
}
int a[MAXN];
bool vis[1000001];
void init (ll maxNum){
	for (ll i = 7; i <= 2*maxNum; i+=10){
		vis[i] = 1;
		for (ll j = 2; (i*j) <= 2*maxNum; ++j){
			vis[i*j] = 1;
		}
	}
	for (ll i = 70; i <= 2*maxNum; i+= 100){
		for (ll j = i; j <= i + 9; ++j){
			vis[j] = 1;
			for (ll k = 2; k * j <= 2*maxNum;++k){
				vis[k*j] = 1;
			}
		}
	}
	for (ll i = 700; i <= 2*maxNum; i+= 1000){
		for (ll j = i; j <= i + 99; ++j){
			vis[j] = 1;
			for (ll k = 2; k * j <= 2*maxNum;++k){
				vis[k*j] = 1;
			}
		}
	}
	for (ll i = 7000; i <= 2*maxNum; i+= 10000){
		for (ll j = i; j <= i + 999; ++j){
			vis[j] = 1;
			for (ll k = 2; k * j <= 2*maxNum; ++k){
				vis[k*j] = 1;
			}
		}
	}		
	return;
}
bool check(ll x){
	ll d;
	while (x){
		d = x % 10;	
		x /= 10;
		if (d == 7) return 1;
	}
	return 0;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ll T, x, ma = 0;
	T = read();
	for (ll i = 1; i <= T; ++i){
		x = read();
		if (x > ma) ma = x;
		a[i] = x;
	}
	init(ma);
	for (ll i = 1; i <= T; ++i){
		if (vis[a[i]]) {cout << -1 << endl; continue;}
		for (ll j = a[i] + 1; j <= 2*ma; ++j){
			if (check(j)) continue;
			if (!vis[j]){
				print(j);
				cout << endl;
				break;
			}
		}
	}
	return 0;
}
