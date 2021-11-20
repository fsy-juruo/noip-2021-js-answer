#include<bits/stdc++.h>
#define in(x) x = read()
#define MAXN 100001
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
ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a%b);
}
pair<ll, ll> add(ll a, ll b, ll c, ll d){
	if (a == 0) b == 1;
	if (c == 0) d == 1;	
	pair<ll, ll> tmp;
	ll p = gcd(b, d);
	a = a * d / p;
	c = c * b / p;
	a += c;
	b = b * d / p;
	p = gcd(a, b);
	a /= p;
	b /= p;
	tmp.first = a;
	tmp.second = b;
	return tmp;
}
pair<ll, ll> chy(ll a, ll b, ll c, ll d){
	pair<ll, ll> tmp;
	if (a == 0 || c == 0) 
		tmp.first = 0;
		tmp.second = 1;
		return tmp;
	a = a * c;
	b = b * d;
	ll p = gcd(a, b);
	a = a / p;
	b = b / p;
	tmp.first = a;
	tmp.second = b;
	return tmp;
}
pair<ll, ll> cha(ll a, ll b, ll c, ll d){
	if (a == 0) b == 1;
	if (c == 0) d == 1;
	double a1, b1, c1, d1;
	a1 = a, b1 = b, c1 = c, d1 = d;
	if (a / b < c / d){
		swap(a, c);
		swap(b, d);
	}
	ll p = gcd(b, d);
	pair<ll, ll> tmp;
	a = a * d / p;
	c = c * b / p;
	a -= c;
	b = b * d / p;
	p = gcd(a, b);
	a /= p;
	b /= p;
	tmp.first = a;
	tmp.second = b;
	return tmp;
}
ll n = 0;
ll num[20001];
ll ans = 0x7ffffff;
ll sum;
pair<ll, ll> ave, sup;
void work(){
	pair<ll, ll> tmp1;
	tmp1.first = 0, tmp1.second = 1;
	sup.first = 0, sup.second = 1;
	ave.first = 0, ave.second = 1;
	sum = 0;//init
	for (int i = 1; i <= n; ++i) {
		sum+=num[i];
 	}
	ll p = 0, a = 0, b = 0, c = 0, d = 0;
	p = gcd(n, sum);
	a = sum / p;
	b = n / p;
	ave.first = a;
	ave.second = b;
	//cout << a << " " << b << endl; 
	sup.second = 1;	
	for (int i = 1; i <= n; ++i){
		tmp1 = cha(num[i], 1, ave.first, ave.second);
		//cout << num[i] << " " << 1 << " " << ave.first << " " << ave.second << endl;
		//cout << tmp1.first << " " << tmp1.second<<endl;
		a = tmp1.first * tmp1.first;
		b = tmp1.second * tmp1.second;
		p = gcd(a, b);
		a /= p;
		b /= p;
		//cout << a <<  " " << b << endl;
		sup = add(sup.first, sup.second, a, b);
	}
	//cout << sup.first << " " << sup.second << endl;
	a = sup.first, b = sup.second;
	a *= n;
	p = gcd(a, b);
	a /= p, b /= p;
	//cout << a / b << endl;
	if ((a / b) < ans)
		ans = a / b;
}
int main(){
	/*
	int a, b, c, d;
	in(a), in(b);
	in(c), in(d);
	pair<ll, ll> tmp;
	tmp = cha(a, b, c, d);
	cout <<tmp.first <<" " << tmp.second;
	*/	
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(num[i]);
 	}
 	work();
 	bool flag[20001];
 	memset(flag, false, sizeof(flag));
 	for (int j = 1; j <= n; ++j)
 	for (int i = 2; i <= n - 1; i += 1){
 		if (num[i-1] + num[i+1] - num[i] < num[i+1] && !flag[i])
 		{
 			flag[i] = true;
 			num[i] = num[i-1] + num[i+1] - num[i];
 			//for (int i = 1; i <= n; ++i) cout << num[i] << " ";
 			//cout << endl;
 			work();
		}
		else if (flag[i]) flag[i] = false;
	}	
	cout << ans << endl;
}
